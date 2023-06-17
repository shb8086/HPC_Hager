#include <iostream>
#include <vector>

int main() {
    const int N = 1000000;
    const int R = 10; // Replace with the desired value of R

    std::vector<int> A(N);
    std::vector<int> B(N);
    std::vector<int> C(N);
    std::vector<int> D(N);

    // Initialization
#pragma omp parallel for schedule(static, 512)
    for (int i = 0; i < N; i++) {
        A[i] = 0;
        B[i] = i;
        C[i] = i % 5;
        D[i] = i % 10;
    }

    // Rest of the code...

    for (int j = 0; j < R; j++) {
        // Perform calculations
#pragma omp parallel for schedule(runtime)
        for (int i = 0; i < N; i++) {
            A[i] = B[i] + C[i] * D[i];
        }

        // Call dummy function
        dummy(A, B, C, D);
    }

    // Rest of the code...

    return 0;
}
