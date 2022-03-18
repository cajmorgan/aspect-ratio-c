#include <stdio.h>
#include "aspectratio.h"

int main(int argc, char **argv) {
  if (argc <= 2) {
    fprintf(stderr, "\033[1;31mNeed two arguments, width and height\n\033[0m");
    return -1;
  }

  int width, height, a, b, r;
  a = width = to_number(argv[1]);
  b = height = to_number(argv[2]);

  /** gcd **/
  r = 1;
  while(r != 0) {
    if (a > b) {
      r = a % b;
      a = b;
      b = r;
    } else {
      r = b % a;
      b = a;
      a = r;
    }
  }

  if (a > b)
    printf("Ratio: \033[1;32m%d\033[0m:\033[1;32m%d\033[0m\n", width/a, height/a);
  else
    printf("Ratio: \033[1;32m%d\033[0m:\033[1;32m%d\033[0m\n", width/b, height/b);

  return 0;
}
