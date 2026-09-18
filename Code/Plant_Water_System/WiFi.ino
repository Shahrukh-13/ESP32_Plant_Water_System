#include "Define.h" 

void WiFi_Init()
{
  char buffer[100];
  WC.wifi_connection_timeout_count = 0;
  
  WC.ssid_i = Read_String_EEPROM(EEPROM_SSID_ADDRESS);
  WC.password_i = Read_String_EEPROM(EEPROM_PASSWORD_ADDRESS);

  WS.Saved_WiFi_SSID = WC.ssid_i;
  WS.Saved_WiFi_Password = WC.password_i;
  
  #ifdef SERIAL_DEBUG
    //Serial.println(WC.ssid_i);
    //Serial.println(WC.password_i);
  #endif
     
  //connect to WiFi
  WiFi.begin(WC.ssid, WC.password);
  while (WiFi.status() != WL_CONNECTED && WC.wifi_connection_timeout_count <7) 
  {
      delay(500);
      #ifdef SERIAL_DEBUG
        Serial.print(".");
        Serial.print("Connecting to ");
        Serial.print(WC.ssid_i);
      #endif
      
      LCD__Clear();
      snprintf(buffer, sizeof(buffer), "Connecting to \n" 
                                       "%s", WC.ssid_i.c_str()); 
      LCD_Write(0, 0, String(buffer));
      
      WC.wifi_connection_timeout_count++;
      #ifdef SERIAL_DEBUG
        Serial.print("WC.wifi_connection_timeout_count= ");
        Serial.print(WC.wifi_connection_timeout_count);
        Serial.println();
     #endif
  }
  
  if(WC.wifi_connection_timeout_count >=7)
  {
    if(WC.PowerCycle_Count <5)
    {
      WC.PowerCycle_Count++;
      EEPROM.write(EEPROM_POWERCYCLE_COUNT_ADDRESS,WC.PowerCycle_Count);
      EEPROM.commit();
      WC.PowerCycle_Count = EEPROM.read(EEPROM_POWERCYCLE_COUNT_ADDRESS);

      #ifdef SERIAL_DEBUG
        Serial.print("NewPowerCycle_Count= ");
        Serial.print(WC.PowerCycle_Count);
        Serial.println();
      #endif
      ESP.restart();
    }
    else
    {
      WC.PowerCycle_Count = 0;
      EEPROM.write(EEPROM_POWERCYCLE_COUNT_ADDRESS,WC.PowerCycle_Count);
      EEPROM.commit();
      
      WC.ssid_i = Default_WiFi_SSID;
      WriteString_EEPROM(EEPROM_SSID_ADDRESS,WC.ssid_i);
      WC.ssid_i = Read_String_EEPROM(EEPROM_SSID_ADDRESS);

      WC.password_i = Default_WiFi_Password;
      WriteString_EEPROM(EEPROM_PASSWORD_ADDRESS, WC.password_i);
      WC.password_i = Read_String_EEPROM(EEPROM_PASSWORD_ADDRESS);
      #ifdef SERIAL_DEBUG
        Serial.println("revert to default SSID");
        Serial.println("revert to default password");
      #endif
      delay(2000);
      ESP.restart();
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

void WiFi_Reconnect()
{
    WiFi.disconnect();
    WiFi.reconnect();
}
