#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include "screens_desing.hpp"
#include "data.hpp"
#include "divces.hpp"
#include "screens_logic.hpp"
#include "screens_manger.hpp"



Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC); // 320*240

void setup()
{
    pinMode(out_clock, OUTPUT);
    analogWrite(out_clock, 128);
    pinMode(divce_multipix_3,OUTPUT);
    pinMode(divce_multipix_1,OUTPUT);
    pinMode(divce_multipix_2,OUTPUT);
    pinMode(divce_multipix_3,OUTPUT);
    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(ILI9341_BLACK);
    //tft.fillScreen(ILI9341_BLACK);
}

void loop()
{
    if (CURRENT_SCREEN != NEXT_SCREEN){set_screen(NEXT_SCREEN);}
    PREV_SCREEN = CURRENT_SCREEN;
}
