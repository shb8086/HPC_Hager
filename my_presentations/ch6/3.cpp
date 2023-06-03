void mySubroutine(int local_var) {
  static int shared_var; // Local variable with 'static' storage class
  // Modifications made on shared_var will be visible to all threads
  // Each calling thread will have its own private copy of 'local_var'
}

int main() {
  int n = 5 ;
  // Other code...​
  #pragma omp parallel
  {
    // Each thread will call the subroutine with its own private copy of 'local_var'
    mySubroutine(n);
  }
  // Other code...​
  return 0;
}




