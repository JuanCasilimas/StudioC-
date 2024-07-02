#include <iostream>
#include <string>

class Persona{
public:
    Persona(std::string name, int age) : name(name), age(age){}

    std::string getname(){
        return name;
    }

    int getage(){
        return age;
    }

private:
    std::string name;
    int age;
};

int main(){
    std::string name;
    int age;

    std::cout << "Enter the name of person 1: " << std::endl;
    std:: cin >> name;
    std:: cout << "Enter the age of person 1: " << std::endl;t
    std:: cin >> age;
    Persona p1(name, age);

    std:: cout << "Enter the name of person 2: " << std::endl;
    std:: cin >> name;
    std:: cout << "Enter the age of person 2: " << std::endl;
    std:: cin >> name;
    Persona p2(name, age);

    std::cout << "Person 1 Name: " << p1.getname() << ", Age: "<< p1.getage() << std::endl;

    std::cout << "Person 2 Name: " << p2.getname() << ", Age: " << p2.getage() << std::endl;

    return 0;
}