#ifndef ZERO_CONTAINER_H
#define ZERO_CONTAINER_H
#include "Box.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace ContBox {
    class Container {
    private:
        vector<Box> boxVector;//коробки
        int length = 0;//длина
        int width = 0;//ширина
        int height = 0;//высота
        double maxWeight = 0.;//макс вес
    public:
        Container(vector<Box> boxVector, int length, int width, int height, double maxWeight) {
            this->boxVector = boxVector;
            this->length = length;
            this->width = width;
            this->height = height;
            this->maxWeight = maxWeight;
        }

        int countBoxes();

        double sumWeight();

        int sumValue();

        Box getBox(int i);

        void deleteBox(int i);

        void addBox(Box box);

        friend istream &operator>>(istream &s, Container &obj);

        friend ostream &operator<<(ostream &out, Container &obj);

        Box &operator[](int &i);
    };
}


#endif //ZERO_CONTAINER_H
