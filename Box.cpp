#include "Box.h"
#include <iostream>
using namespace ContBox;

int Box::TotalValue(Box b[], int size) {//#2
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += b[i].value;
    }
    return total;
}

bool Box::SizeControl(Box b[], int size, int a) {//#3
    int k = 0;
    for (int i = 0; i < size; i++) {
        int summ = b[i].height + b[i].length + b[i].width;
        if (summ <= a) {
            k++;
        }
    }
    if (k == size) {
        return true;
    }
    else {
        return false;
    }
}

int Box::MaxWeight(Box b[], int size, int maxV) {//#4
    double maxW = 0;//максимальная стоимость
    for (int i = 0; i < size; i++) {
        if ((b[i].weight > maxW) && (Volume(b[i]) <= maxV)) {
            maxW = b[i].weight;
        }
    }
}

int Box::Volume(Box a) {//объе
    int volume = a.height * a.length * a.width;
    return volume;
}

bool Box::ContentBoxes(Box b[], int size) {//коробку в коробку
    int minLen;//длина
    int minWid;//ширина
    int minHei;//высота
    int memory = 0;
    Box c[size];
    Box d = Box(2147483647, 2147483647, 2147483647, 0, 0);

    for (int i = 0; i < size; i++) {//копия ориг массива
        c[i] = b[i];
    }

    for (int j = 0; j < size; j++) {
        minLen = 2147483647;
        minHei = 2147483647;
        minWid = 2147483647;
        for (int i = j + 1; i < size; i++) {//найти самую маленькую и запомнить ее индекс
            if(c[i].length == c[j].length || c[i].width == c[j].width || c[i].height == c[j].height){
                cout << "1";
                return false;
            }
            if((b[i].length < b[j].length) && (b[i].width > b[j].width) && (b[i].height > b[j].height) ||
               (b[i].length > b[j].length) && (b[i].width < b[j].width) && (b[i].height > b[j].height) ||
               (b[i].length > b[j].length) && (b[i].width > b[j].width) && (b[i].height < b[j].height)){
                cout << "2";
                return false;
            }
            if ((minLen > c[i].length) &&
                (minWid > c[i].width) &&
                (minHei > c[i].height)) {

                minLen = c[i].length;
                minWid = c[i].width;
                minHei = c[i].height;
                memory = i;

            }
            else continue;
        }

        c[memory] = d;
    }
    return true;
}

istream& operator>>(istream& s, Box& obj) {//#7.1
    s >> obj.length;
    s >> obj.width;
    s >> obj.height;
    s >> obj.weight;
    s >> obj.value;
    return s;
}

ostream& operator<<(ostream& out, Box& obj) {//#7.2
    out << "Size:(" << obj.length << ", " << obj.width << ", " << obj.height <<
        ")cm Weight:(" << obj.weight <<
        " kg) Value:(" << obj.value << " kop.)" << endl;
    return out;
}

void Box::PrintBox() {
        cout << length << width << height << weight << value;
}

bool Box::operator == (const Box& box) const {//#6
    return this->length == box.length &&
              this->width == box.width &&
              this->height == box.height &&
              this->value == box.value &&
              this->weight == box.weight;
}

Box& Box::operator = (const Box& box) {
    if (&box == this){
        return *this;
    }
    this->height = box.height;
    this->length = box.length;
    this->width = box.width;
    this->weight = box.weight;
    this->value = box.value;
    return *this;
}