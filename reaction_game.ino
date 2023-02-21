int led1 = 13;
int led2 = 12;
int led3 = 11;
int button1 = 4;
int button2 = 3;
int button3 = 2;
int read_1;
int read_2;
int read_3;

double total_score;
double scores[10];


  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  
 
}

void loop() {
  // put your main code here, to run repeatedly:
  
  reset();
  
}

int score(){
  //score the time and report total score
  for(int i = 0; i < 10; i++){
    Serial.print("Time for ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(scores[i]);
    Serial.println("");
    total_score += scores[i];
  }
  Serial.print("Your total time was: ");
  Serial.print(total_score);
}

void ran(){
  //pick random one to light and measure time
  for(int i = 0; i < 10; i ++){
    //int picked = random(1,4);
    int picked = 3;
    long start;
    long finish;
    if(picked == 3){
      digitalWrite(led3, HIGH);
      start = millis();
      while (true){
        int read_3 = digitalRead(button3);
        if (read_3 == 1){
          break();
        }
      }
      finish = millis();
     }
    scores[i] = finish - start;
    Serial.print(scores[i]);
    digitalWrite(led3, LOW);
    delay(200);
    }
    
  }
  //score();




void reset(){
  // reset the game to 0
  while (true){
    int read_1 = digitalRead(button1);
    int read_2 = digitalRead(button2);
    int read_3 = digitalRead(button3);
    if(read_1 + read_2 + read_3 == 3){
      ran();
      break;
    }
  }
}
