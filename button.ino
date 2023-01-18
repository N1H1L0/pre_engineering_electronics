
int reading;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = digitalRead(2);
  Serial.println(reading);
  delay(50);
  
}
