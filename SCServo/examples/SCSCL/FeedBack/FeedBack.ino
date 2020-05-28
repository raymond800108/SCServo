#include <SCServo.h>

SCSCL sc;
int LEDpin = 13;

void setup()
{
  pinMode(LEDpin,OUTPUT);
  digitalWrite(LEDpin, HIGH);
  Serial1.begin(1000000);
  Serial.begin(115200);
  sc.pSerial = &Serial1;
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
  if(sc.FeedBack(1)!=-1){
    digitalWrite(LEDpin, LOW);
    Pos = sc.ReadPos(-1);
    Speed = sc.ReadSpeed(-1);
    Load = sc.ReadLoad(-1);
    Voltage = sc.ReadVoltage(-1);
    Temper = sc.ReadTemper(-1);
    Move = sc.ReadMove(-1);
    Current = sc.ReadCurrent(-1);
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
