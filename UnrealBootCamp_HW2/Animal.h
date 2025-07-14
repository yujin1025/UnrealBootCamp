#ifndef ANIMAL_H
#define ANIMAL_H

// 기본 클래스: Animal
class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() {}
};

// 파생 클래스: Dog
class Dog : public Animal {
public:
    void makeSound() override;
};

// 파생 클래스: Cat
class Cat : public Animal {
public:
    void makeSound() override;
};

// 파생 클래스: Cow
class Cow : public Animal {
public:
    void makeSound() override;
};

#endif