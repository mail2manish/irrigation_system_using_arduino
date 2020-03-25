#include<ESP8266WiFi.h>
const char* ssid="your hotspot/wifi name";
const char* password="your password";
int relay=D0;
WiFiServer Server(80);

void setup()
{
  Serial.begin(115200);
  delay(10);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGH);
  Serial.println();
  
  Serial.println();
  Serial.print("Connecting to");

  Serial.print(ssid);
  WiFi.begin(ssid,password);
  whiel(WiFi.status() !=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("");
  Serial.println("WIFI CONNECTED");
  Server.begin)();
  Serial.println("Server started");

  Serial.print("use this url to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
