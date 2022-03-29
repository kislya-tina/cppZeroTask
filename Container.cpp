#include "Container.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

    int Container::countBoxes(){
        cout << endl << "VectorSize " << boxVector.size() << endl;

        return boxVector.size();
    }

    double Container::summaryWeight(){
        double sumWei = 0;//общий вес содержимого
        for(int i = 0; i < boxVector.size(); i++){
            sumWei += boxVector.at(i).getWeight();
        }
        return sumWei;
    }

    int Container::summaryValue(){
        int sumVal = 0;//общая стоимость содержимого
        for(int i = 0; i < boxVector.size(); i++){
            sumVal += boxVector.at(i).getValue();
        }
        return sumVal;
    }

    Box Container::getBox(int i){
        Box box;
        return box = boxVector.at(i);
    }

    void Container::deleteBox(int i){
        boxVector.erase(boxVector.begin() + i - 1) ;
    }

    int Container::addBox(Box box){
        if(maxWeight > this->summaryWeight() + box.getWeight()){
            boxVector.push_back(box);
        }else{
            throw range_error("Коробка не влезет в контейнер по весу");
        }
        return boxVector.size() - 1;
    }

    istream& operator>>(istream& s, Container& obj) {//#7.1
        s >> obj.length;
        s >> obj.width;
        s >> obj.height;
        s >> obj.maxWeight;
        return s;
    }

    ostream& operator<<(ostream& out, Container& obj) {//#7.2
        out << "Size:(" << obj.length << ", " << obj.width << ", " << obj.height <<
            ")cm Max weight:(" << obj.maxWeight<< ")kg" << endl;
        return out;
    }

    Box& Container::operator[]( int &i ){
        return boxVector[i];
    }


