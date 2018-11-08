#include <iostream>
#include <string>

#include "vector.hpp"

void sizes()
{
    std::cout << "\n size of int: " << sizeof(int) << " bytes\n";
    std::cout << "size of int*: " << sizeof(int*) <<
              " bytes (" << sizeof(int*)*8 << " bits)\n";

    std::cout << "\n size of long double: " << sizeof(long double) << " bytes\n";
    std::cout << "size of long double*: " << sizeof(long double*) << " bytes\n";
}


int main() {

    int pi = 3;
    int* p_pi = &pi;

    std::cout << "  pi = " << pi << '\n';
    std::cout << "p_pi = " << p_pi << '\n';

    vector v1 {1.2, 3.4, 5.6};
    std::cout << "\nv1 =\n" << v1 << '\n';

    vector v2 = v1; // Copy construction due to elision

    v2[1] = 0;
    std::cout << "\nv2 =\n" << v2 << '\n';
    std::cout << "\nv1 =\n" << v1 << '\n';

    return 0;
}
