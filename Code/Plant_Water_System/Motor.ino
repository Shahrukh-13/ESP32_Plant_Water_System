#include "Define.h" 

void Motor_Init()
{
  MS[MOTOR_DRAIN].Motor_Good_To_Run = false;
  MS[MOTOR_DRAIN].Motor_Enable = false;
  MS[MOTOR_DRAIN].State = MOTOR_STOP;

  MS[MOTOR_REFILL].Motor_Good_To_Run = false;
  MS[MOTOR_REFILL].Motor_Enable = false;
  MS[MOTOR_REFILL].State = MOTOR_STOP;

  EBS.Drain_Bottle_Full_Val = 1;      // Full  (Sensor is configured as normally closed)
  EBS.Refill_Bottle_Empty_Val = 1;    // Empty (Sensor is configured as normally open)
}

void Motor_Loop()
{
  MS[MOTOR_DRAIN].Motor_Switch_val = digitalRead(Switch_ExternalDrain);
  MS[MOTOR_REFILL].Motor_Switch_val = digitalRead(Switch_ExternalRefill);

  #ifdef SERIAL_DEBUG
    /*Serial.print(MS[MOTOR_DRAIN].Motor_Switch_val);
    Serial.print(" : ");
    Serial.print(MS[MOTOR_REFILL].Motor_Switch_val);*/
  #endif

  motor_id_t motor_id;
  
  for(uint8_t i=0; i<MOTOR_MAX ; i++)
  {
    motor_id = (motor_id_t) i;
    
    switch(MS[motor_id].State)
    {
      case MOTOR_RUN:
      case MOTOR_STOP:        
        if(MS[motor_id].Motor_Switch_val == 1)
        {
          if(MS[motor_id].Motor_Good_To_Run == 1)
          {
            MS[motor_id].Motor_Enable = true;
            MS[motor_id].State = MOTOR_RUN;
            Motor_Command(motor_id, true);
          }
          else
          {
            MS[motor_id].Motor_Enable = false;
            MS[motor_id].State = MOTOR_STOP;
            Motor_Command(motor_id, false);
          }
        }
        else
        {
          MS[motor_id].Motor_Enable = false;
          MS[motor_id].State = MOTOR_STOP;
          Motor_Command(motor_id, false);
        }
      break;

      default:
      /*Do Nothing*/
      break;
    }
  }
}

void Motor_Command(motor_id_t id, bool Enable)
{
  EBS.Drain_Bottle_Full_Val = digitalRead(WaterLevel_DrainBottle_Full);
  EBS.Refill_Bottle_Empty_Val = digitalRead(WaterLevel_RefillBottle_Empty);
  
  switch(id)
  {
    case MOTOR_DRAIN:
      if(Enable == true && AC.Valve_Is_Open == true)
      {
        if(EBS.Drain_Bottle_Full_Val == 0)
        {
          #ifdef SERIAL_DEBUG
            //Serial.print("Drain _Motor: Enable , ");
          #else
           digitalWrite(Drain_Motor_Enable, 1);
          #endif
        }
        else
        {
          #ifdef SERIAL_DEBUG
            //Serial.print("Drain _Motor: Stop , ");
          #else
           digitalWrite(Drain_Motor_Enable, 0);
          #endif
        }
      }
      else
      {
        #ifdef SERIAL_DEBUG
          //Serial.print("Drain _Motor: Stop , ");
        #else
          digitalWrite(Drain_Motor_Enable, 0);
        #endif
      }
    break;

    case MOTOR_REFILL:
      if(Enable == true)
      {
        if(EBS.Refill_Bottle_Empty_Val == 0)
        {
          #ifdef SERIAL_DEBUG
            //Serial.print("Refill_Motor: Enable , ");
          #else
            digitalWrite(Refill_Motor_Enable, 1);
          #endif
        }
        else
        {
          #ifdef SERIAL_DEBUG
            //Serial.print("Refill_Motor: Stop , ");
          #else
            digitalWrite(Refill_Motor_Enable, 0);
          #endif          
        }
      }
      else
      {
        #ifdef SERIAL_DEBUG
          //Serial.print("Refill_Motor: Stop , ");
        #else
          digitalWrite(Refill_Motor_Enable, 0);
        #endif
      }
    break;

    default:
    /*Do Nothing*/
    break;
  }
}
