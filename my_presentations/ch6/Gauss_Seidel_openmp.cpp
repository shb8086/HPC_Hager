#include <iostream>
#include <omp.h>

const int imax = 10;
const int jmax = 10;
const int kmax = 10;
const double osth = 1.0 / 6.0;

int main() {
    double phi[imax+2][jmax+2][kmax+2];

    #pragma omp parallel private(k, j, i, jStart, jEnd, threadID)
    {
        threadID = omp_get_thread_num();

        #pragma omp single
        {
            int numThreads = omp_get_num_threads();
        }

        jStart = (jmax / numThreads) * threadID;
        jEnd = jStart + (jmax / numThreads); // jmax is a multiple of numThreads

        for (int l = 1; l <= kmax + numThreads - 1; l++) {
            k = l - threadID;

            if (k >= 1 && k <= kmax) {
                for (j = jStart; j < jEnd; j++) {
                    for (i = 1; i <= imax; i++) {
                        phi[i][j][k] = (phi[i-1][j][k] + phi[i+1][j][k]
                                        + phi[i][j-1][k] + phi[i][j+1][k]
                                        + phi[i][j][k-1] + phi[i][j][k+1]) * osth;
                    }
                }
            }

            #pragma omp barrier
        }
    }

    // Print the values for verification
    for (int k = 1; k <= kmax; k++) {
        for (int j = 1; j <= jmax; j++) {
            for (int i = 1; i <= imax; i++) {
                std::cout << "phi[" << i << "][" << j << "][" << k << "] = " << phi[i][j][k] << std::endl;
            }
        }
    }

    return 0;
}
