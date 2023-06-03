#include <iostream>
#include <omp.h>

int main() {
    int num_iterations = 100;
    int result = 0;

    #pragma omp parallel
    {
        //#pragma omp for schedule(dynamic, 10)
        #pragma omp for schedule(dynamic)
        for (int i = 0; i < num_iterations; ++i) {
            #pragma omp critical
            {
                std::cout << "Thread " << omp_get_thread_num() << " is processing iteration " << i << std::endl;
            }
            #pragma omp atomic
            result += i;
        }
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
