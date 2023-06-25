#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, message;
    MPI_Status status;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
      // Process 0 sends a message to process 1
      message = 123;
      MPI_Send(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
      // Process 1 receives the message from process 0
      MPI_Recv(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

      // Access information from the status structure
      int source = status.MPI_SOURCE;
      int tag = status.MPI_TAG;

      // Check for errors
      if (status.MPI_ERROR != MPI_SUCCESS) {
        printf("Error receiving message\n");
      // Handle the error
      } else {
        printf("Received message %d from process %d with tag %d\n", message, source, tag);
      }
    }

    MPI_Finalize();
    return 0;
}
