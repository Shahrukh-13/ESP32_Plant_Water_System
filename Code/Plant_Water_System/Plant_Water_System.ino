#include "Define.h" 

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
  TIME_VALVE_CFG_Struct_Set();
  RTOS_Init();
  NTP_Time_Init();
  WiFi_Init();
}

void loop() 
{
 
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

  AC.Do_Harp_LED = false;
  AC.Mute_Audio = false;
  AC.Which_Valve_Enabled = VALVE_NONE;
  
  AC.CurrentMillis = 0;
  AC.WiFi_Status_PreviousMillis = 0;
  AC.Audio_Mute_Status_PreviousMillis = 0;

  AC.Audio_Mute_Min = 15;
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
        for(uint8_t i=1 ; i<=VALVE5 ; i++)
        {
          if(NTP.Time == TIME_VALVE_CFG[i].Vale_Time_String && AC.Valve_Is_Open == false)
          {
            Valve_Select(TIME_VALVE_CFG[i].Valve_ID);
            AC.Which_Valve_Enabled = TIME_VALVE_CFG[i].Valve_ID;
            if(AC.Mute_Audio == false)
            {
              AC.Do_Harp_LED = true;
              Audio_Write();
              AC.Do_Harp_LED = false;
            }
            AC.Mute_Audio = true;
            AC.Valve_Status_PreviousMillis = AC.CurrentMillis;
            AC.Audio_Mute_Status_PreviousMillis = AC.CurrentMillis;
            #ifdef SERIAL_DEBUG
              Serial.print("Valve");
              Serial.print(TIME_VALVE_CFG[i].Valve_ID);
              Serial.print(" enabled");
              Serial.println();
              Serial.println(AC.Valve_Status_PreviousMillis);
            #endif
          }
        }
        
        for(uint8_t i=1 ; i<=VALVE5 ; i++)
        {
          if (AC.Valve_Is_Open == true && (i == AC.Which_Valve_Enabled) && (AC.CurrentMillis - AC.Valve_Status_PreviousMillis >= (TIME_VALVE_CFG[i].Valve_Open_Sec * 1000)))
          { 
            All_Valves_OFF();
            #ifdef SERIAL_DEBUG
              Serial.print("Valve");
              Serial.print(TIME_VALVE_CFG[i].Valve_ID);
              Serial.print(" disabled");
              Serial.println();
              Serial.println(AC.CurrentMillis);
            #endif
          }
        }

        if(AC.Mute_Audio == true && (AC.CurrentMillis - AC.Audio_Mute_Status_PreviousMillis >= (AC.Audio_Mute_Min * 60 * 1000)))
        {
          AC.Mute_Audio = false;
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
