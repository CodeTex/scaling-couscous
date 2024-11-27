#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define ARRAY_SIZE 1000000

// Function to generate random array
void generate_array(int *array, size_t size) {
    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 100000;
    }
}

// Helper function for quicksort
void quicksort(int *array, int left, int right) {
    if (left < right) {
        int pivot = array[right];
        int partition_index = left;

        for (int i = left; i < right; i++) {
            if (array[i] < pivot) {
                int temp = array[i];
                array[i] = array[partition_index];
                array[partition_index] = temp;
                partition_index++;
            }
        }
        int temp = array[partition_index];
        array[partition_index] = array[right];
        array[right] = temp;

        quicksort(array, left, partition_index - 1);
        quicksort(array, partition_index + 1, right);
    }
}


int main() {
    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int));

    generate_array(array, ARRAY_SIZE);
    clock_t start = clock();
    quicksort(array, 0, ARRAY_SIZE - 1);
    clock_t end = clock();
    printf("Single-core quicksort: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(array);
    return 0;
}
