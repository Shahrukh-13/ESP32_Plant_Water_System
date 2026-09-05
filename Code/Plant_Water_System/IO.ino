#include "Define.h" 

typedef enum 
{
  GPIO_INPUT = 0,
  GPIO_OUTPUT,
}gpio_dir_t;

typedef enum 
{
  GPIO_NOPULL = 0,
  GPIO_PULLUP,
  GPIO_PULLDOWN
}gpio_pull_t;

struct gpio_config
{
  uint8_t     Gpio_Pin;
  gpio_dir_t  Direction;
  gpio_pull_t Pull;
  bool        Init_Val;
};

struct gpio_config ESP32_GPIO[]= {
  {WiFi_Status_LED,               GPIO_OUTPUT,  GPIO_NOPULL, 0},
  #ifndef SERIAL_DEBUG
    {HeartBeat_LED,                 GPIO_OUTPUT,  GPIO_NOPULL, 0},
  #endif
  {Refill_Motor_Enable,           GPIO_OUTPUT,  GPIO_NOPULL, 0},
  #ifndef SERIAL_DEBUG
    {Refill_Bottle_Empty_LED,       GPIO_OUTPUT,  GPIO_NOPULL, 0},
  #endif 
  {DrainSensor_Bypass_LED,        GPIO_OUTPUT,  GPIO_NOPULL, 0},
  {Switch_TestMode,               GPIO_INPUT,   GPIO_NOPULL, 0},  //External Pulldown
  {WaterLevel_Tank_Low,           GPIO_INPUT,   GPIO_NOPULL, 1},  //External Pullup
  {WaterLevel_Tank_Full,          GPIO_INPUT,   GPIO_NOPULL, 1},  //External Pullup
  {WaterLevel_DrainBottle_Full,   GPIO_INPUT,   GPIO_NOPULL, 0},  //External Pullup
  {TestMode_LED,                  GPIO_OUTPUT,  GPIO_NOPULL, 0},
  {Drain_Bottle_Full_LED,         GPIO_OUTPUT,  GPIO_NOPULL, 0},
  {Switch_ExternalRefill,         GPIO_INPUT,   GPIO_NOPULL, 0},  //External Pulldown
  {Switch_LowLevel_Sensor_Bypass, GPIO_INPUT,   GPIO_NOPULL, 0},  //External Pulldown
  {Button_TestMode_ValveEnable,   GPIO_INPUT,   GPIO_NOPULL, 0},  //External Pulldown
  {Drain_Motor_Enable,            GPIO_OUTPUT,  GPIO_NOPULL, 0},
  {WaterLevel_RefillBottle_Empty, GPIO_INPUT,   GPIO_NOPULL, 1},  //External Pullup
  {HEX_1,                         GPIO_INPUT,   GPIO_NOPULL, 0},  //External Pulldown
  {HEX_4,                         GPIO_INPUT,   GPIO_NOPULL, 0},  //External Pulldown
  {HEX_2,                         GPIO_INPUT,   GPIO_NOPULL, 0},  //External Pulldown
  {Switch_ExternalDrain,          GPIO_INPUT,   GPIO_NOPULL, 0},  //External Pulldown
  {HEX_8,                         GPIO_INPUT,   GPIO_NOPULL, 0}   //External Pulldown
};

#define NUMBER_OF_ESP_GPIO  (sizeof(ESP32_GPIO))/(sizeof(ESP32_GPIO[0]))

struct gpio_config MCP_GPIO[]= {
  //MCP PORT A
  {Harp_LED_0,                    GPIO_OUTPUT,  GPIO_NOPULL, 0},
  {Harp_LED_1,                    GPIO_OUTPUT,  GPIO_NOPULL, 0},
  {Harp_LED_2,                    GPIO_OUTPUT,  GPIO_NOPULL, 0},
  {Harp_LED_3,                    GPIO_OUTPUT,  GPIO_NOPULL, 0},
  {Harp_LED_4,                    GPIO_OUTPUT,  GPIO_NOPULL, 0},
  {Change_Tank_Water_LED,         GPIO_OUTPUT,  GPIO_NOPULL, 0}, 
  {NU_3,                          GPIO_OUTPUT,  GPIO_NOPULL, 0},  
  {NU_2,                          GPIO_OUTPUT,  GPIO_NOPULL, 0},  
  
  //MCP PORT B
  {Valve_0_Enable,                GPIO_OUTPUT,  GPIO_NOPULL, 0},  
  {Valve_1_Enable,                GPIO_OUTPUT,  GPIO_NOPULL, 0},
  {Valve_2_Enable,                GPIO_OUTPUT,  GPIO_NOPULL, 0},
  {Valve_3_Enable,                GPIO_OUTPUT,  GPIO_NOPULL, 0},  
  {Valve_4_Enable,                GPIO_OUTPUT,  GPIO_NOPULL, 0},  
  {Valve_5_Enable,                GPIO_OUTPUT,  GPIO_NOPULL, 0},  
  {NU_0,                          GPIO_OUTPUT,  GPIO_NOPULL, 0}, 
  {NU_1,                          GPIO_OUTPUT,  GPIO_NOPULL, 0}
};

#define NUMBER_OF_MCP_GPIO  (sizeof(MCP_GPIO))/(sizeof(MCP_GPIO[0]))

void IO_Init()
{
  ESP32_Gpio_Init();
  MCP_Gpio_Init();
}

void ESP32_Gpio_Init()
{
  for(uint8_t i=0; i<NUMBER_OF_ESP_GPIO; i++)
  {
    if(ESP32_GPIO[i].Direction == GPIO_INPUT)
    {
      if(ESP32_GPIO[i].Pull == GPIO_NOPULL)
      {
        pinMode(ESP32_GPIO[i].Gpio_Pin, INPUT);
      }
      else if(ESP32_GPIO[i].Pull == GPIO_PULLUP)
      {
        pinMode(ESP32_GPIO[i].Gpio_Pin, INPUT_PULLUP);
      }
      else if(ESP32_GPIO[i].Pull == GPIO_PULLDOWN) 
      {
        pinMode(ESP32_GPIO[i].Gpio_Pin, INPUT_PULLDOWN);
      }
    }
    else if(ESP32_GPIO[i].Direction == GPIO_OUTPUT)
    {
      pinMode(ESP32_GPIO[i].Gpio_Pin, OUTPUT);
      digitalWrite(ESP32_GPIO[i].Gpio_Pin, ESP32_GPIO[i].Init_Val);
    }
    else
    {
      /*Do Nothing*/
    }
  }
}

void MCP_Gpio_Init()
{
  // Initialize MCP23017
  if (!mcp.begin_I2C(0x20)) // A0:0, A1:0, A2:0
  {
    #ifdef SERIAL_DEBUG
      Serial.println("Error connecting to MCP23017");
    #endif
    while (1);
  }
  
  for(uint8_t i=0; i<NUMBER_OF_MCP_GPIO; i++)
  {
    if(MCP_GPIO[i].Direction == GPIO_INPUT)
    {
      if(MCP_GPIO[i].Pull == GPIO_NOPULL)
      {
        mcp.pinMode(MCP_GPIO[i].Gpio_Pin, INPUT);
      }
      else if(MCP_GPIO[i].Pull == GPIO_PULLUP)
      {
        mcp.pinMode(MCP_GPIO[i].Gpio_Pin, INPUT_PULLUP);
      }
      else if(MCP_GPIO[i].Pull == GPIO_PULLDOWN) // MCP23017 does not have internal pulldown 
      {
        mcp.pinMode(MCP_GPIO[i].Gpio_Pin, INPUT);
      }
    }
    else if(MCP_GPIO[i].Direction == GPIO_OUTPUT)
    {
      mcp.pinMode(MCP_GPIO[i].Gpio_Pin, OUTPUT);
      mcp.digitalWrite(MCP_GPIO[i].Gpio_Pin, MCP_GPIO[i].Init_Val);
    }
    else
    {
      /*Do Nothing*/
    }
  }
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

void Hex_Encoder_Get()
{
  bool Hex_1_Val = digitalRead(HEX_1);
  bool Hex_2_Val = digitalRead(HEX_2);
  bool Hex_4_Val = digitalRead(HEX_4);
  bool Hex_8_Val = digitalRead(HEX_8);
  
  AC.Hex_Encoder_Val = ((Hex_8_Val << 3) |
                        (Hex_4_Val << 2) | 
                        (Hex_2_Val << 1) |
                         Hex_1_Val);  
}
