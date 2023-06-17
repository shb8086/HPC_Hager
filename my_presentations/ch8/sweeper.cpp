#include <iostream>
#include <cmath>
#include <vector>

int main() {
    const long long SIZE = SIZE_OF_MEMORY_IN_DOUBLES;
    std::vector<double> A(SIZE);
    double tmp = 0.0;

    // Touch all pages
#pragma omp parallel for
    for (long long i = 0; i < SIZE; i++) {
        A[i] = std::sqrt(static_cast<double>(i)); // Dummy values
    }

    // Use the result
#pragma omp parallel for reduction(+:tmp)
    for (long long i = 0; i < SIZE; i++) {
        tmp += A[i] * A[0];
    }

    std::cout << tmp << std::endl;

    return 0;
}

