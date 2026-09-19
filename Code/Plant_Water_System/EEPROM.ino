#include "Define.h"

void EEPROM_Init()
{
  EEPROM.begin(512);

  //Reset the PowerCycle_Count to 0 on fresh EEPROM//
  WC.PowerCycle_Count = EEPROM.read(EEPROM_POWERCYCLE_COUNT_ADDRESS);
  #ifdef SERIAL_DEBUG
    Serial.print("PowerCycle_Count= ");
    Serial.print(WC.PowerCycle_Count);
    Serial.println();
  #endif
  if(WC.PowerCycle_Count == 0xFF)
  {
    WC.PowerCycle_Count = 0;
    EEPROM.write(EEPROM_POWERCYCLE_COUNT_ADDRESS,WC.PowerCycle_Count);
    EEPROM.commit();
    WC.PowerCycle_Count = EEPROM.read(EEPROM_POWERCYCLE_COUNT_ADDRESS);
  }

  //Set the ssid_i to  Default_WiFi_SSID if nothing saved on EEPROM
  //Set the passsword_i to  Default_WiFi_Password if nothing saved on EEPROM
  WC.ssid_i = Read_String_EEPROM(EEPROM_SSID_ADDRESS);
  WC.password_i = Read_String_EEPROM(EEPROM_PASSWORD_ADDRESS);

  if(WC.ssid_i == "empty")
  {
    WC.ssid_i = Default_WiFi_SSID;
    WriteString_EEPROM(EEPROM_SSID_ADDRESS,WC.ssid_i);
    WC.ssid_i = Read_String_EEPROM(EEPROM_SSID_ADDRESS);
  }
  if(WC.password_i == "empty")
  {
    WC.password_i = Default_WiFi_Password;
    WriteString_EEPROM(EEPROM_PASSWORD_ADDRESS, WC.password_i);
    WC.password_i = Read_String_EEPROM(EEPROM_PASSWORD_ADDRESS);
  }
  WC.ssid_i.toCharArray(WC.ssid, WC.ssid_i.length()+1);
  WC.password_i.toCharArray(WC.password, WC.password_i.length()+1);

  //Set Plant1_Time to "empty" if nothing saved on EEPROM
  //Set Plant2_Time to "empty" if nothing saved on EEPROM
  //Set Plant3_Time to "empty" if nothing saved on EEPROM
  //Set Plant4_Time to "empty" if nothing saved on EEPROM
  //Set Plant5_Time to "empty" if nothing saved on EEPROM
  WS.Plant1_Time = Read_String_EEPROM(EEPROM_PLANT1_TIME_ADDRESS);
  WS.Plant2_Time = Read_String_EEPROM(EEPROM_PLANT2_TIME_ADDRESS);
  WS.Plant3_Time = Read_String_EEPROM(EEPROM_PLANT3_TIME_ADDRESS);
  WS.Plant4_Time = Read_String_EEPROM(EEPROM_PLANT4_TIME_ADDRESS);
  WS.Plant5_Time = Read_String_EEPROM(EEPROM_PLANT5_TIME_ADDRESS);
  if(WS.Plant1_Time == "empty")
  {
    WriteString_EEPROM(EEPROM_PLANT1_TIME_ADDRESS, WS.Plant1_Time);
    WS.Plant1_Time = Read_String_EEPROM(EEPROM_PLANT1_TIME_ADDRESS);
  }
  if(WS.Plant2_Time == "empty")
  {
    WriteString_EEPROM(EEPROM_PLANT2_TIME_ADDRESS, WS.Plant2_Time);
    WS.Plant2_Time = Read_String_EEPROM(EEPROM_PLANT2_TIME_ADDRESS);
  }
  if(WS.Plant3_Time == "empty")
  {
    WriteString_EEPROM(EEPROM_PLANT3_TIME_ADDRESS, WS.Plant3_Time);
    WS.Plant3_Time = Read_String_EEPROM(EEPROM_PLANT3_TIME_ADDRESS);
  }
  if(WS.Plant4_Time == "empty")
  {
    WriteString_EEPROM(EEPROM_PLANT4_TIME_ADDRESS, WS.Plant4_Time);
    WS.Plant4_Time = Read_String_EEPROM(EEPROM_PLANT4_TIME_ADDRESS);
  }
  if(WS.Plant5_Time == "empty")
  {
    WriteString_EEPROM(EEPROM_PLANT5_TIME_ADDRESS, WS.Plant5_Time);
    WS.Plant5_Time = Read_String_EEPROM(EEPROM_PLANT5_TIME_ADDRESS);
  }

  //Set Plant1_Valve_Open_Sec to 5 if nothing saved on EEPROM
  //Set Plant2_Valve_Open_Sec to 5 if nothing saved on EEPROM
  //Set Plant3_Valve_Open_Sec to 5 if nothing saved on EEPROM
  //Set Plant4_Valve_Open_Sec to 5 if nothing saved on EEPROM
  //Set Plant5_Valve_Open_Sec to 5 if nothing saved on EEPROM
  WS.Plant1_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT1_VALVE_OPEN_SEC);
  WS.Plant2_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT2_VALVE_OPEN_SEC);
  WS.Plant3_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT3_VALVE_OPEN_SEC);
  WS.Plant4_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT4_VALVE_OPEN_SEC);
  WS.Plant5_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT5_VALVE_OPEN_SEC);
  if(WS.Plant1_Valve_Open_Sec == 0xFF)
  {
    WS.Plant1_Valve_Open_Sec = 5;
    EEPROM.write(EEPROM_PLANT1_VALVE_OPEN_SEC, WS.Plant1_Valve_Open_Sec);
    EEPROM.commit();
    WS.Plant1_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT1_VALVE_OPEN_SEC);
  }
  if(WS.Plant2_Valve_Open_Sec == 0xFF)
  {
    WS.Plant2_Valve_Open_Sec = 5;
    EEPROM.write(EEPROM_PLANT2_VALVE_OPEN_SEC, WS.Plant2_Valve_Open_Sec);
    EEPROM.commit();
    WS.Plant2_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT2_VALVE_OPEN_SEC);
  }
  if(WS.Plant3_Valve_Open_Sec == 0xFF)
  {
    WS.Plant3_Valve_Open_Sec = 5;
    EEPROM.write(EEPROM_PLANT3_VALVE_OPEN_SEC, WS.Plant3_Valve_Open_Sec);
    EEPROM.commit();
    WS.Plant3_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT3_VALVE_OPEN_SEC);
  }
  if(WS.Plant4_Valve_Open_Sec == 0xFF)
  {
    WS.Plant4_Valve_Open_Sec = 5;
    EEPROM.write(EEPROM_PLANT4_VALVE_OPEN_SEC, WS.Plant4_Valve_Open_Sec);
    EEPROM.commit();
    WS.Plant4_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT4_VALVE_OPEN_SEC);
  }
  if(WS.Plant5_Valve_Open_Sec == 0xFF)
  {
    WS.Plant5_Valve_Open_Sec = 5;
    EEPROM.write(EEPROM_PLANT5_VALVE_OPEN_SEC, WS.Plant5_Valve_Open_Sec);
    EEPROM.commit();
    WS.Plant5_Valve_Open_Sec = EEPROM.read(EEPROM_PLANT5_VALVE_OPEN_SEC);
  }

  //Set Audio_Mute_Min to 10 if nothing saved on EEPROM
  /*WS.Audio_Mute_Min = EEPROM.read(EEPROM_AUDIO_MUTE_MIN);
  if(WS.Audio_Mute_Min == 0xFF)
  {
    WS.Audio_Mute_Min = 10;
    EEPROM.write(EEPROM_AUDIO_MUTE_MIN, WS.Audio_Mute_Min);
    EEPROM.commit();
    WS.Audio_Mute_Min = EEPROM.read(EEPROM_AUDIO_MUTE_MIN);
  }*/
}


void WriteString_EEPROM(char add,String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.write(add+i,data[i]);
  }
  EEPROM.write(add+_size,'\0');   //Add termination null character for String Data
  EEPROM.commit();
}


String Read_String_EEPROM(char add)
{
  int i;
  char data[50]; 
  int len=0;
  unsigned char k;
  k=EEPROM.read(add);
  if(k == 0xFF)
  {
    return String("empty");
  }
  else
  {
    while(k != '\0' && len<50)   //Read until null character
    {    
      k=EEPROM.read(add+len);
      data[len]=k;
      len++;
    }
    data[len]='\0';
    return String(data);
  }
}
