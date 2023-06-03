#include <iostream>
#include <omp.h>

class MyType {
public:
    int value;

    MyType() : value(0) {}

    MyType(int val) : value(val) {}

    // Custom reduction operation for MyType
    friend MyType operator+(const MyType& lhs, const MyType& rhs) {
        MyType result;
        result.value = lhs.value + rhs.value;
        return result;
    }
};

#pragma omp declare reduction(customReduction : MyType : omp_out = omp_out + omp_in)

int main() {
    MyType sum;

    #pragma omp parallel for reduction(customReduction : sum)
    for (int i = 0; i < 10; i++) {
        MyType temp(i);
        sum = sum + temp;
    }

    std::cout << "Sum: " << sum.value << std::endl;

    return 0;
}
