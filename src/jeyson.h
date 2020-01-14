#ifndef _jeyson_H_
#define _jeyson_H_

#include <ArduinoJson.h>
#include <FS.h>

// Эта функция читает из JSON-строки значение одного параметра 
String getParameterByJson(String jsonString = "", String parameterName = "")
  {
    DynamicJsonDocument doc(1024);
    doc.clear();
    deserializeJson(doc, jsonString);
    JsonObject obj = doc.as<JsonObject>();
    return obj[parameterName];
  }

// Эта функция читает из файла с календарем строку, относящуюся к конкретной дате
// Возвращает JSON-строку. Можно передать в getParameterByJson
String loadDiaryString(String curDate)
{
  String res = "";
  if (!SPIFFS.begin()) 
    { Serial.println("ERROR FILESYSTEM"); }
  File diaryFile = SPIFFS.open("/diary.dat", "r");
  if (!diaryFile)
  {
    Serial.println("NO FILE");
    return "";
  }
  else
  {
    Serial.println("CONFIG LOADED");
    DynamicJsonDocument doc(1024);

    while (diaryFile.available())
    {
      doc.clear();
      String jString = diaryFile.readStringUntil('\n');
      deserializeJson(doc, jString);
      JsonObject obj = doc.as<JsonObject>();
      String d = obj["Date"];
      if (d == curDate)
      {
        res = jString;
      }
    }    
  };

  SPIFFS.end();
  return res;
}

#endif;