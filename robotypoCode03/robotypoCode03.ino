int LDR1, LDR2, LDR3; // sensor values
int ledR = 13, ledO = 12, ledV =8;
// calibration offsets
int leftOffset = 0, rightOffset = 0, centre = 0;
// pins for motor speed and direction
int speed1 = 9, speed2 = 10 ;
// starting speed and rotation offset
int startSpeed = 95, rotate = 5;
// sensor threshold
int threshhold = 10;
// initial speeds of left and right motors
int left = startSpeed, right = startSpeed;

// Sensor calibration routine
void calibrate() {

  for (int x=0; x<10; x++) { // run this 10 times to obtain average
  digitalWrite(ledR, HIGH); // lights on
  delay(100);
  LDR1 = analogRead(0); // read the 3 sensors
  LDR2 = analogRead(1);
  LDR3 = analogRead(2);
  leftOffset = leftOffset + LDR1; // add value of left sensor to total
  centre = centre + LDR2; // add value of centre sensor to total
  rightOffset = rightOffset + LDR3; // add value of right sensor to total
  
  delay(100);
  digitalWrite(ledR, LOW); // lights off
  delay(100);
  }
  // obtain average for each sensor
  leftOffset = leftOffset / 10; 
  rightOffset = rightOffset / 10;
  centre = centre /10;  
  // calculate offsets for left and right sensors
  leftOffset = centre - leftOffset;
  rightOffset = centre - rightOffset;
  }

void setup()
{
    // set the motor pins to outputs
    pinMode(ledR,OUTPUT);
    pinMode(ledO,OUTPUT);
    pinMode(ledV, OUTPUT);
    pinMode(speed1, OUTPUT); 
    pinMode(speed2, OUTPUT);
    // calibrate the sensors
    calibrate();
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


