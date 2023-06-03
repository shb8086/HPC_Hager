#include <iostream>
#include <cmath>

const int N = 100; // Matrix size
const double eps = 1e-14; // Convergence threshold

int main() {
    double phi[N+2][N+2][2] = {}; // 3D matrix for storing phi values
    double maxdelta = 2.0 * eps;
    int t0 = 0, t1 = 1;
    
    while (maxdelta > eps) {
        maxdelta = 0.0;
        
        #pragma omp parallel for reduction(max:maxdelta)
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                phi[i][k][t1] = (phi[i+1][k][t0] + phi[i-1][k][t0]
                                 + phi[i][k+1][t0] + phi[i][k-1][t0]) * 0.25;
                
                maxdelta = std::max(maxdelta, std::abs(phi[i][k][t1] - phi[i][k][t0]));
            }
        }
        
        // Swap arrays
        int temp = t0;
        t0 = t1;
        t1 = temp;
    }
    
    return 0;
}
