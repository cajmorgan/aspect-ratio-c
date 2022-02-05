#include <stdio.h>
#include "aspectratio.h"

int main(int argc, char **argv) {
  if (argc <= 3) {
    fprintf(stderr, "\033[1;31mNeed three arguments, size and ratio a, b\n\033[0m");
    return -1;
  }

  double size, new_size, ratio_a, ratio_b;

  size = to_number(argv[1]);
  ratio_a = to_number(argv[2]);
  ratio_b = to_number(argv[3]);
  new_size = (size/ratio_a) * ratio_b;

  printf("Width:\033[1;32m %g\033[0m\nHeight:\033[1;32m %g\033[0m\n", size, new_size);
  return 0;
}
