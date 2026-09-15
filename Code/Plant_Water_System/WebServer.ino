#include "Define.h" 

char* PARAM_INPUT_1 = "input1";
char* PARAM_INPUT_2 = "input2";
char* PARAM_INPUT_3 = "input3";
char* PARAM_INPUT_4 = "input4";
char* PARAM_INPUT_5 = "input5";
  
void Update_WebPage()
{
  WS.html = "<!DOCTYPE HTML><html><head>";
  WS.html+= "<title>ESP Input Form</title>";
  WS.html+= "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  WS.html+= "<title>ESP Input Form</title>";
  WS.html+= "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  WS.html+= "</head><body>";
  WS.html+= "<h2>";
  WS.html+= WiFi.localIP().toString();
  WS.html+= "<br>"; //new line in heading
  WS.html+= NTP.Time;
  WS.html+= "</h2>";
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant1 Time: <input type=\"text\" name=\"input1\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br>";
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant2 Time: <input type=\"text\" name=\"input2\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br>";
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant3 Time: <input type=\"text\" name=\"input3\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br>";
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant4 Time: <input type=\"text\" name=\"input4\">";
  WS.html+= "<input type=\"submit\" value=\"Submit\">";
  WS.html+= "</form><br>";
  WS.html+= "<form action=\"/get\">";
  WS.html+= "Plant5 Time: <input type=\"text\" name=\"input5\">";
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
    if (request->hasParam(PARAM_INPUT_1)) 
    {
      WS.Plant1_Time = request->getParam(PARAM_INPUT_1)->value();
      Update_WebPage();
    }
    // GET input2 value on <ESP_IP>/get?input2=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_2)) 
    {
      WS.Plant2_Time = request->getParam(PARAM_INPUT_2)->value();
      Update_WebPage();
    }
    // GET input3 value on <ESP_IP>/get?input3=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_3)) 
    {
      WS.Plant3_Time = request->getParam(PARAM_INPUT_3)->value();
      Update_WebPage();
    }
    // GET input4 value on <ESP_IP>/get?input3=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_4)) 
    {
      WS.Plant4_Time = request->getParam(PARAM_INPUT_4)->value();
      Update_WebPage();
    }
    // GET input5 value on <ESP_IP>/get?input3=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_5)) 
    {
      WS.Plant5_Time = request->getParam(PARAM_INPUT_5)->value();
      Update_WebPage();
    }
      
    request->send_P(200, "text/html", WS.index_html);
  });
}

void notFound(AsyncWebServerRequest *request) 
{
  request->send(404, "text/plain", "Not found");
}
