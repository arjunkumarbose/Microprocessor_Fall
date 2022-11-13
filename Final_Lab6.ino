int distanceThreshold = 0; int cm = 0;
int inches = 0;
long readUltrasonicDistance (int triggerPin, int echoPin) {
pinMode (triggerPin, OUTPUT); // Clear the trigger digitalWrite (triggerPin, LOW);
delayMicroseconds(2);
// Sets the trigger pin to HIGH state for 10 microseconds
digitalWrite (triggerPin, HIGH); delayMicroseconds(10); digitalWrite (triggerPin, LOW); pinMode (echoPin, INPUT);
// Reads the echo pin, and returns the sound wave travel time in microseconds
return pulseIn (echoPin, HIGH); }

void setup()
{
  Serial.begin(9600); pinMode(2, OUTPUT); pinMode(3, OUTPUT);
  pinMode(4, OUTPUT); 
}

void loop()
{
  // set a threshold distance to activate LEDs
  //considering the features of ultrasonic sensor
  distanceThreshold = 80;
  // measure the ping time in cm, 340m/s=0.034cm/μs, therefore 0.034/2=0.017 mainly as the signal is working as echo
  cm = 0.017 * readUltrasonicDistance(7, 6);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54); Serial.print(cm); Serial.print("cm, "); Serial.print(inches); Serial.println("in");
  if (cm > distanceThreshold) 
  { 
    digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW);
  }
  if (cm < distanceThreshold && cm > distanceThreshold-20 ) 
  { 
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (cm < distanceThreshold-20 && cm > distanceThreshold-30 ) 
  { 
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  if (cm < distanceThreshold-30 && cm > distanceThreshold-70 ) 
  { 
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(100); // Wait for 100 millisecond(s) }
}
