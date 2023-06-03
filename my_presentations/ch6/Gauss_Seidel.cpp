#include <iostream>

const double osth = 1.0 / 6.0;
const int imax = 100; // Number of grid points in x-direction
const int jmax = 100; // Number of grid points in y-direction
const int kmax = 100; // Number of grid points in z-direction
const int itmax = 100; // Number of iterations

int main() {
    double phi[imax+2][jmax+2][kmax+2] = {}; // 3D grid for storing phi values

    for (int it = 1; it <= itmax; it++) {
        // Iterate over grid points in z, y, and x directions
        for (int k = 1; k <= kmax; k++) {
            for (int j = 1; j <= jmax; j++) {
                for (int i = 1; i <= imax; i++) {
                    phi[i][j][k] = (phi[i-1][j][k] + phi[i+1][j][k]
                                    + phi[i][j-1][k] + phi[i][j+1][k]
                                    + phi[i][j][k-1] + phi[i][j][k+1]) * osth;
                }
            }
        }
    }

    return 0;
}
