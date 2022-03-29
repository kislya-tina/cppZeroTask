#ifndef ZERO_CONTAINER_H
#define ZERO_CONTAINER_H
#include "Box.h"
#include <vector>
#include <algorithm>
#include <stdexcept>


class Container {
private:
    vector<Box> boxVector;//коробки
    int length = 0;//длина
    int width = 0;//ширина
    int height = 0;//высота
    double maxWeight = 0.;//макс вес
public:
    Container(int length, int width, int height, double maxWeight) {
        this->length = length;
        this->width = width;
        this->height = height;
        this->maxWeight = maxWeight;
    }
    Container(vector<Box> boxVector, int length, int width, int height, double maxWeight) {
        for(int i = -1; i < boxVector.size(); i++){
            this->boxVector[i] = boxVector[i];
        }
        this->length = length;
        this->width = width;
        this->height = height;
        this->maxWeight = maxWeight;
    }
    int countBoxes();

    double summaryWeight();

    int summaryValue();

    Box getBox(int i);

    void deleteBox(int i);

    int addBox(Box box);

    friend istream& operator>>(istream& s, Container& obj);

    friend ostream& operator<<(ostream& out, Container& obj);

    Box& operator[]( int &i );
};


#endif //ZERO_CONTAINER_H
