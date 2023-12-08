#include <iostream>
#include <conio.h>
#include <vector>

struct IDevice
{
    virtual void power() = 0;
	virtual void plus() = 0;
	virtual void minus() = 0;
	virtual void next() = 0;
	virtual void prev() = 0;
	virtual void print() const = 0;
};

class TV : public IDevice
{
	const size_t max_volume = 100;
	size_t volume;
	size_t chanel;
	const size_t max_chanel;
	bool start;
	bool isPower() const;
	bool isZeroVolume() const;
	bool isMaxVolume() const;
	bool isMaxChanel() const;
	bool isMinChanel() const;
	void print() const override;
public:
	TV(const size_t& max_chanel):
		max_chanel{max_chanel}
	{
		volume = 20;
		chanel = 1;
		start = 0;
	}
	void power() override
	{
		if (!isPower())
		{
			this->start = true;
			std::cout << "Start TV" << std::endl;
		}
		else
		{
			this->start = false;
			std::cout << "End TV" << std::endl;
		}
	}
	void plus() override
	{
		if (this->start)
		{
			if (isZeroVolume() or !isMaxVolume())
			{
				++this->volume;
			}
			else if (isMaxVolume())
			{
				std::cout << "Volume is full !!!\n";
			}
			return;
		}
		std::cout << "TV does't work" << std::endl;
	}
	void minus() override
	{
		if (this->start)
		{
			if (isMaxVolume() or !isZeroVolume())
			{
				--this->volume;
			}
			else if (isZeroVolume())
			{
				std::cout << "Volume is zero !!!\n";
			}
			return;
		}
		std::cout << "TV does't work" << std::endl;
	}
	void next() override
	{
		if (this->start)
		{
			if (!isMaxChanel())
			{
				++this->chanel;
			}
			else if (isMaxChanel())
			{
				this->chanel = 1;
			}
			return;
		}
		std::cout << "TV does't work" << std::endl;
	}
	void prev() override
	{
		if (this->start)
		{
			if (!isMinChanel())
			{
				--this->chanel;
			}
			else if (isMinChanel())
			{
				this->chanel = this->max_chanel;
			}
			return;
		}
		std::cout << "TV does't work" << std::endl;
	}
};

enum Mode { hit, cold, turbo, sleep };

class AirConditioner : public IDevice
{
	Mode mode;
	size_t temperature;
	size_t min_temperature;
	size_t max_temperature;
	bool start;
	bool isStart() const;
	bool isMaxTemperature() const;
	bool isMinTemperature() const;
	void print() const override;
	std::string enumString() const;
public:
	AirConditioner(const size_t& temperature, const size_t min_temperature, const size_t& max_temperature):
		temperature{ temperature }, min_temperature{min_temperature }, max_temperature {max_temperature }
	{
		mode = sleep;
		start = false;
	}
	void power() override
	{
		if (isStart())
		{
			this->start = false;
		}
		else if (!isStart())
		{
			this->start = true;
		}
	}
	void plus() override
	{
		if (isStart())
		{
			if (isMinTemperature() or !isMaxTemperature())
			{
				++this->temperature;
			}
			else if (isMaxTemperature())
			{
				std::cout << "temperature is full\n";
			}
			return;
		}
		std::cout << "Air - Conditioner does't work" << std::endl;
	}
	void minus() override
	{
		if (isStart())
		{
			if (isMaxTemperature() or !isMinTemperature())
			{
				--this->temperature;
			}
			else if (isMinTemperature())
			{
				std::cout << "temperature is minimum\n";
			}
			return;
		}
		std::cout << "Air - Conditioner does't work" << std::endl;
	}
	void next() override
	{
		if (isStart())
		{
			if (this->mode == sleep)
			{
				this->mode = static_cast<Mode>(0);
			}
			else if (this->mode == hit or !(this->mode == sleep))
			{
				int mod = static_cast<int>(this->mode);
				++mod;
				this->mode = static_cast<Mode>(mod);
			}
			return;
		}
		std::cout << "Air - Conditioner does't work" << std::endl;
	}
	void prev() override
	{
		if (isStart())
		{
			if (this->mode == hit)
			{
				this->mode = static_cast<Mode>(3);
			}
			else if (this->mode == sleep or !(this->mode == hit))
			{
				int mod = static_cast<int>(this->mode);
				--mod;
				this->mode = static_cast<Mode>(mod);
			}
			return;
		}
		std::cout << "Air - Conditioner does't work" << std::endl;
	}
};

class SmartRemove
{
	IDevice* ptr;
	std::vector<IDevice*> pulty;
public:
	SmartRemove(IDevice* ptr):
		ptr{ptr}
	{
		pulty.push_back(ptr);
	}
	void setDevise(IDevice* ptr)
	{
		this->ptr = ptr;
		std::cout << "method of pult :: " << typeid(*this->ptr).name() << std::endl;
		pulty.push_back(ptr);
	}
	void make()
	{
		std::cout << "up - power;\tdown - print;\t left - minus;\t right - plus;\t a - next;\td - prev;\t Esc - exit;" << std::endl;
		char s;
		do
		{
			s = _getch();
			if (&ptr == nullptr) return;
			if (s == 72)
			{
				ptr->power();
			}
			else if (s == 97)
			{
				ptr->prev();
			}
			else if (s == 80)
			{
				ptr->print();
			}
			else if (s == 100)
			{
				ptr->next();
			}
			else if (s == 75)
			{
				ptr->minus();
			}
			else if (s == 77)
			{
				ptr->plus();
			}
		} while (s != 27);
	}
};

int main()
{
	TV tv(5);
	AirConditioner air(17,16,27);

	SmartRemove pult(&tv);
	pult.make();
	std::cout << "========================\n";
	pult.setDevise(&air);
	pult.make();
}

bool TV::isPower() const
{
	return this->start != 0;
}

bool TV::isZeroVolume() const
{
	return this->volume == 0;
}

bool TV::isMaxVolume() const
{
	return this->volume == this->max_volume;
}

bool TV::isMaxChanel() const
{
	return this->chanel == this->max_chanel;
}

bool TV::isMinChanel() const
{
	return this->chanel == 1;
}

void TV::print() const
{
	std::cout << "Power  :: " << this->start << std::endl;
	std::cout << "Chanel :: " << this->chanel << std::endl;
	std::cout << "Volume :: " << this->volume << std::endl;
}

bool AirConditioner::isStart() const
{
	return this->start;
}

bool AirConditioner::isMaxTemperature() const
{
	return this->max_temperature == this->temperature;
}

bool AirConditioner::isMinTemperature() const
{
	return this->temperature == this->min_temperature;
}

void AirConditioner::print() const
{
	std::cout << "Power       :: " << this->start << std::endl;
	std::cout << "Temperature :: " << this->temperature << std::endl;
	std::cout << "Mode        :: " << this->enumString() << std::endl;
}

std::string AirConditioner::enumString() const
{
	if (this->mode == hit)
		return "hit";
	else if (this->mode == cold)
		return "cold";
	else if (this->mode == turbo)
		return "turbo";
	else if (this->mode == sleep)
		return "sleep";
	else
		exit(0);
}


