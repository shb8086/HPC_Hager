#include <iostream>
#include <omp.h>

int main() {
    int num_iterations = 10;
    int chunk_size = 1;

    // Set the desired loop scheduling at runtime using the OMP_SCHEDULE environment variable
    // char* env_var = "OMP_SCHEDULE=dynamic,2"; // Example: dynamic scheduling with a chunk size of 2
    // putenv(env_var);

    #pragma omp parallel for schedule(runtime)
    for (int i = 0; i < num_iterations; i++) {
        int thread_id = omp_get_thread_num();
        std::cout << "Thread " << thread_id << " executing iteration " << i << std::endl;
    }

    return 0;
}

