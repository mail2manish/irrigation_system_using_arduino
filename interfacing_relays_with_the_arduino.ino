#define relay1 8

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(relay1,OUTPUT);
  digitalWrite(relay1,HIGH);
}
