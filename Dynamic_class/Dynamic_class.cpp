#include <iostream>
#include "Array.h"
#include "Mystring.h"
using namespace std;

int main()
{
    /*Array arr(5);
    arr.Fill();
    arr.Show();
    arr.Fillin();
    arr.sort(0, arr.getSize() - 1);
    arr.Show();
    arr.changeSize(10);
    arr.Show();
    cout << arr.min() << endl;
    cout << arr.max() << endl;
    Array arr_2(7);
    arr_2.Fill();
    Array arr_3(arr_2);
    arr_2.Show();
    arr_2.Fillin();
    arr_2.Show();
    arr_3.Show();*/

    // string
    /*Mystring str_1;
    Mystring str_2("I am Happy");
    Mystring str_3(str_2);
    str_1 = "Hello Word";
    str_1.print();
    str_2.print();
    str_3.print();
    str_3 = str_1;
    str_3.print();
    str_2.print();*/
    Mystring str;
    str.ConsoleFill();
    str.print();
    cout << str.getCounter() << endl;

}
