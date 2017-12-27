#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

MDNSResponder mdns;
const char* ssid = "Weather_station";
DHT sensor(DHTPIN, DHTTYPE);
ESP8266WebServer server(80);

String webPage = "";
float temp;
float hum;

void setup(void){

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  server.on("/", [](){
    webPage = "<head><meta http-equiv='refresh' content='5'></head><h1>Micro weather station</h1><p>Temperature: "+String(temp)+"</p><p>Humidity: "+String(hum)+"</p>";
    server.send(200, "text/html", webPage);
  });
  
  server.begin();
}
 
void loop(){
  hum = sensor.readHumidity();
  temp = sensor.readTemperature();
  delay(500);
  server.handleClient();
} 
