#include <iostream>
#include <vector>
#include <omp.h>

// Function to calculate the value based on index
int calculate(int index) {
    return index * index;
}

int main() {
    const int N = 10;
    std::vector<int> a(N);

    // int chunkSize = N / numThreads;
    // #pragma omp parallel for schedule(static, chunkSize)
    #pragma omp parallel for schedule(static, 4)
    for (int i = 0; i < N; i++) {
        int threadId = omp_get_thread_num();
        std::cout << "Thread " << threadId << " processed word " << i << std::endl;
        // Loop body
    }

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) {
        a[i] = calculate(i + 1);
    }

    // Output the calculated values
    for (int i = 0; i < N; i++) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    return 0;
}
