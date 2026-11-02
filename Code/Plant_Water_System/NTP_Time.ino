#include "Define.h" 

void NTP_Time_Init()
{
  NTP.gmtOffset_sec = -18000;
  NTP.daylightOffset_sec = 3600;
  NTP.ntpServer = "pool.ntp.org";
  NTP.Time = "none";
}

void Config_NTP_Time()
{
  configTime(NTP.gmtOffset_sec, NTP.daylightOffset_sec, NTP.ntpServer);
  GetLocalTime();
}

void GetLocalTime()
{
  char chBuffer[81];
  time_t rawtime;
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain date and time");
    NTP.Time = "Failed to obtain time";
    ESP.restart();
  }

  strftime(chBuffer, sizeof(chBuffer), "%m/%d/%Y", &timeinfo);
  NTP.Date = String(chBuffer);

  AC.Change_water_Flag = isOneMonthApart(WS.Water_Change_Date, NTP.Date);
  
  // Obtain Time Hr:Min:Sec
  strftime(NTP.chHour, sizeof(NTP.chHour), "%I", & timeinfo);
  strftime(NTP.chMinute, sizeof(NTP.chMinute), "%M", & timeinfo);
  strftime(NTP.chSecond, sizeof(NTP.chSecond), "%S", & timeinfo);
  
  // Then obtain day of week, AM/PM.
  strftime(NTP.chDayofWeek, sizeof(NTP.chDayofWeek), "%A", & timeinfo);
  strftime(NTP.AM_PM, sizeof(NTP.AM_PM), "%p", & timeinfo);

 // Build Time String
  sprintf(chBuffer, "%s:%s:%s:%s:%s", String(NTP.chDayofWeek), String(NTP.chHour), String(NTP.chMinute), String(NTP.chSecond), String(NTP.AM_PM));
  NTP.Time = String(chBuffer);
  #ifdef SERIAL_DEBUG
   //Serial.println(NTP.Time);
  #endif
}

// Function to check if D2 is approximately 1 month after D1
bool isOneMonthApart(String D1, String D2) 
{
  struct tm timeinfo1;
  struct tm timeinfo2;
  time_t t1;
  time_t t2;
  
  // Variables to hold parsed values
  int month = 0; 
  int day = 0;
  int year = 0;

  // Parse the string using sscanf
  // %d matches integers, and the '/' characters match the literal slashes
  if (sscanf(D1.c_str(), "%d/%d/%d", &month, &day, &year) == 3) 
  {   
    memset(&timeinfo1, 0, sizeof(struct tm)); // Clear the structure

    timeinfo1.tm_mday = day;           // Day of the month (1-31)
    timeinfo1.tm_mon =  month - 1;     // Months since January (0-11)
    timeinfo1.tm_year = year - 1970;   // Years since 1970

    //Convert to time_t to let the system calculate weekday/yearday
    t1 = mktime(&timeinfo1);
  }

  if (sscanf(D2.c_str(), "%d/%d/%d", &month, &day, &year) == 3) 
  {    
    memset(&timeinfo2, 0, sizeof(struct tm)); // Clear the structure

    timeinfo2.tm_mday = day;           // Day of the month (1-31)
    timeinfo2.tm_mon =  month - 1;     // Months since January (0-11)
    timeinfo2.tm_year = year - 1970;   // Years since 1970

    //Convert to time_t to let the system calculate weekday/yearday
    t2 = mktime(&timeinfo2);
  }

  if (t1 == -1 || t2 == -1) 
  {
    //printf("Error processing dates.\n");
    return 0;
  }

  //Get difference in seconds
  double seconds = difftime(t2, t1);

  //Convert seconds to days (86400 seconds in a day)
  double days = seconds / 86400;

  if (days >=30)
  {
    return true;
  }
  else
  {
    return false;
  }
}
