#include <iostream>
#include "FList.h"
using namespace std;

int main()
{
    /*int a;
    int* ptr = new int(5);
    cout << *ptr << endl;
    delete ptr;*/
    /*FList<int> list;
    list.addHead(23);
    list.addHead(13);
    list.print();
    list.addTail(43);
    list.print();
    list.removeHead();
    list.print();
    list.removeTail();
    list.print();
    list.removeTail();
    list.print(); list.removeTail();
    list.print();
    
    FList<int> list_2;
    list.addHead(1);
    list_2.addHead(2);
    list += list_2;
    list.print();
    list_2.print();
    list.addHead(23);
    list.addHead(13);
    list.addHead(3);
    list.addHead(1);

   
    list_2.addHead(8);
    list_2.addHead(-8);
    list_2.addHead(63);
    list_2.addHead(-1);
    list_2.addHead(0);
    list += list_2;
    list.print();
    list_2.print();*/

    /*FList<int> list;
    list.addHead(43);
    FList<int> list_;
    list_.addHead(34);
    list_.print();
    list.print();
    list_ = list;
    cout << list.copy() << endl;
    cout << list_.copy() << endl;
    list.print();
    list_.print();*/
    FList<int> list;
    FList<int> list_;
    list.addHead(1);
    list.addHead(2);
    list_.addHead(3);
    list_.addHead(2);

    cout << "Adress + :: " << list + list_ << endl;
    list.print(list + list_);

    cout << "Adress * :: " << list * list_ << endl;
    list.print(list * list_);
}


