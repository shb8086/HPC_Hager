#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, **matrix1, **matrix2, **result;
    clock_t start, end;
    double cpu_time_used;

    // Get input for matrix size
    printf("Enter the size of matrices (n): ");
    scanf("%d", &n);

    // Allocate memory for matrices
    matrix1 = (int **)malloc(n * sizeof(int *));
    matrix2 = (int **)malloc(n * sizeof(int *));
    result = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix1[i] = (int *)malloc(n * sizeof(int));
        matrix2[i] = (int *)malloc(n * sizeof(int));
        result[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize matrix values
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
            result[i][j] = 0;
        }
    }

    // Multiply matrices and measure time
    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[j][i] += i*j;
        }
    }
    end = clock();

    // Print result and time taken
    // printf("\nMatrix multiplication result:\n");
    // for (i = 0; i < n; i++) {
    //     for (j = 0; j < n; j++) {
    //         printf("%d ", result[i][j]);
    //     }
    //     printf("\n");
    // }
    cpu_time_used = ((double) (end - start));
    printf("Time taken: %f seconds\n", cpu_time_used);

    // Free memory
    for (i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}

//Time taken: 9732.000000 seconds