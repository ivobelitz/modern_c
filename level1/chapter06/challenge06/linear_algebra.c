#include <stdio.h>
#include <stdlib.h>

#define A_ROWS 3
#define A_COLUMNS 4
#define B_ROWS 4
#define B_COLUMNS 5
#define D_ROWS 4
#define D_COLUMNS 1

int multiply(size_t a_rows, size_t a_columns, unsigned int A[a_rows][a_columns], size_t b_rows, size_t b_columns, unsigned int B[b_rows][b_columns], unsigned int C[a_rows][b_columns]) {
    if (a_columns != b_rows) {
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < a_rows; i++) {
        for (size_t j = 0; j < b_columns; j++) {
            for (size_t k = 0; k < a_columns; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return EXIT_SUCCESS;
}

int main(void) {
    unsigned int A[A_ROWS][A_COLUMNS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    unsigned int B[B_ROWS][B_COLUMNS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}};
    unsigned int C[A_ROWS][B_COLUMNS] = {0};

    if (multiply(A_ROWS, A_COLUMNS, A, B_ROWS, B_COLUMNS, B, C)) {
        printf("Error with multiplication!");
        return EXIT_FAILURE;
    }

    printf("Matrix - matrix multiplication:\n");
    for (size_t i = 0; i < A_ROWS; i++) {
        for (size_t j = 0; j < B_COLUMNS; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    unsigned int D[D_ROWS][D_COLUMNS] = {
        {1},
        {2},
        {3},
        {4}};

    unsigned int E[A_ROWS][D_COLUMNS];

    if (multiply(A_ROWS, A_COLUMNS, A, D_ROWS, D_COLUMNS, D, E)) {
        printf("Error with multiplication!");
        return EXIT_FAILURE;
    }

    printf("Matrix - vector multiplication:\n");
    for (size_t i = 0; i < A_ROWS; i++) {
        for (size_t j = 0; j < D_COLUMNS; j++) {
            printf("%d ", E[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}