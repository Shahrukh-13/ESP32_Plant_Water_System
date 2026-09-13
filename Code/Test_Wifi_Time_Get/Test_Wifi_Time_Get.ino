#include <WiFi.h>
#include <EEPROM.h>

#define EEPROM_SSID_ADDRESS                   0   //(0  - 49)
#define EEPROM_PASSWORD_ADDRESS               50  //(50 - 99)

#define EEPROM_PLANT1_TIME_ADDRESS            100
#define EEPROM_PLANT2_TIME_ADDRESS            150
#define EEPROM_PLANT3_TIME_ADDRESS            200
#define EEPROM_PLANT4_TIME_ADDRESS            250
#define EEPROM_PLANT5_TIME_ADDRESS            300

#define EEPROM_POWERCYCLE_COUNT_ADDRESS       301 

const long  gmtOffset_sec = -18000;
const int   daylightOffset_sec = 3600;
String Date;
String Year;
String Time;

bool wifi_flag;

String ssid_i;
String password_i;

String inputMessage = "" ;
String inputParam = "" ;
    
char ssid[50];
char password[50];

String input = "";
String command = "";

static  char chBuffer[81];

char        chDayOfMonth[3];                                    // Day of month (0 through 31).
char        chDayofWeek[4];                                     // Day of week (Sunday through Saturday).
char        chHour[3];                                          // Hour.
char        chMinute[3];                                        // Minute.
char        chMonth[4];                                         // Month.
const char* ntpServer = "pool.ntp.org";
char        chSecond[3];                                        // Second.
char        chYear[5];                                          // Year.
char        AM_PM[3];                                           // AM/PM.

uint8_t wifi_connection_timeout_count;

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
const long interval = 1000; // 1 second

uint8_t PowerCycle_Count;

void setup() 
{
  Serial.begin(115200);
  EEPROM.begin(512);
   
  wifi_connection_timeout_count = 0;
  
  //Reset the PowerCycle_Count to 0 on fresh EEPROM//
  PowerCycle_Count = EEPROM.read(EEPROM_POWERCYCLE_COUNT_ADDRESS);
  Serial.println(PowerCycle_Count);
  if(PowerCycle_Count == 0xFF)
  {
    PowerCycle_Count = 0;
    EEPROM.write(EEPROM_POWERCYCLE_COUNT_ADDRESS,PowerCycle_Count);
    EEPROM.commit();
    PowerCycle_Count = EEPROM.read(EEPROM_POWERCYCLE_COUNT_ADDRESS);
  }
  
  ssid_i = read_String(EEPROM_SSID_ADDRESS);
  password_i = read_String(EEPROM_PASSWORD_ADDRESS);

  Serial.println(ssid_i);
  Serial.println(password_i);

  ssid_i.toCharArray(ssid, ssid_i.length()+1);
  password_i.toCharArray(password, password_i.length()+1);
    
  //connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED && wifi_connection_timeout_count <10) 
  {
      delay(500);
      Serial.print(".");
      Serial.print("Connecting");
      wifi_connection_timeout_count++;
  }
  
  if(wifi_connection_timeout_count >=10)
  {
    if(PowerCycle_Count <5)
    {
      PowerCycle_Count++;
      EEPROM.write(EEPROM_POWERCYCLE_COUNT_ADDRESS,PowerCycle_Count);
      EEPROM.commit();
      ESP.restart();
    }
    else
    {
      PowerCycle_Count = 0;
      EEPROM.write(EEPROM_POWERCYCLE_COUNT_ADDRESS,PowerCycle_Count);
      EEPROM.commit();
      delay(2000);
    }
  }

  if(WiFi.status() == WL_CONNECTED)
  {
    //init and get the time
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    GetLocalTime();
  }
}

void loop()
{
    scan_connect_reset();
    if(WiFi.status() == WL_CONNECTED)
    {
      GetLocalTime(); 
    }
}

void GetLocalTime()
{
  time_t rawtime;
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain date and time");
    Date = "Failed to obtain date";
    Time = "Failed to obtain time";
    ESP.restart();
    //return;
  }
  //Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  
  //Serial.println(timeinfo.tm_mday);
  /*tm_sec: seconds after the minute;
  tm_min: minutes after the hour;
  tm_hour: hours since midnight;
  tm_mday: day of the month;
  tm_year: years since 1900;
  tm_wday: days since Sunday;
  tm_yday: days since January 1;
  tm_isdst: Daylight Saving Time flag;*/ 

  //time (&rawtime);
  //Date_Time = asctime(localtime (&rawtime));

  strftime(chHour, sizeof(chHour), "%I", & timeinfo);
  strftime(chMinute, sizeof(chMinute), "%M", & timeinfo);
  strftime(chSecond, sizeof(chSecond), "%S", & timeinfo);
  
  // Then obtain day of week, day of month, month and year.
    
  strftime(chDayofWeek, sizeof(chDayofWeek), "%A", & timeinfo);
  strftime(chDayOfMonth, sizeof(chDayOfMonth), "%d", & timeinfo);
  strftime(chMonth, sizeof(chMonth), "%B", & timeinfo);
  strftime(chYear, sizeof(chYear), "%Y", & timeinfo);
  strftime(AM_PM, sizeof(AM_PM), "%p", & timeinfo);
 
   sprintf(chBuffer, "%s:%s:%s:%s:%s", String(chDayofWeek), String(chHour), String(chMinute), String(chSecond), String(AM_PM));
   Time = String(chBuffer);
   Serial.println(Time);
}


void writeString(char add,String data)
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


String read_String(char add)
{
  int i;
  char data[50]; //Max 100 Bytes
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

void scan_connect_reset()
{  
  while (Serial.available() > 0)
  {            
    //input += (char) Serial.read(); 
    input =Serial.readString();
    //command =input.substring(0,input.length()-2);  //both NL and CR
    command =input.substring(0,input.length());  // No newline
    if(command == "scan")
    {      
      Serial.println("scan start");
      // WiFi.scanNetworks will return the number of networks found
      int n = WiFi.scanNetworks();
      Serial.println("scan done");
      if (n == 0) 
      {
        Serial.println("no networks found");
      } 
      else 
      {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) 
        {            
          // Print SSID and RSSI for each network found
          Serial.print(i + 1);
          Serial.print(": ");
          Serial.print(WiFi.SSID(i));
          Serial.print(" (");
          Serial.print(WiFi.RSSI(i));
          Serial.print(")");
          Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
          delay(10);
        }
      }
      Serial.println("");
      Serial.print("If you want to connect to a new network, enter 'ssid' and 'passowrd' in following format: ssid,password");
      Serial.println();
    }

    else if(command == "reset")
    {
      ESP.restart();        
    }
    
    else if(command.indexOf(",") >= 0)
    {
      ssid_i = input.substring(0,input.indexOf(','));
      password_i =   input.substring(input.indexOf(',')+1);
  
      writeString(EEPROM_SSID_ADDRESS, ssid_i);
      writeString(EEPROM_PASSWORD_ADDRESS, password_i);
  
      Serial.println();
      Serial.print("new ssid: ");
      Serial.print(ssid_i);
      Serial.print(" , ");
      Serial.print("new password: ");
      Serial.print(password_i);
      Serial.println();
           
      delay(5); 
    }
  }
}
