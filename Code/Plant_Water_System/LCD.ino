#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH      128 // OLED display width, in pixels
#define SCREEN_HEIGHT     64 // OLED display height, in pixels

#define SSD1306_ADDRESS   0x3C

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void LCD_Init()
{
  if(!display.begin(SSD1306_SWITCHCAPVCC, SSD1306_ADDRESS)) 
  { 
    #ifdef SERIAL_DEBUG 
      Serial.println("Error connecting to SSD1306");
    #endif
    while(1);
  }
  delay(1000);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  LCD__Clear();
}

void LCD__Clear()
{
  display.clearDisplay();
  display.setCursor(0,0);
}

void LCD_Write(uint8_t x, uint8_t y, String str)
{
  if(x > SCREEN_WIDTH)
  {
    x = SCREEN_WIDTH;
  }
  else
  {
    /*Do Nothing*/
  }

  if(y > SCREEN_HEIGHT)
  {
    y = SCREEN_HEIGHT;
  }
  else
  {
    /*Do Nothing*/
  }

  display.setCursor(x,y);
  display.print(str);
  display.display(); 
}

void LCD_Display_App_Stats()
{
  char buffer[150];
  LCD__Clear();
  
  /*Standard sprintf() can easily crash your board if the formatted text exceeds the size of your allocated char array (a buffer overflow). 
  Using snprintf() limits the characters written, ensuring it never goes out of bounds*/
  snprintf(buffer, sizeof(buffer), "App Mode: %s\n" 
                                   "Water Level: %s\n"
                                   "Valve Open: %s\n"
                                   "Valve ID: %s\n"
                                   "Drain Switch: %d\n"
                                   "Refill Switch: %d\n"
                                   "Drain Motor good: %d\n"
                                   "Refill Motor good: %d",
                                   (AC.Test_Mode_Switch_Val == 0) ? "Normal" : "Test",
                                   (WL.State == WATER_LEVEL_LOW) ? "Low" : (WL.State == WATER_LEVEL_NOT_FULL) ? "Not Full" : "Full",
                                   (AC.Valve_Is_Open == false) ? "No" : "Yes",
                                   (AC.Hex_Encoder_Val >5) ? "None" : String(AC.Hex_Encoder_Val).c_str(),
                                   MS[MOTOR_DRAIN].Motor_Switch_val,
                                   MS[MOTOR_REFILL].Motor_Switch_val,
                                   MS[MOTOR_DRAIN].Motor_Good_To_Run,
                                   MS[MOTOR_REFILL].Motor_Good_To_Run);
  LCD_Write(0, 0, String(buffer));
}
