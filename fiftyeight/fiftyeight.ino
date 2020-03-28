/*

Fifty Eight melody IC player

　"M8058S" melody IC control code.


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

// Pin definitions
#define PIN_ADVOL           0
#define PIN_MELODYIC_CTRL   2
#define PIN_LATCH           3
#define PIN_RCLK            4
#define PIN_SER             5

// Define variable register value
#define ADC_RESOLUTION      1024
#define ADVAL_MARGIN          20
#define ADVAL_VOL_MIN        512
#define ADVAL_VOL_MAX        867
#define ADVAL_PLAY            63
#define ADVAL_STOP           290
#define MELODY_NUMBER         58
#define MELODY_STEP            6

// loop periodic
//   - To check key input by every loop
#define HZ 120
#define READ_MELODY_NUM_PERIODIC 20

// prototype definition
int read_melody_num();
void send_melody_command(int command);
void display_melody_num(int number);
int is_play_key(int analogval);
int is_stop_key(int analogval);

// 7segment LED mapping
static const int data[] {
  B00000010,   //ZERO
  B10011110,   //ONE
  B00100100,   //TWO
  B00001100,   //THREE
  B10011000,   //FOUR
  B01001000,   //FIVE
  B01000000,   //SIX
  B00011010,   //SEVEN
  B00000000,   //EIGHT
  B00001000,   //NINE
};

// Global value
int melody = 0x01;
int check_melody_number = READ_MELODY_NUM_PERIODIC;
int led_digit = 0;
int pressing_playkey = 0;


// setup function
void setup() {

  // Initialize for Serial debug
  Serial.begin(115200);

  // initialize port
  pinMode(PIN_ADVOL, INPUT);
  pinMode(PIN_MELODYIC_CTRL, OUTPUT);
  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_RCLK, OUTPUT);
  pinMode(PIN_SER, OUTPUT);

  // initialize melody IC command port
  digitalWrite(PIN_MELODYIC_CTRL, LOW);
  send_melody_command(0xF8);  // set melody IC volume (MAX)
  send_melody_command(0xE8);  // set melody IC play mode (play melody + blinking LED)

}

// main loop
void loop() {
  unsigned int analog_val = 0;
  
  // Check Play key
  analog_val = analogRead(PIN_ADVOL);

  if( (is_play_key(analog_val) == true) && (pressing_playkey == 0)){
    play_melody(melody);
    pressing_playkey = 1;
  } else {
    pressing_playkey = 0;
  }
  if(is_stop_key(analog_val) == true){
    send_melody_command(0xFF);
  }

  // Check and display melody number
  check_melody_number--;
  if(check_melody_number == 0){
    melody = read_melody_num(analog_val);
    check_melody_number = READ_MELODY_NUM_PERIODIC;
  }

  // Display melody number
  display_melody_num(melody);
  // loop delay
  delay(1000/HZ); 

}


void play_melody(int melody_no) {
    send_melody_command(melody_no);
    return 0;
}


void send_melody_command(int command) {
  int i=0;

  // Initialize port
  digitalWrite(PIN_MELODYIC_CTRL, LOW);

  // Send header to melody IC
  digitalWrite(PIN_MELODYIC_CTRL, HIGH);
  delay(6);
  digitalWrite(PIN_MELODYIC_CTRL, LOW);

  // Send DATA
  for(i=0;i<8;i++){      
    if( ((command>>i)&0x1) == 1){
      delayMicroseconds(500);
      digitalWrite(PIN_MELODYIC_CTRL, HIGH);
      delayMicroseconds(1500);
    } else {
      delayMicroseconds(1500);
      digitalWrite(PIN_MELODYIC_CTRL, HIGH);
      delayMicroseconds(500);
    }
      digitalWrite(PIN_MELODYIC_CTRL, LOW);
   }

  // improve display quality
  for(i=0;i<READ_MELODY_NUM_PERIODIC;i++) {
    // Display melody number
    display_melody_num(melody);
    // loop delay
    delay(1000/HZ); 
  }
   
    return 0;

}


int read_melody_num(int analogval) {

  int retval = 0;

  // Get melody number
  retval = (analogval - ADVAL_VOL_MIN) / MELODY_STEP;

  if( analogval < ADVAL_VOL_MIN ){
     retval = 0x00;
  }  
  if( analogval > ADVAL_VOL_MAX ){
     retval = 0x3A;
  }  

  return retval;
}


void display_melody_num(int number) {
  char num1, num2, dispnum;

  num1 = number / 10;
  num2 = number % 10;

  if(led_digit == 0) {
    dispnum = data[num1] | 0x01;
    led_digit = 1;
  } else {
    dispnum = data[num2] & 0xFE;
    led_digit = 0;
  }
  digitalWrite(PIN_LATCH, LOW);
  shiftOut(PIN_SER, PIN_RCLK, LSBFIRST, dispnum);
  digitalWrite(PIN_LATCH, HIGH);

  // improve display quality
  if(led_digit == 0) {
    delay(1000/HZ); 
  }    

}


int is_play_key(int analogval){
  if( (analogval>(ADVAL_PLAY-ADVAL_MARGIN)) && (analogval<(ADVAL_PLAY+ADVAL_MARGIN))){
    return true;
  } else {
    return false;
  }  
}


int is_stop_key(int analogval){
  if( (analogval>(ADVAL_STOP-ADVAL_MARGIN)) && (analogval<(ADVAL_STOP+ADVAL_MARGIN))){
    return true;
  } else {
    return false;
  }  
}
