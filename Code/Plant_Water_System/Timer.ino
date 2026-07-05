#include "Define.h" 

// Define the Interrupt Service Routine (ISR)
void IRAM_ATTR onTimer()
{
  digitalWrite(HeartBeat_LED, !digitalRead(HeartBeat_LED)); 
}

void Timer_Init()
{
  // Initialize the timer (Timer 0, Prescaler 80)
  // ESP32 Timer clock runs at 80 MHz, so a prescaler of 80 scales it to 1 MHz (1 tick = 1 microsecond)
  timer = timerBegin(0, 80, true);

  // Attach the onTimer function to the timer
  timerAttachInterrupt(timer, &onTimer, true);

  // Set the alarm to trigger every 1 second (1,000,000 microseconds)
  timerAlarmWrite(timer, 1000000, true);

  // Enable the alarm
  timerAlarmEnable(timer);
}
