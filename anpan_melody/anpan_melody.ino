/*
Anpanman jukebox

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
#include "anpan_melody.h"

// Pin definitions
#define PIN_SPEAKER 2
#define PIN_LED_RED 3
#define PIN_LED_GREEN 4
#define PIN_LED_BLUE 5
#define PIN_SW1 6
#define PIN_SW2 7
#define PIN_SW3 8

// prototype definition
void play_melody(int melody_no);
int read_switch();
int wait_for_switch = 0;


// setup function
void setup() {

  // initialize for LED port
  pinMode(PIN_LED_RED, OUTPUT);
  digitalWrite(PIN_LED_RED, HIGH);
  pinMode(PIN_LED_GREEN, OUTPUT);
  digitalWrite(PIN_LED_GREEN, HIGH);
  pinMode(PIN_LED_BLUE, OUTPUT);
  digitalWrite(PIN_LED_BLUE, HIGH);

  // initialize for switch input
  pinMode(PIN_SW1, INPUT_PULLUP);
  pinMode(PIN_SW2, INPUT_PULLUP);
  pinMode(PIN_SW3, INPUT_PULLUP);
  
}

// main loop
void loop() {
  int melody;
  
  //select a melody
  melody = read_switch();

  switch (melody) {
    case 0:
      // Wait for melody select
      if(wait_for_switch == 0) {
        digitalWrite(PIN_LED_GREEN, LOW);
        wait_for_switch = 1;
      } else {
        digitalWrite(PIN_LED_GREEN, HIGH);
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
  }

}


int read_switch() {

  int retval = 0;

  if(digitalRead(PIN_SW1) == LOW){
    retval += 1;
    digitalWrite(PIN_LED_RED, LOW);
  }else {
    digitalWrite(PIN_LED_RED, HIGH);
  }
  
  if(digitalRead(PIN_SW2) == LOW){
    retval += 1<<1;
    digitalWrite(PIN_LED_GREEN, LOW);
  }else {
    digitalWrite(PIN_LED_GREEN, HIGH);
  }
  
  if(digitalRead(PIN_SW3) == LOW){
    retval += 1<<2;
    digitalWrite(PIN_LED_BLUE, LOW);
  }else {
    digitalWrite(PIN_LED_BLUE, HIGH);
  }

  return retval;

}
