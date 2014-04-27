int LDR1, LDR2, LDR3;
int leftOffset = 0, rightOffset = 0, centre = 0, leftTest = 0, rightTest = 0, centreTest = 0;
int motorRight = 9, motorLeft = 10 ;
int right = 180, left = 180, rightSlow=80, leftSlow=80; 


void calibrate(){

  for (int x=0; x<10; x++) {
    delay(100);
    //trouver la val min et max exact
    LDR1 = map(analogRead(0),0,900,0,255);
    LDR2 = map(analogRead(1),0,900,0,255);
    LDR3 = map(analogRead(2),0,900,0,255);
    
    leftOffset = leftOffset + LDR1;
    centre = centre + LDR2;
    rightOffset = rightOffset + LDR3;
    delay(100);
  }
  leftOffset = leftOffset / 10; 
  rightOffset = rightOffset / 10;
  centre = centre / 10;
}

void test(){
  for (int y=0; y<5; y++){
    LDR1 = map(analogRead(0),0,900,0,255);
    LDR2 = map(analogRead(1),0,900,0,255);
    LDR3 = map(analogRead(2),0,900,0,255);
       
    leftTest = leftTest + LDR1;
    centreTest = centreTest + LDR2;
    rightTest = rightTest + LDR3;   
  }
  
  leftTest = leftTest / 5; 
  centreTest = centreTest/ 5;
  rightTest = rightTest / 5;
}

void setup(){
  pinMode(motorRight, OUTPUT); 
  pinMode(motorLeft, OUTPUT);
  //turn on a redled
  calibrate();
  delay(1000);
  //turn on a green led
  Serial.begin(9600);
}

void loop() {  
  
  test();

  if(leftOffset>leftTest){
    right=rightSlow;
  }else if(leftOffset>leftTest && centre > centreTest){
    right = 0;
  }else{
    right = right;
  }
  
  if(rightOffset>rightTest){
    left=leftSlow;
  }else if(rightOffset>rightTest && centre > centreTest){
    left = 0;
  }else{
    left = left;
  }
  
  analogWrite(motorRight,left); 
  analogWrite(motorLeft,right);
}



