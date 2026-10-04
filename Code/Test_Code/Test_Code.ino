#include <Wire.h>
#include <Adafruit_MCP23X17.h>

Adafruit_MCP23X17 mcp;

#define TOTAL_ESP_DIGITAL_OUTPUT_PINS 8
#define TOTAL_ESP_DIGITAL_INPUT_PINS  13

uint8_t ESP_DigitalOut_Pin_Num[TOTAL_ESP_DIGITAL_OUTPUT_PINS]= {15, 2, 0, 4, 16, 3, 1, 23};

struct ESP_DigitalIn 
{
  uint8_t Pin_Num[TOTAL_ESP_DIGITAL_INPUT_PINS]= {17, 5, 18, 19, 36, 39, 34, 35, 32, 27, 14, 12, 13};
  uint8_t Pin_Val[TOTAL_ESP_DIGITAL_INPUT_PINS]= {0 , 0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 }; 
};

//uint8_t ESP_DigitalIn_Pin_Num[TOTAL_ESP_DIGITAL_INPUT_PINS]= {17, 5, 18, 19, 36, 39, 34, 35, 32, 27, 14, 12, 13};


#define TOTAL_MSP_DIGITAL_OUTPUT_PINS  16

uint8_t MCP_DigitalOut_Pin_Num[TOTAL_MSP_DIGITAL_OUTPUT_PINS]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

uint8_t Hex_Val;

ESP_DigitalIn  ESP_DigitalIn;

void setup() 
{
  for(uint8_t i=0; i<TOTAL_ESP_DIGITAL_OUTPUT_PINS; i++)
  {
    pinMode(ESP_DigitalOut_Pin_Num[i],OUTPUT);
    digitalWrite(ESP_DigitalOut_Pin_Num[i], LOW);
  }

  for(uint8_t i=0; i<TOTAL_ESP_DIGITAL_INPUT_PINS; i++)
  {
    pinMode(ESP_DigitalIn.Pin_Num[i],INPUT);
  }

  // Initialize MCP23017
  if (!mcp.begin_I2C(0x20)) // A0:0, A1:0, A2:0
  {
    Serial.println("Error connecting to MCP23017");
    while (1);
  }

  for(uint8_t i=0; i<TOTAL_MSP_DIGITAL_OUTPUT_PINS; i++)
  {
    mcp.pinMode(MCP_DigitalOut_Pin_Num[i], OUTPUT);
    mcp.digitalWrite(MCP_DigitalOut_Pin_Num[i], LOW);
  }
  Serial.println("MCP23017 Initialized");
  
  Hex_Val = 0;
}

void loop() 
{
  Read_ESP_Digital_Pins();

  digitalWrite(ESP_DigitalOut_Pin_Num[0], HIGH);
}

void Hex_Encoder_Loop()
{
  Hex_Val = ((digitalRead(39) << 3) |
             (digitalRead(34) << 2) | 
             (digitalRead(35) << 1) |
              digitalRead(32));  
}

void Read_ESP_Digital_Pins()
{
  for(uint8_t i=0; i<TOTAL_ESP_DIGITAL_INPUT_PINS; i++)
  {
    ESP_DigitalIn.Pin_Val[i] = digitalRead(ESP_DigitalIn.Pin_Num[i]);
  }
}
