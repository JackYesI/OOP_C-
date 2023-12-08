#include <iostream>
#include "My_Library.h"
#include "MyDate.h"

int main()
{
    Book test_book(6, 12, 2023, "Erin Ganter", "Warriors Cat1");
    Book test_book1(6, 12, 2023, "Erin Winter", "Warriors Cat2");
    Book test_book2(6, 10, 2023, "Alan Ganter", "Warriors Cat3");
    /*cout << test_book << endl;*/

    Library lib;
    lib.addBook(test_book);
    lib.addBook(test_book1);
    lib.addBook(test_book2);
    /*lib.print();

    
    lib.search("Warriors Cat", "Erin Ganter");
    cout << "for author ========" << endl;
    lib.searchBooks("Erin Ganter");

    cout << "===============" << endl;
    lib.print();
    lib.giveBook("Warriors Cat");
    lib.print();
    lib.giveBook("Warriors Cat");*/
    /*lib.sortByAutorNextByName();*/

    /*lib.print();
    lib.pop("Erin Winter", "Warriors Cat2", 6, 12, 2023);
    lib.print();*/
    /*lib.print();
    lib.popIndex(0);
    lib.print();*/
    lib.print();
    /*lib.editBook("Erin Winter", "Warriors Cat2");*/
    lib.writeFile();
}


