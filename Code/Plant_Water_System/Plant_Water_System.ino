#include <Wire.h>
#include <Adafruit_MCP23X17.h>
#include "Define.h" 

void setup() 
{
  #ifdef SERIAL_DEBUG
    Serial.begin(115200);
  #endif
  Init_IO();
  Set_All_Digital_Outputs_Low();
  Hex_Encoder_Init();
  Water_Level_Sensor_Init();
  Timer_Init();
  Motor_Init();
}

void loop() 
{
  //Hex_Encoder_Get();
  //Serial.println(HE.Hex_Encoder_Val); 
  Water_Level_Loop();
  Motor_Loop();

  /*EBS.Drain_Bottle_Full_Val = digitalRead(WaterLevel_DrainBottle_Full);
  EBS.Refill_Bottle_Empty_Val = digitalRead(WaterLevel_RefillBottle_Empty);

  if(EBS.Refill_Bottle_Empty_Val == 1)
  {
    Serial.print("Refill_Bottle: Empty ,");
  }
  else
  {
    Serial.print("Refill_Bottle: Not Empty ,");
  }

  if(EBS.Drain_Bottle_Full_Val == 0)
  {
    Serial.print("Drain_Bottle: Not Full ,");
  }
  else
  {
    Serial.print("Drain_Bottle: Full ,");
  }*/
  #ifdef SERIAL_DEBUG
    Serial.print(WL.State);
    Serial.println();
  #endif
}
