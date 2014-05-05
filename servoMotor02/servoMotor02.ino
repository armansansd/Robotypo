int LDR1, LDR2, LDR3;
int leftOffset = 0, rightOffset = 0, centre = 0, leftTest = 0, rightTest = 0, centreTest = 0;
int motorRight = 9, motorLeft = 10 ;
int right = 100, left = 200, rightSlow=80, leftSlow=80; 
int LDR1max, LDR1min, LDR3max, LDR3min;
int LDR1comp,LDR3comp;

void calibrate(){
  LDR1max = analogRead(0);
  LDR1min = LDR1max-300;
  LDR3max = analogRead(2);
  LDR3min = LDR3max-300;
 
  LDR1comp=map(analogRead(0),LDR1min,LDR1max,0,255);
  
}



void setup(){
  pinMode(motorRight, OUTPUT); 
  pinMode(motorLeft, OUTPUT);
  calibrate();
  delay(1000);
  Serial.begin(9600);
  Serial.print(LDR1comp);
}

void motorLeftOn(){
  analogWrite(motorLeft,170);
}

void motorRightOn(){
  analogWrite(motorRight,110);
}

void motorRightOff(){
  analogWrite(motorRight,0);
}
void motorLeftOff(){
  analogWrite(motorLeft,0);
}

void loop() { 
  
  LDR1 = map(analogRead(0),LDR1min,LDR1max,0,255);
  LDR3 = map(analogRead(2),LDR3min,LDR3max,0,255); 
  
  if(LDR1<190){
    motorLeftOn();
    motorRightOff();
  }else if(LDR3<220){
    motorLeftOff();
    motorRightOn();
  }else{
    motorLeftOn();
    motorRightOn();
  }

}


