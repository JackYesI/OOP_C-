#include <iostream>
#include "dog.h"
#include "Cat.h"
#include "Hamster.h"
#include "Parrot.h"
#include "HomeZoo.h"
#include <vector>

using namespace std;

int main()
{
    dog dog_("Gavchyk", 4);
    Cat cat("Murchyck", 5);
    Hamster humster("lola", 1);
    Parrot parrot("enjoy", 10);
    
    /*new Cat("murka", 2)*/
    /*Animal* homeZoo[] = {&cat};*/
    vector<Animal*> zo = {&cat};
    zo.push_back(&dog_);
    
    Zoo zoo(zo);
    
    zoo.Show();

    zo[0]->setName("Jack-1");
    zoo.add();
  /*  zoo.Show();*/
    zoo.buyAll();
    zoo.Show();
    zoo.pop(0);
    zoo.add();
    zoo.add();
    zoo.Show();
    cout << "======================" << endl;
    zoo.pop(0);
    zoo.Show();
    /*for (size_t i = 0; i < 0; i++)
    {
        cout << "Name is " << homeZoo[i]->getName() << endl;;
        cout << "Age is " << homeZoo[i]->getAge() << endl;
        homeZoo[i]->show();
    }*/
    /*cout << homeZoo << endl;
    cout << *homeZoo << endl;
    cout << homeZoo[0] << endl;*/
    /*Zoo zoo(&zo);
    zoo.Show();*/
}


