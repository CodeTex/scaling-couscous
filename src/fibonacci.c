#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define FIB_INDEX 1000000000

uint64_t fibonacci(int n) {
    if (n <= 1) return n;

    uint64_t a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    const int n = FIB_INDEX;

    clock_t start_time = clock();
    /* uint64_t result = fibonacci(n); */
    fibonacci(n);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    /* printf("Fibonacci(%d) = %llu\n", n, result); */
    printf("Time taken: %.6f seconds\n", elapsed_time);

    return 0;
}
