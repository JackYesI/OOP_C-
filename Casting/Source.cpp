#include <iostream>
#include <conio.h>
using namespace std;

struct IDrivable
{
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void upSpeed() = 0;
    virtual void lowSpeed() = 0;
};

class Car : IDrivable
{
    string brand;
    const size_t maxSpeed;
    double speed;
public:
    Car(const string& brand, const size_t& maxSpeed) :
        brand{ brand }, maxSpeed{ maxSpeed }
    {
        this->speed = 0;
    }
    void Start() override
    {
        if (this->speed != 0) return;
        cout << "Start " << typeid(*this).name() << endl;
        this->speed = 1;
        cout << "Speed " << this->speed << endl;
    }
    void Stop() override
    {
        cout << "Stop " << typeid(*this).name() << endl;
        this->speed = 0;
        cout << "Speed " << this->speed << endl;
    }
    void upSpeed()
    {
        if (this->speed == 0) {
            cout << "depend Start()" << endl;
            return;
        }
        if (this->speed == 0)
        {
            this->Start();
        }
        else if (this->speed != this->maxSpeed)
        {
            ++this->speed;
            cout << "Speed " << this->speed << endl;
        }
        else
            cout << "NOW Max SPEED " << typeid(*this).name() << endl;
    }
    void lowSpeed()
    {
        if (this->speed != 0) {
            --this->speed;
            cout << "Speed " << this->speed << endl;
        }
        else
            this->Stop();
    }
};

class Hourse : IDrivable
{
    string kind;
    string name;
    double speed;
    const double maxSpeed = 65;
public:
    Hourse(const string& kind, const string& name) :
        kind{ kind }, name{ name }
    {
        this->speed = 0;
    }
    void Start() override
    {
        if (this->speed != 0) return;
        cout << "Start " << typeid(*this).name() << endl;
        this->speed = 1;
        cout << "Speed " << this->speed << endl;
    }
    void Stop() override
    {
        cout << "Stop " << typeid(*this).name() << endl;
        this->speed = 0;
        cout << "Speed " << this->speed << endl;
    }
    void upSpeed()
    {
        if (this->speed == 0) {
            cout << "depend Start()" << endl;
            return;
        }
        if (this->speed == 0)
        {
            this->Start();
        }
        else if (this->speed != this->maxSpeed)
        {
            ++this->speed;
            cout << "Speed " << this->speed << endl;
        }
        else
            cout << "NOW Max SPEED " << typeid(*this).name() << endl;
    }
    void lowSpeed()
    {
        if (this->speed != 0) {
            --this->speed;
            cout << "Speed " << this->speed << endl;
        }
        else
            this->Stop();
    }
};

class Driver
{
    string name;
    IDrivable* vehicle = nullptr;
public:
    Driver(const string& name, IDrivable* vehicle) :
        name{ name }, vehicle{ vehicle }
    {

    }
    void setVehicle(IDrivable* vehicle)
    {
        cout << "Change method of moving\t" << typeid(*this).name() << endl;
        this->vehicle = vehicle;
    }
    void testDrive()
    {
        cout << "up - Start;\t down - Stop;\t left - downSpeed;\t right - upSpeed;\t Esc - exit;" << endl;
        char s;
        do
        {
            s = _getch();
            if (vehicle == nullptr) return;
            if (s == 72)
            {
                vehicle->Start();
            }
            else if (s == 80)
            {
                vehicle->Stop();
            }
            else if (s == 75)
            {
                vehicle->lowSpeed();
            }
            else if (s == 77)
            {
                vehicle->upSpeed();
            }
        } while (s != 27);
    }
};

int main()
{
    Car car("ford", 220);
    Hourse hourse("white hourse", "Podro");
    Driver driver("denus", (IDrivable*)&car);
    driver.testDrive();
    driver.setVehicle((IDrivable*)&hourse);
    driver.testDrive();
}


