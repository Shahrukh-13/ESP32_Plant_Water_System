#include "Define.h" 

void Hex_Encoder_Init()
{
  HE.Hex_1_Val = 0;
  HE.Hex_2_Val = 0;
  HE.Hex_4_Val = 0;
  HE.Hex_8_Val = 0;
  HE.Hex_Encoder_Val = 0;
}
void Hex_Encoder_Get()
{
  HE.Hex_1_Val = digitalRead(HEX_1);
  HE.Hex_2_Val = digitalRead(HEX_2);
  HE.Hex_4_Val = digitalRead(HEX_4);
  HE.Hex_8_Val = digitalRead(HEX_8);
  
  HE.Hex_Encoder_Val = ((HE.Hex_8_Val << 3) |
                        (HE.Hex_4_Val << 2) | 
                        (HE.Hex_2_Val << 1) |
                         HE.Hex_1_Val);  
}
