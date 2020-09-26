#include <iostream>
#include "Fraction.hpp"

#include <assert.h>

using namespace std;

int main() {
    //Fraction a(10, 2), b(10, 2);

    //std::cout << a << std::endl;
    {
        Fraction a(10, 2), b(10, 3), result(25,3);
        a.add(b);
        assert(a == result);
    }

    /*{

    }*/
    //std::cout << "equal: " << (a == b) << "\n";
    return 0;
}
