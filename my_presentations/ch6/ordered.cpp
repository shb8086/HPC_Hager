#include <omp.h>
#include <iostream>

int main() {
    #pragma omp parallel
    {
        #pragma omp critical
        {
            #pragma omp ordered
            {
                // Code block executed in order of thread IDs
                int thread_id = omp_get_thread_num();
                std::cout << "Thread " << thread_id << " is executing the ordered block." << std::endl;
            }
        }
    }

    return 0;
}