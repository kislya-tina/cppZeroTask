#include <iostream>
#include "Box.h"
#include "Container.h"



using namespace std;


int main() {
    Box b(1, 2, 3, 4., 5);
    Box c(1, 2, 3, 4, 5);
    if (c == b) {
        cout << "workaet" << endl << c << endl;
    }
    b.PrintBox();
}