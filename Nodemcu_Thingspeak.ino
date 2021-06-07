#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "motog5plus"; //Enter your WIFI ssid
const char *password = "omkar_1234"; //Enter your WIFI password
const char* server = "api.thingspeak.com";

String apiKey = "PC9JD7KM9IGDBAF0"; 

double data11 = 987;
WiFiClient client;
void setup() 
{
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
 

 
 
}

void loop() {

  float data = analogRead(A0);
  data11 = data;
  
  if (client.connect(server,80))   
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(data11);
                            
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("sensor value ");
                             Serial.print(data11);
                            
                             Serial.println("%. Send to Thingspeak.");
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  delay(50);

}
