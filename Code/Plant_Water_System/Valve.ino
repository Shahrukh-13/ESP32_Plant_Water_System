#include "Define.h" 

typedef enum 
{
  VALVE0 = 0,
  VALVE1,
  VALVE2,
  VALVE3,
  VALVE4,
  VALVE5,
  VALVE_NONE,
  VALVE_MAX
}valve_id_t;

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
