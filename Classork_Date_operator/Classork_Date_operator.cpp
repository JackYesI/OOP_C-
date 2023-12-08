#include <iostream>
#include <string>
using namespace std;

//Створіть клас Date, який буде містити інформацію про дату(день, місяць, рік).За допомогою механізму перевантаження операторів, визначте операцію різниці двох дат(результат у вигляді кількості днів між датами), а також операцію збільшення дати на певну кількість днів.

class Date
{
public:
	Date(): Date(1, 1, 2002)
	{
		
	}
	Date(size_t day, size_t mon, size_t year)
	{
		if (cheak(day, mon, year)) {
			this->day = day;
			this->mon = mon;
			this->year = year;
		}
		else {
			cout << "Eroor" << endl;
			this->day = 1;
			this->mon = 1;
			this->year = 2002;
		}
	}
	size_t operator-(Date date)
	{
		size_t days;
		if (this->year > date.year)
		{
			size_t day_deffer = countMon(date.mon, date.day, date.year);
			if (date.year % 4 == 0)
			{
				day_deffer = 366 - day_deffer;
			}
			else
			{
				day_deffer = 365 - day_deffer;
			}
			size_t day_sum = countMon(this->mon, this->day, this->year);
			if (this->year - date.year - 1 >= 1)
			{
				days = (this->year - date.year - 1) * 365 + countYear(this->year, date.year) + day_deffer + day_sum;
			}
			else
			{
				days = day_deffer + day_sum;
			}
		}
		else if (this->year > date.year)
		{
			size_t day_deffer = countMon(this->mon, this->day, this->year);
			if (this->year % 4 == 0)
			{
				day_deffer = 366 - day_deffer;
			}
			else
			{
				day_deffer = 365 - day_deffer;
			}
			size_t day_sum = countMon(date.mon, date.day, date.year);
			if (date.year - this->year - 1 >= 1)
			{
				days = (date.year - this->year - 1) * 365 + countYear(date.year, this->year) + day_deffer + day_sum;
			}
			else
			{
				days = day_deffer + day_sum;
			}
		}
		else
		{
			size_t day_1 = countMon(this->mon, this->day, this->year);
			size_t day_2 = countMon(date.mon, date.day, date.year);
			if (day_1 > day_2)
				days = day_1 - day_2;
			else if (day_1 < day_2)
				days = day_2 - day_1;
			else
				days = 0;
		}
		return days;
	}
	void operator+(size_t day)
	{
		if (cheak(this->day + day, this->mon, this->year))
			this->day = this->day + day;
		else
		{
			while (true)
			{
				bool flag = (this->year % 4 == 0) ? 1 : 0;
				if (this->mon == 1)
				{
					if ((31 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (31 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 2 and flag)
				{
					if ((29 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (29 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 2 and !flag)
				{
					if ((28 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (28 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 3)
				{
					if ((31 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (31 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 4)
				{
					if ((30 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (30 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 5)
				{
					if ((31 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (31 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 6)
				{
					if ((30 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (30 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 7)
				{
					if ((31 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (31 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 8)
				{
					if ((31 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (31 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 9)
				{
					if ((30 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (30 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 10)
				{
					if ((31 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (31 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 11)
				{
					if ((30 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (30 - this->day);
						this->mon = this->mon + 1;
						this->day = 0;
					}
				}
				else if (mon == 12)
				{
					if ((31 - this->day) >= day)
					{
						this->day = this->day + day;
						break;
					}
					else
					{
						day = day - (31 - this->day);
						this->year = this->year + 1;
						this->mon = 1;
						this->day = 0;
					}
				}
			}
		}
	}
	void Show()
	{
		cout << to_string(this->day) + "." + to_string(this->mon) + "." + to_string(this->year) << endl;
	}
private:
	size_t day;
	size_t mon;
	size_t year;
	bool cheak(const size_t& day, const size_t& mon, const size_t& year)
	{
		if (mon == 1 and (day >= 1 and day <= 31))
		{
			return true;
		}
		else if ((mon == 2 and (year % 4 == 0) and (day >= 1 and day <= 29)) or (mon == 2 and !(year % 4 == 0) and (day >= 1 and day <= 28)))
		{
			return true;
		}
		else if (mon == 3 and (day >= 1 and day <= 31))
		{
			return true;
		}
		else if (mon == 4 and (day >= 1 and day <= 30))
		{
			return true;
		}
		else if (mon == 5 and (day >= 1 and day <= 31))
		{
			return true;
		}
		else if (mon == 6 and (day >= 1 and day <= 30))
		{
			return true;
		}
		else if (mon == 7 and (day >= 1 and day <= 31))
		{
			return true;
		}
		else if (mon == 8 and (day >= 1 and day <= 31))
		{
			return true;
		}
		else if (mon == 9 and (day >= 1 and day <= 30))
		{
			return true;
		}
		else if (mon == 10 and (day >= 1 and day <= 31))
		{
			return true;
		}
		else if (mon == 11 and (day >= 1 and day <= 30))
		{
			return true;
		}
		else if (mon == 12 and (day >= 1 and day <= 31))
		{
			return true;
		}
		else return false;
	}
	size_t countYear(size_t year_1, size_t year_2)
	{
		size_t count = 0;
		for (size_t i = year_2 + 1; i < year_1; i++)
		{
			if (i % 4 == 0) count++;
		}
		return count;
	}
	size_t countMon(size_t mon, size_t day, size_t year)
	{
		size_t days = 0;
		bool flag = 1;
		if (!(year % 4 == 0)) flag = 0;
		if (mon == 1)
		{
			days = day;
		}
		else if (mon == 2 and flag)
		{
			days = 31 + day;
		}
		else if (mon == 2 and !flag)
		{
			days = 31 + day;
		}
		else if (mon == 3 and flag)
		{
			days = 31 + 29 + day;
		}
		else if (mon == 4 and flag)
		{
			days = 31 + 29 + 31 + day;
		}
		else if (mon == 5 and flag)
		{
			days = 31 + 29 + 31 + 30 + day;
		}
		else if (mon == 6 and flag)
		{
			days = 31 + 29 + 31 + 30 + 31 + day;
		}
		else if (mon == 7 and flag)
		{
			days = 31 + 29 + 31 + 30 + 31 + 30 + day;
		}
		else if (mon == 8 and flag)
		{
			days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + day;
		}
		else if (mon == 9 and flag)
		{
			days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + day;
		}
		else if (mon == 10 and flag)
		{
			days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
		}
		else if (mon == 11 and flag)
		{
			days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
		}
		else if (mon == 12 and flag)
		{
			days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
		}
		else if (mon == 3 and !flag)
		{
			days = 31 + 28 + day;
		}
		else if (mon == 4 and !flag)
		{
			days = 31 + 28 + 31 + day;
		}
		else if (mon == 5 and !flag)
		{
			days = 31 + 28 + 31 + 30 + day;
		}
		else if (mon == 6 and !flag)
		{
			days = 31 + 28 + 31 + 30 + 31 + day;
		}
		else if (mon == 7 and !flag)
		{
			days = 31 + 28 + 31 + 30 + 31 + 30 + day;
		}
		else if (mon == 8 and !flag)
		{
			days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
		}
		else if (mon == 9 and !flag)
		{
			days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
		}
		else if (mon == 10 and !flag)
		{
			days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
		}
		else if (mon == 11 and !flag)
		{
			days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
		}
		else if (mon == 12 and !flag)
		{
			days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
		}
		return days;
	}
};

int main()
{
	Date date(5, 12, 2002);
	Date date_2(3, 12, 2002);
	size_t days = date_2 - date;
	cout << days << endl;
	date + (27);
	date.Show();
}


