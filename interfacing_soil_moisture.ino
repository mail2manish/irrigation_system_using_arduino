#define moisture_sensorPin A0
const int avg_moisture=600; //for this value check readMe file.

void loop()
{
  if(analogRead(moisture_sensorPin) < avg_moisture) //less than condition
  {
    digitalWrite(relay1,HIGH); //turning realay1 low for turning on the motor
    digitalWrite(2,LOW); //turning on the moisture status LED
  }
  else if(analogRead(moisture_sensorPin) > avg_moisture) // more than condition
  {
    digitalWrite(relay1,LOW); //turning the relay1 low for turning on the motor
    digitalWrite(2,HIGH); //turning on the moisture status LED
  }
}
