#include <iostream>
#include <cmath>
#include <random>
#include <omp.h>

const int n = 1000;

int main() {
    double a[n], noise[n], norm = 0.0;
    int i;

    // Initialize the random number generator
    for (i=0; i<n; i++)
      noise[i] = rand();

    // Add random noise to the array elements
    #pragma omp parallel for default(none) shared(a, noise) private(i)
    for (i = 0; i < n; i++) {
        #pragma omp atomic
        a[i] += noise[i];
    }

    // Calculate the vector norm
    #pragma omp parallel for reduction(+: norm) default(none) shared(a) private(i)
    for (i = 0; i < n; i++) {
        #pragma omp atomic
        norm += a[i] * a[i];
    }

    norm = std::sqrt(norm);

    std::cout << "Vector norm: " << norm << std::endl;

    return 0;
}
