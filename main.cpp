#include <iostream>
#include <cassert>
#include "vector.h"
using namespace std;

int main()
{
    Vector<int, 10> a(3), b(5);
    a[4] = 2;
    cout << a << "\n" << b << "\n" << a + b << "\n" << a * b << "\n" << 2 * a << "\n";
    assert(a[2] == 3);
        cout << "the 3rd value is 3";
    return 0;
}
