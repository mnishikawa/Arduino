#define PORT_SWITCH 2

//#define WAIT_TIME_MS (24*60*60*1000UL) // 1day
//#define EXECUTION_TIME_MS (60*1000UL) //60sec
#define WAIT_TIME_MS (5*1000UL) // 1day
#define EXECUTION_TIME_MS (60*1000UL) //60sec


void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(2, HIGH);
   delay(EXECUTION_TIME_MS);
   digitalWrite(2, LOW);
   delay(WAIT_TIME_MS);
}
