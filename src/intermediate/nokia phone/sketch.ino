#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <ctype.h>

#include "screens.h"
#include "Keyboard.h"
#include "lister.h"
int screen = -1;
int last_screen = -2;//-2  is update
int name_time = 15;
char up='A';
char left ='B';
char down='C';
char right='D';
int screens_range_low=2;
int screens_range_high=6;
String number = "";
// Display setup
Adafruit_PCD8544 display = Adafruit_PCD8544(1, 2, 3, 4, 5); // CLK,DIN,DC,CE,RST
void setup() {
  display.begin();
  display.setContrast(40);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  update_display();
  screen =0;
  delay(name_time);
}
void loop() {
  if (screen !=  last_screen) {
    update_display();
    last_screen = screen;
  }
  update_status();
}
void update_status() {
  char pressed = My_keys.getKey();
  if (pressed != NO_KEY) {
    if (isdigit(pressed)) {
      screen = 1;
      number = number + pressed ;
      last_screen = -2;
    }
    else if (pressed == 'A'){
      if (screen>=screens_range_low && screen<screens_range_high){
      screen=screen+1;
      }
      else if (screen==screens_range_high){
        screen=0;
      }
      else if (screen==0 || screen == 1){
        screen=2;
      }
    }
  }
}

void update_display() {
  display.clearDisplay();
  switch(screen){
    case -1:
      start_screen();
      break;
    case 0:
      main_screen();
      break;
    case 1:
      phone_screen();
      break;
    case 2:
      history_screen();
      break;
    case 3:
      names_screen();
      break;
    case 4:
      clock_screen();
      break;
    case 5:
      massage_screen();
      break;
    case 6:
      draw();
  }
  display.display();

}