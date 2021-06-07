#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "motog5plus"; //Enter your WIFI ssid
const char *password = "omkar_1234"; //Enter your WIFI password

ESP8266WebServer server(80);

String page = "";
String page1 = "";
String page2 = "";

//double data;
double data11 = 987;
void setup(void) {

  pinMode(A0, INPUT);
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to");
  Serial.println(ssid);
  Serial.print("IP Address");
  Serial.println(WiFi.localIP());
  server.on("/", [](){
//    page = "<h1>Garbage Indicator SAKEC</h1>" + String(data11);
    page1 = "<h1>Garbage Indicator SAKEC</h1><h2>Garbage is Dry</h2><h4>Moisture Value</h4>" + String(data11);
    page2 = "<h1>Garbage Indicator SAKEC</h1><h2>Garbage is Wet</h2><h4>Moisture Value</h4>" + String(data11);
//    server.send(200, "text/html", page);
  });

  server.begin();
  Serial.println("Web server started");
}

void loop(void) {
  float data = analogRead(A0);
  data11 = data;
  page1 = "<h1>Garbage Indicator SAKEC</h1><h2>Garbage is Dry</h2><h4>Moisture Value</h4>" + String(data11);
  page2 = "<h1>Garbage Indicator SAKEC</h1><h2>Garbage is Wet</h2><h4>Moisture Value</h4>" + String(data11);
  Serial.println(data11);
  if (data11>=1015)
//  server.on("/", [](){
//  page1 = "<h1>Garbage is Wet</h1>" + String(data11);

  server.send(200, "text/html", page1);
//  });
  else
  server.send(200, "text/html", page2);
  delay(500);
  server.handleClient();
}
