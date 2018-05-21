int sensorValue;
int sensorLow = 0;
int sensorHigh = 1023; //this will automatically change during the calibration loop
const int led = 2; //the LED's pin

void setup() {
  pinMode(led, OUTPUT);
  while (millis() < 500){ //calibration loop starts here 
  	sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh){ 
    	sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow){
    	sensorLow = sensorValue;
    }
  } //calibration loop ends here
}

void loop() {
  sensorValue = analogRead(A0);
  if(sensorValue == sensorHigh){
  	digitalWrite(led, HIGH);
  }
  else if(sensorValue == sensorLow){
  	digitalWrite(led, LOW);
  }
  else{
  	digitalWrite(led, LOW);
  }
}
