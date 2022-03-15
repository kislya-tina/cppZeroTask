#include <iostream>
#include "Box.h"
#include "Container.h"



using namespace std;


int main() {
    Box a(0, 0, 0, 0, 0);
    Box b(1, 2, 3, 4., 5);
    Box c(1, 2, 3, 4, 5);
    c = a;
    if (c == b) {
        cout << "workaet" << endl << c << endl;
    }
    cout << a << b << c;
    b.PrintBox();

}