#include "Define.h" 

void Config_NTP_Time();

void setup() 
{
  #ifdef SERIAL_DEBUG
    Serial.begin(115200);
  #endif
  EEPROM.begin(512);
  IO_Init();
  App_Init();
  Water_Level_Sensor_Init();
  Timer_Init();
  Motor_Init();
  LCD_Init();
  I2S_Audio_Init();
  RTOS_Init();
  NTP_Time_Init();
  WiFi_Init();
}

void loop() 
{
  /*App_Mode_Loop();
  Water_Level_Loop();
  Motor_Loop();
  Set_Leds();
  LCD_Display_App_Stats();*/
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
        if(AC.Test_Mode_Valve_Button_Val == 1)
        {
          Audio_Write();          
        }
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
