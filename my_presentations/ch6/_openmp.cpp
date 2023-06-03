#include <iostream>
#include <omp.h>

int main() {
    #ifdef _OPENMP
    std::cout << "OpenMP is enabled!" << std::endl;
    #else
    std::cout << "OpenMP is not enabled!" << std::endl;
    #endif

    #pragma omp parallel
    {
        #ifdef _OPENMP
        int numThreads = omp_get_num_threads();
        int threadID = omp_get_thread_num();
        std::cout << "Hello from thread " << threadID << " out of " << numThreads << " threads." << std::endl;
        #endif
    }

    return 0;
}
