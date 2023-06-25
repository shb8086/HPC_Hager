#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
  int rank;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  int numbers = 10;

  for( int i=0; i<numbers; i++ ) {
    std::cout << "I am " << rank << " I'm printing " << i << std::endl;
  }

  MPI_Finalize();
  return 0;
}

