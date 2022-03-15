//
// Created by kislya on 3/1/2022.
//

#ifndef ZERO_BOX_H
#define ZERO_BOX_H
#include <iostream>

using namespace std;

class Box {

private:
    int lenght = 0;//длина
    int width = 0;//ширина
    int height = 0;//высота

    double weight = 0.;//вес
    int value = 0;//стоимость

public:

    Box() {
        lenght = 0;
        width = 0;
        height = 0;
        weight = 0;
        value = 0;
    }

    Box(int a1, int a2, int a3, double a4, int a5) {
        lenght = a1;
        width = a2;
        height = a3;
        weight = a4;
        value = a5;
    }
    //getter
    int getLenght() const {return lenght;}
    int getWidth() const {return width;}
    int getHeight() const {return height;}
    double getWeight() const {return weight;}
    int getValue() const {return value;}
    //setters
    void setLenght(int len) {Box::lenght = len;}
    void setWidth(int wid) {Box::width = wid;}
    void setHeight(int hei) {Box::height = hei;}
    void setWeight(double wei) {Box::weight = wei;}
    void setValue(int val) {Box::value = val;}

    int TotalValue(Box b[]) {//#2
        int size = sizeof(b) / sizeof(int);
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += b[i].value;
        }
        return total;
    }

    bool SizeControl(Box b[], int a) {//#3
        int size = sizeof(b) / sizeof(int);
        int k = 0;
        for (int i = 0; i < size; i++) {
            int summ = b[i].height + b[i].lenght + b[i].width;
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

    int MaxWeight(Box b[], int maxV) {//#4
        int size = sizeof(b) / sizeof(int);
        double maxW = 0;//максимальная стоимость
        for (int i = 0; i < size; i++) {
            if ((b[i].weight > maxW) && (Volume(b[i]) <= maxV)) {
                maxW = b[i].weight;
            }
        }
    }

    int Volume(Box a) {//объем
        int volume = a.height * a.lenght * a.width;
        return volume;
    }

    /*Не знаю как сложить их в друг друга
    * упдЖ
    * знаю и сделал
    if ((b[i].lenght > b[i + 1].lenght) && (b[i].width > b[i + 1].width) && (b[i].height > b[i + 1].height)) {
                minLen = b[i + 1].lenght;
                minWid = b[i + 1].width;
                minHei = b[i + 1].height;
            }
            if ((c[i].lenght > c[i + 1].lenght) && (minLen > c[i + 1].lenght) &&
                    (c[i].width > c[i + 1].width) && (minWid > c[i + 1].width) &&
                    (c[i].height > c[i + 1].height) && (minHei > c[i + 1].height)) {

    */
    bool ContentBoxes(Box b[]) {//коробку в коробку
        int size = sizeof(b) / sizeof(int);
        int minLen;//длина
        int minWid;//ширина
        int minHei;//высота
        int memory = 0;
        Box c[sizeof(b) / sizeof(int)];
        Box d = Box(2147483647, 2147483647, 2147483647, 0, 0);

        for (int i = 0; i < size; i++) {//копия ориг массива
            c[i] = b[i];
        }

        for (int j = 0; j < size; j++) {
            minLen = 2147483647;
            minHei = 2147483647;
            minWid = 2147483647;
            for (int i = 0; i < size; i++) {//найти самую маленькую и запомнить ее индекс
                if ((minLen > c[i].lenght) &&
                    (minWid > c[i].width) &&
                    (minHei > c[i].height)) {

                    minLen = c[i].lenght;
                    minWid = c[i].width;
                    minHei = c[i].height;
                    memory = i;

                }
                else continue;

            }

            c[memory] = d;
        }

        return false;
    }


    friend istream& operator>>(istream& s, Box& obj) {//#7.1
        s >> obj.lenght;
        s >> obj.width;
        s >> obj.height;
        s >> obj.value;
        s >> obj.weight;
        return s;
    }

    friend ostream& operator<<(ostream& out, Box& obj) {//#7.2
        out << "Size:(" << obj.lenght << ", " << obj.width << ", " << obj.height <<
            ")cm Weight:(" << obj.weight <<
            " kg) Value:(" << obj.value << " kop.)" << endl;
        return out;
    }

    void PrintBox() {
        cout << lenght << width << height << weight << value;
    }

    bool operator == (const Box& box) const {//#6
        return	this->lenght == box.lenght &&
                  this->width == box.width &&
                  this->height == box.height &&
                  this->value == box.value &&
                  this->weight == box.weight;
    }
};


#endif //ZERO_BOX_H
