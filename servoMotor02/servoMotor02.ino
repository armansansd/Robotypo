int ledR = 13, ledO = 12, ledV =8;
int motorRight = 9, motorLeft = 10 ;
//capteurs
int LDR1, LDR2, LDR3;
int LDR1test, LDR3test, LDR1max, LDR1min, LDR3max, LDR3min, LDR1comp, LDR3comp;

void calibrate(){
  digitalWrite(ledR,HIGH);
  delay(3000);
  for(int i=0; i<5; i++){
    LDR1 = analogRead(0);
    LDR3 = analogRead(2);
    LDR1test = LDR1test + LDR1;
    LDR3test = LDR3test + LDR3;
   }
  
  LDR1max = LDR1test/5;
  LDR3max = LDR3test/5;
  
  
  digitalWrite(ledR,LOW);
  //reset test ? 
  LDR1test = 0;
  LDR3test = 0;
  digitalWrite(ledO,HIGH);
  delay(3000);
  for(int j=0; j<5; j++){
    LDR1 = analogRead(0);
    LDR3 = analogRead(2);
    LDR1test = LDR1test + LDR1;
    LDR3test = LDR3test + LDR3;
  }
  LDR1min = LDR1test/5;
  LDR3min = LDR3test/5;
  
  digitalWrite(ledO,LOW);

  digitalWrite(ledV,HIGH);
}

void setup(){
  Serial.begin(9600);
  pinMode(ledR,OUTPUT);
  pinMode(ledO,OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(motorRight, OUTPUT); 
  pinMode(motorLeft, OUTPUT);
  calibrate();
  delay(3000);
  LDR1comp = map(analogRead(0),LDR1min,LDR1max,0,255)-10;
  LDR3comp = map(analogRead(2),LDR3min,LDR3max,0,255)-10;
  
}

void loop() {
  LDR1 = map(analogRead(0),LDR1min,LDR1max,0,255);
  LDR3 = map(analogRead(2),LDR3min,LDR3max,0,255);
  
 
  if(LDR3<LDR3comp){
    motorLeftOff();
    motorRightOn();
  }
  else if(LDR1<LDR1comp){
    motorLeftOn();
    motorRightOff();
  }else{
    motorLeftOn();
    motorRightOn();
 }

}

void motorLeftOn(){
  analogWrite(motorLeft,110);
}

void motorRightOn(){
  analogWrite(motorRight,100);
}

void motorRightOff(){
  analogWrite(motorRight,0);
}
void motorLeftOff(){
  analogWrite(motorLeft,0);
}

