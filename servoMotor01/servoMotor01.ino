// Project 30 - Line Following Robot

int LDR1, LDR2, LDR3;

//calib
int leftOffset = 0, rightOffset = 0, centre = 0;
// pins for motor speed and direction
int speed1 = 9, speed2 = 10 ;
// starting speed and rotation offset
int startSpeed = 130, rotate = 30;
// sensor threshold
int threshhold = 5;
// initial speeds of left and right motors
int left = startSpeed, right = startSpeed;

// Sensor calibration routine
void calibrate() {

  for (int x=0; x<10; x++) { // run this 10 times to obtain average

  delay(100);
  LDR1 = analogRead(0); // read the 3 sensors
//  LDR2 = analogRead(1);
  LDR3 = analogRead(2);
  leftOffset = leftOffset + LDR1; // add value of left sensor to total
  centre = centre + LDR2; // add value of centre sensor to total
  rightOffset = rightOffset + LDR3; // add value of right sensor to total
  delay(100);

  }
  // obtain average for each sensor
  leftOffset = leftOffset / 10; 
  rightOffset = rightOffset / 10;
  
  }

void setup()
{
    // set the motor pins to outputs
    pinMode(speed1, OUTPUT); 
    pinMode(speed2, OUTPUT);
    // calibrate the sensors
    calibrate();
    delay(3000);
     
    // set speed of both motors
  analogWrite(speed1,left); 
  analogWrite(speed2,right);
    Serial.begin(9600);
}

void loop() {
  
  // make both motors same speed
   left = startSpeed;
   right = startSpeed;
    
  // read the sensors and add the offsets
  LDR1 = analogRead(0) + leftOffset;
//  LDR2 = analogRead(1);
  LDR3 = analogRead(2) + rightOffset;
  Serial.println(LDR3);
  // if LDR1 is greater than the centre sensor + threshold turn right
  if (LDR1 > LDR3) {
    left = startSpeed + rotate;
    right = startSpeed - rotate; 
  } 
  
  // if LDR3 is greater than the centre sensor + threshold turn left
  if (LDR3 > LDR1) {
    left = startSpeed - rotate;
    right = startSpeed + rotate; 
  }
    // send the speed values to the motors
    analogWrite(speed1,left); 
    analogWrite(speed2,right);
}

