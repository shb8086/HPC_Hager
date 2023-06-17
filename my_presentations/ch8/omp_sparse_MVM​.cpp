#include <iostream>
#include <vector>

int main() {
    int Nr = 100; // Replace with the desired value of Nr

    std::vector<int> row_ptr(Nr + 1);
    std::vector<double> C(Nr);
    std::vector<double> B(Nr);
    std::vector<double> val; // Assuming val is already declared and allocated
    std::vector<int> col_idx; // Assuming col_idx is already declared and allocated

    // Parallel loop to initialize row_ptr, C, and B
#pragma omp parallel for
    for (int i = 0; i < Nr; i++) {
        row_ptr[i] = 0;
        C[i] = 0.0;
        B[i] = 0.0;
    }

    // Preset row_ptr array

    // Parallel loop to set val and col_idx to 0 within the specified range for each row
#pragma omp parallel for private(start, end, j)
    for (int i = 0; i < Nr; i++) {
        int start = row_ptr[i];
        int end = row_ptr[i + 1];
        for (int j = start; j < end; j++) {
            val[j] = 0.0;
            col_idx[j] = 0;
        }
    }

    // Rest of the code...

    return 0;
}