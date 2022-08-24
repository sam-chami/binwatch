#define BIT(n,i) (n>>i&1)

#include <Rtc_Pcf8563.h>

const int btnPin = 13;
bool btn = 0;

Rtc_Pcf8563 rtc;

void setup()
{
  for (int i = 2; i < 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(btnPin, INPUT);

  rtc.initClock();
  //day, weekday, month, century, year
  rtc.setDate(24, 3, 8, 0, 22);
  //hr, min, sec
  rtc.setTime(13, 55, 00);
}


void writeHours(int hours){
  digitalWrite(5, BIT(hours, 0));
  digitalWrite(4, BIT(hours, 1));
  digitalWrite(3, BIT(hours, 2));
  digitalWrite(2, BIT(hours, 3));
}

void writeMin_ten(int min_ten){
  digitalWrite(8, BIT(min_ten, 0));
  digitalWrite(7, BIT(min_ten, 1));
  digitalWrite(6, BIT(min_ten, 2));
}

void writeMin_unit(int min_unit){
  digitalWrite(12, BIT(min_unit, 0));
  digitalWrite(11, BIT(min_unit, 1));
  digitalWrite(10, BIT(min_unit, 2));
  digitalWrite(9, BIT(min_unit, 3));
}

void loop()
{
  for (int i = 2; i < 13; i++) {
    digitalWrite(i, 0);
  }
  
  sleepMode(SLEEP_IDLE);
  sleep();
//
//  btn = digitalRead(btnPin);
//  if(btn = HIGH) {
//    noSleep();
//    writeHours(rtc.getHour()%12);
//    writeMin_ten(rtc.getMinute() / 10);
//    writeMin_unit(rtc.getMinute()%10);
//    delay(10000);
//  }
  btn = digitalRead(btnPin);
  if(btn == HIGH){
    writeHours(rtc.getHour()%12);
    writeMin_ten(rtc.getMinute() / 10);
    writeMin_unit(rtc.getMinute()%10);
    delay(16000);
  }
}
