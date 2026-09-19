#include "Define.h" 

struct valve_config
{
  valve_id_t  Valve_ID;
  bool  Valve0_Pin_Val;
  bool  Valve1_Pin_Val;
  bool  Valve2_Pin_Val;
  bool  Valve3_Pin_Val;
  bool  Valve4_Pin_Val;
  bool  Valve5_Pin_Val;
};

struct valve_config VALVE_CFG[]= {
  {VALVE0,      1,  0,  0,  0,  0,  0},
  {VALVE1,      0,  1,  0,  0,  0,  0},
  {VALVE2,      0,  0,  1,  0,  0,  0},
  {VALVE3,      0,  0,  0,  1,  0,  0},
  {VALVE4,      0,  0,  0,  0,  1,  0},
  {VALVE5,      0,  0,  0,  0,  0,  1},
  {VALVE_NONE,  0,  0,  0,  0,  0,  0}
};

void Valve_Select(uint8_t id)
{
  if(id > VALVE5)
  {
    id = VALVE_NONE;
    AC.Valve_Is_Open = false;
  }
  else
  {
    AC.Valve_Is_Open = true;
  }

  #ifdef SERIAL_DEBUG
    /*Serial.print(id);
    Serial.println();*/
  #endif
  
  for(uint8_t i=0 ; i<VALVE_MAX ; i++)
  {
    if(id == VALVE_CFG[i].Valve_ID)
    {
      mcp.digitalWrite(Valve_0_Enable, VALVE_CFG[i].Valve0_Pin_Val);
      mcp.digitalWrite(Valve_1_Enable, VALVE_CFG[i].Valve1_Pin_Val);
      mcp.digitalWrite(Valve_2_Enable, VALVE_CFG[i].Valve2_Pin_Val);
      mcp.digitalWrite(Valve_3_Enable, VALVE_CFG[i].Valve3_Pin_Val);
      mcp.digitalWrite(Valve_4_Enable, VALVE_CFG[i].Valve4_Pin_Val);
      mcp.digitalWrite(Valve_5_Enable, VALVE_CFG[i].Valve5_Pin_Val);
    }
  }
}

void All_Valves_OFF()
{
  AC.Valve_Is_Open = false;
  mcp.digitalWrite(Valve_0_Enable, 0);
  mcp.digitalWrite(Valve_1_Enable, 0);
  mcp.digitalWrite(Valve_2_Enable, 0);
  mcp.digitalWrite(Valve_3_Enable, 0);
  mcp.digitalWrite(Valve_4_Enable, 0);
  mcp.digitalWrite(Valve_5_Enable, 0);
}

void TIME_VALVE_CFG_Struct_Set()
{
  TIME_VALVE_CFG[0].Valve_ID = VALVE0;          //Do not care because for loop never looks at TIME_VALVE_CFG[0]
  TIME_VALVE_CFG[0].Vale_Time_String = "empty"; //Do not care because for loop never looks at TIME_VALVE_CFG[0]
  TIME_VALVE_CFG[0].Valve_Open_Sec = 0;         //Do not care because for loop never looks at TIME_VALVE_CFG[0]
  
  TIME_VALVE_CFG[1].Valve_ID = VALVE1;
  TIME_VALVE_CFG[1].Vale_Time_String = WS.Plant1_Time;
  TIME_VALVE_CFG[1].Valve_Open_Sec = WS.Plant1_Valve_Open_Sec; 

  TIME_VALVE_CFG[2].Valve_ID = VALVE2;
  TIME_VALVE_CFG[2].Vale_Time_String = WS.Plant2_Time;
  TIME_VALVE_CFG[2].Valve_Open_Sec = WS.Plant2_Valve_Open_Sec; 

  TIME_VALVE_CFG[3].Valve_ID = VALVE3;
  TIME_VALVE_CFG[3].Vale_Time_String = WS.Plant3_Time;
  TIME_VALVE_CFG[3].Valve_Open_Sec = WS.Plant3_Valve_Open_Sec; 

  TIME_VALVE_CFG[4].Valve_ID = VALVE4;
  TIME_VALVE_CFG[4].Vale_Time_String = WS.Plant4_Time;
  TIME_VALVE_CFG[4].Valve_Open_Sec = WS.Plant4_Valve_Open_Sec; 

  TIME_VALVE_CFG[5].Valve_ID = VALVE5;
  TIME_VALVE_CFG[5].Vale_Time_String = WS.Plant5_Time;
  TIME_VALVE_CFG[5].Valve_Open_Sec = WS.Plant5_Valve_Open_Sec; 
}
