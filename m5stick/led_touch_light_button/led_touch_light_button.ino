#include <M5StickC.h>

#define BIGSW 36
#define LIGHTLED 26

int sw_val = 0;

void setup() {
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Axp.ScreenBreath(15);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.fillScreen(BLACK);
  
  pinMode(LIGHTLED, OUTPUT);
  digitalWrite(LIGHTLED, HIGH);

  pinMode(BIGSW, INPUT);

  // initialize for LCD
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setCursor(0, 0);  
  M5.Lcd.setTextSize(1);
  M5.Lcd.print("LIGHT BUTTON TEST");  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sw_val = digitalRead(BIGSW);
  if(sw_val == LOW){
    M5.Lcd.fillScreen(TFT_BLACK);
    M5.Lcd.setCursor(0, 0);  
    M5.Lcd.print("LIGHT BUTTON TEST");  
    M5.Lcd.setCursor(10, 20);  
    M5.Lcd.print("PUSH    BUTTON");  
    // turn on LED
    digitalWrite(LIGHTLED, LOW);
  } else {
    M5.Lcd.fillScreen(TFT_BLACK);
    M5.Lcd.setCursor(0, 0);  
    M5.Lcd.print("LIGHT BUTTON TEST");  
    M5.Lcd.setCursor(10, 20);  
    M5.Lcd.print("RELEASE BUTTON");  
    // turn off LED
    digitalWrite(LIGHTLED, HIGH);
  }

  // loop delay
  delay(100);
}
