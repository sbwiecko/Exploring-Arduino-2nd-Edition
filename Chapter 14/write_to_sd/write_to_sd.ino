/*
Exploring Arduino, Second Edition
Code Listing 14-1: SD Card Write Test
https://www.exploringarduino.com/content2/ch14

Copyright 2019 Jeremy Blum ( https://www.jeremyblum.com )
Licensed under MIT ( https://github.com/sciguy14/Exploring-Arduino-2nd-Edition/blob/master/LICENSE.md )
*/

//Write to SD card

#include <SD.h> //Include the SD Card Library

//These are set by default via the SD card library
//MOSI = Pin 11
//MISO = Pin 12
//SCLK = PIN 13

//We always need to set the CS Pin
const int CS_PIN  = 10;

void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing Card");
  
  //CS pin must be configured as an output
  pinMode(CS_PIN, OUTPUT);
 
  if (!SD.begin(CS_PIN))
  {
    Serial.println("Card Failure");
    while(1);
  }
  Serial.println("Card Ready"); 
}

void loop()
{
  long timeStamp = millis();
  String dataString = "Hello There!";
 
  //Open a file and write to it. 
  File dataFile = SD.open("log.csv", FILE_WRITE);
  if (dataFile)
  {
    dataFile.print(timeStamp);
    dataFile.print(",");
    dataFile.println(dataString);
    dataFile.close(); //Data isn't written until we run close()!
  
    //Print same thing to the screen for debugging
    Serial.print(timeStamp);
    Serial.print(",");
    Serial.println(dataString);
  }
  else
  {
    Serial.println("Couldn't open log file");
  }
  delay(5000);
}

