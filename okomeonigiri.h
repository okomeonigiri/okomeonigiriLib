#ifndef OKOMEONIGIRI_H
#define OKOMEONIGIRI_H

//コピペ用
//==================================================
//==============================



#include <Arduino.h>
#include <stdio.h>
#include <limits.h>


//printf format for arudino Serial print
//==================================================

// Use snprintf to format strings and print them to Serial
// This allows for formatted output similar to printf in standard C

//buf size:256  normal
#define printf_s(fmt, ...) ({ char buf[256]; snprintf(buf, sizeof(buf), fmt, ##__VA_ARGS__); Serial.print(buf); })
//buf size:128  short
#define printf_s_short(fmt, ...) ({ char buf[128]; snprintf(buf, sizeof(buf), fmt, ##__VA_ARGS__); Serial.print(buf); })
//buf size:512  long
#define printf_s_long(fmt, ...) ({ char buf[512]; snprintf(buf, sizeof(buf), fmt, ##__VA_ARGS__); Serial.print(buf); })
//buf size:custom  // Use a custom buffer size defined by the user
#define printf_s_custom(bufsize,fmt, ...) ({ char buf[bufsize]; snprintf(buf, sizeof(buf), fmt, ##__VA_ARGS__); Serial.print(buf); })
//buf size:SIZE_MAX  // Use the maximum size of a buffer, which is defined by SIZE_MAX
#define printf_s_max(fmt, ...) ({ char buf[SIZE_MAX]; snprintf(buf, sizeof(buf), fmt, ##__VA_ARGS__); Serial.print(buf); })

//==================================================

//A for loop that allows you to easily use a for loop with just a single number.
#define floop(i) for(int i = 0; i < (i); ++i)
//A floop that allows you to use any variable name you like as the loop counter.
#define floop_id(var, n) for(int var = 0; var < (n); ++var)

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int calculate_deg(char mode, int num1, int num2){switch(mode){
case 'a': return (num1+num2>=360)?(num1+num2)%360:(num1+num2);
case 'r': return (num1+180)%360;
case 's': return (num1-num2<0)?(num1-num2+360)%360:(num1-num2);
case 'A': return ((num1+num2)/2>=360)?((num1+num2)/2)%360:((num1+num2)/2);
default: return 999;}}
int cal_deg(char mode, int num1, int num2){return calculate_deg(mode, num1, num2);}

#endif //OKOMEONIGIRI_H