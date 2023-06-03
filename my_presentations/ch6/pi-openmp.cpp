#include <iostream>
#include <omp.h>

int main() {
  int N = 1000000;
  double pi = 0.0;
  double w = 1.0 / static_cast<double>(N);
  double sum = 0.0;

  #pragma omp parallel private(x) firstprivate(sum)
  {
    #pragma omp for
    for (int i = 1; i <= N; ++i) {
        double x = w * (i - 0.5);
        sum = sum + 4.0 / (1.0 + x * x);
    }

    #pragma omp critical
    {
        pi = pi + w * sum;
    }
  }

  std::cout << "Approximated value of pi: " << pi << std::endl;

  return 0;
}