//
// Created by kisel on 3/6/2022.
//

#ifndef ZERO_CONTAINER_H
#define ZERO_CONTAINER_H
#include <vector>
#include <algorithm>
#include <stdexcept>


class Container {
private:
    vector<Box> boxVector;//коробки
    int lenght = 0;//длина
    int width = 0;//ширина
    int height = 0;//высота
    double maxWeight = 0.;//макс вес
public:
    Container(int lenght, int width, int height, double maxWeight) {
        this->lenght = lenght;
        this->width = width;
        this->height = height;
        this->maxWeight = maxWeight;
    }
    /*Container(vector<Box> boxvector, int lenght, int width, int height, double maxWeight) {
        for(){

        }
        this->lenght = lenght;
        this->width = width;
        this->height = height;
        this->maxWeight = maxWeight;
    }*/

    int countBoxes(){
        int count = boxVector.size();
        return count;
    }

    double summaryWeight(){
        double sumWei = 0;//общий вес содержимого
        for(int i = 0; i < boxVector.size(); i++){
            sumWei += boxVector.at(i).getWeight();
        }
        return sumWei;
    }

    int summaryValue(){
        int sumVal = 0;//общая стоимость содержимого
        for(int i = 0; i < boxVector.size(); i++){
            sumVal += boxVector.at(i).getValue();
        }
        return sumVal;
    }

    Box getBox(int i){
        Box box;
        return box = boxVector.at(i);
    }

    void deleteBox(int i){
        boxVector.erase(boxVector.begin() + i - 1) ;
    }

    int addBox(Box box){
        if(maxWeight > this->summaryWeight() + box.getWeight()){
            boxVector.push_back(box);
        }else{
            throw range_error("Коробка не влезет в контейнер по весу");
        }
        return boxVector.size() - 1;
    }

    friend istream& operator>>(istream& s, Container& obj) {//#7.1
        s >> obj.lenght;
        s >> obj.width;
        s >> obj.height;
        s >> obj.maxWeight;
        return s;
    }

    friend ostream& operator<<(ostream& out, Container& obj) {//#7.2
        out << "Size:(" << obj.lenght << ", " << obj.width << ", " << obj.height <<
            ")cm Max weight:("<< obj.maxWeight<< ")kg" << endl;
        return out;
    }

    Box& operator[]( int &i ){
        return boxVector[i];
    }
};


#endif //ZERO_CONTAINER_H
