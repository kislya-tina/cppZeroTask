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

    Box(int lenght, int width, int height, double weight, int value) {
        this->lenght = lenght;
        this->width = width;
        this->height = height;
        this->weight = weight;
        this->value = value;
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

    static int TotalValue(Box b[], int size);

    static bool SizeControl(Box b[], int a, int size);

    int MaxWeight(Box b[], int maxV, int size);

    static int Volume(Box a);

    static bool ContentBoxes(Box b[], int size);

    friend istream& operator>>(istream& s, Box& obj);

    friend ostream& operator<<(ostream& out, Box& obj);

    void PrintBox();

    bool operator == (const Box& box) const;

    Box& operator = (const Box& box);
};


#endif //ZERO_BOX_H
