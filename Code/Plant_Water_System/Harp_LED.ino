#include "Define.h" 

typedef enum 
{
  HLED4 = 0,
  HLED3,
  HLED2,
  HLED1,
  HLED0,
  HLED_NONE,
  HLED_MAX
}harp_led_id_t;

struct harp_led_config
{
  harp_led_id_t  HLED_ID;
  bool  HLED0_Pin_Val;
  bool  HLED1_Pin_Val;
  bool  HLED2_Pin_Val;
  bool  HLED3_Pin_Val;
  bool  HLED4_Pin_Val;
};

struct harp_led_config HLED_CFG[]= {
  {HLED4,      0,  0,  0,  0,  1},
  {HLED3,      0,  0,  0,  1,  0},
  {HLED2,      0,  0,  1,  0,  0},
  {HLED1,      0,  1,  0,  0,  0},
  {HLED0,      1,  0,  0,  0,  0},
  {HLED_NONE,  0,  0,  0,  0,  0}
};

void Do_Harp_LED()
{
  for(uint8_t i=0 ; i<HLED_MAX ; i++)
  {
    mcp.digitalWrite(Harp_LED_4, HLED_CFG[i].HLED4_Pin_Val);
    mcp.digitalWrite(Harp_LED_3, HLED_CFG[i].HLED3_Pin_Val);
    mcp.digitalWrite(Harp_LED_2, HLED_CFG[i].HLED2_Pin_Val);
    mcp.digitalWrite(Harp_LED_1, HLED_CFG[i].HLED1_Pin_Val);
    mcp.digitalWrite(Harp_LED_0, HLED_CFG[i].HLED0_Pin_Val);
    delay(500);
  }
}
