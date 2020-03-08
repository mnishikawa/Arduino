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
#include "quest_sound_box.h"

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
int repeat_sound = 0;
int melody = 0;


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

  //select a melody
  melody = read_switch();
  if((melody == 0) || (melody == repeat_sound)){
    melody = repeat_sound;
  }

  switch (melody) {
    case 0:
      // Wait for melody select
      digitalWrite(PIN_LED_GREEN, LOW);
      digitalWrite(PIN_LED_RED, LOW);
      if(wait_for_switch == 0) {
        digitalWrite(PIN_LED_BLUE, LOW);
        wait_for_switch = 1;
      } else {
        digitalWrite(PIN_LED_BLUE, HIGH);
        wait_for_switch = 0;
      }
      delay(500);
      break;


    case 1:
      digitalWrite(PIN_LED_RED, LOW);
      digitalWrite(PIN_LED_GREEN, HIGH);
      digitalWrite(PIN_LED_BLUE, LOW);
      play_melody(1,1536);
      repeat_sound = 1;
      break;      

    case 2:
      digitalWrite(PIN_LED_RED, HIGH);
      digitalWrite(PIN_LED_GREEN, LOW);
      digitalWrite(PIN_LED_BLUE, LOW);
      play_melody(2,1216);
      repeat_sound = 2;
      break;      

    case 4:
      digitalWrite(PIN_LED_RED, LOW);
      digitalWrite(PIN_LED_GREEN, LOW);
      digitalWrite(PIN_LED_BLUE, HIGH);
      play_melody(4,1000);
      repeat_sound = 0;
      break;      

    case 7:
      // play quest melody
      digitalWrite(PIN_LED_RED, HIGH);
      digitalWrite(PIN_LED_GREEN, HIGH);
      digitalWrite(PIN_LED_BLUE, HIGH);
      play_melody(1,1536);
      play_melody(2,1216);
      play_melody(4,1000);
      repeat_sound = 0;
      break;
    
    default:
      //play melody
      digitalWrite(PIN_LED_RED, LOW);
      digitalWrite(PIN_LED_GREEN, LOW);
      digitalWrite(PIN_LED_BLUE, HIGH);
      play_melody(4,1000);
      repeat_sound = 0;

      break;
  }


}


void play_melody(int melody_no, int melody_baseDuration) {
  // iterate over the notes of the melody:
  for (uint16_t thisNote = 0; thisNote < pgm_read_word(&notenum[melody_no]); thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    uint16_t noteDuration = melody_baseDuration / pgm_read_word(&noteDurations[melody_no][thisNote]);
    tone(PIN_SPEAKER, pgm_read_word(&melodynotes[melody_no][thisNote]), noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    uint16_t pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(PIN_SPEAKER);

    //select a melody
    melody = read_switch();
    if((melody == 0) || (melody == repeat_sound)){
      melody = repeat_sound;
    } else {
      break;
    }

  }

}


int read_switch() {

  int retval = 0;

  if(digitalRead(PIN_SW1) == LOW){
    retval += 1;
  }
  
  if(digitalRead(PIN_SW2) == LOW){
    retval += 1<<1;
  }
  
  if(digitalRead(PIN_SW3) == LOW){
    retval += 1<<2;
  }

  return retval;

}
