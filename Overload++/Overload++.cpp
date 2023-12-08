#include <iostream>
#include "classes_overload.h"
#include <string>
using namespace std;

int main()
{
    Circle circle_1(5);
    Circle circle_2(5);
    if (circle_1 == circle_2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << circle_1.lenght() << endl;
    circle_1 += 2;
    cout << circle_1.lenght() << endl;
    if (circle_1 > circle_2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    Airplan airplan("NARX04", 10, 200);
    Airplan airplan_2("NMNM0008", 15, 150);
    if (airplan == airplan_2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (size_t i = 0; i < 5; i++)
    {
        ++airplan;
        cout << to_string(airplan.getCount_human()) << "\t";
    }
    cout << endl;
    for (size_t i = 0; i < 5; i++)
    {
        --airplan_2;
        cout << to_string(airplan_2.getCount_human()) << "\t";
    }
    cout << endl;
    if (airplan > airplan_2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

}


