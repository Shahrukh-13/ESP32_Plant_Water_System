#include "Define.h" 

void setup() 
{
  #ifdef SERIAL_DEBUG
    Serial.begin(115200);
  #endif
  IO_Init();
  App_Init();
  Water_Level_Sensor_Init();
  Timer_Init();
  Motor_Init();
  LCD_Init();
}

void loop() 
{
  //LCD_Write(0, 0, "HELLO\n");
  App_Mode_Loop();
  Water_Level_Loop();
  Motor_Loop();
  Set_Leds();
  LCD_Display_App_Stats();

  #ifdef SERIAL_DEBUG
    /*Serial.print("Valve Open: ");
    Serial.print(AC.Valve_Is_Open);
    Serial.println();
    Serial.print("Water Level: ");
    Serial.print(WL.State);
    Serial.println();
    Serial.print("Drain Motor good to run: ");
    Serial.print(MS[MOTOR_DRAIN].Motor_Good_To_Run);
    Serial.println();
    Serial.print("Refill Motor good to run: ");
    Serial.print(MS[MOTOR_REFILL].Motor_Good_To_Run);
    Serial.println();
    Serial.print("Drain Motor state: ");
    Serial.print(MS[MOTOR_DRAIN].State);
    Serial.println();
    Serial.print("Refill Motor state: ");
    Serial.print(MS[MOTOR_REFILL].State);
    Serial.println();*/
    //Serial.println();
  #endif
}

void App_Init()
{
  AC.LowLevel_Sensor_Bypass_Val = 0;
  AC.Test_Mode_Switch_Val = 0;
  AC.HeartBeat_Toggle = 0;
  AC.State = APP_STATE_NORMAL;
  AC.Hex_Encoder_Val = 0;
  AC.Test_Mode_Valve_Button_Val = 0;
  AC.Valve_Is_Open = false;
}

void App_Mode_Loop()
{
  AC.Test_Mode_Switch_Val = digitalRead(Switch_TestMode);
  AC.Test_Mode_Valve_Button_Val = digitalRead(Button_TestMode_ValveEnable);
  
  switch(AC.State)
  {
    case APP_STATE_NORMAL:
    case APP_STATE_TEST:
      if(AC.Test_Mode_Switch_Val == 0)
      {
        AC.State = APP_STATE_NORMAL;
      }
      else
      {
        Hex_Encoder_Get();
        if(AC.Test_Mode_Valve_Button_Val == 1)
        {
          Valve_Select(AC.Hex_Encoder_Val);
        }
        else
        {
          All_Valves_OFF();
        }
        AC.State = APP_STATE_TEST;
      }
    break;

    default:
      /*Do Nothing*/
    break;   
  }
}
