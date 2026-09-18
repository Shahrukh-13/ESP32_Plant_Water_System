#include "Define.h" 

TaskHandle_t Task1;
TaskHandle_t Task2;

void RTOS_Init()
{
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  delay(500); 

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */
  delay(500); 
}

//Task1code: Plant Water system
void Task1code( void * pvParameters )
{
  for(;;){
    AC.CurrentMillis = millis();
    App_Mode_Loop();
    Water_Level_Loop();
    Motor_Loop();
    Set_Leds();
    GetLocalTime();
    LCD_Display_App_Stats();
    
    // if WiFi is down, try reconnecting
    if ((WiFi.status() != WL_CONNECTED) && (AC.CurrentMillis - AC.WiFi_Status_PreviousMillis >= AC.WiFi_Reconnect_Interval)) 
    {
      WiFi_Reconnect();
      AC.WiFi_Status_PreviousMillis = AC.CurrentMillis;
    }
  }
}

//Task2code: Harp LEDs
void Task2code( void * pvParameters )
{
  for(;;){
    AC.Test_Mode_Valve_Button_Val = digitalRead(Button_TestMode_ValveEnable);
    delay(500);
    if(AC.Test_Mode_Valve_Button_Val == 1)
    {
      Do_Harp_LED();
    }
  }
}
