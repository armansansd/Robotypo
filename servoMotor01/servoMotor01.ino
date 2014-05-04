int LDR1, LDR2, LDR3;
int leftOffset = 0, rightOffset = 0, centre = 0, leftTest = 0, rightTest = 0, centreTest = 0;
int motorRight = 9, motorLeft = 10 ;
int right = 100, left = 200, rightSlow=80, leftSlow=80; 


//void calibrate(){
//
//  for (int x=0; x<10; x++) {
//    delay(100);
//    //trouver la val min et max exact
//    LDR1 = map(analogRead(0),0,900,0,255);
//    LDR2 = map(analogRead(1),0,900,0,255);
//    LDR3 = map(analogRead(2),0,900,0,255);
//    
//    leftOffset = leftOffset + LDR1;
//    centre = centre + LDR2;
//    rightOffset = rightOffset + LDR3;
//    delay(100);
//  }
//  leftOffset = leftOffset / 10; 
//  rightOffset = rightOffset / 10;
//  centre = centre / 10;
//}

//void test(){
//  for (int y=0; y<10; y++){
//    LDR1 = map(analogRead(0),600,900,0,255);
//    LDR2 = map(analogRead(1),0,900,0,255);
//    LDR3 = map(analogRead(2),0,900,0,255);
//       
//    leftTest = leftTest + LDR1;
//    centreTest = centreTest + LDR2;
//    rightTest = rightTest + LDR3;   
//  }
//  
//  leftTest = leftTest / 10; 
//  centreTest = centreTest/ 10;
//  rightTest = rightTest / 10;
//}



void setup(){
  pinMode(motorRight, OUTPUT); 
  pinMode(motorLeft, OUTPUT);
  //turn on a redled
  //turn on a green led
  Serial.begin(9600);

}
void motorLeftOn(){
  analogWrite(motorLeft,160);
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

void loop() { 
  
  LDR1 = map(analogRead(0),600,900,0,255);
  LDR2 = map(analogRead(1),500,800,0,255);
  LDR3 = map(analogRead(2),580,795,0,255); 
  
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


