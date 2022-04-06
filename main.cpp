#include <iostream>
#include "Box.h"
#include "Container.h"

using namespace std;
using namespace ContBox;

int main() {
    Box a(4, 4, 5, 3, 17);
    Box b(3, 3, 4, 1, 11);
    Box c(1, 2, 3, 2, 1);
    Box d;
    Box arrABC[3] = {a, b, c};
    Box arrBC[2] = {c, b};
    Box arrAC[2] = {a, c};
    cout << "TotalValue: " << Box::TotalValue(arrBC, 2) << endl;

    if(Box::ContentBoxes(arrABC, 3)){
        cout << "ContentBox: yes" << endl;
    }else{
        cout << "ContentBox: no" << endl;
    }

    if(Box::ContentBoxes(arrAC, 2)){
        cout << "ContentBox: yes" << endl;
    }else {
        cout << "ContentBox: no" << endl;
    }

    cout << "SizeControl: " << Box::SizeControl(arrBC, 2, 7) << endl;
    cout << "MaxWeight: " << Box::MaxWeight(arrBC, 2, 12) << endl;

    cout << a << d << endl;
    d = a;
    if (a == d) {
        cout << a << d << endl;
    }



    vector<Box> vectorBox = {a, b, c, d};
    Container cont(vectorBox, 100, 100, 100, 100.);

    cout << "countBoxes: " << cont.countBoxes() << endl;
    cout << "sumWeight: " << cont.sumWeight() << endl;
    cout << "sumValue: " << cont.sumValue() << endl;
    cont.addBox(a);
    cout << "countBoxes: " << cont.countBoxes() << endl;
    Box box = cont.getBox(4);
    cout << "getBox: " << endl << box << endl;
    cont.deleteBox(0);
    cout << cont << endl;
}
