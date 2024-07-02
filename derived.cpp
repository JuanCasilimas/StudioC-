#include <iostream>
#include <string>

class Animal{
public:

    Animal(const std::string &name) : name(name) {}

    virtual void makesound(){
        std::cout << name << " makes a sound." << std::endl;
    }
protected:
    std::string name;
};

class Dog : public Animal{
public:
    Dog(const std::string &name) : Animal(name){}

    void makesound(){
        std::cout << name << "Barks" << std::endl; 
    }
};

int main(){
    Animal animal("Animal");
    animal.makesound();

    Dog dog("Dog");
    dog.makesound();

    Animal* animalptr = &dog;
    animalptr -> makesound();

    return 0;
}