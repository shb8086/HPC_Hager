#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int maxProcesses;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &maxProcesses);
    printf("Maximum number of processes: %d\n", maxProcesses);
    MPI_Finalize();
    return 0;
}