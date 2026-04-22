#ifndef element
#define element
#include <Adafruit_ILI9341.h>
extern Adafruit_ILI9341 tft;
void scroll_bar(int width, int persent);
void terminal_line(char text,int start_pix,int end_pix);
void info_box(char text,int start_pix,int end_pix);
void danger(char tex,int x,int y,int h,int w);
#endif