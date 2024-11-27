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

// Helper function for merge sort
void merge(int *array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }

    while (i < n1) {
        array[k++] = L[i++];
    }
    while (j < n2) {
        array[k++] = R[j++];
    }

    free(L);
    free(R);
}

void merge_sort(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            merge_sort(array, left, mid);

            #pragma omp section
            merge_sort(array, mid + 1, right);
        }

        merge(array, left, mid, right);
    }
}

int main() {
    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int));

    generate_array(array, ARRAY_SIZE);
    double omp_start = omp_get_wtime();
    merge_sort(array, 0, ARRAY_SIZE - 1);
    double omp_end = omp_get_wtime();
    printf("Multi-core merge sort: %.2f seconds\n", omp_end - omp_start);

    free(array);
    return 0;
}
