#include "Define.h" 

void Config_NTP_Time();

void setup() 
{
  #ifdef SERIAL_DEBUG
    Serial.begin(115200);
  #endif
  EEPROM_Init();
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

  AC.CurrentMillis = 0;
  AC.WiFi_Status_PreviousMillis = 0;
  AC.WiFi_Reconnect_Interval = 30000; // check every 30 seconds
}

void App_Mode_Loop()
{
  static bool VE = 0;
  AC.Test_Mode_Switch_Val = digitalRead(Switch_TestMode);
  AC.Test_Mode_Valve_Button_Val = digitalRead(Button_TestMode_ValveEnable);
  
  switch(AC.State)
  {
    case APP_STATE_NORMAL:
      if(AC.Test_Mode_Switch_Val == 0)
      {
        if(NTP.Time == WS.Plant1_Time && VE == 0)
        {
          VE = 1;
          AC.Valve_Status_PreviousMillis = AC.CurrentMillis;
          #ifdef SERIAL_DEBUG
            Serial.println("Valve1 enabled");
            Serial.println(AC.Valve_Status_PreviousMillis);
          #endif
        }
        if (VE == 1 && (AC.CurrentMillis - AC.Valve_Status_PreviousMillis >= WS.Plant1_Valve_Open_Sec))
        { 
          VE = 0;
          #ifdef SERIAL_DEBUG
            Serial.println("Valve1 disabled");
            Serial.println(AC.CurrentMillis);
          #endif
        }
        if(AC.Test_Mode_Valve_Button_Val == 1)
        {
          Audio_Write();          
        }
        AC.State = APP_STATE_NORMAL;
      }
      else
      {
        AC.State = APP_STATE_TEST;
      }
    break;
    case APP_STATE_TEST:
      
      if(AC.Test_Mode_Switch_Val == 1)
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
      else
      {
        AC.State = APP_STATE_NORMAL;
      }
    break;

    default:
      /*Do Nothing*/
    break;   
  }
}
