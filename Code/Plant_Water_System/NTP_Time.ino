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
