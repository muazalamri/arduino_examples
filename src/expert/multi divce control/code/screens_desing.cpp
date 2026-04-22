#ifndef screens
#define screens
#include <Adafruit_ILI9341.h>
#include "element.hpp"
#include "icons.hpp"
#include "data.hpp"
extern Adafruit_ILI9341 tft;
void load_img()
{
    tft.setTextColor(ILI9341_GREEN);
    tft.setTextSize(2);
    tft.setCursor(34, 130);
    tft.println("Smart Controler");
    tft.setCursor(33, 200);
    tft.println("BUY MUAZ ALAMRI");
    delay(200);
    NEXT_SCREEN=1;
}
void terminal(){
    tft.setTextColor(ILI9341_GREEN);
    tft.setTextSize(2);
    tft.setCursor(4, 10);
    tft.println("> ");
}
#endif