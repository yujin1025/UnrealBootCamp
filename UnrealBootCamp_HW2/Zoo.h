#ifndef ZOO_H
#define ZOO_H
#include "Animal.h"

class Zoo {
private:
    Animal* animals[10]; 
    int animalCount;    

public:
    Zoo();               
    void addAnimal(Animal* animal); 
    void performActions();          
    ~Zoo();            
};

#endif 
