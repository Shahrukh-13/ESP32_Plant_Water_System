#include "Define.h" 

void Init_IO()
{
  pinMode(TestMode_LED, OUTPUT);
  pinMode(HeartBeat_LED, OUTPUT);
  pinMode(WiFi_Status_LED, OUTPUT);
  pinMode(DrainSensor_Bypass_LED, OUTPUT);
  pinMode(Drain_Bottle_Full_LED, OUTPUT);

  #ifndef SERIAL_DEBUG
    pinMode(Drain_Motor_Enable, OUTPUT);
    pinMode(Refill_Motor_Enable, OUTPUT);
  #endif
  
  pinMode(Refill_Bottle_Empty_LED, OUTPUT);


  pinMode(Switch_ExternalRefill, INPUT);
  pinMode(Switch_TestMode, INPUT);
  pinMode(Switch_LowLevel_Sensor_Bypass, INPUT);
  pinMode(Button_TestMode_ValveEnable, INPUT);
  pinMode(Switch_ExternalDrain, INPUT);
  pinMode(HEX_8, INPUT);
  pinMode(HEX_4, INPUT);
  pinMode(HEX_2, INPUT);
  pinMode(HEX_1, INPUT);
  pinMode(WaterLevel_RefillBottle_Empty, INPUT);
  pinMode(WaterLevel_DrainBottle_Full, INPUT);
  pinMode(WaterLevel_Tank_Low, INPUT);
  pinMode(WaterLevel_Tank_Full, INPUT);
  
  // Initialize MCP23017
  if (!mcp.begin_I2C(0x20)) // A0:0, A1:0, A2:0
  {
    #ifdef SERIAL_DEBUG
      Serial.println("Error connecting to MCP23017");
    #endif
    while (1);
  }

  // Configure GPA as Output
  mcp.pinMode(Harp_LED_0, OUTPUT);
  mcp.pinMode(Harp_LED_1, OUTPUT);
  mcp.pinMode(Harp_LED_2, OUTPUT);
  mcp.pinMode(Harp_LED_3, OUTPUT);
  mcp.pinMode(Harp_LED_4, OUTPUT);
  mcp.pinMode(Change_Tank_Water_LED, OUTPUT);
  mcp.pinMode(NU_3, OUTPUT);
  mcp.pinMode(NU_2, OUTPUT);

  mcp.pinMode(Valve_0_Enable, OUTPUT);
  mcp.pinMode(Valve_1_Enable, OUTPUT);
  mcp.pinMode(Valve_2_Enable, OUTPUT);
  mcp.pinMode(Valve_3_Enable, OUTPUT);
  mcp.pinMode(Valve_4_Enable, OUTPUT);
  mcp.pinMode(Valve_5_Enable, OUTPUT);          
  mcp.pinMode(NU_0, OUTPUT);
  mcp.pinMode(NU_1, OUTPUT);
}

void Set_All_Digital_Outputs_Low()
{
  digitalWrite(TestMode_LED, LOW);
  digitalWrite(HeartBeat_LED, LOW);
  digitalWrite(WiFi_Status_LED, LOW);
  digitalWrite(DrainSensor_Bypass_LED, LOW);
  digitalWrite(Drain_Bottle_Full_LED, LOW);
  
  digitalWrite(Drain_Motor_Enable, LOW);
  digitalWrite(Refill_Motor_Enable, LOW);
  
  digitalWrite(Refill_Bottle_Empty_LED, LOW);
  
  mcp.digitalWrite(Harp_LED_0, LOW);
  mcp.digitalWrite(Harp_LED_1, LOW);
  mcp.digitalWrite(Harp_LED_2, LOW);
  mcp.digitalWrite(Harp_LED_3, LOW);
  mcp.digitalWrite(Harp_LED_4, LOW);
  mcp.digitalWrite(Change_Tank_Water_LED, LOW);
  mcp.digitalWrite(NU_3, LOW);
  mcp.digitalWrite(NU_2, LOW);
  mcp.digitalWrite(Valve_0_Enable, LOW);
  mcp.digitalWrite(Valve_1_Enable, LOW);
  mcp.digitalWrite(Valve_2_Enable, LOW);
  mcp.digitalWrite(Valve_3_Enable, LOW);
  mcp.digitalWrite(Valve_4_Enable, LOW);
  mcp.digitalWrite(Valve_5_Enable, LOW);
  mcp.digitalWrite(NU_0, LOW);
  mcp.digitalWrite(NU_1, LOW);
}


void Set_Leds()
{
  //HeartBeat LED
  digitalWrite(HeartBeat_LED, AC.HeartBeat_Toggle); 

  //App Mode LED
  if(AC.State == APP_STATE_NORMAL)
  {
    digitalWrite(TestMode_LED, LOW);
  }
  else
  {
    digitalWrite(TestMode_LED, HIGH);
  }
  
  //Low Level Sensor Bypass LED
  if(AC.LowLevel_Sensor_Bypass_Val == 0)
  {
    digitalWrite(DrainSensor_Bypass_LED, LOW);
  }
  else
  {
    digitalWrite(DrainSensor_Bypass_LED, HIGH);
  }

  //Drain Bottle Full LED
  if(EBS.Drain_Bottle_Full_Val == 0)
  {
    digitalWrite(Drain_Bottle_Full_LED, LOW);
  }
  else
  {
    digitalWrite(Drain_Bottle_Full_LED, HIGH);
  }

  //Drain Bottle Empty LED
  if(EBS.Refill_Bottle_Empty_Val == 0)
  {
    digitalWrite(Refill_Bottle_Empty_LED, LOW);
  }
  else
  {
    digitalWrite(Refill_Bottle_Empty_LED, HIGH);
  }
}
