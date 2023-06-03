int main() {

    int shared_var = 0;
    // Other code...​
    #pragma omp parallel
    {
        // Each thread will have its own private copy of shared_var
        int private_var = shared_var;

        // Modify private copy of shared_var within the parallel region
        // ...

        // Update shared_var with the modified private copy
        shared_var = private_var;

        // Synchronize threads before accessing shared_var
        #pragma omp barrier
    }
    // shared_var outside the parallel region will retain its original value​
    // Other code...​
    return 0;
}




