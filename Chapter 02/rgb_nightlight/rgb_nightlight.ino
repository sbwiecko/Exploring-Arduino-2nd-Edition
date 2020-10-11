/*
Exploring Arduino, Second Edition
Code Listing 2-6: Toggling RGB LED Nightlight
https://www.exploringarduino.com/content2/ch2

-- FOR THIS SKETCH I AM USING A COMMON CATHODE INSTEAD OF COMMON ANODE LED --

Copyright 2019 Jeremy Blum ( https://www.jeremyblum.com )
Licensed under MIT ( https://github.com/sciguy14/Exploring-Arduino-2nd-Edition/blob/master/LICENSE.md )
*/

const int BLED=9;      // Blue LED ANODE on Pin 9
const int GLED=10;     // Green LED ANODE on Pin 10
const int RLED=11;     // Red LED ANODE on Pin 11
const int BUTTON=2;    // The Button is connected to pin 2

boolean lastButton = LOW;    // Last Button State
boolean currentButton = LOW; // Current Button State
int ledMode = 0;             // Cycle between LED states

void setup()
{
  pinMode (BLED, OUTPUT);   // Set Blue LED as Output
  pinMode (GLED, OUTPUT);   // Set Green LED as Output
  pinMode (RLED, OUTPUT);   // Set Red LED as Output
  pinMode (BUTTON, INPUT);  // Set button as input (not required)
}

/*
* Debouncing Function
* Pass it the previous button state,
* and get back the current debounced button state.
*/
boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);       // Read the button state
  if (last != current)                         // If it's different...
  {
    delay(5);                                  // Wait 5ms
    current = digitalRead(BUTTON);             // Read it again
  }
  return current;                              // Return the current value
}

/*
* LED Mode Selection
* Pass a number for the LED state and set it accordingly
* Note, since the RGB LED is COMMON ANODE, you must set the
* cathode pin for each color LOW for that color to turn ON.
*/
void setMode(int mode)
{
  //RED
  if (mode == 1)
  {
    digitalWrite(RLED, HIGH); // inversed all HIGH and LOW
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
  //GREEN
  else if (mode == 2)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  //BLUE
  else if (mode == 3)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
  //PURPLE (RED+BLUE)
  else if (mode == 4)
  {
    analogWrite(RLED, 255);
    analogWrite(GLED, 0);
    analogWrite(BLED, 170);
  }
  //TEAL (BLUE+GREEN)
  else if (mode == 5)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 255);
    analogWrite(BLED, 170);
  }
  //ORANGE (GREEN+RED)
  else if (mode == 6)
  {
    analogWrite(RLED, 255);
    analogWrite(GLED, 50);
    analogWrite(BLED, 0);
  }
  //WHITE (GREEN+RED+BLUE)
  else if (mode == 7)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
  //OFF (mode = 0)
  else
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
}

void loop()
{
  currentButton = debounce(lastButton);           // Read debounced state
  if (lastButton == LOW && currentButton == HIGH) // If it was pressed...
  {
    ledMode++;                                    // Increment the LED value
  }
  lastButton = currentButton;                     // Reset button value
  // If you’ve cycled through the different options,
  // reset the counter to 0
  if (ledMode == 8) ledMode = 0;
  setMode(ledMode);                               // Change the LED state
}

/*
+5V----o o----.<10k>----GND
              |
              |
             [2]


[9~ ]---<220>--|>!------GND
        R1     BLU       |
                         |
[10~]---<220>---|>!------.
                GRN      |
[11~]---<220>-----|>!----.
                  RED 
     
 */
