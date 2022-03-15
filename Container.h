//
// Created by kisel on 3/6/2022.
//

#ifndef ZERO_CONTAINER_H
#define ZERO_CONTAINER_H
#include <vector>


class Container {
private:
    vector<Box> boxVector;//коробки
    int lenght = 0;//длина
    int width = 0;//ширина
    int height = 0;//высота
    double maxWeight = 0.;//макс вес

public:

    Container(int lenght, int width, int height, double maxWeight) {
        boxVector = 0;
        this.lenght = lenght;
        this.width = width;
        this.height = height;
        this.maxWeight = maxWeight;
    }
    void addBox(int i){
        delete boxVector.at(i) ;
    }


};


#endif //ZERO_CONTAINER_H
