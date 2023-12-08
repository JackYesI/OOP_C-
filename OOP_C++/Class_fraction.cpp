#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction()
	{
		num = 1;
		dnum = 1;
	}
	Fraction(const int& num, const int& dnum)
	{
		this->num = num;
		this->dnum = dnum;
	}
	inline int getNum() const
	{
		return this->num;
	}
	inline int getDnum() const
	{
		return this->dnum;
	}
	inline void setNum(const int& num)
	{
		this->num = num;
	}
	inline void setDnum(const int& dnum)
	{
		this->dnum = dnum;
	}
	void cut()
	{
		for (int i = 9; i > 1; i--)
		{
			if (this->num % i == 0 and this->dnum % i == 0)
			{
				setNum(this->num / i);
				setDnum(this->dnum / i);
				i = 9;
			}
		}
	}
	void show() const
	{
		cout << getNum() << "/" << getDnum() << endl;
	}
	Fraction add(const Fraction& offer)
	{
		Fraction result(this->num, this->dnum);
		result.dnum = result.dnum * offer.dnum;
		result.num = result.num * offer.dnum + offer.num * this->dnum;
		result.cut();
		return result;
	}
	Fraction operator+ (const Fraction& offer)
	{
		Fraction result(this->num, this->dnum);
		result.dnum = result.dnum * offer.dnum;
		result.num = result.num * offer.dnum + offer.num * this->dnum;
		result.cut();
		return result;
	}
	Fraction sub(const Fraction& offer)
	{
		Fraction result(this->num, this->dnum);
		result.dnum = this->dnum * offer.dnum;
		result.num = result.num * offer.dnum - offer.num * this->dnum;
		result.cut();
		return result;
	}
	Fraction operator- (const Fraction& offer)
	{
		Fraction result(this->num, this->dnum);
		result.dnum = this->dnum * offer.dnum;
		result.num = result.num * offer.dnum - offer.num * this->dnum;
		result.cut();
		return result;
	}
	Fraction mult(const Fraction& offer)
	{
		Fraction result(this->num, this->dnum);
		result.num = result.num * offer.num;
		result.dnum = result.dnum * offer.dnum;
		result.cut();
		return result;
	}
	Fraction operator * (const Fraction& offer)
	{
		Fraction result(this->num, this->dnum);
		result.num = result.num * offer.num;
		result.dnum = result.dnum * offer.dnum;
		result.cut();
		return result;
	}
	Fraction div(const Fraction& offer)
	{
		Fraction result(this->num, this->dnum);
		result.num = result.num * offer.dnum;
		result.dnum = result.dnum * offer.num;
		result.cut();
		return result;
	}
	Fraction operator /(const Fraction& offer)
	{
		Fraction result(this->num, this->dnum);
		result.num = result.num * offer.dnum;
		result.dnum = result.dnum * offer.num;
		result.cut();
		return result;
	}

private:
	int num;
	int dnum;
};

int main()
{
	Fraction x(20, 4);
	Fraction y(3, 10);
	Fraction z;
	z = x.add(y);
	z.show();
	z = x.sub(y);
	z.show();
	z = x.mult(y);
	z.show();
	z = x.div(y);
	z.show();

	cout << "===========================" << endl;

	z = x + y;
	z.show();
	z = x - y;
	z.show();
	z = x * y;
	z.show();
	z = x / y;
	z.show();

	return 0;
}