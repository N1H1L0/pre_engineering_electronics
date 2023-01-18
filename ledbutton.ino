int buttonPin = 3;
int button;
int yell = 2;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(buttonPin, INPUT);
    pinMode(yell, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
   button = digitalRead(buttonPin);
   if (button == 1){
      digitalWrite(2, HIGH);
      
   }
   else{
      digitalWrite(2, LOW);
    
   }
   
  
}
