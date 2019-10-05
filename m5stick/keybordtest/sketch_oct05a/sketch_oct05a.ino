#include <Update.h>

/*
KEYBORD test for M5StickC

Copyright 2019 Makoto Nishikawa

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* 
 *  M5Stack用カード型キーボードユニット
 *  CardKB Mini Keyboard Unit (MEGA328P)
 *  向けのテストプログラム
 *  
 */

#include <M5StickC.h>

#define CARDKB_ADDR 0x5F
#define SCREENX 20
#define SCREENY 8
#define CHAR_SIZE_X 8
#define CHAR_SIZE_Y 8


int cur_x = 0;
int cur_y = 0;


void setup()
{
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setRotation(1);
  Serial.begin(115200);
  Wire.begin();
  pinMode(5, INPUT);
  digitalWrite(5, HIGH);
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setCursor(1, 1);
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setTextSize(1);
}

void clear()
{
  cur_x = 0;
  cur_y = 0;
  M5.Lcd.fillScreen(TFT_BLACK);
  
}


void loop()
{
  Wire.requestFrom(CARDKB_ADDR, 1);
  while(Wire.available())
  {
    char c = Wire.read(); // receive a byte as characterif
    if (c != 0)
    {

      M5.Lcd.setCursor(cur_x*CHAR_SIZE_X, cur_y*CHAR_SIZE_Y);
      M5.Lcd.printf("%c", c);
      Serial.println(c, HEX);
//      Serial.println(cur_x, HEX);
//      Serial.println(cur_y, HEX);

      // push ESC key to clear screen
      if(c == 0x1B) {
        clear();
      }

      if(cur_x == SCREENX) {
        cur_x = 0;
        cur_y++;
      }else {
        cur_x++;
      }
      
      if((cur_x==SCREENX) && (cur_y==SCREENY) ) {
        clear();
      }

     }

    }
//   delay(10);
  
}
