#include <iostream>
#include "Array_DL.h"

int main()
{
    Array_DL<int> arr(5);
    arr.print();
    std::cout << arr.getSize() << std::endl;

    arr.setSize(6, 2);
    arr.print();
    std::cout << arr.getSize() << std::endl;

    /*arr.FreeExtra();
    arr.print();
    std::cout << arr.getSize() << std::endl;*/
    /*arr.setAt(3, 43);
    cout << "This -> " << arr[3] << endl;;

    arr[3] = 15;
    cout << "This -> " << arr[10] << endl;;*/


    arr.print();
    std::cout << arr.getSize() << std::endl;

    for (size_t i = 0; i < 9; i++)
    {
        arr.Add(i);
    }
    arr.print();
    std::cout << arr.getSize() << std::endl;

    Array_DL<int> arr_1(3);
    for (size_t i = 0; i < 3; i++)
    {
        arr_1.Add((i + 1) * 2);
    }
    arr_1.print();
    std::cout << arr_1.getSize() << std::endl;

    arr.Append(arr_1);
    arr.print();
    std::cout << arr.getSize() << std::endl;

    // copy

    arr = arr_1;
    arr.print();
    std::cout << arr.getSize() << std::endl;
    arr_1.print();
    std::cout << arr_1.getSize() << std::endl;


    // getData
    /*Node<int>* ptr = arr.getData();
    for (size_t i = 0; i < 3; i++)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }*/

    // InsertAt 
    arr.InsertAt(0, 43);
    arr.print();
    std::cout << arr.getSize() << std::endl;

    // RemoveAt 

    arr.RemoveAt(3);
    arr.print();
    std::cout << arr.getSize() << std::endl;

    return 0;
}

