#ifndef LISTER_H
#define LISTER_H
#include <Adafruit_PCD8544.h>
#include <Arduino.h>
extern Adafruit_PCD8544 display;
int width = 72;
int hight = 11;
int pre = 3;
int gab = 1;
int len = 2;
int items = 4;
int pixes = 2;
int text_x=5;
int text_dy=12;

void HLine(int x0, int y, int x1, int segmentLength, int gapLength) {

  for (int x = x0; x < x1; x += segmentLength + gapLength) {

    int segmentEnd = x + segmentLength;

    if (segmentEnd > x1) segmentEnd = x1; // تجنب تجاوز الحدود

    display.drawLine(x, y, segmentEnd, y, 255);

  }

}


void VLine(int x, int y0, int y1, int segmentLength, int gapLength) {

  for (int y = y0; y < y1; y += segmentLength + gapLength) {

    int segmentEnd = y + segmentLength;

    if (segmentEnd > y1) segmentEnd = y1; // تجنب تجاوز الحدود

    display.drawLine(x, y, x, segmentEnd, 255);

  }

}

void draw() {
  display.setTextSize(0.25);
  for (int i = 0; i < items; i++) {
    display.drawRect(pre, gab * i + hight * i+ gab, width, hight, 255);
    display.setCursor(text_x,text_dy*i+gab+1);
    display.print("Test texty !");
  }
  VLine(width+2*pre, gab, items*gab+items*hight, len, gab);
  display.setTextSize(1);
}


#endif