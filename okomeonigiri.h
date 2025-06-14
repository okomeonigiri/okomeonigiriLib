#ifndef OKOMEONIGIRI_H
#define OKOMEONIGIRI_H

#include <Arduino.h>
#include <stdio.h>

//printf format for arudino Serial print
#define printf_s(fmt, ...) ({ char buf[512]; snprintf(buf, sizeof(buf), fmt, ##__VA_ARGS__); Serial.print(buf); })

#define floop(n) for(int i = 0; i < (n); ++i)

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int calculate_deg(char mode, int num1, int num2){switch(mode){
case 'a': return (num1+num2>=360)?(num1+num2)%360:(num1+num2);
case 'r': return (num1+180)%360;
case 's': return (num1-num2<0)?(num1-num2+360)%360:(num1-num2);
case 'A': return ((num1+num2)/2>=360)?((num1+num2)/2)%360:((num1+num2)/2);
default: return 999;}}
/*
使い方
a:加算[num1+num2] ex) 240+230=10
s:減算[num1-num2] ex) 30-45=345
r:反転[reverse num1] ex)30→150  [-180]
A:平均[num1+num2/2] ex) 240+30=135
※文字は''で囲ってね
*/
int cal_deg(char mode, int num1, int num2){return calculate_deg(mode, num1, num2);}



#endif //OKOMEONIGIRI_H0