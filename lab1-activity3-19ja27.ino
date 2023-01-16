/**
lab1-activty3-19ja27.ino
Joshua Argiropoulos (19ja27@queensu.ca) 
2022-02-17
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  if (buttonState == 1) {
    digitalWrite(LED_BUILTIN, HIGH);
    //Checks if push button is on or in state 1 and turns the LED on 
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
    //If push button is not being pressed, turns the LED off
  }
  Serial.println(buttonState);
  delay(1);        // delay in between reads for stability
}
