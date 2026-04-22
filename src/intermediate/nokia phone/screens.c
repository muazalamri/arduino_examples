// screens.h
#ifndef SCREENS_H
#define SCREENS_H

#include <Arduino.h>
#include <Adafruit_PCD8544.h>

// تعرّف display من النوع الموجود في ملفك الرئيسي
extern Adafruit_PCD8544 display;
extern String number;
int by_x = 35;
int by_y = 0;
int name_x = 9;
int name_y = 12;
String name = "Muaz Alamri";
int center_x = 42; //0-83
int center_y = 24; //0-47
int screen_w = 84;
int screen_h = 47;
int rows_len = 7;
int number_x=5;
int number_y=26;
int time_x = 26;
int time_y =5;
String timer ="09:13";
void apps_core() {
  int starts[2][3] = {{3 + rows_len, center_y, 1}, {74, center_y, -1}};
  for (int i = 0; i < 2; i++) {
    display.drawLine(starts[i][0], starts[i][1], starts[i][0] - rows_len * starts[i][2], starts[i][1] - rows_len, 255);
    display.drawLine(starts[i][0], starts[i][1], starts[i][0] - rows_len * starts[i][2], starts[i][1] + rows_len, 255);
  }
}
void history_screen() {
  int r=int(rows_len*1.5);
  apps_core();
  display.drawCircle(center_x, center_y, r, 255);
  display.fillRect(center_x - rows_len * 2, center_y, rows_len, int(rows_len * 1.2), 0);
  display.drawLine(center_x, center_y, center_x, center_y - rows_len, 255);
  display.drawLine(center_x, center_y, center_x + rows_len, center_y - rows_len, 255);
  display.drawLine(center_x-r,center_y,center_x-r-rows_len,center_y-rows_len,255);
  display.drawLine(center_x-r,center_y,center_x-r+rows_len,center_y-rows_len,255);
}
void clock_screen() {
  apps_core();
  display.drawCircle(center_x, center_y, int(rows_len * 1.5), 255);
  display.drawLine(center_x, center_y, center_x, center_y - rows_len, 255);
  display.drawLine(center_x, center_y, center_x + rows_len, center_y - rows_len, 255);
}
void names_screen() {
  apps_core();
  display.fillCircle(center_x,center_y,rows_len,255);
  display.drawCircle(center_x,center_y,rows_len,255);
  display.fillCircle(center_x,center_y-2*rows_len,rows_len,255);
  display.drawCircle(center_x,center_y-2*rows_len,rows_len,255);
  display.drawRect(center_x-rows_len,center_y,2*rows_len,3*rows_len,255);
  display.fillRect(center_x-rows_len,center_y,2*rows_len+1,3*rows_len,255);
}

void massage_screen() {
  apps_core();
  display.drawLine(center_x,center_y,center_x+3*rows_len,center_y-2*rows_len,255);
  display.drawLine(center_x,center_y,center_x-3*rows_len,center_y-2*rows_len,255);
  display.drawRect(center_x-3*rows_len,center_y-2*rows_len,rows_len*6,rows_len*4,255);
}
void start_screen() {
  display.setCursor(by_x, by_y);
  display.print("BY");
  display.setCursor(name_x, name_y);
  display.print(name);
}
// دالة الشاشة الرئيسية
void main_screen() {
  display.clearDisplay();
  display.setCursor(time_x, time_x);
  display.print(timer );
  display.display();
}

// دالة شاشة كتابة الرقم
void phone_screen() {
  display.clearDisplay();
  display.setCursor(number_x,number_y);
  display.print(number);
  display.display();
}

#endif