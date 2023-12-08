#include "MyDate.h"

bool Date::operator==(Date date)
{
    if (this->day == date.day and this->mon == date.mon and this->year == date.year)
        return 1;
    else
        return 0;
}

void Date::operator=(Date date)
{
    this->day = date.day;
    this->mon = date.mon;
    this->year = date.year;
}

size_t Date::getYear() const
{
    return this->year;
}




