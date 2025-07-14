#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Zoo.h"

// 랜덤으로 동물 객체를 반환하는 함수
Animal* createRandomAnimal() {
    int random = rand() % 3;
    if (random == 0) return new Dog();
    else if (random == 1) return new Cat();
    else return new Cow();
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Zoo myZoo;

    for (int i = 0; i < 5; i++) {
        Animal* animal = createRandomAnimal();
        myZoo.addAnimal(animal);
    }
    myZoo.performActions();

    return 0;
}
