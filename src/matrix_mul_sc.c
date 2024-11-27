#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int **allocate_matrix(int size) {
    int **matrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(int));
    }
    return matrix;
}

void free_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void generate_matrix(int **matrix) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void multiply_matrices(int **mat1, int **mat2, int **result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int **mat1 = allocate_matrix(SIZE);
    int **mat2 = allocate_matrix(SIZE);
    int **result = allocate_matrix(SIZE);

    printf("Generating matrices...\n");
    generate_matrix(mat1);
    generate_matrix(mat2);
    printf("Matrices generated successfully.\n");

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    multiply_matrices(mat1, mat2, result);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Single-core matrix multiplication: %.6f seconds\n", elapsed);

    free_matrix(mat1, SIZE);
    free_matrix(mat2, SIZE);
    free_matrix(result, SIZE);

    return 0;
}
