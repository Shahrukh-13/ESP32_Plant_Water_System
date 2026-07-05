#include "Define.h" 

void Water_Level_Sensor_Init()
{
  MC.LowLevel_Sensor_Bypass_Val = 0;  // LowLevel Sensor Bypass mode OFF
  WL.Sensor_Full_Val = 1;             // Low  (Sensor is configured an normally open)
  WL.Sensor_Low_Val= 1;               // Low  (Sensor is configured an normally open)
  WL.State = WATER_LEVEL_LOW;
}


void Water_Level_Loop()
{
  MC.LowLevel_Sensor_Bypass_Val = digitalRead(Switch_LowLevel_Sensor_Bypass);
  WL.Sensor_Full_Val = digitalRead(WaterLevel_Tank_Full);
  WL.Sensor_Low_Val  = digitalRead(WaterLevel_Tank_Low);

  switch(WL.State)
  {
    case WATER_LEVEL_LOW:
      if (WL.Sensor_Full_Val == 1 && WL.Sensor_Low_Val == 1)
      {
        if(MC.LowLevel_Sensor_Bypass_Val == 0)
        {
          MS[MOTOR_DRAIN].Motor_Good_To_Run = false;
        }
        else
        {
          MS[MOTOR_DRAIN].Motor_Good_To_Run = true;
        }
    
        MS[MOTOR_REFILL].Motor_Good_To_Run = true;
        WL.State = WATER_LEVEL_LOW;
        /*Serial.print(MC.LowLevel_Sensor_Bypass_Val);
        Serial.print(" : ");
        Serial.print(MS[MOTOR_DRAIN].Motor_Good_To_Run);*/
      }
      else if(WL.Sensor_Full_Val == 1 && WL.Sensor_Low_Val == 0)
      {
        MS[MOTOR_DRAIN].Motor_Good_To_Run = true;
        MS[MOTOR_REFILL].Motor_Good_To_Run = true;
        WL.State = WATER_LEVEL_NOT_FULL; 
      }
    break;
    
    case WATER_LEVEL_NOT_FULL:
      if (WL.Sensor_Full_Val == 1 && WL.Sensor_Low_Val == 1)
      {
        MS[MOTOR_DRAIN].Motor_Good_To_Run = false;
        MS[MOTOR_REFILL].Motor_Good_To_Run = true;
        WL.State = WATER_LEVEL_LOW;
      }
      else if(WL.Sensor_Full_Val == 1 && WL.Sensor_Low_Val == 0)
      {
        MS[MOTOR_DRAIN].Motor_Good_To_Run = true;
        MS[MOTOR_REFILL].Motor_Good_To_Run = true;
        WL.State = WATER_LEVEL_NOT_FULL; 
      }
      else if(WL.Sensor_Full_Val == 0 && WL.Sensor_Low_Val == 0)
      {
        MS[MOTOR_DRAIN].Motor_Good_To_Run = true;
        MS[MOTOR_REFILL].Motor_Good_To_Run = false;
        WL.State = WATER_LEVEL_FULL; 
      }
    break;
    
    case WATER_LEVEL_FULL:
      if(WL.Sensor_Full_Val == 1 && WL.Sensor_Low_Val == 0)
      {
        MS[MOTOR_DRAIN].Motor_Good_To_Run = true;
        MS[MOTOR_REFILL].Motor_Good_To_Run = true;
        WL.State = WATER_LEVEL_NOT_FULL; 
      }
      if(WL.Sensor_Full_Val == 0 && WL.Sensor_Low_Val == 0)
      {
        MS[MOTOR_DRAIN].Motor_Good_To_Run = true;
        MS[MOTOR_REFILL].Motor_Good_To_Run = false;
        WL.State = WATER_LEVEL_FULL; 
      }
    break;
    
    default:
      /*Do Nothing*/
    break;
  }
}
