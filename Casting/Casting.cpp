//#include <iostream>
//using namespace std;
//
//
//class Point
//{
//protected:
//    int x;
//    int y;
//public:
//    Point(const int& x, const int &y):
//        x{x}, y{y}
//    {
//
//    }
//    void Show() const
//    {
//        cout << "(" << this->x << ";" << this->y << ")" << endl;
//    }
//};
//
//class Point3d : public Point
//{
//private:
//    int z;
//public:
//    Point3d(const int& x, const int& y, const int& z):
//        Point(x,y), z{z}
//    {
//
//    }
//    void Show() const
//    {
//        cout << "(" << this->x << ";" << this->y << ";" << this->z << ")" << endl;
//    }
//};
//
//
//
//
//int main()
//{
//    Point3d point3d(1, 2, 3);
//    point3d.Show();
//
//    Point& res = point3d;
//    res.Show();
//
//    Point3d& res_ = static_cast<Point3d&>(res);
//    res_.Show();
//}
//
//
