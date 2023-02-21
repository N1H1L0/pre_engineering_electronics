int led1 = 3;
int button1 = 2; 
long start;
long score = 0;
int led2 = 13;

long totalScore;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(button1, INPUT);
 
}

void loop() {
  int pressed = false;
  int button = digitalRead(button1);

  delay(1000);    
  int picked = random (1, 3);
  if(picked == 1){
    start = millis();
    digitalWrite(led1, HIGH);
 
      pressed = false;
      score = 0;
      
      while(true){    
        button = digitalRead(button1);
        if(pressed == false && button == 1){
        
          pressed = true;
          score = (millis() - start);
          Serial.print(score);
          Serial.print(" ms\n");
          digitalWrite(led1, LOW);
          break;
             
          
          
          
      }

      
    }
   
  }
  
  
  
  

  

}
