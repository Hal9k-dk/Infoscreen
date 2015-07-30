

#include <Time.h>

int relaypin = 7;
int ledpin = 13; 

int PIR_1 = 2;
int PIR_2 = 3;



unsigned long lastmovemnt = 0;
unsigned int offtime = 3600; //Seconds

void setup() {
Serial.begin(9600);
pinMode(relaypin, OUTPUT); 
pinMode(ledpin, OUTPUT); 
digitalWrite(relaypin, LOW);
digitalWrite(ledpin, LOW);

pinMode(PIR_1, INPUT); 
//attachInterrupt(0, movement, RISING);
//pinMode(PIR_2, INPUT); 
//attachInterrupt(1, movement, RISING);

}

void loop() {
Serial.print("Loop: ");
Serial.println(lastmovemnt);

Serial.print("PIR value: ");
Serial.println(PIR_1);

if (digitalRead(PIR_1)){
  lastmovemnt = now();
  }

if(now()- lastmovemnt < offtime){
  Serial.println("IF");
  digitalWrite(relaypin, HIGH);
  digitalWrite(ledpin, HIGH);
}
else if(now()- lastmovemnt > offtime){
  Serial.println("ELSE");
  digitalWrite(relaypin, LOW);
  digitalWrite(ledpin, LOW);
  }

delay(100); 
}


/*void movement(){
 detachInterrupt(0);
 //detachInterrupt(1);
 Serial.println("INTERRUPT");
 lastmovemnt = now();

 attachInterrupt(0, movement, RISING);
 //attachInterrupt(1, movement, RISING);
}*/
