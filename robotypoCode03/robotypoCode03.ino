int LDR1, LDR2, LDR3; // sensor values
int LDR1max, LDR1min, LDR2max, LDR2min,LDR3max,LDR3min;
int ledR = 13, ledO = 12, ledV =8;
int speed1 = 9, speed2 = 10 ;
int startSpeed = 150;
int threshhold = 5;
int left = startSpeed, right = startSpeed;

// Sensor calibration
void calibrate() {
  digitalWrite(ledR, HIGH);
  delay(3000);
  for (int x=0; x<10; x++) {
  LDR1 = analogRead(0);
  LDR2 = analogRead(1);
  LDR3 = analogRead(2);
  LDR1max = LDR1max+LDR1;
  LDR2max = LDR2max+LDR2;
  LDR3max = LDR3max+LDR3;
  }
  LDR1max = LDR1max/10;
  LDR2max = LDR2max/10;
  LDR3max = LDR3max/10;
  digitalWrite(ledR, LOW);
  digitalWrite(ledO, HIGH);
  
  delay(3000);
  
  for (int x=0; x<10; x++) {
  LDR1 = analogRead(0);
  LDR2 = analogRead(1);
  LDR3 = analogRead(2);
  LDR1min = LDR1min+LDR1;
  LDR2min = LDR2min+LDR2;
  LDR3min = LDR3min+LDR3;
  }
  LDR1min = LDR1min/10;
  LDR2min = LDR2min/10;
  LDR3min = LDR3min/10;
  digitalWrite(ledO, LOW);
  digitalWrite(ledV, HIGH);
}

void setup(){
    pinMode(ledR,OUTPUT);
    pinMode(ledO,OUTPUT);
    pinMode(ledV, OUTPUT);
    pinMode(speed1, OUTPUT); 
    pinMode(speed2, OUTPUT);
    
   // calibrate();
    delay(3000);
    digitalWrite(ledV, HIGH);
    delay(100);
    analogWrite(speed1,left); 
    analogWrite(speed2,right);
}

void loop() {
  
  // make both motors same speed
  left = startSpeed;
  right = startSpeed;
  //read sensor
//  LDR1 = map(analogRead(0),LDR1min,LDR1max,0,255);
//  LDR2 = map(analogRead(1),LDR2min,LDR2max,0,255);
//  LDR3 = map(analogRead(2),LDR3min,LDR3max,0,255);
  
  LDR1 = analogRead(0);
  LDR2 = analogRead(1);
  LDR3 = analogRead(2);
  
  // if LDR1 is greater than the centre sensor + threshold turn right
  if (LDR1 > (LDR2+threshhold)) {
    right = 0;
    left = startSpeed; 
  } else if (LDR3 > (LDR2+threshhold)) {
    right = startSpeed;
    left = 0; 
  }else{
    left = startSpeed ;
    right = startSpeed ;
    
  }
    // send the speed values to the motors
    analogWrite(speed1,left); 
    analogWrite(speed2,right);
}


