/*
Water the plants

Copyright 2019 Makoto Nishikawa

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// I/O port definitions
#define PORT_WATER_PUMP_SWITCH 2
#define PORT_LED 3
#define PORT_RUN_BUTTON 4


// Planning for water the plants
#define OPERATING_PERIOD_MS 1000 // 1sec
//#define WAIT_TIME (24*60*60UL) // 1day
//#define EXECUTION_TIME (60) //60sec
#define RUNNING_TIME (10) //20sec for test
#define WAIT_TIME (30) // 5 sec for test

unsigned int wait_counter = WAIT_TIME;
unsigned int running_counter = 0;

// Prototype definitions
void water_the_plants(boolean runnning_pump);
void print_status();

void setup() {

  // Serial output for debug
  Serial.begin(115200);

  // initialize ports
  pinMode(PORT_WATER_PUMP_SWITCH, OUTPUT);
  pinMode(PORT_LED, OUTPUT);
  pinMode(PORT_RUN_BUTTON, INPUT_PULLUP);

  // Disable LED
  digitalWrite(PORT_LED, LOW);

}

void loop() {

  // Press RUN button
  if(digitalRead(PORT_RUN_BUTTON) == LOW){
    water_the_plants(true);
    // reset counter
    running_counter = RUNNING_TIME;
    wait_counter = WAIT_TIME;
  } 

  // Count down and check the wait counter
  wait_counter--;
  if(wait_counter <= 0){
    water_the_plants(true);
    running_counter = RUNNING_TIME;
    wait_counter = WAIT_TIME;
  }

  // Count down and check the runnning counter
  if(running_counter > 0){
    running_counter--;
    // Enable LED
    digitalWrite(PORT_LED, HIGH);
    if(running_counter == 0){
      running_counter = RUNNING_TIME;
      water_the_plants(false);
      running_counter = 0;
      // Disable LED
      digitalWrite(PORT_LED, LOW);
    }
  }

  // Print system status (for debug)
  print_status();

  // wait for next oparation
  delay(OPERATING_PERIOD_MS);

}

// Water the Plants
void water_the_plants(boolean runnning_pump) {
  if(runnning_pump == true){
     digitalWrite(PORT_WATER_PUMP_SWITCH, HIGH);
  } else {
     digitalWrite(PORT_WATER_PUMP_SWITCH, LOW);
  }
}

// Print system status (for debug)
void print_status() {
  Serial.print("---Operation period---\n");
  Serial.print("wait_counter  : ");
  Serial.print(wait_counter, DEC);
  Serial.print("\n");
  Serial.print("running_counter  : ");
  Serial.print(running_counter, DEC);
  Serial.print("\n");
}
