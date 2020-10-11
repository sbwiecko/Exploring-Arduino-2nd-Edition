/*
Exploring Arduino, Second Edition
Code Listing 2-1: Turning on an LED
https://www.exploringarduino.com/content2/ch2

Copyright 2019 Jeremy Blum ( https://www.jeremyblum.com )
Licensed under MIT ( https://github.com/sciguy14/Exploring-Arduino-2nd-Edition/blob/master/LICENSE.md )
*/

const int LED=9;            // Define LED for pin 9
void setup()
{
  pinMode (LED, OUTPUT);    // Set the LED pin as an output
  digitalWrite(LED, HIGH);  // Set the LED pin high
}

void loop()
{
  // We are not doing anything in the loop!
}

/*

[9~]---/\/\/\/----|>!----GND
          R1      LED1

R=V/I where V=3V and I=20mA, R=150Ω < 220Ω
P=IV --> P=60mW < resistor's rating of 1/8W
 
 */
