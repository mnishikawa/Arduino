/*
SLOTGAME for M5StickC

Copyright 2019 Makoto Nishikawa

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include <M5StickC.h>


#define SLOTNUM 3
#define DELAY_TIME 100


void setup() {
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setRotation(1);
}


void title() {
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextColor(TFT_WHITE);  // Adding a background colour erases previous text automatically
  M5.Lcd.setCursor(5, 10);  
  M5.Lcd.setTextSize(3);
  M5.Lcd.print("SLOTGAME");  
}

void push_A_key() {
  int pressed=0;

  // wait for push
  while(pressed==0){
    M5.update();
    if(M5.BtnA.wasPressed()){
      pressed++;
    }
  }

  // wait for release
  while(pressed){
    M5.update();
    if(M5.BtnA.wasReleased()){
      pressed=0;
    }
  }
}


void loop() {

  int i;
  int slot=0;
  int slot_val[SLOTNUM];
  int pressed=0;

  while(1){ // game loop

    // initialize each game
    slot=0;
    pressed=0;
    for(i=0;i<SLOTNUM;i++) {
      slot_val[i]=0;
    }

    // title screen
    title();
    push_A_key();
    M5.Lcd.fillScreen(TFT_BLACK);

    // GAME loop
    while(slot<SLOTNUM) {
      M5.update();
      // press detection
      if(pressed==0){
        if(M5.BtnA.wasPressed()){
          pressed++;
          slot++;
        }
      }
      // release detection
      if(pressed>0){
        if(M5.BtnA.wasReleased()){
          pressed=0;
        }
      }

      for(i=slot;i<SLOTNUM;i++){
        slot_val[i]++;
        if(slot_val[i]>9) {
          slot_val[i]=0;
          }
      }

      // display slot value
      M5.Lcd.fillScreen(TFT_BLACK);
      for(i=0;i<SLOTNUM;i++){
        M5.Lcd.setCursor(32+i*48,24);  
        M5.Lcd.print(slot_val[i]);
      }

      // controll game speed
      delay(DELAY_TIME);
   }

   // complete one game.
   // (judge game result and calurate score if you needed...)


   // next game
   push_A_key();
  } // end of game loop

}
