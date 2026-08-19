#ifndef DEFINE_H
#define DEFINE_H

#include <Wire.h>
#include <Adafruit_MCP23X17.h>

//#define SERIAL_DEBUG

//ESP32 Digital IO
#define WiFi_Status_LED                 0
#define HeartBeat_LED                   1
#define Refill_Motor_Enable             2
#define Refill_Bottle_Empty_LED         3
#define DrainSensor_Bypass_LED          4
#define Switch_TestMode                 5
#define WaterLevel_Tank_Low             12
#define WaterLevel_Tank_Full            13
#define WaterLevel_DrainBottle_Full     14
#define TestMode_LED                    15
#define Drain_Bottle_Full_LED           16
#define Switch_ExternalRefill           17
#define Switch_LowLevel_Sensor_Bypass   18
#define Button_TestMode_ValveEnable     19
#define Drain_Motor_Enable              23
#define WaterLevel_RefillBottle_Empty   27
#define HEX_1                           32
#define HEX_4                           34
#define HEX_2                           35
#define Switch_ExternalDrain            36
#define HEX_8                           39
    

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


Adafruit_MCP23X17 mcp;

/******Typedefs****************************************/
typedef enum
{
  WATER_LEVEL_LOW = 0,
  WATER_LEVEL_NOT_FULL,
  WATER_LEVEL_FULL
}water_level_state_t;

typedef enum
{
  MOTOR_DRAIN = 0,
  MOTOR_REFILL,
  MOTOR_MAX
}motor_id_t;

typedef enum
{
  MOTOR_STOP = 0,
  MOTOR_RUN,
}motor_state_t;

typedef enum
{
  APP_STATE_NORMAL = 0,
  APP_STATE_TEST,
}app_state_t;
/*****************************************************/

/******Structures************************************/
struct water_level
{
  bool Sensor_Full_Val;
  bool Sensor_Low_Val;
  water_level_state_t State;
};

struct external_bottle_sensor
{
  bool Drain_Bottle_Full_Val;
  bool Refill_Bottle_Empty_Val;
};

struct motor_status
{
  bool Motor_Good_To_Run;
  bool Motor_Enable;
  bool Motor_Switch_val;
  motor_state_t State;
};

struct app_config
{
  app_state_t State;
  bool LowLevel_Sensor_Bypass_Val;
  bool Test_Mode_Switch_Val;
  bool HeartBeat_Toggle;
  uint8_t Hex_Encoder_Val;
  bool Test_Mode_Valve_Button_Val;
  bool Valve_Is_Open;
};

/****************************************************/

/*****Varriables*************************************/
struct water_level WL;
struct external_bottle_sensor EBS;
struct app_config AC;
struct motor_status MS[MOTOR_MAX];
/****************************************************/

#endif // DEFINE_H
