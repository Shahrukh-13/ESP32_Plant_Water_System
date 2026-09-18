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
  WS.html+= "Connected to SSID: " + WC.ssid_i;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h2>";
  
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
  WS.html+= "Saved Plant1 Valve Open Seconds: " + String(WS.Plant1_Valve_Open_Sec/1000);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";

  // Input field for New Plant1 Time and New Plant1 Valve Open Seconds
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant1 Time: <input type=\"text\" name=\"input3\">";
  WS.html+= "<br><br>";
  WS.html+= "Plant1 Valve Open Seconds: <input type=\"number\" name=\"input4\" min=\"1\" max=\"60\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Heading to display current saved Plant2 Time in EEPROM and saved Plant2 Valve Open Secons in EEPROM
  WS.html+= "<h3>";
  WS.html+= "Saved Plant2 Time: " + WS.Plant2_Time;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "Saved Plant2 Valve Open Seconds: " + String(WS.Plant2_Valve_Open_Sec/1000);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";

  // Input field for New Plant2 Time and New Plant2 Valve Open Seconds
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant2 Time: <input type=\"text\" name=\"input5\">";
  WS.html+= "<br><br>";
  WS.html+= "Plant2 Valve Open Seconds: <input type=\"number\" name=\"input6\" min=\"1\" max=\"60\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Heading to display current saved Plant3 Time in EEPROM and saved Plant3 Valve Open Secons in EEPROM
  WS.html+= "<h3>";
  WS.html+= "Saved Plant3 Time: " + WS.Plant3_Time;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "Saved Plant3 Valve Open Seconds: " + String(WS.Plant3_Valve_Open_Sec/1000);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";
  
  // Input field for New Plant3 Time and New Plant3 Valve Open Seconds
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant3 Time: <input type=\"text\" name=\"input7\">";
  WS.html+= "<br><br>";
  WS.html+= "Plant3 Valve Open Seconds: <input type=\"number\" name=\"input8\" min=\"1\" max=\"60\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Heading to display current saved Plant4 Time in EEPROM and saved Plant4 Valve Open Secons in EEPROM
  WS.html+= "<h3>";
  WS.html+= "Saved Plant4 Time: " + WS.Plant4_Time;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "Saved Plant4 Valve Open Seconds: " + String(WS.Plant4_Valve_Open_Sec/1000);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";
  
  // Input field for New Plant4 Time and New Plant4 Valve Open Seconds
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant4 Time: <input type=\"text\" name=\"input9\">";
  WS.html+= "<br><br>";
  WS.html+= "Plant4 Valve Open Seconds: <input type=\"number\" name=\"input10\" min=\"1\" max=\"60\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";

  // Heading to display current saved Plant5 Time in EEPROM and saved Plant5 Valve Open Secons in EEPROM
  WS.html+= "<h3>";
  WS.html+= "Saved Plant5 Time: " + WS.Plant5_Time;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "Saved Plant5 Valve Open Seconds: " + String(WS.Plant5_Valve_Open_Sec/1000);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";
  
  // Input field for New Plant5 Time and New Plant5 Valve Open Seconds
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant5 Time: <input type=\"text\" name=\"input11\">";
  WS.html+= "<br><br>";
  WS.html+= "Plant5 Valve Open Seconds: <input type=\"number\" name=\"input12\" min=\"1\" max=\"60\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
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
        WriteString_EEPROM(EEPROM_SSID_ADDRESS,WS.New_WiFi_SSID);
      }
      if(WS.New_WiFi_Password != WS.Saved_WiFi_Password)
      {
        #ifdef SERIAL_DEBUG
          Serial.println(WS.New_WiFi_Password);
        #endif
        WS.Saved_WiFi_Password = WS.New_WiFi_Password;
        WriteString_EEPROM(EEPROM_PASSWORD_ADDRESS,WS.New_WiFi_Password);
      }
      Update_WebPage();
    }
        
    // GET input3 and input4 value on <ESP_IP>/get?input3=<VAL>&input4=<VAL>
    else if (request->hasParam(PARAM_INPUT_3) && request->hasParam(PARAM_INPUT_4)) 
    {
      WS.Plant1_Time = request->getParam(PARAM_INPUT_3)->value();
      WS.Plant1_Valve_Open_Sec = request->getParam(PARAM_INPUT_4)->value().toInt() * 1000;
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant1_Time);
        Serial.println(WS.Plant1_Valve_Open_Sec);
      #endif
      Update_WebPage();
    }
    
    // GET input5 and input6 value on <ESP_IP>/get?input5=<VAL>&input6=<VAL>
    else if (request->hasParam(PARAM_INPUT_5) && request->hasParam(PARAM_INPUT_6)) 
    {
      WS.Plant2_Time = request->getParam(PARAM_INPUT_5)->value();
      WS.Plant2_Valve_Open_Sec = request->getParam(PARAM_INPUT_6)->value().toInt() * 1000;
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant2_Time);
        Serial.println(WS.Plant2_Valve_Open_Sec);
      #endif
      Update_WebPage();
    }
    
    // GET input7 and input8 value on <ESP_IP>/get?input7=<VAL>&input8=<VAL>
    else if (request->hasParam(PARAM_INPUT_7) && request->hasParam(PARAM_INPUT_8)) 
    {
      WS.Plant3_Time = request->getParam(PARAM_INPUT_7)->value();
      WS.Plant3_Valve_Open_Sec = request->getParam(PARAM_INPUT_8)->value().toInt() * 1000;
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant3_Time);
        Serial.println(WS.Plant3_Valve_Open_Sec);
      #endif
      Update_WebPage();
    }
    
    // GET input9 and input10 value on <ESP_IP>/get?input9=<VAL>&input10=<VAL>
    else if (request->hasParam(PARAM_INPUT_9) && request->hasParam(PARAM_INPUT_10)) 
    {
      WS.Plant4_Time = request->getParam(PARAM_INPUT_9)->value();
      WS.Plant4_Valve_Open_Sec = request->getParam(PARAM_INPUT_10)->value().toInt() * 1000;
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant4_Time);
        Serial.println(WS.Plant4_Valve_Open_Sec);
      #endif
      Update_WebPage();
    }
    
    // GET input11 and input12 value on <ESP_IP>/get?input11=<VAL>&input12=<VAL>
    else if (request->hasParam(PARAM_INPUT_11) && request->hasParam(PARAM_INPUT_12)) 
    {
      WS.Plant5_Time = request->getParam(PARAM_INPUT_11)->value();
      WS.Plant5_Valve_Open_Sec = request->getParam(PARAM_INPUT_12)->value().toInt() * 1000;
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant5_Time);
        Serial.println(WS.Plant5_Valve_Open_Sec);
      #endif
      Update_WebPage();
    }
      
    request->send_P(200, "text/html", WS.index_html);
  });
}

void notFound(AsyncWebServerRequest *request) 
{
  request->send(404, "text/plain", "Not found");
}
