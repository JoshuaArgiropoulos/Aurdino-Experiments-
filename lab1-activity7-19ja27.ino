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

void setup() {
  pinMode(trigPin, OUTPUT); 
  // Used to set the trigPin as the output
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

  Serial.print("The range is: ");
  Serial.print(range);
  Serial.println(" cm");
  //print statement to display the range 
}
