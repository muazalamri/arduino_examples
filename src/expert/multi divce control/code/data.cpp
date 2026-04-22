#ifndef data
#define data

// For UNO scrren
#define TFT_CS 12
#define TFT_DC 9
#define out_clock 10//out clock bin
#define interupt 7//interupt pin active high
#define serial_in 4//serial in pin
#define serial_out 12//serial out pin
#define ENABLE_SPI 5//index of spi enable bin,active high
#define divce_multipix_1 2// divces multi pix pin no 0:
#define divce_multipix_2 3// divces multi pix pin no 1:
#define divce_multipix_3 4// divces multi pix pin no 2:
uint8_t NEXT_SCREEN=1;//index of screen on screens list
uint8_t CURRENT_SCREEN=0;//index of screen on screens list
uint8_t PREV_SCREEN = 1;//index of  pervios screen on screens list
int divce_mlutipix[3]={1,1,1};// values of divce multi pix pins
#endif