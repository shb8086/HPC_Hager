#include <iostream>
#include <omp.h>

int main() {
    volatile int numThreads = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            numThreads = omp_get_num_threads();
        }

        #pragma omp barrier

        #pragma omp critical
        {
            int threadID = omp_get_thread_num();
            std::cout << "Hello from thread " << threadID << " out of " << numThreads << " threads." << std::endl;
        }
    }

    return 0;
}
