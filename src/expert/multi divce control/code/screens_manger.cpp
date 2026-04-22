#ifndef SCREENS_MANGER
#define SCREENS_MANGER
using Voidptr= void (*)(void);
Voidptr screens_list[2]={load_img,terminal};
void set_screen(uint8_t id){
  CURRENT_SCREEN=id;
  tft.fillScreen(ILI9341_BLACK);
  screens_list[id]();
}
#endif