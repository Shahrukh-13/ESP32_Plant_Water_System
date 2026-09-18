#include "Define.h" 

const char* PARAM_INPUT_1 = "input1";
const char* PARAM_INPUT_2 = "input2";
const char* PARAM_INPUT_3 = "input3";
const char* PARAM_INPUT_4 = "input4";
const char* PARAM_INPUT_5 = "input5";
const char* PARAM_INPUT_6 = "input6";
const char* PARAM_INPUT_7 = "input7";
const char* PARAM_INPUT_8 = "input8";
  
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
  
  WS.html+= "<h3>";
  WS.html+= "Saved Plant1 Time: " + WS.Plant1_Time;
  WS.html+= "<br>"; //new line in heading
  WS.html+= "Saved Plant1 Valve Open Seconds: " + String(WS.Plant1_Valve_Open_Sec);
  WS.html+= "<br>"; //new line in heading
  WS.html+= "</h3>";
  
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant1 Time: <input type=\"text\" name=\"input3\">";
  WS.html+= "<br><br>";
  WS.html+= "Plant1 Valve Open Seconds: <input type=\"number\" name=\"input4\" min=\"1\" max=\"60\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br><br>";
  
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant2 Time: <input type=\"text\" name=\"input5\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br>";
  
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant3 Time: <input type=\"text\" name=\"input6\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br>";
  
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant4 Time: <input type=\"text\" name=\"input7\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br>";
  
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant5 Time: <input type=\"text\" name=\"input8\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br>";
  
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
    // GET input1 value on <ESP_IP>/get?input1=<inputMessage>
    if (request->hasParam(PARAM_INPUT_1) && request->hasParam(PARAM_INPUT_2)) 
    {
      WS.New_WiFi_SSID = request->getParam(PARAM_INPUT_1)->value();
      WS.New_WiFi_Password = request->getParam(PARAM_INPUT_2)->value();
      #ifdef SERIAL_DEBUG
        Serial.println(WS.New_WiFi_SSID);
      #endif
      WriteString_EEPROM(EEPROM_SSID_ADDRESS,WS.New_WiFi_SSID);

      #ifdef SERIAL_DEBUG
        Serial.println(WS.New_WiFi_Password);
      #endif
      WriteString_EEPROM(EEPROM_PASSWORD_ADDRESS,WS.New_WiFi_Password);
      
      Update_WebPage();
    }
        
    // GET input3 value on <ESP_IP>/get?input3=<inputMessage>
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
    
    // GET input4 value on <ESP_IP>/get?input4=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_5)) 
    {
      WS.Plant2_Time = request->getParam(PARAM_INPUT_5)->value();
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant2_Time);
      #endif
      Update_WebPage();
    }
    
    // GET input5 value on <ESP_IP>/get?input5=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_6)) 
    {
      WS.Plant3_Time = request->getParam(PARAM_INPUT_6)->value();
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant3_Time);
      #endif
      Update_WebPage();
    }
    
    // GET input6 value on <ESP_IP>/get?input6=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_7)) 
    {
      WS.Plant4_Time = request->getParam(PARAM_INPUT_7)->value();
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant4_Time);
      #endif
      Update_WebPage();
    }
    
    // GET input7 value on <ESP_IP>/get?input7=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_8)) 
    {
      WS.Plant5_Time = request->getParam(PARAM_INPUT_8)->value();
      #ifdef SERIAL_DEBUG
        Serial.println(WS.Plant5_Time);
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
