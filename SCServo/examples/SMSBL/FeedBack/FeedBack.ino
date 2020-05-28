#include <SCServo.h>

SMSBL sm;
int LEDpin = 13;

void setup()
{
  pinMode(LEDpin,OUTPUT);
  digitalWrite(LEDpin, HIGH);
  Serial1.begin(115200);
  Serial.begin(115200);
  sm.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  int Pos;
  int Speed;
  int Load;
  int Voltage;
  int Temper;
  int Move;
  int Current;
  if(sm.FeedBack(1)!=-1){
    digitalWrite(LEDpin, LOW);
    Pos = sm.ReadPos(-1);
    Speed = sm.ReadSpeed(-1);
    Load = sm.ReadLoad(-1);
    Voltage = sm.ReadVoltage(-1);
    Temper = sm.ReadTemper(-1);
    Move = sm.ReadMove(-1);
    Current = sm.ReadCurrent(-1);
    Serial.println(Pos);
    Serial.println(Speed);
    Serial.println(Load);
    Serial.println(Voltage);
    Serial.println(Temper);
    Serial.println(Move);
    Serial.println(Current);
    Serial.println();
    delay(10);
  }else{
    digitalWrite(LEDpin, HIGH);
    Serial.println("read err");
    delay(2000);
  }
}
