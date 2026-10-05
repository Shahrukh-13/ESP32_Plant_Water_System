#include "Define.h" 

const char* PARAM_INPUT_1  = "input1";
const char* PARAM_INPUT_2  = "input2";
const char* PARAM_INPUT_3  = "input3";
const char* PARAM_INPUT_4  = "input4";
const char* PARAM_INPUT_5  = "input5";
const char* PARAM_INPUT_6  = "input6";
const char* PARAM_INPUT_7  = "input7";
const char* PARAM_INPUT_8  = "input8";
const char* PARAM_INPUT_9  = "input9";
const char* PARAM_INPUT_10 = "input10";
const char* PARAM_INPUT_11 = "input11";
const char* PARAM_INPUT_12 = "input12";
const char* PARAM_INPUT_13 = "input13";
const char* PARAM_INPUT_14 = "input14";
const char* PARAM_INPUT_15 = "input15";

String temp_str;
uint16_t temp_int;

void Update_WebPage()
{
  WS.html = "<!DOCTYPE HTML><html><head>";
  WS.html+= "<title>ESP Input Form</title>";
  WS.html+= "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  WS.html+= "<title>ESP Input Form</title>";
  WS.html+= "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  WS.html+= "</head><body>";

  // Heading: print connected network SSID
  WS.html+= "<h2>";
  WS.html+= "Connected to SSID: " + WC.ssid_str;
  WS.html+= "<br><br>"; //new line in heading
  WS.html+= "</h2>";

  // Heading: print connected network SSID
  WS.html+= "<h3>";
  WS.html+= "Saved SSID: " + WS.Saved_WiFi_SSID;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";
  
  // Input field for New WiFi SSID
  WS.html+= "<form action=\"/get\">";
  WS.html+= "New WiFi SSID: <input type=\"text\" name=\"input1\">";
  WS.html+= "<br><br>";
  
  // Input field for New WiFi Password
  WS.html+= "New WiFi Password: <input type=\"password\" name=\"input2\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Heading to display current saved Plant1 Time in EEPROM and saved Plant1 Valve Open Secons in EEPROM
  WS.html+= "<h3>";
  WS.html+= "Saved Plant1 Time: " + WS.Plant1_Time;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "Saved Plant1 Valve Open Seconds: " + String(WS.Plant1_Valve_Open_Sec);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";

  // Input field for New Plant1 Time and New Plant1 Valve Open Seconds
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant1 Time: <input type=\"text\" name=\"input3\" style=\"width: 300px;\">";   //style=\"height: 16px; width: 300px; font-size: 16px;\"
  WS.html+= "<br><br>";
  WS.html+= "Plant1 Valve Open Seconds: <input type=\"number\" name=\"input4\" min=\"1\" max=\"60\" value=\"5\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Heading to display current saved Plant2 Time in EEPROM and saved Plant2 Valve Open Secons in EEPROM
  WS.html+= "<h3>";
  WS.html+= "Saved Plant2 Time: " + WS.Plant2_Time;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "Saved Plant2 Valve Open Seconds: " + String(WS.Plant2_Valve_Open_Sec);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";

  // Input field for New Plant2 Time and New Plant2 Valve Open Seconds
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant2 Time: <input type=\"text\" name=\"input5\" style=\"width: 300px;\">";   //style=\"height: 16px; width: 300px; font-size: 16px;\"
  WS.html+= "<br><br>";
  WS.html+= "Plant2 Valve Open Seconds: <input type=\"number\" name=\"input6\" min=\"1\" max=\"60\" value=\"5\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Heading to display current saved Plant3 Time in EEPROM and saved Plant3 Valve Open Secons in EEPROM
  WS.html+= "<h3>";
  WS.html+= "Saved Plant3 Time: " + WS.Plant3_Time;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "Saved Plant3 Valve Open Seconds: " + String(WS.Plant3_Valve_Open_Sec);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";
  
  // Input field for New Plant3 Time and New Plant3 Valve Open Seconds
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant3 Time: <input type=\"text\" name=\"input7\" style=\"width: 300px;\">";   //style=\"height: 16px; width: 300px; font-size: 16px;\"
  WS.html+= "<br><br>";
  WS.html+= "Plant3 Valve Open Seconds: <input type=\"number\" name=\"input8\" min=\"1\" max=\"60\" value=\"5\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Heading to display current saved Plant4 Time in EEPROM and saved Plant4 Valve Open Secons in EEPROM
  WS.html+= "<h3>";
  WS.html+= "Saved Plant4 Time: " + WS.Plant4_Time;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "Saved Plant4 Valve Open Seconds: " + String(WS.Plant4_Valve_Open_Sec);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";
  
  // Input field for New Plant4 Time and New Plant4 Valve Open Seconds
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant4 Time: <input type=\"text\" name=\"input9\" style=\"width: 300px;\">";   //style=\"height: 16px; width: 300px; font-size: 16px;\"
  WS.html+= "<br><br>";
  WS.html+= "Plant4 Valve Open Seconds: <input type=\"number\" name=\"input10\" min=\"1\" max=\"60\" value=\"5\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Heading to display current saved Plant5 Time in EEPROM and saved Plant5 Valve Open Secons in EEPROM
  WS.html+= "<h3>";
  WS.html+= "Saved Plant5 Time: " + WS.Plant5_Time;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "Saved Plant5 Valve Open Seconds: " + String(WS.Plant5_Valve_Open_Sec);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";
  
  // Input field for New Plant5 Time and New Plant5 Valve Open Seconds
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant5 Time: <input type=\"text\" name=\"input11\" style=\"width: 300px;\">";   //style=\"height: 16px; width: 300px; font-size: 16px;\"
  WS.html+= "<br><br>";
  WS.html+= "Plant5 Valve Open Seconds: <input type=\"number\" name=\"input12\" min=\"1\" max=\"60\" value=\"5\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Heading to display current saved Audio Mute minutes in EEPROM
  WS.html+= "<h3>";
  WS.html+= "Saved Audio Mute Minutes: " + String(WS.Audio_Mute_Min);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";

  // Input field for New Audio Mute Minutes
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Audio Mute Minutes: <input type=\"number\" name=\"input13\" min=\"1\" max=\"60\" value=\"15\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Heading to display WiFi reconnect interval in seconds in EEPROM
  WS.html+= "<h3>";
  WS.html+= "WiFi Reconnect Seconds: " + String(WS.WiFi_Reconnect_Sec);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";

  // Input field for New WiFi Reconnect Seconds
  WS.html+= "<form action=\"/get\">";
  WS.html+= "WiFi Reconnect Seconds: <input type=\"number\" name=\"input14\" min=\"5\" max=\"240\" value=\"30\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Input button to Reset ESP32
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Reset ESP32: <input type=\"submit\" name=\"input15\" value=\"Submit\">";
  WS.html+= "</form><br><br>";
  
  WS.html+= "</body></html>";
  
  WS.html.toCharArray(WS.index_html, WS.html.length()+1);
}

void Send_WebPage()
{
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send_P(200, "text/html", WS.index_html);
  });
}

void Get_WebPage()
{    
  // Send a GET request to <ESP_IP>
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) 
  {
    String temp_str;
    uint16_t temp_int;
        
    // GET input1 and input2 value on <ESP_IP>/get?input1=<VAL>&input2=<VAL>
    if (request->hasParam(PARAM_INPUT_1) && request->hasParam(PARAM_INPUT_2)) 
    {
      WS.New_WiFi_SSID = request->getParam(PARAM_INPUT_1)->value();
      WS.New_WiFi_Password = request->getParam(PARAM_INPUT_2)->value();
      if(WS.New_WiFi_SSID != WS.Saved_WiFi_SSID)
      {
        #ifdef SERIAL_DEBUG
          Serial.println(WS.New_WiFi_SSID);
        #endif
        WS.Saved_WiFi_SSID = WS.New_WiFi_SSID;
        Write_String_EEPROM(EEPROM_SSID_ADDRESS,WS.New_WiFi_SSID);
        WS.Saved_WiFi_SSID = Read_String_EEPROM(EEPROM_SSID_ADDRESS);
      }
      if(WS.New_WiFi_Password != WS.Saved_WiFi_Password)
      {
        #ifdef SERIAL_DEBUG
          //Serial.println(WS.New_WiFi_Password);
        #endif
        WS.Saved_WiFi_Password = WS.New_WiFi_Password;
        Write_String_EEPROM(EEPROM_PASSWORD_ADDRESS,WS.New_WiFi_Password);
        WS.Saved_WiFi_Password = Read_String_EEPROM(EEPROM_PASSWORD_ADDRESS);
      }
    }
        
    // GET input3 and input4 value on <ESP_IP>/get?input3=<VAL>&input4=<VAL>
    else if (request->hasParam(PARAM_INPUT_3) && request->hasParam(PARAM_INPUT_4)) 
    {
      temp_str = request->getParam(PARAM_INPUT_3)->value();
      if(Time_String_Valid(temp_str) == true)
      {
        if(temp_str == "empty" || temp_str == "none" || temp_str == "")
        {
          temp_str = "empty";
        }
        if(temp_str != WS.Plant1_Time)
        {
          WS.Plant1_Time = temp_str;
          Write_String_EEPROM(EEPROM_PLANT1_TIME_ADDRESS, WS.Plant1_Time);
          WS.Plant1_Time = Read_String_EEPROM(EEPROM_PLANT1_TIME_ADDRESS);
        }
      }
      
      temp_int = request->getParam(PARAM_INPUT_4)->value().toInt();
      if(temp_int != WS.Plant1_Valve_Open_Sec)
      {
        WS.Plant1_Valve_Open_Sec = temp_int;
        EEPROM.write(EEPROM_PLANT1_VALVE_OPEN_SEC, WS.Plant1_Valve_Open_Sec);
        EEPROM.commit();
        WS.Plant1_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT1_VALVE_OPEN_SEC);
      }
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant1_Time);
        Serial.println(WS.Plant1_Valve_Open_Sec);
      #endif
    }
    
    // GET input5 and input6 value on <ESP_IP>/get?input5=<VAL>&input6=<VAL>
    else if (request->hasParam(PARAM_INPUT_5) && request->hasParam(PARAM_INPUT_6)) 
    {
      temp_str = request->getParam(PARAM_INPUT_5)->value();
      if(Time_String_Valid(temp_str) == true)
      {
        if(temp_str == "empty" || temp_str == "none" ||temp_str == "")
        {
          temp_str = "empty";
        }
        if(temp_str != WS.Plant2_Time)
        {
          WS.Plant2_Time = temp_str;
          Write_String_EEPROM(EEPROM_PLANT2_TIME_ADDRESS, WS.Plant2_Time);
          WS.Plant2_Time = Read_String_EEPROM(EEPROM_PLANT2_TIME_ADDRESS);
        }
      }
      
      temp_int = request->getParam(PARAM_INPUT_6)->value().toInt();
      if(temp_int != WS.Plant2_Valve_Open_Sec)
      {
        WS.Plant2_Valve_Open_Sec = temp_int;
        EEPROM.write(EEPROM_PLANT2_VALVE_OPEN_SEC, WS.Plant2_Valve_Open_Sec);
        EEPROM.commit();
        WS.Plant2_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT2_VALVE_OPEN_SEC);
      }
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant2_Time);
        Serial.println(WS.Plant2_Valve_Open_Sec);
      #endif
    }
    
    // GET input7 and input8 value on <ESP_IP>/get?input7=<VAL>&input8=<VAL>
    else if (request->hasParam(PARAM_INPUT_7) && request->hasParam(PARAM_INPUT_8)) 
    {
      temp_str = request->getParam(PARAM_INPUT_7)->value();
      if(Time_String_Valid(temp_str) == true)
      {
        if(temp_str == "empty" || temp_str == "none" || temp_str == "")
        {
          temp_str = "empty";
        }
        if(temp_str != WS.Plant3_Time)
        {
          WS.Plant3_Time = temp_str;
          Write_String_EEPROM(EEPROM_PLANT3_TIME_ADDRESS, WS.Plant3_Time);
          WS.Plant3_Time = Read_String_EEPROM(EEPROM_PLANT3_TIME_ADDRESS);
        }
      }
      
      temp_int = request->getParam(PARAM_INPUT_8)->value().toInt();
      if(temp_int != WS.Plant3_Valve_Open_Sec)
      {
        WS.Plant3_Valve_Open_Sec = temp_int;
        EEPROM.write(EEPROM_PLANT3_VALVE_OPEN_SEC, WS.Plant3_Valve_Open_Sec);
        EEPROM.commit();
        WS.Plant3_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT3_VALVE_OPEN_SEC);
      }
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant3_Time);
        Serial.println(WS.Plant3_Valve_Open_Sec);
      #endif
    }
    
    // GET input9 and input10 value on <ESP_IP>/get?input9=<VAL>&input10=<VAL>
    else if (request->hasParam(PARAM_INPUT_9) && request->hasParam(PARAM_INPUT_10)) 
    {
      temp_str = request->getParam(PARAM_INPUT_9)->value();
      if(Time_String_Valid(temp_str) == true)
      {
        if(temp_str == "empty" || temp_str == "none" || temp_str == "")
        {
          temp_str = "empty";
        }
        if(temp_str != WS.Plant4_Time)
        {
          WS.Plant4_Time = temp_str;
          Write_String_EEPROM(EEPROM_PLANT4_TIME_ADDRESS, WS.Plant4_Time);
          WS.Plant4_Time = Read_String_EEPROM(EEPROM_PLANT4_TIME_ADDRESS);
        }
      }
      
      temp_int = request->getParam(PARAM_INPUT_10)->value().toInt();
      if(temp_int != WS.Plant4_Valve_Open_Sec)
      {
        WS.Plant4_Valve_Open_Sec = temp_int;
        EEPROM.write(EEPROM_PLANT4_VALVE_OPEN_SEC, WS.Plant4_Valve_Open_Sec);
        EEPROM.commit();
        WS.Plant4_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT4_VALVE_OPEN_SEC);
      }
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant4_Time);
        Serial.println(WS.Plant4_Valve_Open_Sec);
      #endif
    }
    
    // GET input11 and input12 value on <ESP_IP>/get?input11=<VAL>&input12=<VAL>
    else if (request->hasParam(PARAM_INPUT_11) && request->hasParam(PARAM_INPUT_12)) 
    {
      temp_str = request->getParam(PARAM_INPUT_11)->value();
      if(Time_String_Valid(temp_str) == true)
      {
        if(temp_str == "empty" || temp_str == "none" || temp_str == "")
        {
          temp_str = "empty";
        }
        if(temp_str != WS.Plant5_Time)
        {
          WS.Plant5_Time = temp_str;
          Write_String_EEPROM(EEPROM_PLANT5_TIME_ADDRESS, WS.Plant5_Time);
          WS.Plant5_Time = Read_String_EEPROM(EEPROM_PLANT5_TIME_ADDRESS);
        }
      }
      
      temp_int = request->getParam(PARAM_INPUT_12)->value().toInt();
      if(temp_int != WS.Plant5_Valve_Open_Sec)
      {
        WS.Plant5_Valve_Open_Sec = temp_int;
        EEPROM.write(EEPROM_PLANT5_VALVE_OPEN_SEC, WS.Plant5_Valve_Open_Sec);
        EEPROM.commit();
        WS.Plant5_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT5_VALVE_OPEN_SEC);
      }
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant5_Time);
        Serial.println(WS.Plant5_Valve_Open_Sec);
      #endif
    }

    else if (request->hasParam(PARAM_INPUT_13)) 
    {
      temp_int = request->getParam(PARAM_INPUT_13)->value().toInt();
      if(temp_int != WS.Audio_Mute_Min)
      {
        WS.Audio_Mute_Min = temp_int;
        EEPROM.write(EEPROM_AUDIO_MUTE_MIN, WS.Audio_Mute_Min);
        EEPROM.commit();
        WS.Audio_Mute_Min = EEPROM.read(EEPROM_AUDIO_MUTE_MIN);
      }
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Audio_Mute_Min);
      #endif
    }

    else if(request->hasParam(PARAM_INPUT_14))
    {
      temp_int = request->getParam(PARAM_INPUT_14)->value().toInt();
      if(temp_int != WS.WiFi_Reconnect_Sec)
      {
        WS.WiFi_Reconnect_Sec = temp_int;
        EEPROM.write(EEPROM_WIFI_RECON_SEC, WS.WiFi_Reconnect_Sec);
        EEPROM.commit();
        WS.WiFi_Reconnect_Sec = EEPROM.read(EEPROM_WIFI_RECON_SEC);
      }
      #ifdef SERIAL_DEBUG
        Serial.println(WS.WiFi_Reconnect_Sec);
      #endif
    }

    else if(request->hasParam(PARAM_INPUT_15))
    {
      ESP.restart();
    }
    
    Update_WebPage();
    TIME_VALVE_CFG_Struct_Set();
    
    request->send_P(200, "text/html", WS.index_html);
  });
}

void notFound(AsyncWebServerRequest *request) 
{
  request->send(404, "text/plain", "Not found");
}


bool Time_String_Valid(String Time_String)
{
  bool String_valid = false;
  uint8_t char_count = 0;
  uint8_t prev_idx = 0; 
   if(Time_String == "empty" || Time_String == "none" || Time_String == "")
   {
    String_valid = true;
   }
   else
   {   
     //Check that string contatins atleast 15 characters and max 39
     if(Time_String.length() >= 15 && Time_String.length() <= 39)
     {
       String_valid = true;   
     }
     else
     {
       String_valid = false;  
       return String_valid;
     }
     
     //Check that the last two charaters of the string are either "PM" or "AM"
     if(Time_String.substring((Time_String.length() - 2), Time_String.length()) == "PM" ||
        Time_String.substring((Time_String.length() - 2), Time_String.length()) == "AM")
     {
       String_valid = true;   
     }
     else
     {
       String_valid = false;
       return String_valid; 
     }
  
     //Check that the total numbers of colon character(:) in the string are atleast 4 and max 10
     for (uint8_t i = 0; i < Time_String.length(); i++) 
     {
      if (Time_String[i] == ':') 
      {
        char_count++;
      }
     }
     if(char_count >= 4 and char_count<= 10)
     {
       String_valid = true;   
     }
     else
     {
       String_valid = false; 
       return String_valid;
     }
  
    //Make sure all the colon character(:) are in right places in the string
    if(char_count==4)  //1 day in the string,  Mon:12:00:00:PM
    {
      if((Time_String[3]  == ':' && 
          Time_String[6]  == ':' && 
          Time_String[9]  == ':' &&
          Time_String[12] == ':') &&
         (Time_String.substring(0,3) == "Mon" ||
          Time_String.substring(0,3) == "Tue" ||
          Time_String.substring(0,3) == "Wed" ||
          Time_String.substring(0,3) == "Thu" ||
          Time_String.substring(0,3) == "Fri" ||
          Time_String.substring(0,3) == "Sat" ||
          Time_String.substring(0,3) == "Sun"))
      {
        String_valid = true;   
      }
      else
      {
        String_valid = false; 
        return String_valid;
      }
    }
    if(char_count==5) //2 days in the string,  Mon:Tue:12:00:00:PM
    {
      if((Time_String[3]  == ':' && 
          Time_String[7]  == ':' && 
          Time_String[10] == ':' &&
          Time_String[13] == ':' &&
          Time_String[16] == ':') &&
         (Time_String.substring(0,3) == "Mon" ||
          Time_String.substring(0,3) == "Tue" ||
          Time_String.substring(0,3) == "Wed" ||
          Time_String.substring(0,3) == "Thu" ||
          Time_String.substring(0,3) == "Fri" ||
          Time_String.substring(0,3) == "Sat" ||
          Time_String.substring(0,3) == "Sun") &&
         (Time_String.substring(4,7) == "Tue" ||
          Time_String.substring(4,7) == "Wed" ||
          Time_String.substring(4,7) == "Thu" ||
          Time_String.substring(4,7) == "Fri" ||
          Time_String.substring(4,7) == "Sat" ||
          Time_String.substring(4,7) == "Sun"))
      {
        String_valid = true;   
      }
      else
      {
        String_valid = false; 
        return String_valid;
      }
    }
  
    if(char_count==6) //3 days in the string,  Mon:Tue:Wed:12:00:00:PM
    {
      if((Time_String[3]  == ':' && 
          Time_String[7]  == ':' && 
          Time_String[11] == ':' &&
          Time_String[14] == ':' &&
          Time_String[17] == ':' &&
          Time_String[20] == ':') &&
         (Time_String.substring(0,3) == "Mon" ||
          Time_String.substring(0,3) == "Tue" ||
          Time_String.substring(0,3) == "Wed" ||
          Time_String.substring(0,3) == "Thu" ||
          Time_String.substring(0,3) == "Fri" ||
          Time_String.substring(0,3) == "Sat" ||
          Time_String.substring(0,3) == "Sun") &&
         (Time_String.substring(4,7) == "Tue" ||
          Time_String.substring(4,7) == "Wed" ||
          Time_String.substring(4,7) == "Thu" ||
          Time_String.substring(4,7) == "Fri" ||
          Time_String.substring(4,7) == "Sat" ||
          Time_String.substring(4,7) == "Sun") &&
         (Time_String.substring(8,11) == "Wed" ||
          Time_String.substring(8,11) == "Thu" ||
          Time_String.substring(8,11) == "Fri" ||
          Time_String.substring(8,11) == "Sat" ||
          Time_String.substring(8,11) == "Sun"))
      {
        String_valid = true;   
      }
      else
      {
        String_valid = false; 
        return String_valid;
      }
    }
  
    if(char_count==7) //4 days in the string,  Mon:Tue:Wed:Thu:12:00:00:PM
    {
      if((Time_String[3]  == ':' && 
          Time_String[7]  == ':' && 
          Time_String[11] == ':' &&
          Time_String[15] == ':' &&
          Time_String[18] == ':' &&
          Time_String[21] == ':' &&
          Time_String[24] == ':') &&
         (Time_String.substring(0,3) == "Mon" ||
          Time_String.substring(0,3) == "Tue" ||
          Time_String.substring(0,3) == "Wed" ||
          Time_String.substring(0,3) == "Thu" ||
          Time_String.substring(0,3) == "Fri" ||
          Time_String.substring(0,3) == "Sat" ||
          Time_String.substring(0,3) == "Sun") &&
         (Time_String.substring(4,7) == "Tue" ||
          Time_String.substring(4,7) == "Wed" ||
          Time_String.substring(4,7) == "Thu" ||
          Time_String.substring(4,7) == "Fri" ||
          Time_String.substring(4,7) == "Sat" ||
          Time_String.substring(4,7) == "Sun") &&
         (Time_String.substring(8,11) == "Wed" ||
          Time_String.substring(8,11) == "Thu" ||
          Time_String.substring(8,11) == "Fri" ||
          Time_String.substring(8,11) == "Sat" ||
          Time_String.substring(8,11) == "Sun") &&
         (Time_String.substring(12,15) == "Thu" ||
          Time_String.substring(12,15) == "Fri" ||
          Time_String.substring(12,15) == "Sat" ||
          Time_String.substring(12,15) == "Sun"))
      {
        String_valid = true;   
      }
      else
      {
        String_valid = false; 
        return String_valid;
      }
    }
  
    if(char_count==8) //5 days in the string,  Mon:Tue:Wed:Thu:Fri:12:00:00:PM
    {
      if((Time_String[3]  == ':' && 
          Time_String[7]  == ':' && 
          Time_String[11] == ':' &&
          Time_String[15] == ':' &&
          Time_String[19] == ':' &&
          Time_String[22] == ':' &&
          Time_String[25] == ':' &&
          Time_String[28] == ':') &&
         (Time_String.substring(0,3) == "Mon" ||
          Time_String.substring(0,3) == "Tue" ||
          Time_String.substring(0,3) == "Wed" ||
          Time_String.substring(0,3) == "Thu" ||
          Time_String.substring(0,3) == "Fri" ||
          Time_String.substring(0,3) == "Sat" ||
          Time_String.substring(0,3) == "Sun") &&
         (Time_String.substring(4,7) == "Tue" ||
          Time_String.substring(4,7) == "Wed" ||
          Time_String.substring(4,7) == "Thu" ||
          Time_String.substring(4,7) == "Fri" ||
          Time_String.substring(4,7) == "Sat" ||
          Time_String.substring(4,7) == "Sun") &&
         (Time_String.substring(8,11) == "Wed" ||
          Time_String.substring(8,11) == "Thu" ||
          Time_String.substring(8,11) == "Fri" ||
          Time_String.substring(8,11) == "Sat" ||
          Time_String.substring(8,11) == "Sun") &&
         (Time_String.substring(12,15) == "Thu" ||
          Time_String.substring(12,15) == "Fri" ||
          Time_String.substring(12,15) == "Sat" ||
          Time_String.substring(12,15) == "Sun") &&
         (Time_String.substring(16,19) == "Fri" ||
          Time_String.substring(16,19) == "Sat" ||
          Time_String.substring(16,19) == "Sun"))
      {
        String_valid = true;   
      }
      else
      {
        String_valid = false; 
        return String_valid;
      }
    }
  
    if(char_count==9) //6 days in the string,  Mon:Tue:Wed:Thu:Fri:Sat:12:00:00:PM
    {
      if((Time_String[3]  == ':' && 
          Time_String[7]  == ':' && 
          Time_String[11] == ':' &&
          Time_String[15] == ':' &&
          Time_String[19] == ':' &&
          Time_String[23] == ':' &&
          Time_String[26] == ':' &&
          Time_String[29] == ':' &&
          Time_String[32] == ':') &&
         (Time_String.substring(0,3) == "Mon" ||
          Time_String.substring(0,3) == "Tue" ||
          Time_String.substring(0,3) == "Wed" ||
          Time_String.substring(0,3) == "Thu" ||
          Time_String.substring(0,3) == "Fri" ||
          Time_String.substring(0,3) == "Sat" ||
          Time_String.substring(0,3) == "Sun") &&
         (Time_String.substring(4,7) == "Tue" ||
          Time_String.substring(4,7) == "Wed" ||
          Time_String.substring(4,7) == "Thu" ||
          Time_String.substring(4,7) == "Fri" ||
          Time_String.substring(4,7) == "Sat" ||
          Time_String.substring(4,7) == "Sun") &&
         (Time_String.substring(8,11) == "Wed" ||
          Time_String.substring(8,11) == "Thu" ||
          Time_String.substring(8,11) == "Fri" ||
          Time_String.substring(8,11) == "Sat" ||
          Time_String.substring(8,11) == "Sun") &&
         (Time_String.substring(12,15) == "Thu" ||
          Time_String.substring(12,15) == "Fri" ||
          Time_String.substring(12,15) == "Sat" ||
          Time_String.substring(12,15) == "Sun") &&
         (Time_String.substring(16,19) == "Fri" ||
          Time_String.substring(16,19) == "Sat" ||
          Time_String.substring(16,19) == "Sun") &&
         (Time_String.substring(20,23) == "Sat" ||
          Time_String.substring(20,23) == "Sun"))
      {
        String_valid = true;   
      }
      else
      {
        String_valid = false; 
        return String_valid;
      }
    }
  
    if(char_count==10) //7 days in the string,  Mon:Tue:Wed:Thu:Fri:Sat:Sun:12:00:00:PM
    {
      if((Time_String[3]  == ':' && 
          Time_String[7]  == ':' && 
          Time_String[11] == ':' &&
          Time_String[15] == ':' &&
          Time_String[19] == ':' &&
          Time_String[23] == ':' &&
          Time_String[27] == ':' &&
          Time_String[30] == ':' &&
          Time_String[33] == ':' &&
          Time_String[36] == ':') &&
         (Time_String.substring(0,3) == "Mon" ||
          Time_String.substring(0,3) == "Tue" ||
          Time_String.substring(0,3) == "Wed" ||
          Time_String.substring(0,3) == "Thu" ||
          Time_String.substring(0,3) == "Fri" ||
          Time_String.substring(0,3) == "Sat" ||
          Time_String.substring(0,3) == "Sun") &&
         (Time_String.substring(4,7) == "Tue" ||
          Time_String.substring(4,7) == "Wed" ||
          Time_String.substring(4,7) == "Thu" ||
          Time_String.substring(4,7) == "Fri" ||
          Time_String.substring(4,7) == "Sat" ||
          Time_String.substring(4,7) == "Sun") &&
         (Time_String.substring(8,11) == "Wed" ||
          Time_String.substring(8,11) == "Thu" ||
          Time_String.substring(8,11) == "Fri" ||
          Time_String.substring(8,11) == "Sat" ||
          Time_String.substring(8,11) == "Sun") &&
         (Time_String.substring(12,15) == "Thu" ||
          Time_String.substring(12,15) == "Fri" ||
          Time_String.substring(12,15) == "Sat" ||
          Time_String.substring(12,15) == "Sun") &&
         (Time_String.substring(16,19) == "Fri" ||
          Time_String.substring(16,19) == "Sat" ||
          Time_String.substring(16,19) == "Sun") &&
         (Time_String.substring(20,23) == "Sat" ||
          Time_String.substring(20,23) == "Sun") &&
         (Time_String.substring(24,27) == "Sun"))
      {
        String_valid = true;   
      }
      else
      {
        String_valid = false; 
        return String_valid;
      }
    }
  
    //make sure that days are not repeated in the string
    if(countSubstring(Time_String, "Mon") > 1 ||
       countSubstring(Time_String, "Tue") > 1 ||
       countSubstring(Time_String, "Wed") > 1 ||
       countSubstring(Time_String, "Thu") > 1 ||
       countSubstring(Time_String, "Fri") > 1 ||
       countSubstring(Time_String, "Sat") > 1 ||
       countSubstring(Time_String, "Sun") > 1)
    {
      String_valid = false; 
      return String_valid;
    }
    else
    {
      String_valid = true; 
    } 
       
    //Check that the Hour value in the string is 1 - 12
    if((Time_String.substring((Time_String.length() - 11), Time_String.length() - 9).toInt() >= 1 &&
        Time_String.substring((Time_String.length() - 11), Time_String.length() - 9).toInt() <= 12) &&
       (Time_String.substring((Time_String.length() - 8), Time_String.length() - 6).toInt() >= 0 &&
        Time_String.substring((Time_String.length() - 8), Time_String.length() - 6).toInt() <= 59) &&
       (Time_String.substring((Time_String.length() - 5), Time_String.length() - 3).toInt() >= 0 &&
        Time_String.substring((Time_String.length() - 5), Time_String.length() - 3).toInt() <= 59))
    {
       String_valid = true; 
    }
    else
    {
      String_valid = false;
      return String_valid; 
    }
  }
  return String_valid;
}


int countSubstring(String mainStr, String subStr) 
{
  int count = 0;
  int index = 0;

  // indexOf() returns -1 if the substring is no longer found
  while (true) {
    index = mainStr.indexOf(subStr, index);
    if (index == -1) {
      break;
    }
    count++;
    index += subStr.length(); // Move past the last found match
  }

  return count;
}
