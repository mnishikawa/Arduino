/*
Anpanman jukebox 2

Copyright 2020 Makoto Nishikawa

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


----
This code is based on "Melody" created by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone

*/
#include "pitches.h"
#include "anpan_melody2.h"

// Pin definitions
#define PIN_SPEAKER     2

#define PIN_7SEGLED_E  11
#define PIN_7SEGLED_D  12
#define PIN_7SEGLED_C   4
#define PIN_7SEGLED_DP  5
#define PIN_7SEGLED_B   6
#define PIN_7SEGLED_A   7
#define PIN_7SEGLED_F   9
#define PIN_7SEGLED_G  10

#define PIN_ADVOL       0

// Define variable register value
#define MAX_REGISTER_VAL 1024
#define MELODY_STEP      (MAX_REGISTER_VAL / 8)



// prototype definition
void play_melody(int melody_no);
int read_melody_num();
void display_melody_num(int number);
int wait_for_switch = 0;


// setup function
void setup() {

  // Initialize for Serial debug
  Serial.begin(115200);

  // initialize for LED port
  pinMode(PIN_7SEGLED_A, OUTPUT);
  digitalWrite(PIN_7SEGLED_A, HIGH);
  pinMode(PIN_7SEGLED_B, OUTPUT);
  digitalWrite(PIN_7SEGLED_B, HIGH);
  pinMode(PIN_7SEGLED_C, OUTPUT);
  digitalWrite(PIN_7SEGLED_C, HIGH);
  pinMode(PIN_7SEGLED_D, OUTPUT);
  digitalWrite(PIN_7SEGLED_D, HIGH);
  pinMode(PIN_7SEGLED_E, OUTPUT);
  digitalWrite(PIN_7SEGLED_E, HIGH);
  pinMode(PIN_7SEGLED_F, OUTPUT);
  digitalWrite(PIN_7SEGLED_F, HIGH);
  pinMode(PIN_7SEGLED_G, OUTPUT);
  digitalWrite(PIN_7SEGLED_G, HIGH);
  pinMode(PIN_7SEGLED_DP, OUTPUT);
  digitalWrite(PIN_7SEGLED_DP, HIGH);
}

// main loop
void loop() {
  int melody;
  
  //select a melody
  melody = read_melody_num();

  switch (melody) {
    case 0:
      // Wait for melody select
      if(wait_for_switch == 0) {
        display_melody_num(10);
        wait_for_switch = 1;
      } else {
        display_melody_num(0);
        wait_for_switch = 0;
      }
      delay(500);
      break;

    case 7:
      // play anpan melody
      play_melody(1);
      play_melody(2);
      play_melody(3);
      play_melody(4);
      break;
    
    default:
      //play melody
      play_melody(melody);
      break;
  }

  // delay
  //  delay(1000); // delay 1 sec

}


void play_melody(int melody_no) {
  // iterate over the notes of the melody:
  for (uint16_t thisNote = 0; thisNote < pgm_read_word(&notenum[melody_no]); thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    uint16_t noteDuration = 1000 / pgm_read_word(&noteDurations[melody_no][thisNote]);
    tone(PIN_SPEAKER, pgm_read_word(&melody[melody_no][thisNote]), noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    uint16_t pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(PIN_SPEAKER);
    // Update melody number
    read_melody_num();
  }

}


int read_melody_num() {

  int retval = 0;
  int analog_val = 0;

  // Read analog value from variable register
  analog_val = analogRead(PIN_ADVOL);

  // Get melody number
  retval = analog_val / MELODY_STEP;

  // Debug print
//  Serial.print("register value : ");
//  Serial.print(analog_val, DEC);
//  Serial.print("\n");
//  Serial.print("melody number : ");
//  Serial.print(retval, DEC);
//  Serial.print("\n");

  // Display melody number
  display_melody_num(retval);


  return retval;

}

void display_melody_num(int number) {


  switch (number) {
    case 0:
      digitalWrite(PIN_7SEGLED_A, HIGH); 
      digitalWrite(PIN_7SEGLED_B, HIGH); 
      digitalWrite(PIN_7SEGLED_C, HIGH); 
      digitalWrite(PIN_7SEGLED_D, HIGH); 
      digitalWrite(PIN_7SEGLED_E, HIGH); 
      digitalWrite(PIN_7SEGLED_F, HIGH); 
      digitalWrite(PIN_7SEGLED_G, LOW); 
      digitalWrite(PIN_7SEGLED_DP,LOW); 
      break;
      
    case 1:
      digitalWrite(PIN_7SEGLED_A, LOW); 
      digitalWrite(PIN_7SEGLED_B, HIGH); 
      digitalWrite(PIN_7SEGLED_C, HIGH); 
      digitalWrite(PIN_7SEGLED_D, LOW); 
      digitalWrite(PIN_7SEGLED_E, LOW); 
      digitalWrite(PIN_7SEGLED_F, LOW); 
      digitalWrite(PIN_7SEGLED_G, LOW); 
      digitalWrite(PIN_7SEGLED_DP,LOW); 
      break;
      
    case 2:
      digitalWrite(PIN_7SEGLED_A, HIGH); 
      digitalWrite(PIN_7SEGLED_B, HIGH); 
      digitalWrite(PIN_7SEGLED_C, LOW); 
      digitalWrite(PIN_7SEGLED_D, HIGH); 
      digitalWrite(PIN_7SEGLED_E, HIGH); 
      digitalWrite(PIN_7SEGLED_F, LOW); 
      digitalWrite(PIN_7SEGLED_G, HIGH); 
      digitalWrite(PIN_7SEGLED_DP,LOW); 
      break;
      
    case 3:
      digitalWrite(PIN_7SEGLED_A, HIGH); 
      digitalWrite(PIN_7SEGLED_B, HIGH); 
      digitalWrite(PIN_7SEGLED_C, HIGH); 
      digitalWrite(PIN_7SEGLED_D, HIGH); 
      digitalWrite(PIN_7SEGLED_E, LOW); 
      digitalWrite(PIN_7SEGLED_F, LOW); 
      digitalWrite(PIN_7SEGLED_G, HIGH); 
      digitalWrite(PIN_7SEGLED_DP,LOW); 
      break;
      
    case 4:
      digitalWrite(PIN_7SEGLED_A, LOW); 
      digitalWrite(PIN_7SEGLED_B, HIGH); 
      digitalWrite(PIN_7SEGLED_C, HIGH); 
      digitalWrite(PIN_7SEGLED_D, LOW); 
      digitalWrite(PIN_7SEGLED_E, LOW); 
      digitalWrite(PIN_7SEGLED_F, HIGH); 
      digitalWrite(PIN_7SEGLED_G, HIGH); 
      digitalWrite(PIN_7SEGLED_DP,LOW); 
      break;
      
    case 5:
      digitalWrite(PIN_7SEGLED_A, HIGH); 
      digitalWrite(PIN_7SEGLED_B, LOW); 
      digitalWrite(PIN_7SEGLED_C, HIGH); 
      digitalWrite(PIN_7SEGLED_D, HIGH); 
      digitalWrite(PIN_7SEGLED_E, LOW); 
      digitalWrite(PIN_7SEGLED_F, HIGH); 
      digitalWrite(PIN_7SEGLED_G, HIGH); 
      digitalWrite(PIN_7SEGLED_DP,LOW); 
      break;
      
    case 6:
      digitalWrite(PIN_7SEGLED_A, HIGH); 
      digitalWrite(PIN_7SEGLED_B, LOW); 
      digitalWrite(PIN_7SEGLED_C, HIGH); 
      digitalWrite(PIN_7SEGLED_D, HIGH); 
      digitalWrite(PIN_7SEGLED_E, HIGH); 
      digitalWrite(PIN_7SEGLED_F, HIGH); 
      digitalWrite(PIN_7SEGLED_G, HIGH); 
      digitalWrite(PIN_7SEGLED_DP,LOW); 
      break;
      
    case 7:
      digitalWrite(PIN_7SEGLED_A, HIGH); 
      digitalWrite(PIN_7SEGLED_B, HIGH); 
      digitalWrite(PIN_7SEGLED_C, HIGH); 
      digitalWrite(PIN_7SEGLED_D, LOW); 
      digitalWrite(PIN_7SEGLED_E, LOW); 
      digitalWrite(PIN_7SEGLED_F, HIGH); 
      digitalWrite(PIN_7SEGLED_G, LOW); 
      digitalWrite(PIN_7SEGLED_DP,LOW); 
      break;
      
    case 8:
      digitalWrite(PIN_7SEGLED_A, HIGH); 
      digitalWrite(PIN_7SEGLED_B, HIGH); 
      digitalWrite(PIN_7SEGLED_C, HIGH); 
      digitalWrite(PIN_7SEGLED_D, HIGH); 
      digitalWrite(PIN_7SEGLED_E, HIGH); 
      digitalWrite(PIN_7SEGLED_F, HIGH); 
      digitalWrite(PIN_7SEGLED_G, HIGH); 
      digitalWrite(PIN_7SEGLED_DP,LOW); 
      break;
      
    case 9:
      digitalWrite(PIN_7SEGLED_A, HIGH); 
      digitalWrite(PIN_7SEGLED_B, HIGH); 
      digitalWrite(PIN_7SEGLED_C, HIGH); 
      digitalWrite(PIN_7SEGLED_D, HIGH); 
      digitalWrite(PIN_7SEGLED_E, LOW); 
      digitalWrite(PIN_7SEGLED_F, HIGH); 
      digitalWrite(PIN_7SEGLED_G, HIGH); 
      digitalWrite(PIN_7SEGLED_DP,LOW); 
      break;
      
    default:
      digitalWrite(PIN_7SEGLED_A, LOW); 
      digitalWrite(PIN_7SEGLED_B, LOW); 
      digitalWrite(PIN_7SEGLED_C, LOW); 
      digitalWrite(PIN_7SEGLED_D, LOW); 
      digitalWrite(PIN_7SEGLED_E, LOW); 
      digitalWrite(PIN_7SEGLED_F, LOW); 
      digitalWrite(PIN_7SEGLED_G, LOW); 
      digitalWrite(PIN_7SEGLED_DP,HIGH); 
      break;
  }

  
}
