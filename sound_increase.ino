// defines pins numbers
const int trigPin = 6;
const int echoPin = 7;



void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() { 
  Serial.print("Distance: ");
  int distance = readSensor();
  Serial.println(distance);  
  int num = map(distance, 0, 200, 2000, 10);
  Serial.println(num);
  tone(11, num); 
}


int readSensor(){
  // defines variables
  long duration;
  int distance;
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance in cm
  distance = duration * 0.034 / 2;
  
  return distance;
  //turn on and off with delay so that it increases pitch as sensor reads far is away is bigger dealy is lower pitch so lower delay is a higher pitch
 }
