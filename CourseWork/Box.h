#pragma once

enum Name_Box {
	Box_2 = 2, Box_5 = 5, Box_10 = 10, Box_15 = 15, Box_20 = 20, Box_30 = 30, None = 0
};


class Box
{
	Name_Box name;
	size_t length;
	size_t height;
	size_t width;
	size_t weight;
	void setLength()
	{
		if (this->name == Box_2) this->length = 20;
		if (this->name == Box_5) this->length = 30;
		if (this->name == Box_10) this->length = 40;
		if (this->name == Box_15) this->length = 50;
		if (this->name == Box_20) this->length = 60;
		if (this->name == Box_30) this->length = 60;
		if (this->name == None) this->length = size_t();
	}
	void setHeight()
	{
		if (this->name == Box_2) this->height = 20;
		if (this->name == Box_5) this->height = 30;
		if (this->name == Box_10) this->height = 40;
		if (this->name == Box_15) this->height = 50;
		if (this->name == Box_20) this->height = 60;
		if (this->name == Box_30) this->height = 60;
		if (this->name == None) this->height = size_t();
	}
	void setWidth()
	{
		if (this->name == Box_2) this->width = 20;
		if (this->name == Box_5) this->width = 30;
		if (this->name == Box_10) this->width = 40;
		if (this->name == Box_15) this->width = 50;
		if (this->name == Box_20) this->width = 60;
		if (this->name == Box_30) this->width = 60;
		if (this->name == None) this->width = size_t();
	}
	void setWeight()
	{
		this->weight = (size_t)this->name;
	}
public:
	Box(const Name_Box& name = None) :
		name{ name }
	{
		if (this->name != None)
		{
			setLength();
			setHeight();
			setWidth();
			setWeight();
		}
	}
	void setName(const Name_Box& name)
	{
		this->name = name;
		if (this->name != None)
		{
			setLength();
			setHeight();
			setWidth();
			setWeight();
		}
	}
	size_t getName() const
	{
		return this->name;
	}
	size_t getLength() const
	{
		return this->length;
	}
	size_t getHeight() const
	{
		return this->height;
	}
	size_t getWigth() const
	{
		return this->width;
	}
	size_t getWeight() const
	{
		return this->weight;
	}
};

