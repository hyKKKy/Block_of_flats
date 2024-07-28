#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Human {
private:
    char* name;
    int age;
public:
    Human() {
        this->name = nullptr;
        this->age = 0;
    }
    Human(char* NAME, int AGE) {
        name = new char[strlen(NAME) + 1];
        strcpy(name, NAME);
        age = AGE;
    }

    Human(const Human& obj) {
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);
        age = obj.age;
    }

    ~Human() {
        delete[] name;
    }

    void Print() {
        std::cout << name << " : " << age << std::endl;
    }
};

class Flat
{
private:
    Human* humans;
    int people;
public:
    Flat() {
        humans = nullptr;
        people = 0;
    }
    Flat(Human* HUMAN,int PEOPLE) {
        people = PEOPLE;
        humans = new Human[people];
        for (int i = 0; i < people; i++) {
            humans[i] = HUMAN[i];
        }
    }
    Flat(const Flat& obj) {
        people = obj.people;
        humans = new Human[people];
        for (int i = 0; i < people; i++) {
            humans[i] = obj.humans[i];
        }
    }

    /*~Flat() {
        delete[] humans;
    }*/

    void Print() {
        std::cout << "Here live: " << people << " human" << std::endl;
        for (int i = 0; i < people; i++) {
            std::cout << "\t";
            humans[i].Print();
        }
    }
};

class Block_of_Flats
{
private:
    Flat* flats;
    int amount;
public:
    Block_of_Flats() : flats(nullptr), amount(0) {}

    Block_of_Flats(Flat* FLATS, int AMOUNT) {
        amount = AMOUNT;
        flats = new Flat[amount];
        for (int i = 0; i < amount; i++) {
            flats[i] = FLATS[i];
        }
    }

    Block_of_Flats(const Block_of_Flats& obj) {
        amount = obj.amount;
        flats = new Flat[amount];
        for (int i = 0; i < amount; i++) {
            flats[i] = obj.flats[i];
        }
    }
    ~Block_of_Flats() {
        delete[] flats;
    }

    void Print() {
        std::cout << "Flats here are: " << amount << " flats" << std::endl;
        for (int i = 0; i < amount; i++) {
            std::cout << "\t";
            flats[i].Print();
        }
    }
};



int main()
{
    char name[] = "Dmytro";
    int age = 17;
    char name1[] = "Ivan";
    int age1 = 19;

    char name2[] = "Dmytro";
    int age2 = 16;
    char name3[] = "Ann";
    int age3 = 20;

    Human h1(name,age);
    Human h2(name1, age1);

    Human h3(name2, age2);
    Human h4(name3, age3);
   
    Human human_array[2] = { h1,h2 };
    Human human_array1[2] = { h3,h4 };

    Flat flat1(human_array, 2);
    Flat flat2(human_array1, 2);

    Flat flat_array[] = { flat1,flat2 };

    Block_of_Flats block1(flat_array, 2);
    block1.Print();
}


