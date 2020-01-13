

// 74HC595 pin        QA,QB,QC,QD,QE,QF,QG,QH 
// 7segment Mapping   a, b, c, d, e, f, g ,D.P

int tDelay = 2;   // 100ms遅延設定←ここの時間を短くしていく。
int rclkPin = 11;   // (11) ST_CP [RCLK] on 74HC595
int srclkPin = 9;   // (9)  SH_CP [SRCLK] on 74HC595
int dsPin = 12;     // (12) DS [SER] on 74HC595
int dig1 = 5;       // DIG1を5番ピンに割り当て
int dig2 = 2;       // DIG2を2番ピンに割り当て
int dig3 = 3;       // DIG3を3番ピンに割り当て
int dig4 = 4;       // DIG4を4番ピンに割り当て


// seven_ledsをbyte型として定義
// 配列にDisplay表示用のデータ0~9と全消灯を設定
// 1 = LED on, 0 = LED off
byte seven_leds[12] =       { B11111100,  // 0
                              B01100000,  // 1
                              B11011010,  // 2
                              B11110010,  // 3
                              B01100110,  // 4
                              B10110110,  // 5
                              B10111110,  // 6
                              B11100000,  // 7
                              B11111110,  // 8
                              B11100110,  // 9
                              B00000001,  // D.P 
                              B00000000,  // OFF
                             };


//シフトレジスタ部分を関数化
void funcShiftReg(int x)
{
  digitalWrite(rclkPin, LOW);                         //送信中のRCLKをLowにする
  shiftOut(dsPin, srclkPin, LSBFIRST, seven_leds[x]); //シフト演算を使って点灯するLEDを選択
  digitalWrite(rclkPin, HIGH);                        //送信終了後RCLKをHighにする
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(rclkPin, OUTPUT);   //11番ピンをOUTPUTとして定義
  pinMode(dsPin, OUTPUT);     //12番ピンをOUTPUTとして定義
  pinMode(srclkPin, OUTPUT);  //9番ピンをOUTPUTとして定義
  pinMode(dig1, OUTPUT);      //5番ピンをOUTPUTとして定義
  pinMode(dig2, OUTPUT);      //2番ピンをOUTPUTとして定義
  pinMode(dig3, OUTPUT);      //3番ピンをOUTPUTとして定義
  pinMode(dig4, OUTPUT);      //4番ピンをOUTPUTとして定義
  digitalWrite(dig1, LOW);    //1番ピンをLOW DI1 OFF
  digitalWrite(dig2, LOW);    //2番ピンをLOW DI2 OFF
  digitalWrite(dig3, LOW);    //3番ピンをLOW DI3 OFF
  digitalWrite(dig4, LOW);    //4番ピンをLOW DI4 OFF
  funcShiftReg(12);           //信号初期化

}


void loop() {
  // put your main code here, to run repeatedly:
  int val, val1, val2, val3, val4;

  //可変抵抗の読み込み
  val = analogRead(0);
  val1 = val / 1000;
  val2 = (val - val1*1000) / 100;
  val3 = (val - val1*1000 - val2*100) / 10;
  val4 = (val - val1*1000 - val2*100 - val3*10);

  //DIG1の表示
  delay(tDelay);
  digitalWrite(dig1, LOW); 
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
  //DIG1に1を表示
  funcShiftReg(val1);
  delay(tDelay);

  
  //DIG2の表示
  delay(tDelay);
  digitalWrite(dig1, HIGH); 
  digitalWrite(dig2, LOW);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
  //DIG2に2を表示
  funcShiftReg(val2);
  delay(tDelay);


  //DIG3の表示
  delay(tDelay);
  digitalWrite(dig1, HIGH); 
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, LOW);
  digitalWrite(dig4, HIGH);
  //DIG2に3を表示
  funcShiftReg(val3);
  delay(tDelay);


  //DIG4の表示
  delay(tDelay);
  digitalWrite(dig1, HIGH); 
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, LOW);
  //DIG2に4を表示
  funcShiftReg(val4);
  delay(tDelay);
  
//  Serial.print("register value : ");
//  Serial.print(val, DEC);
//  Serial.print("\n");
//  delay(tDelay);
}
