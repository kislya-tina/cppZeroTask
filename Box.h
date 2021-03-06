#ifndef ZERO_BOX_H
#define ZERO_BOX_H
#include <iostream>

using namespace std;
namespace ContBox {
    class Box {

    private:
        int length = 0;//длина
        int width = 0;//ширина
        int height = 0;//высота

        double weight = 0.;//вес
        int value = 0;//стоимость

    public:

        Box() {
            length = 0;
            width = 0;
            height = 0;
            weight = 0;
            value = 0;
        }

        Box(int lenght, int width, int height, double weight, int value) {
            this->length = lenght;
            this->width = width;
            this->height = height;
            this->weight = weight;
            this->value = value;
        }

        //getter
        int getLength() const { return length; }

        int getWidth() const { return width; }

        int getHeight() const { return height; }

        double getWeight() const { return weight; }

        int getValue() const { return value; }

        //setter
        void setLength(int len) { Box::length = len; }

        void setWidth(int wid) { Box::width = wid; }

        void setHeight(int hei) { Box::height = hei; }

        void setWeight(double wei) { Box::weight = wei; }

        void setValue(int val) { Box::value = val; }

        static int TotalValue(Box b[], int size);

        static bool SizeControl(Box b[], int size, int a);

        static int MaxWeight(Box b[], int size, int maxV);

        static int Volume(Box a);

        static bool ContentBoxes(Box b[], int size);

        friend istream &operator>>(istream &s, Box &obj);

        friend ostream &operator<<(ostream &out, Box &obj);

        void PrintBox();

        bool operator==(const Box &box) const;

        Box &operator=(const Box &box);
    };
}

#endif //ZERO_BOX_H
