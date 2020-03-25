#include<SoftwareSerial.h>
SoftwareSerial mySerial(A2,A3);

while(distance > 15)
{
  if(Serial.avilable()>0)
  switch(Serial.read())
  {
    case 'a':
    mySerial.println("AT+CMGF=1"); sets the gsm module in text mode
    delay(1000); //delay of 1 second
    mySerial.println("AT+CMGS=\"+91**********\"\r"); //replace * with mobile number
    delay(1000);
    mySerial.println("your soil moisture level is low"); // the SMS text you want to send
    mySerial.println("your tank level is low");
    mySerial.println("would you like to turn on the motor or not ?");
    delay(1000);
    mySerial.println((char)26); // ASCII code of CTRL+Z for saying the end of sms to the module
    delay(1000);
    
  }
}
