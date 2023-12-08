#include <iostream>
#include <vector>
#include "Square.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Rectangle.h"
using namespace std;

int main()
{
    Square square(5);
    square.Show();
    square.Save();
    /*Square square_load(1);
    square_load.Load();
    square_load.Show();*/

    Rectangle rectangle(5., 10.);
    rectangle.Show();
    rectangle.Save();
    /*rectangle.Load();
    rectangle.Show();*/

    Circle circle(43);
    circle.Show();
    circle.Save();
    /*circle.Load();
    circle.Show();*/

    Ellipse ellipse(5, 3);
    ellipse.Show();
    ellipse.Save();
   /* ellipse.Load();
    ellipse.Show();*/

    Shape* arr[] = {&ellipse, &circle, &rectangle, &square};
    for (auto &i: arr)
    {
        cout << "Show array" << endl;
        i->Show();
    }

    cout << "================================\n";
    cout << "Load and Show array" << endl;

    vector<Shape*> result{ new Ellipse, new Circle, new Rectangle, new Square};

    for (auto& i : result)
    {
        i->Load(); i->Show();
    }


}


