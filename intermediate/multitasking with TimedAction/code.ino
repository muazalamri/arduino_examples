#include <TimedAction.h>

#include <VariableTimedAction.h>
#include <LiquidCrystal_AIP31068_I2C.h>
#include <string.h>
#define led_pin 3
LiquidCrystal_AIP31068_I2C lcd(0x8, 20, 4);
int timer_counter = 0;
int str_index = 0;
int roller;
bool led_status = true;

char *text = " muaz alamri : arduino : simulIDE ";
int len = strlen(text);
void setup()
{
    pinMode(led_pin, OUTPUT);
    lcd.init();
}
void print_text()
{
    str_index = (str_index > len - 20 - 1) ? 0 : str_index + 1;
    int start = str_index;            // start index (0-based)
    int n = 20;                       // number of characters to copy
    char result[n + 1];               // +1 for null terminator
    strncpy(result, text + start, n); // copy from text[start]
    result[n] = '\0';
    lcd.setCursor(0, 0);
    lcd.print(result);
}
void roll_text()
{
    int n = 20; // number of characters to print
    roller = (roller > 126) ? 0 : roller + 1;
    int start = roller % len; // start index (0-based)
    int rolled;
    if (len - start < n)
        rolled = n - (len - start);
    else
        rolled = 0;
    Serial.println(rolled);
    char result[n + 1];                        // +1 for null terminator
    strncpy(result, text + start, n - rolled); // copy from text[start]
    if (rolled > 0)
        strncpy(result + (20 - rolled), text, rolled); // copy from text
    result[n] = '\0';
    lcd.setCursor(0, 1);
    lcd.print(result);
}
void check_led()
{
    digitalWrite(led_pin, int(led_status));
    led_status = !led_status;
}

TimedAction roll_text_th = TimedAction(600, roll_text);
TimedAction print_text_th = TimedAction(500, print_text);
TimedAction check_led_th = TimedAction(1000, check_led);

void loop()
{
    print_text_th.check();
    roll_text_th.check();
    check_led_th.check();
}
