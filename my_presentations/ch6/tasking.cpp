#include <iostream>
#include <cstdlib>
#include <ctime>

struct Object {
    double weight;
};

void do_work_with(Object& obj) {
    // Perform work with obj
}

int main() {
    int N = 1000000;
    Object* p = new Object[N];
    double r;

    #pragma omp parallel private(r)
    {
        #pragma omp single
        {
            for (int i = 0; i < N; i++) {
                r = static_cast<double>(rand()) / RAND_MAX;
                if (p[i].weight > r) {
                    #pragma omp task
                    {
                        do_work_with(p[i]);
                    }
                }
            }
        }
    }

    delete[] p;
    return 0;
}

