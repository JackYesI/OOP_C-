#include <iostream>
#include "DLists.h"
using namespace std;

int main()
{
	DLists<int> list;
	// add and pop
	list.addFirst(3);
	list.addFirst(2);
	list.addFirst(1);
	list.addLast(43);
	list.printRight();
	list.printLeft();
	list.popFirst();
	list.printRight();
	list.popFirst();
	list.printRight();
	list.popFirst();
	list.printRight();
	list.popFirst();
	list.printRight();
	list.popFirst();
	list.printRight();

	// popLast()
	list.addFirst(3);
	list.addFirst(2);
	list.addFirst(1);
	list.addLast(43);
	list.popLast();
	list.printRight();
	list.popLast();
	list.printRight();
	list.popLast();
	list.printRight();
	list.popLast();
	list.printRight();
	list.popLast();
	list.printRight();

	// clear()
	list.addFirst(3);
	list.addFirst(2);
	list.addFirst(1);
	list.addLast(43);
	list.printRight();
	list.clear();
	list.printRight();

	// pop(data)
	list.addFirst(3);
	list.addFirst(2);
	list.addFirst(1);
	list.addLast(43);
	list.pop(3);
	list.printRight();
	list.pop(2);
	list.printRight();

	// addBefore() and addAfter()
	list.addFirst(3);
	list.addFirst(2);
	list.printRight();
	list.addBefore(43, 100);
	list.printRight();
	list.addAfter(1, -1);
	list.printRight();

	// Find()
	cout << "count of replace :: " << list.Find(43, 24) << endl;
	list.printRight();
	cout << "count of replace :: " << list.Find(24, 43) << endl;
	list.printRight();

	// + and +=
	DLists<int> list_1;
	list_1.addFirst(1);
	list_1.addFirst(2);
	list_1.addFirst(3);

	DLists<int> list_2;
	list_2.addFirst(4);
	list_2.addFirst(5);
	list_2.addFirst(6);

	DLists<int> list_3 = list_1 + list_2;
	cout << " + " << endl;
	list_3.printRight();

	cout << " += " << endl;
	list_1 += list_2;
	list_1.printRight();
	list_2.printRight();
	
	// *
	DLists<int> list_4;
	list_4.addFirst(1);
	list_4.addFirst(2);
	list_4.addFirst(3);

	DLists<int> list_5;
	list_5.addFirst(4);
	list_5.addFirst(2);
	list_5.addFirst(6);
	list_5.addFirst(2);

	DLists<int> list_6 = list_4 * list_5;
	cout << " * " << endl;
	list_4.printRight();
	list_5.printRight();
	list_6.printRight();

	// rotation()
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();
	list_1.clear();

	list_1.addFirst(1);
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();

	list_1.addFirst(2);
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();

	list_1.addFirst(3);
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();

	list_1.addFirst(4);
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();

	list_1.addFirst(5);
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();

	list_1.addFirst(6);
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();

	list_1.addFirst(7);
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();

	list_1.addFirst(8);
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();

	list_1.addFirst(9);
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();

	list_1.addFirst(10);
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();

	list_1.addFirst(11);
	list_1.printRight();
	list_1.rotation();
	list_1.printRight();
	






	cout << "count of replace :: " << list_1.Find(11, 24) << endl;
	list_1.printRight();
	/*int a = 5, b = 3;
	int* ptr = &a, *ptr2 = ptr;
	ptr = &b;
	cout << ptr << endl;
	cout << ptr2 << endl;*/
	
}


