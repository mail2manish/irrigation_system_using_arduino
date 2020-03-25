const int trigpin=5;
const int echopin=3;
long duration=0;
long distance=0;

void setup()
{
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  
}

void loop()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance-(duration/2) * 0.0343;
  Serial.println(distance);
  delay(1000);

  if(distance < 15)
  {
    digitalWrite(8,LOW);
  }

  else if(distance > 15)
  {
    digitalWrite(8,HIGH);
    digitalWrite(relay1,LOW);
  }
}
