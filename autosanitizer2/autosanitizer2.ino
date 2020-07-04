/*
Autosanitizer for Arduino

Copyright 2020 Makoto Nishikawa

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <Servo.h>
#include <LiquidCrystal.h>

#define PIN_SERVO_PWM     9
#define PIN_ECHO          2
#define PIN_TRIG          3
#define PIN_SW_PUSHPUMP   8
#define PIN_SW_INIT       7
#define PIN_SW_PUSHPUMP   8
#define PIN_ANALOG_CDS    0
#define PIN_CDS_THRESHOLD 1
#define PIN_LCD_RS        4 // LCD register select signal
#define PIN_LCD_EN        6 // LCD operation enable signal
#define PIN_LCD_DB4      10 // LCD data bus line
#define PIN_LCD_DB5      11 // LCD data bus line
#define PIN_LCD_DB6      12 // LCD data bus line
#define PIN_LCD_DB7      13 // LCD data bus line

// Prototype definitions
void display_status();
float ultrasonic_read();


// servo instance
Servo servo;

// LCD instance
LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_EN, PIN_LCD_DB4, PIN_LCD_DB5, PIN_LCD_DB6, PIN_LCD_DB7);


// CDS threshold default value
int cds_detectval = 100;

// status definitions
int pumping = 0;
int pumpcount = 0;


void setup() {
  // put your setup code here, to run once:

  // Initialize for Serial debug
  Serial.begin(115200);
 
  // Initialize for servo
  servo.attach(PIN_SERVO_PWM);
  servo.write(0);

  // Initialize for button
  pinMode(PIN_SW_INIT, INPUT_PULLUP);
  pinMode(PIN_SW_PUSHPUMP, INPUT_PULLUP);

  // Initialize for LCD
  lcd.begin( 16, 2 );
  lcd.clear();
  lcd.setCursor(0, 0);

  // Initialize for Ultrasonic Sensor
  pinMode(PIN_TRIG,OUTPUT);
  pinMode(PIN_ECHO,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  int analog_val;

  // button operation
  if(digitalRead(PIN_SW_INIT) == LOW){
    servo.write(0);
  } else if(digitalRead(PIN_SW_PUSHPUMP) == LOW) {
    servo.write(180);
  }
  
  // Read analog value from variable register
//  analog_val = analogRead(PIN_ANALOG_CDS);
  analog_val = 0;
  // Debug print
  Serial.print("Cds value : ");
  Serial.print(analog_val, DEC);
  Serial.print("\n");

  cds_detectval = analogRead(PIN_CDS_THRESHOLD);
  // Debug print
  Serial.print("Sensor detect value: ");
  Serial.print(cds_detectval, DEC);
  Serial.print("\n");

  if( analog_val>cds_detectval){
    // Debug print
    Serial.print("Detect cds dark state\n");
    if(pumping == 0){
      // pumping lequid
      Serial.print("Pumping lequid\n");
      servo.write(180);
      pumping = 1;
      pumpcount++;
      delay(500);
      } 
  } else {
    Serial.print("Stop pumping\n");
    servo.write(0);
    pumping = 0;
    delay(500);
  }

  analog_val = (int)ultrasonic_read();
  if(analog_val < cds_detectval ) {
    // Debug print
    Serial.print("Detect ultrasonic sensor \n");
    Serial.print(analog_val, DEC);
    Serial.print("\n");
    if(pumping == 0){
      // pumping lequid
      Serial.print("Pumping lequid\n");
      servo.write(180);
      pumping = 1;
      pumpcount++;
      delay(500);
      } 
  } else {
    Serial.print("Stop pumping\n");
    servo.write(0);
    pumping = 0;
    delay(500);
  }



  //Display current status to LCD
  display_status();
 
  //wait for loop
  delay(500);
  
}


float ultrasonic_read() {
  int duration = 0;
  float distance = 0;;
  const unsigned int MAX_DIST = 23200; //400cm(23200μs/pulse)以上は測定範囲外

  digitalWrite(PIN_TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG,LOW);

  duration = pulseIn(PIN_ECHO,HIGH);
  if(duration>0){
    distance=duration/58.8;
  }
  
  if(duration>MAX_DIST){
    return 400;
  }else{
    return distance;
  }
}



void display_status()
{
//  lcd.clear();
  lcd.clear();

  //Display pump counter
  lcd.setCursor(0, 0);
  lcd.print("COUNT: ");
  lcd.print(pumpcount, DEC);

  //Display CdS threshold
  lcd.setCursor(0, 1);
  lcd.print("SENSOR: ");
  lcd.print(cds_detectval, DEC);
  
}
