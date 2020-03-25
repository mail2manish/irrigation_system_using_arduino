***** water irrigation system using arduino*****
devloped by :- Manish prakash jadhav
----------------------------------------------------------------------------
this is the readme file for the following project please read the readme file first to understand the project
and it's pre-requisites.

1)Software –
Here, for interfacing the hardware with the main board, we are using Arduino IDE 1.8.8 software. 
It will provide better and efficient working environment for coding. 
The Arduino integrated development environment (IDE) is a cross-platform application (for Windows, macOS, Linux) that is written in the programming language Java. 
It is used to write and upload programs to Arduino compatible boards, but also, with the help of 3rd party cores, other vendor development boards


2)Transfer Rate Setting –
We have to interface so many different modules with Arduino board. 
Hence each module will work with its compatible serial rate i.e. “Baud Rate”. 
The baud rate is nothing but the number of bites transfers within 1 second. 
It varies from module to module. For the serial communication of GSM module we have to set the baud rate of communication to 9600. 
And for the NodeMCU, we have to set communication rate to 115200.


3)NodeMCU setting –
For interfacing ESP8266 with the Arduino we have to make changes into the software before uploading the code into the Wi-Fi module. This is mandatory for both LAN i.e. (Local Area Network) and for Cloud network the following are the steps to add NodeMCU board into Arduino IDE.
Steps: -
1. Click on file then preferences then just paste this URL into URL box 
“http://arduino.esp8266.com/versions/2.5.0/package_esp8266com_index.json " hit ok.
 
2. Go to tools then boards then board manager then it will search for the update let it do. Then simply type ESP8266 into the filter box then install the latest version.

3. Go to sketch then include library then manage libraries then search for aRest and download both the aRest related liberaries.

4. Then download PubSubClient library from the same section.

5. Once everything is set you are ready to set your NodeMCU 

6. NOTE: - make sure your baud rate is set to 115200



4)moisture sensor details:-
Here we have defined the pin A0 of Arduino as “moisture_sensorPin”. That will take input from the sensor. 
And set the average moisture level by defining the constant of integer data type to 600 and named it as “avg_moisture”.
Now in void loop(). The if loop will check the condition that is defined. 
If the condition gets true the block of if will get execute.othervise block of else-if will be execute.



5)ultrasonic sensor details:-
Here we have defined the trigger pin of sensor to digital pin 5 of Arduino. 
And echo pin of sensor to digital pin 3 of Arduino. Then we took two constants to store the calculated data from the sensor. 
then in void setup(), we have set the trig pin as output and echo pin as input.
In void loop() firstly we are keeping the trig pin off for 2 ms. Then turning it on for 10ms. 
Then again turned it off. This is how the trigger pin will generate the ultrasonic sound for the time duration of 10ms. 
then once this is done we have took “duration” to store the value from echo pin by enabling the echo pin using “pulseIn” .
Then once all this is done. We will finally calculate the distance by using the above formula. 
Then according to the distance the respective if and else-if loop will execute.


6)relay to arduino connection:-

Here we have define i1 to the digital pin 8 of arduino. And then in vid setup() we have to put the relay off for the initial stage.
 So here in relays LOW means it will turn on the relay. And the HIGH means it will turn of the relay.
the relay’s HIGH/LOW will be written into the appropriate condition of sensors in void loop().


7)Submersible motor with relay:-
Every relay module comes with three output nodes. This is known for NC, COM and NO i.e. normally closed, common and normally open respectively, here we don’tNeed to write any code to drive the motor but have to make proper connection so that motor will switch on/off only when the relay gets triggered.
We have made the same connection as shown above. 
•	Positive of motor will go into the COM of relay.
•	Positive of battery will go into the NO of relay.
•	And last but not the least negative of battery will go to the negative of motor.



8)GSM module to Arduino details:-
Interfacing the GSM module with Arduino is simplest among rest of the interfacings in this project. 
We just have to connect GND of GSM module to GND of Arduino. 
And Tx, Rx of GSM module to the Tx, Rx of Arduino board and that’s it. We are ready to use GSM module.
Note that before uploading the code into the Arduino just unplugged the Tx and Rx pins aside so that controller will assume that there is no communication happening before. 
Here Tx stands for transmission and Rx stands for receiver. We have to connect Tx of GSM module to the Rx of Arduino. 
And Rx of GSM module to the Tx of Arduino. 
Once everything is set. Wait for the coverage. 
If the network led is blinking firstly it means that the SIM card has no coverage it may take few seconds or minutes to set the SIM for communication. 
Once the led start blinking slowly means that you got the coverage.

//programming explained
Here we are using “SoftwareSerial” library for making any pin of Arduino board as a Tx and Rx. 
Here we have defined A2 and A3 as Tx and Rx respectively. Then once this is set. 
In void loop() it will check for the condition that whether the water level in the tank is greater than 15 or not. 
If yes, it will send the message to the mentioned phone number.



9)lan_network_for_MCU explained:-
we will create our own html page that will provide you two active buttons for switching the motor ON/OFF. 
So firstly we are entereing the Wi-Fi username and password into SSID and password. 
Then we are defining the D0 of NodeMCU as a relay pin. Once this is done.
In void setup(), serial communication will starts with 115200 baud rate.
Then here at initial state we are keeping the relay off. Then the WiFi.begin() is called to get connected to the Wi-Fi. 
Once it is connected, it will print “WIFI connected” and will generate device’s logical address which is called as IP address (internet protocol). 
All these things will be displayed on the serial monitor. Note that for displaying all this things on serial monitor we have to set the same baud rate of serial monitor as the baud rate that we have defined into the code. 
We will be using that generated IP address for accessing the motor. 
Just paste the address into the browser and hit enter. It will redirect you to our html page that will provide two buttons.
Note that for redirecting to our html page you have to be in the same network in which the NodeMCU is connected.

