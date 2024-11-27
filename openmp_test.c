#include <omp.h>
#include <stdio.h>

int main() {
  #ifdef _OPENMP
  printf("OpenMP is supported! Version: %d\n", _OPENMP);
  #else
  printf("OpenMP is not supported!\n");
  #endif
  return 0;
}
