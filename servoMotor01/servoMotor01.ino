

//PhotoResistor Pin
int lightPin = 0; 
//LED Pin
int ledPin = 9;   

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop(){ 
  int threshold = 300; 
  if(analogRead(lightPin) > threshold){ 
    digitalWrite(ledPin, HIGH); 
  }else{ 
    digitalWrite(ledPin, LOW); 
  } 
} 

