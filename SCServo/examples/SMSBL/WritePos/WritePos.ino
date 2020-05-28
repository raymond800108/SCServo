/*
以下例子在SMS40BL中测试通过，舵机出厂速度单位为0.0146rpm
如果使用的出厂速度单位是0.732rpm，则速度改为V=80，延时公式T=[(P1-P0)/(50*V)]*1000+[(50*V)/(A*100)]*1000
*/


#include <SCServo.h>

SMSBL sm;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  sm.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  sm.WritePosEx(1, 4095, 4000, 100);//舵机(ID1)以最高速度V=4000步/秒，加速度A=100(100*100步/秒^2)，运行至P1=4095位置
  delay(1495);//[(P1-P0)/V]*1000+[V/(A*100)]*1000

//--测试运行误差非必要程序--
  int Pos = sm.ReadPos(1);
  Serial.println(Pos);
//--测试运行误差非必要程序--
  
  sm.WritePosEx(1, 0, 4000, 100);//舵机(ID1)以最高速度V=4000步/秒，加速度A=100(100*100步/秒^2)，运行至P0=0位置
  delay(1495);//[(P1-P0)/V]*1000+[V/(A*100)]*1000
  
//--测试运行误差非必要程序--
  Pos = sm.ReadPos(1);
  Serial.println(Pos);
//--测试运行误差非必要程序--
}
