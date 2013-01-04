/*
  Arrays
 
 Demonstrates the use of  an array to hold pin numbers
 in order to iterate over the pins in a sequence. 
 Lights multiple LEDs in sequence, then in reverse.
 
 Unlike the For Loop tutorial, where the pins have to be
 contiguous, here the pins can be in any random order.
 */

int timer = 100;           // The higher the number, the slower the timing.
int ledPins[] = { 
  13, 12, 11, 10, 9,8,7,6,5,4,2};       // an array of pin numbers to which LEDs are attached
int pinCount = 11;           // the number of pins (i.e. the length of the array)

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 3;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  int thisPin;
  // the array elements are numbered from 0 to (pinCount - 1).
  // use a for loop to initialize each pin as an output:

  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);      
  }
    // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  for (int i = 0; i<2; i++) {
    // loop from the lowest pin to the highest:
    for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
      // turn the pin on:
      digitalWrite(ledPins[thisPin], HIGH);   
      delay(timer);                  
      // turn the pin off:
      digitalWrite(ledPins[thisPin], LOW);  
    // read the analog in value:
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);   
    Serial.print("sensor = " );                       
    Serial.print(sensorValue);      
    Serial.print("\t output = ");      
    Serial.println(outputValue);   
    }

    // loop from the highest pin to the lowest:
    for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) { 
      // turn the pin on:
      digitalWrite(ledPins[thisPin], HIGH);
      delay(timer);
      // turn the pin off:
      digitalWrite(ledPins[thisPin], LOW);
          // read the analog in value:
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);   
    Serial.print("sensor = " );                       
    Serial.print(sensorValue);      
    Serial.print("\t output = ");      
    Serial.println(outputValue); 
    }
  }
  for (int j = 0; j < 100; j++ ){
    for (int i = 0; i < pinCount; i++) {
      //snag random pin
      int thisPin = random(12);
      // turn the pin on:
      digitalWrite(ledPins[thisPin], HIGH);
      delay(50);
      // turn the pin off:
      digitalWrite(ledPins[thisPin], LOW);
          // read the analog in value:
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);   
    Serial.print("sensor = " );                       
    Serial.print(sensorValue);      
    Serial.print("\t output = ");      
    Serial.println(outputValue); 

    }
  }
}


