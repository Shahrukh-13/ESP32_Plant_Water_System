#include "Define.h" 

#define EEPROM_SSID_ADDRESS                   0   //(0  - 49)
#define EEPROM_PASSWORD_ADDRESS               50  //(50 - 99)

#define EEPROM_PLANT1_TIME_ADDRESS            100
#define EEPROM_PLANT2_TIME_ADDRESS            150
#define EEPROM_PLANT3_TIME_ADDRESS            200
#define EEPROM_PLANT4_TIME_ADDRESS            250
#define EEPROM_PLANT5_TIME_ADDRESS            300

#define EEPROM_POWERCYCLE_COUNT_ADDRESS       301 


String Default_WiFi_SSID = "Shahrukh13";
String Default_WiFi_Password = "shahan-2020";


void WiFi_Init()
{
  char buffer[150];
  WC.wifi_connection_timeout_count = 0;
  
  //Reset the PowerCycle_Count to 0 on fresh EEPROM//
  WC.PowerCycle_Count = EEPROM.read(EEPROM_POWERCYCLE_COUNT_ADDRESS);
  if(WC.PowerCycle_Count == 0xFF)
  {
    WC.PowerCycle_Count = 0;
    EEPROM.write(EEPROM_POWERCYCLE_COUNT_ADDRESS,WC.PowerCycle_Count);
    EEPROM.commit();
    WC.PowerCycle_Count = EEPROM.read(EEPROM_POWERCYCLE_COUNT_ADDRESS);
  }
  
  WC.ssid_i = Read_String_EEPROM(EEPROM_SSID_ADDRESS);
  WC.password_i = Read_String_EEPROM(EEPROM_PASSWORD_ADDRESS);

  #ifdef SERIAL_DEBUG
    Serial.println(WC.ssid_i);
    Serial.println(WC.password_i);
  #endif
  
  if(WC.ssid_i == "empty")
  {
    WC.ssid_i = Default_WiFi_SSID;
    WriteString_EEPROM(EEPROM_SSID_ADDRESS,WC.ssid_i);
  }
  if(WC.password_i == "empty")
  {
    WC.password_i = Default_WiFi_Password;
    WriteString_EEPROM(EEPROM_PASSWORD_ADDRESS, WC.password_i);
  }
  WC.ssid_i.toCharArray(WC.ssid, WC.ssid_i.length()+1);
  WC.password_i.toCharArray(WC.password, WC.password_i.length()+1);
    
  //connect to WiFi
  WiFi.begin(WC.ssid, WC.password);
  while (WiFi.status() != WL_CONNECTED && WC.wifi_connection_timeout_count <10) 
  {
      delay(500);
      #ifdef SERIAL_DEBUG
        Serial.print(".");
        Serial.print("Connecting to ");
        Serial.print(WC.ssid_i);
      #endif
      
      LCD__Clear();
      snprintf(buffer, sizeof(buffer), "Connecting to \n" 
                                       "%s", WC.ssid_i); 
      LCD_Write(0, 0, String(buffer));
      
      WC.wifi_connection_timeout_count++;
  }
  
  if(WC.wifi_connection_timeout_count >=10)
  {
    if(WC.PowerCycle_Count <5)
    {
      WC.PowerCycle_Count++;
      EEPROM.write(EEPROM_POWERCYCLE_COUNT_ADDRESS,WC.PowerCycle_Count);
      EEPROM.commit();
      ESP.restart();
    }
    else
    {
      WC.PowerCycle_Count = 0;
      EEPROM.write(EEPROM_POWERCYCLE_COUNT_ADDRESS,WC.PowerCycle_Count);
      EEPROM.commit();
      delay(2000);
    }
  }
  
  if(WiFi.status() == WL_CONNECTED)
  {
    #ifdef SERIAL_DEBUG
      //Serial.println(WiFi.localIP().toString());
      Serial.println(WiFi.localIP());
    #endif
    //init and get the time
    Config_NTP_Time();

    //Update WebPage
    Update_WebPage();    
    
    // Send web page with input fields to client
    Send_WebPage(); 
    
    // Send a GET request to <ESP_IP>
    Get_WebPage();
    
    server.onNotFound(notFound);
    server.begin();
  }
}

void WriteString_EEPROM(char add,String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.write(add+i,data[i]);
  }
  EEPROM.write(add+_size,'\0');   //Add termination null character for String Data
  EEPROM.commit();
}


String Read_String_EEPROM(char add)
{
  int i;
  char data[50]; 
  int len=0;
  unsigned char k;
  k=EEPROM.read(add);
  if(k == 0xFF)
  {
    return String("empty");
  }
  else
  {
    while(k != '\0' && len<50)   //Read until null character
    {    
      k=EEPROM.read(add+len);
      data[len]=k;
      len++;
    }
    data[len]='\0';
    return String(data);
  }
}
