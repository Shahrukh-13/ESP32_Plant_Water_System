#include "time.h"
  
void setup() 
{
  Serial.begin(115200);
  
  if(isOneMonthApart("12/01/2026", "01/01/2027"))
  {
    Serial.println("1 month Past");
  }
  else
  {
    Serial.println("1 month not Past");
  }
}

void loop() 
{
  if(isOneMonthApart("12/01/2026", "01/01/2027"))
  {
    Serial.println("1 month Past");
  }
  else
  {
    Serial.println("1 month not Past");
  }
}

// Function to check if t2 is approximately 1 month after t1
bool isOneMonthApart(String D1, String D2) 
{
  struct tm timeinfo1;
  struct tm timeinfo2;

  time_t t1;
  time_t t2;
    // Variables to hold parsed values
  int month = 0, day = 0, year = 0;

  // 1. Parse the string using sscanf
  // %d matches integers, and the '/' characters match the literal slashes
  if (sscanf(D1.c_str(), "%d/%d/%d", &month, &day, &year) == 3) 
  {
   
    memset(&timeinfo1, 0, sizeof(struct tm)); // Clear the structure

    timeinfo1.tm_mday = day;           // Day of the month (1-31)
    timeinfo1.tm_mon =  month - 1;     // Months since January (0-11)
    timeinfo1.tm_year = year - 1970;   // Years since 1900

    // 3. (Optional) Convert to time_t to let the system calculate weekday/yearday
    t1 = mktime(&timeinfo1);
  }

  if (sscanf(D2.c_str(), "%d/%d/%d", &month, &day, &year) == 3) 
  {
    
    memset(&timeinfo2, 0, sizeof(struct tm)); // Clear the structure

    timeinfo2.tm_mday = day;           // Day of the month (1-31)
    timeinfo2.tm_mon =  month - 1;     // Months since January (0-11)
    timeinfo2.tm_year = year - 1970;   // Years since 1900

    // 3. (Optional) Convert to time_t to let the system calculate weekday/yearday
    t2 = mktime(&timeinfo2);
  }

  if (t1 == -1 || t2 == -1) 
  {
        printf("Error processing dates.\n");
        return 0;
  }

  // Get difference in seconds
    double seconds = difftime(t2, t1);

    // Convert seconds to days (86400 seconds in a day)
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
