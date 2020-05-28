#include <SCServo.h>

SMSBL sm;

void setup()
{
  Serial1.begin(115200);
  sm.pSerial = &Serial1;
  delay(1000);
  sm.WheelMode(1);
}

void loop()
{
  sm.WriteSpe(1, 4000, 100);
  delay(2000);
  sm.WriteSpe(1, 0, 100);
  delay(2000);
  sm.WriteSpe(1, -4000, 100);
  delay(2000);
  sm.WriteSpe(1, 0, 100);
  delay(2000);
}
