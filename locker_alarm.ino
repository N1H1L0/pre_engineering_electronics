/* Use a photoresistor (or photocell) to turn on an LED in the dark
   More info and circuit schematic: http://www.ardumotive.com/how-to-use-a-photoresistor-en.html
   Dev: Michalis Vasilakis // Date: 8/6/2015 // www.ardumotive.com */

#include <NewPing.h>

#define TRIGGER_PIN  11
#define ECHO_PIN 10
#define MAX_DISTANCE 200

int dist;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

//Constants
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int ledPin=9;       // Led pin at Arduino pin 9

//Variables
int value; // Store value from photoresistor (0-1023
int light = 400;
int wall = 4;


void setup(){
 Serial.begin(9600);  
 pinMode(ledPin, OUTPUT);  // Set lepPin - 9 pin as an output
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
 
}

void loop(){
 
  dist = sonar.ping_cm();
  

  
  value = analogRead(pResistor);
  Serial.print(dist);
  Serial.print("  cm\n");
  Serial.println(value);

  delay(500); 
  
  alarm();
  
}

void alarm(){

  if(value >= light){
    if(dist <= wall && dist != 0){
      Serial.println("good");
      
    }
    else{
     for(int i = 0; i < 100; i++){
      digitalWrite(9, HIGH);
      delay(100);
      digitalWrite(9, LOW);
       delay(100);
     }
      
      
    }
    
  }
  
}
