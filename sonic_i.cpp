#define trigPinF 9    // Forward sensor trigger pin 
#define echoPinF 10   // Forward sensor echo pin #define trigPinB 6 // Bottom sensor trigger pin 
#define echoPinB 7    // Bottom sensor echo pin #define motorpinF 3 // Forward motor pin 
#define motorPin 5    // Bottom motor pin

void setup() 
{
  Serial.begin(9600);           // Initialize serial communication 
  pinMode (trigPinF, OUTPUT);   // Set trigger pin as output 
  pinMode (echoPinF, INPUT);    // Set echo pin as input 
  pinMode (trigPinB, OUTPUT);   // Set trigger pin as output
  pinMode (echoPinB, INPUT);    // Set echo pin as input 
  pinMode (motorPinF, OUTPUT);  // Set forward motor pin as output 
  pinMode (motorPinB, OUTPUT);  // Set bottom motor pin as output
}

void Loop () 
{
  Long durationF, distancef, duration, distance;  // Forward sensor distance measurement
  digitalWrite (trigPinF, LOW);
  delayMicroseconds (2);
  digitalWrite (trigPinF, HIGH);
  delayMicroseconds (10) ;
  digitalWrite(trigPinF, LOW);
  durationF = pulse[n (echoPinF, HIGH) ;
  distanceF = durationF * 0.034 / 2;
  Serial.print ("Forward distance: ");
  Serial.print (distance);
  Serial.printIn(" mm");
  
  // Bottom sensor distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds (2);
  digitalWrite (trigPinB, HIGH);
  delayMicroseconds (10);
  digitalWrite(trigPinB, LOW);
  duration = pulseIn (echoPinB, HIGH) ;
  distance = duration * 0.034 / 2;
  Serial.print ("Bottom distance: ");
  Serial.print (distance);
  Serial.printIn(" mm");
  
  // Vibration control based on distance measurements
  if (distanceF > 10) {
    digitalWrite (motorPinF, HIGH);
  } else {
    digitalWrite (motorPinF, LOW);
  }
  if (distance > 10) {
    digitalWrite (motorPinB, HIGH);
  } else {
    digitalwrite (motorPinB, LOW);
  }
  delay (100);
}
