/*
Exploring Arduino, Second Edition
Code Listing 2-3: LED Fade Sketch
https://www.exploringarduino.com/content2/ch2

Copyright 2019 Jeremy Blum ( https://www.jeremyblum.com )
Licensed under MIT ( https://github.com/sciguy14/Exploring-Arduino-2nd-Edition/blob/master/LICENSE.md )
*/

const int LED=9;   // Define LED for Pin 9
void setup()
{
  pinMode (LED, OUTPUT);    // Set the LED pin as an output
}

void loop()
{
  for (int i=0; i<256; i++) // 8 bits value from 2^0 (0) to 2^8-1 (255)
  {
    analogWrite(LED, i);    // PWM (pulse-width modulation)
    delay(10);
  }
  for (int i=255; i>=0; i--)
  {
    analogWrite(LED, i);
    delay(25);
  }
}
