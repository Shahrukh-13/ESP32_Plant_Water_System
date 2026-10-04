#include <Wire.h>
#include <Adafruit_MCP23X17.h>

Adafruit_MCP23X17 mcp;

//ESP32 Digital IO
#define TestMode_LED                    15
#define HeartBeat_LED                   2
#define WiFi_Status_LED                 0
#define DrainSensor_Bypass_LED          4
#define Drain_Bottle_Full_LED           16
#define Switch_ExternalRefill           17
#define Switch_TestMode                 5
#define Switch_LowLevel_Sensor_Bypass   18
#define Button_TestMode_ValveEnable     19
#define Drain_Motor_Enable              3
#define Refill_Motor_Enable             1
#define Refill_Bottle_Empty_LED         23
#define Switch_ExternalDrain            36
#define HEX_8                           39
#define HEX_4                           34
#define HEX_2                           35
#define HEX_1                           32
#define WaterLevel_RefillBottle_Empty   27
#define WaterLevel_DrainBottle_Full     14
#define WaterLevel_Tank_Low             12
#define WaterLevel_Tank_Full            13

//MCP A
#define Harp_LED_0                      0
#define Harp_LED_1                      1
#define Harp_LED_2                      2
#define Harp_LED_3                      3
#define Harp_LED_4                      4
#define Change_Tank_Water_LED           5
#define NU_3                            6
#define NU_2                            7
//MCP B
#define Valve_0_Enable                  8
#define Valve_1_Enable                  9
#define Valve_2_Enable                  10
#define Valve_3_Enable                  11
#define Valve_4_Enable                  12
#define Valve_5_Enable                  13          
#define NU_0                            14
#define NU_1                            15

uint8_t Hex_Val;

void setup() 
{
  //Serial.begin(115200);
  pinMode(TestMode_LED, OUTPUT);
  pinMode(HeartBeat_LED, OUTPUT);
  pinMode(WiFi_Status_LED, OUTPUT);
  pinMode(DrainSensor_Bypass_LED, OUTPUT);
  pinMode(Drain_Bottle_Full_LED, OUTPUT);
  pinMode(Drain_Motor_Enable, OUTPUT);
  pinMode(Refill_Motor_Enable, OUTPUT);
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
    Serial.println("Error connecting to MCP23017");
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
   
  Hex_Val = 0;
}

void loop() 
{
  if(!digitalRead(WaterLevel_Tank_Full))
  {
    digitalWrite(TestMode_LED, HIGH);
  }
  else
  {
    digitalWrite(TestMode_LED, LOW);
  }

  if(!digitalRead(WaterLevel_DrainBottle_Full))
  {
    digitalWrite(HeartBeat_LED, HIGH);
  }
  else
  {
    digitalWrite(HeartBeat_LED, LOW);
  }

  if(!digitalRead(WaterLevel_Tank_Low))
  {
    digitalWrite(WiFi_Status_LED, HIGH);
  }
  else
  {
    digitalWrite(WiFi_Status_LED, LOW);
  }

  if(!digitalRead(WaterLevel_RefillBottle_Empty))
  {
    digitalWrite(DrainSensor_Bypass_LED, HIGH);
  }
  else
  {
    digitalWrite(DrainSensor_Bypass_LED, LOW);
  }

  if(digitalRead(Switch_ExternalDrain))
  {
    digitalWrite(Drain_Bottle_Full_LED, HIGH);
  }
  else
  {
    digitalWrite(Drain_Bottle_Full_LED, LOW);
  }
  
  if(digitalRead(Switch_ExternalRefill))
  {
    digitalWrite(Drain_Motor_Enable, HIGH);
  }
  else
  {
    digitalWrite(Drain_Motor_Enable, LOW);
  }

  if(digitalRead(Switch_TestMode))
  {
    //digitalWrite(Refill_Motor_Enable, HIGH);
  }
  else
  {
    //digitalWrite(Refill_Motor_Enable, LOW);
  }

  if(digitalRead(Switch_LowLevel_Sensor_Bypass))
  {
    digitalWrite(Refill_Bottle_Empty_LED, HIGH);
  }
  else
  {
    digitalWrite(Refill_Bottle_Empty_LED, LOW);
  }


  Hex_Encoder_Get();
  //Serial.println(Hex_Val);
  if(Hex_Val == 0)
  {
    //Serial.println("HEX 0");
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
  else if(Hex_Val == 1)
  {
    //Serial.println("HEX 1");
    mcp.digitalWrite(Harp_LED_0, HIGH);
  }
  else if(Hex_Val == 2)
  {
    //Serial.println("HEX 2");
    mcp.digitalWrite(Harp_LED_1, HIGH);
  }
  else if(Hex_Val == 3)
  {
    //Serial.println("HEX 3");
    mcp.digitalWrite(Harp_LED_2, HIGH);
  }
  else if(Hex_Val == 4)
  {
    //Serial.println("HEX 4");
    mcp.digitalWrite(Harp_LED_3, HIGH);
  }
  else if(Hex_Val == 5)
  {
    //Serial.println("HEX 5");
    mcp.digitalWrite(Harp_LED_4, HIGH);
  }
  else if(Hex_Val == 6)
  {
    //Serial.println("HEX 6");
    mcp.digitalWrite(Change_Tank_Water_LED, HIGH);
  }
  else if(Hex_Val == 7)
  {
    //Serial.println("HEX 7");
    mcp.digitalWrite(NU_3, HIGH);
  }
  else if(Hex_Val == 8)
  {
    //Serial.println("HEX 8");
    mcp.digitalWrite(NU_2, HIGH);
  }
  else if(Hex_Val == 9)
  {
    //Serial.println("HEX 9");
    mcp.digitalWrite(Valve_0_Enable, HIGH);
  }
  else if(Hex_Val == 10)
  {
    //Serial.println("HEX 10");
    mcp.digitalWrite(Valve_1_Enable, HIGH);
  }
  else if(Hex_Val == 11)
  {
    //Serial.println("HEX 11");
    mcp.digitalWrite(Valve_2_Enable, HIGH);
  }
  else if(Hex_Val == 12)
  {
    //Serial.println("HEX 12");
    mcp.digitalWrite(Valve_3_Enable, HIGH);
  }
  else if(Hex_Val == 13)
  {
    //Serial.println("HEX 13");
    mcp.digitalWrite(Valve_4_Enable, HIGH);
  }
  else if(Hex_Val == 14)
  {
    //Serial.println("HEX 14");
    mcp.digitalWrite(Valve_5_Enable, HIGH);
  }
  else if(Hex_Val == 15)
  {
    //Serial.println("HEX 15");
    mcp.digitalWrite(NU_0, HIGH); 
  }
  /*else if(Hex_Val == 16)
  {
    mcp.digitalWrite(NU_1, HIGH);
  }*/
}

void Hex_Encoder_Get()
{
  Hex_Val = ((digitalRead(HEX_8) << 3) |
             (digitalRead(HEX_4) << 2) | 
             (digitalRead(HEX_2) << 1) |
              digitalRead(HEX_1));  
}
