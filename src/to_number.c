#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "aspectratio.h"

double to_number(char *str) {
  int length = strlen(str);
  int integers = 0;
  int decimals = 0;
  double number = 0.00;
  int decimal_counter = 0;
  bool has_decimals = false;

  for (int i = 0; i < length; i++) {
    if (has_decimals) {
      decimals *= 10;
      decimals += (str[i] - '0');
      decimal_counter += 1;
      continue;
    }

    if(str[i] == '.' || str[i] == ',') {
      has_decimals = true;
      continue;
    }

    integers *= 10;
    integers += (str[i] - '0');
  }

  number = integers + (decimals / (pow(10, decimal_counter)));
  return number;
}
