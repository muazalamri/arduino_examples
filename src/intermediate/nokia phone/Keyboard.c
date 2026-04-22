#include <Keypad.h>
#define cols 4
#define rows 4
uint8_t Cpins[cols] = {13, 12, 11, 10};
uint8_t Rpins[rows] = {9, 8, 7, 6};
char keys_list[rows][cols] = {{'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
Keypad My_keys(makeKeymap(keys_list), Cpins, Rpins, rows, cols);

