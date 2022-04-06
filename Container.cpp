#include "Container.h"
#include <stdexcept>
using namespace ContBox;
    int Container::countBoxes(){
        return boxVector.size();
    }

    double Container::sumWeight(){
        double sumWei = 0;//общий вес содержимого
        for(int i = 0; i < boxVector.size(); i++){
            sumWei += boxVector.at(i).getWeight();
        }
        return sumWei;
    }

    int Container::sumValue(){
        int sumVal = 0;//общая стоимость содержимого
        for(int i = 0; i < boxVector.size(); i++){
            sumVal += boxVector.at(i).getValue();
        }
        return sumVal;
    }

    Box Container::getBox(int i){
        Box box;
        return box = boxVector[i];
    }

    void Container::deleteBox(int i){
    if(i > boxVector.size() - 1){

    }
        boxVector.erase(boxVector.begin() + i) ;
    }

    void Container::addBox(Box box){
        if(maxWeight > this->sumWeight() + box.getWeight()){
            boxVector.push_back(box);
        }else{
            throw range_error("Коробка не влезет в контейнер по весу");
        }
//        return boxVector.size() - 1;
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
            ")cm Max weight:(" << obj.maxWeight << ")kg" << endl;
        for(int i = 0; i < obj.countBoxes(); i++){
            out << "Box#" << i + 1 << " " << obj[i];
        }
        return out;
    }

    Box& Container::operator[]( int &i ){
        return boxVector[i];
    }


