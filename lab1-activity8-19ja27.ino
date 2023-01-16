/**
lab1-activty3-19ja27.ino
Joshua Argiropoulos (19ja27@queensu.ca) 
2022-02-17
*/

int echoPin = 2; 
int trigPin = 3; 
//Sets the echo pin to 2 and the trig pin to 3

long echoTime; 
//creates variable for the echo time
int range; 
// creates variable for the range 
float period;
int ledState = LOW;  
//Has the LED light start off
unsigned long previousMillis = 0;   
const int ledPin =  LED_BUILTIN;

void setup() {
  pinMode(trigPin, OUTPUT); 
  // Used to set the trigPin as the output
  pinMode(ledPin, OUTPUT);
  //Used to create LED output
  pinMode(echoPin, INPUT); 
  //Used tp set the echoPin as the input
  Serial.begin(9600); 
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Turns the trigPin on for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // returns the echo time travel time in microseconds
  echoTime = pulseIn(echoPin, HIGH);
  // Calculating the range
  range = echoTime * 0.035 / 2; 
  //The range is equal to the echo time multiplied by the speed of sound divided 2. 
  
  
  if (range >= 400){
    period = 1000;
    //Period is equal to 1/(1 Hz) *1000 milliseconds
  }
  else if (range <= 2){
    period = 10;
    //period is equal to 1/(100 Hz) * 100 miliseconds 
  }
  else {
    period = range*2.487+5.025;
    //Used the equation of a line between 1000 and 10 for the period 

  }
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (period/2)) {
    //period divided by 2 because this is the time between On to Off and not a full cycle of On to Off to On again
    //save the last time you blinked the LED
    previousMillis = currentMillis;

    // Used to change the state of the LED light from On to Off or Off to On
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
    //Displays the output of the LED to the arduino board  
  }
  delay(100);
  Serial.println(period/2);
  //Print statement to interval of which the LED blinks 

}
