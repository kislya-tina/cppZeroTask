#include <iostream>
#include "Box.h"
#include "Container.h"

using namespace std;

int main() {
    Box a;
    Box b(2, 3, 4, 0, 0);
    Box c(1, 2, 3, 0, 0);

    Box arr[2] = {b, c};
    if (c == b) {
        cout << "work" << endl << c << endl;
    }
    cout << a << b << c;

    Box::TotalValue(arr, 2);


    if(Box::ContentBoxes(arr, 2)){
        cout << "yes";
    }else{
        cout << "no";
    }


}