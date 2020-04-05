/*
Servo test code for SG92R

Copyright 2020 Makoto Nishikawa

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/


#include <Servo.h>

#define PIN_SERVO_PWM  9
#define PIN_SW_LEFT    2
#define PIN_SW_CENTER  3
#define PIN_SW_RIGHT    4
#define PIN_ANALOG_CDS 0

#define CDS_DETECT_VAL 100


// servo instance
Servo servo;

// status definitions
int pumping = 0;


void setup() {

  // Initialize for Serial debug
  Serial.begin(115200);
 
  // Initialize for servo
  servo.attach(PIN_SERVO_PWM);
  servo.write(0);

  // Initialize for button
  pinMode(PIN_SW_LEFT, INPUT_PULLUP);
  pinMode(PIN_SW_CENTER, INPUT_PULLUP);
  pinMode(PIN_SW_RIGHT, INPUT_PULLUP);
}

void loop() {
  int i;
  int analog_val;
  
/*
  if(digitalRead(PIN_SW_RIGHT) == LOW){
    for(i=0;i<180;i+=30){
      servo.write(i);
      delay(500);
    }
    servo.write(180);
    delay(2000);
    for(i=180;i>0;i-=30){
      servo.write(i);
       delay(500);
    }
  } else if(digitalRead(PIN_SW_CENTER) == LOW) {
    servo.write(90);
  } else if(digitalRead(PIN_SW_LEFT) == LOW) {
    servo.write(0);
  }
  delay(500);
*/
// button operation
  if(digitalRead(PIN_SW_CENTER) == LOW){
    servo.write(90);
  } else if(digitalRead(PIN_SW_LEFT) == LOW) {
    servo.write(0);
  } else if(digitalRead(PIN_SW_RIGHT) == LOW) {
    servo.write(180);
  }

  
  // Read analog value from variable register
  analog_val = analogRead(PIN_ANALOG_CDS);
  // Debug print
  Serial.print("Cds value : ");
  Serial.print(analog_val, DEC);
  Serial.print("\n");

  if( analog_val>CDS_DETECT_VAL){
    // Debug print
    Serial.print("Detect cds dark state\n");
    if(pumping == 0){
      // pumping lequid
      Serial.print("Pumping lequid\n");
      servo.write(180);
      pumping = 1;
      delay(500);
      } 
  } else {
    Serial.print("Stop pumping\n");
    servo.write(0);
    pumping = 0;
  }
  
  //wait for loop
  delay(500);
  
}
