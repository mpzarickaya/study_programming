#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

class Animal
{
private:
    string type;
    string name;
public:
    Animal(string name, string type)
    {
        this->name = name;
        this->type = type;
    }
    string getName()
    {
        return name;
    }
    string getType()
    {
        return type;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setType(string type)
    {
        this->type = type;
    }
    void feed()
    {
        cout << "Животное " << name << " ест" << endl;
    }
    void sleep()
    {
        cout << "Животное " << name << " спит" << endl;
    }
    void play()
    {
        cout << "Животное " << name << " играет" << endl;
    }
};

class Lion : public Animal
{
public:
    Lion(string name) : Animal(name, "Лев")
    {}
};

class Penguin: public Animal
{
public:
    Penguin(string name) : Animal(name, "Пингвин")
    {}
};

class Giraffe : public Animal
{
public:
    Giraffe(string name) : Animal(name, "Жираф")
    {}
};

class Zoo
{
private:
    vector<Animal*> animals;
public:
    Zoo()
    {
    }
    ~Zoo()
    {
        for (int i = 0; i < animals.size(); i++)
        {
            delete animals[i];
        }
    }
    void addAnimal(Animal* animal)
    {
        animals.push_back(animal);
    }
    void deleteAnimal(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals.erase(animals.begin() + i);
                break;
            }
        }
    }
    void feedAll()
    {
        for (int i = 0; i < animals.size(); i++)
        {
            animals[i]->feed();
        }
    }
    void sleepAll()
    {
        for (int i = 0; i < animals.size(); i++)
        {
            animals[i]->sleep();
        }
    }
    void playAll()
    {
        for (int i = 0; i < animals.size(); i++)
        {
            animals[i]->play();
        }
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Zoo zoo;
    zoo.addAnimal(new Lion("Лев"));
    zoo.addAnimal(new Penguin("Пингвин"));
    zoo.addAnimal(new Giraffe("Жираф"));

    zoo.feedAll();
    zoo.sleepAll();
    zoo.playAll();
    cout << "\n\n";
    zoo.deleteAnimal("Лев");

    zoo.feedAll();

    return 0;
};