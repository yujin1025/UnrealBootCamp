#include "Zoo.h"

// 생성자
Zoo::Zoo() : animalCount(0) {
    for (int i = 0; i < 10; i++) {
        animals[i] = nullptr;
    }
}

// 동물을 동물원에 추가하는 함수
void Zoo::addAnimal(Animal* animal) {
    if (animalCount < 10) {
        animals[animalCount++] = animal;
    }
}

// 동물원에 있는 모든 동물의 울음소리를 출력하는 함수
void Zoo::performActions() {
    for (int i = 0; i < animalCount; i++) {
        if (animals[i]) {
            animals[i]->makeSound();
        }
    }
}

// 소멸자
Zoo::~Zoo() {
    for (int i = 0; i < animalCount; i++) {
        delete animals[i];
    }
}
