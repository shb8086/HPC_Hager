#include <mpi.h>
#include <iostream>

int main(int argc, char** argv) {
    int rank, size;
    int recvBuffer[100];
    MPI_Status status;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    // Assuming rank 0 sends an array of 10 integers to rank 1
    if (rank == 1) {
        MPI_Recv(recvBuffer, 10, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        int count;
        MPI_Get_count(&status, MPI_INT, &count);
        std::cout << "Received " << count << " integers." << std::endl;
    }
    else if (rank == 0) {
        int sendBuffer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        MPI_Send(sendBuffer, 10, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    
    MPI_Finalize();
    return 0;
}

