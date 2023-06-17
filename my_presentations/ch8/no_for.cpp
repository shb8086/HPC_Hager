#include <iostream>
#include <fstream>
#include <vector>

double func(double value) {
    // Function implementation
    return value; // Replace with the desired calculation
}

int main() {
    const int N = 1000000;

    std::vector<double> A(N);
    std::vector<double> B(N);

    // executed on single LD
    std::ifstream input("data.txt"); // Assuming the data is stored in a file called "data.txt"
    for (int i = 0; i < N; i++) {
        input >> A[i];
    }
    input.close();

    // Parallel loop
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        B[i] = func(A[i]);
    }

    // Rest of the code...

    return 0;
}
