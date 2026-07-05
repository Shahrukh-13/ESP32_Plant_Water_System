typedef enum
{
  WATER_LEVEL_LOW = 0,
  WATER_LEVEL_NOT_FULL,
  WATER_LEVEL_FULL
}water_level_state;

struct water_level
{
  water_level_state State;
  bool Sensor1_Val;
  bool Sensor2_Val;
};

struct water_level WL;

void setup() 
{
  Water_Level_Sensor_Init();
}

void loop() 
{
  Water_Level_Loop();
  if(WL.State != WATER_LEVEL_LOW)
  {
    Serial.println("Motor Run");
  }
  else
  {
    Serial.println("Motor Stop");
  }
}

void Water_Level_Sensor_Init()
{
  pinMode(13, INPUT);
  pinMode(12, INPUT);

  WL.Sensor1_Val = 1;
  WL.Sensor2_Val= 1;
  WL.State = WATER_LEVEL_LOW;
}


void Water_Level_Loop()
{
  WL.Sensor1_Val = digitalRead(13);
  WL.Sensor2_Val = digitalRead(12);

  switch(WL.State)
  {
    case WATER_LEVEL_LOW:
      if (WL.Sensor1_Val == 1 && WL.Sensor2_Val == 1)
      {
        WL.State = WATER_LEVEL_LOW;
      }
      else if(WL.Sensor1_Val == 1 && WL.Sensor2_Val == 0)
      {
        WL.State = WATER_LEVEL_NOT_FULL; 
      }
    break;
    
    case WATER_LEVEL_NOT_FULL:
      if (WL.Sensor1_Val == 1 && WL.Sensor2_Val == 1)
      {
        WL.State = WATER_LEVEL_LOW;
      }
      else if(WL.Sensor1_Val == 1 && WL.Sensor2_Val == 0)
      {
        WL.State = WATER_LEVEL_NOT_FULL; 
      }
      else if(WL.Sensor1_Val == 0 && WL.Sensor2_Val == 0)
      {
        WL.State = WATER_LEVEL_FULL; 
      }
    break;
    
    case WATER_LEVEL_FULL:
      if(WL.Sensor1_Val == 1 && WL.Sensor2_Val == 0)
      {
        WL.State = WATER_LEVEL_NOT_FULL; 
      }
      if(WL.Sensor1_Val == 0 && WL.Sensor2_Val == 0)
      {
        WL.State = WATER_LEVEL_FULL; 
      }
    break;
    
    default:
      /*Do Nothing*/
    break;
  }
}
