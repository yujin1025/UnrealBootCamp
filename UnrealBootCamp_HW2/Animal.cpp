#include "Animal.h"
#include <iostream>
using namespace std;

void Dog::makeSound() {
    cout << "Dog barks: Woof! Woof!" << endl;
}

void Cat::makeSound() {
    cout << "Cat meows: Meow! Meow!" << endl;
}

void Cow::makeSound() {
    cout << "Cow moos: Moo! Moo!" << endl;
}