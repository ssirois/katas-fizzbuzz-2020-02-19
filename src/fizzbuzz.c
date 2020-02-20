#include <stddef.h>
#include <stdlib.h>

#include "fizzbuzz.h"

int* fizzbuzz(int target) {
  if (target == 0) {
    return NULL;
  }

  int* output = malloc(target*sizeof(int));

  for (int i = 1; i <= target; ++i) {
    if (i % 3 == 0) {
      output[i-1] = FIZZ;
    }
    else if (i % 5 == 0) {
      output[i-1] = BUZZ;
    }
    else {
      output[i-1] = i;
    }
  }

  return output;
}
