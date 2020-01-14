
#include "jeyson.h"
// #include <iostream>
#include <TimeLib.h>
#include <NTPClient.h>
// change next line to use with another board/shield
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include <ESP8266FtpServer.h>



const char *ssid = "6329";
const char *password = "7134006329";

IPAddress ip(192, 168, 0, 36);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
// IPAddress dns1(192,168,0,1);
IPAddress dns1(8, 8, 8, 8);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

FtpServer ftpSrv;

// unsigned long previousMillis = 0;
// unsigned long currentMillis = 0;

void setup()
{
  Serial.begin(115200);

  WiFi.config(ip, gateway, subnet, dns1);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(50);
    Serial.print(".");
  };
  Serial.println();
  Serial.println(WiFi.localIP());
  // Serial.println(WiFi.localIP());
  // Serial.println(WiFi.dnsIP(0));

  // delay(10000);

  timeClient.begin();
  timeClient.setTimeOffset(3600 * (+3));

  while (!timeClient.update())
  {
    delay(5);
    Serial.print(".");
  };
  Serial.println();
  Serial.println(timeClient.getFormattedTime());
  // Serial.println(timeClient.getFormattedTime());
  // ftpSrv.begin("relay", "relay");
  // delay(6000);

  Serial.println(loadDiaryString("29.07"));
  Serial.println(getParameterByJson(loadDiaryString("29.07"), "sunset"));
  // loadDiaryString("29.07");

  Serial.println("=========================");
}

void loop()
{

  // Serial.println("");
  // Serial.println("----------------------------");
  // if ((millis() - previousMillis) > 5000)
  // {

    // // Serial.println(millis());
    // Serial.println(previousMillis);
    Serial.println(timeClient.getFormattedTime());
    // Serial.println(timeClient.getDay());
    Serial.println(timeClient.getEpochTime());

    // Serial.println(timeClient.getFormattedTime());
    Serial.print(day (timeClient.getEpochTime()));
    Serial.print(".");
    Serial.print(month (timeClient.getEpochTime()));
    Serial.print(".");
    Serial.println(year (timeClient.getEpochTime()));

    //  if (timeClient.update())
    //   {
    //     previousMillis = millis();
    //   }

    // Serial.println(timeClient.getFormattedDate());
    // Serial.println(ctime((timeClient.getEpochTime())));

     delay(1000);
  // };

  // ftpSrv.handleFTP();

}