//INSTRUCTIONS
//Please Install Arduino IDE Software and copy this code in new file
//Compile and upload the code
//Whenever the odour reaches the threshold value it sends SMS alert  
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  int sensor=analogRead(A1);
  if (Serial.available()>0)

if (sensor>5 or Serial.read())
{
  SendMessage();
  delay(30000);
}

 if (mySerial.available()>0)
   Serial.write(mySerial.read());

}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917981777562\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Washroom is dirty please go and clean it");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(100000);
}
