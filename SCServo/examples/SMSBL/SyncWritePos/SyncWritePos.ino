/*
以下例子在SMS40BL中测试通过，舵机出厂速度单位为0.0146rpm
如果使用的出厂速度单位是0.732rpm，则速度改为V=80，延时公式T=[(P1-P0)/(50*V)]*1000+[(50*V)/(A*100)]*1000
*/

#include <SCServo.h>

SMSBL sm;

byte ID[2];
s16 Position[2];
u16 Speed[2];

void setup()
{
  Serial1.begin(115200);
  sm.pSerial = &Serial1;
  delay(1000);
  ID[0] = 1;
  ID[1] = 2;
}

void loop()
{
  Position[0] = 4095;
  Position[1] = 4095;
  Speed[0] = 4000;
  Speed[1] = 4000;
  sm.SyncWritePosEx(ID, 2, Position, Speed, 100);//舵机(ID1/ID2)以最高速度V=4000步/秒，加速度A=100(100*100步/秒^2)，运行至P1=4095位置
  delay(1495);//[(P1-P0)/V]*1000+[V/(A*100)]*1000

  Position[0] = 0;
  Position[1] = 0;
  Speed[0] = 4000;
  Speed[1] = 4000;
  sm.SyncWritePosEx(ID, 2, Position, Speed, 100);//舵机(ID1/ID2)以最高速度V=4000步/秒，加速度A=100(100*100步/秒^2)，运行至P0=0位置
  delay(1495);//[(P1-P0)/V]*1000+[V/(A*100)]*1000
}
