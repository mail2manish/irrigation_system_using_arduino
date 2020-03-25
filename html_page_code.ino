int value=LOW;
if(request.indexof("/MOTOR=ON") != -1)
{
 digitalWrite(relay,LOW);
 value=HIGH; 
}
if(request.indexOf(" /MOTOR=OFF") != -1)
{
  digitalWrite(relay,HIGH);
  value=LOW;
}

client.println("HTTP/1.1 200 OK");
client.println("connect type: text/html");
client.println("");
client.println("!DOCTYPE HTML>");
client.println("<html>");
client.print("MOTOR is now: ");

if(value== HIGH)
{
  client.print("ON");
}
else
{
  client.print("OFF");
}
client.println("<br><br>");
delay(1);
Serial.println("client dissconnected");
Serial.println("");
}
