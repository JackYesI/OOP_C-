#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node(const T& data = T(), Node<T>* next = nullptr, Node<T>* prev = nullptr)
		: data{data}, next{next}, prev{prev}
	{

	}
};

template <typename T>
class Array_DL
{
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
	size_t full_size = 0;
	size_t grow = 1;
	bool isEmpty();
	void popFirst();
	void popLast();
	void addLast();
	void clear();
public:
	Array_DL(const size_t& size_ = 1)
	{
		for (size_t i = 0; i < size_; i++)
		{
			if (isEmpty())
			{
				Node<T>* elem = new Node<T>(0);
				head = elem;
				tail = elem;
				++size;
			}
			else
			{
				Node<T>* elem = new Node<T>(0, nullptr, tail);
				tail->next = elem;
				tail = elem;
				++size;
			}
		}
	}
	~Array_DL()
	{
		clear();
	}
	size_t getSize();
	void setSize(int size, int grow = 1);
	void print();
	void RemoveAt(const size_t& index);
	size_t GetUpperBound() const;
	void FreeExtra();
	void removeAll();
	T getAt(const size_t& index) const;
	void setAt(const size_t& index, const T& data);
	T& operator [] (const size_t& index);
	void Add(const T& data);
	void Append(const Array_DL<T>& arr);
	void operator = (const Array_DL<T>& arr);
	Node<T>* getData() const;
	void InsertAt(const size_t& index, const T& data);
};

template<typename T>
inline bool Array_DL<T>::isEmpty()
{
	return head == nullptr;
}

template<typename T>
inline void Array_DL<T>::popFirst()
{
	if (!isEmpty() and head != tail)
	{
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
		--size;
	}
	else if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		--size;
	}
}

template<typename T>
inline void Array_DL<T>::popLast()
{
	if (!isEmpty() and head != tail)
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
		--size;
	}
	else if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		--size;
	}
}

template<typename T>
inline void Array_DL<T>::addLast()
{
	auto tmp = new Node<T>(0, nullptr, tail);
	if (isEmpty())
	{
		tail = tmp;
		head = tmp;
		++size;
	}
	else
	{
		tail->next = tmp;
		tail = tmp;
		++size;
	}
}

template<typename T>
inline void Array_DL<T>::clear()
{
	while (!isEmpty())
	{
		popFirst();
	}
}

template<typename T>
inline size_t Array_DL<T>::getSize()
{
	return this->size;
}

template<typename T>
inline void Array_DL<T>::setSize(int size, int grow)
{
	if (this->size < size)
	{
		while (this->size != size)
		{
			addLast();
		}
	}
	else if (this->size > size)
	{
		while (this->size != size)
		{
			popLast();
		}
	}
	this->grow = grow;
}

template<typename T>
inline void Array_DL<T>::print()
{
	if (!isEmpty())
	{
		auto tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp->data << "\t";
			tmp = tmp->next;
		}
		cout << endl;
	}
}

template<typename T>
inline void Array_DL<T>::RemoveAt(const size_t& index)
{
	if (isEmpty()) {
		return;
	}
	auto tmp = head;
	for (size_t i = 0; i < this->full_size; i++)
	{
		if (index == i)
		{
			for (size_t j = index; j < this->full_size - 1; j++)
			{
				tmp->data = tmp->next->data;
				tmp = tmp->next;
			}
			--this->full_size;
			this->FreeExtra();
			return;
		}
		tmp = tmp->next;
	}
}

template<typename T>
inline size_t Array_DL<T>::GetUpperBound() const
{
	return this->full_size - 1;
}

template<typename T>
inline void Array_DL<T>::FreeExtra()
{
	while (this->size != this->full_size)
	{
		popLast();
	}
}

template<typename T>
inline void Array_DL<T>::removeAll()
{
	auto tmp = head;
	while (this->full_size != 0)
	{
		tmp->data = 0;
		--this->full_size;
		tmp = tmp->next;
	}
}

template<typename T>
inline T Array_DL<T>::getAt(const size_t& index) const
{
	if (index >= 0 and index <= size)
	{
		auto tmp = head;
		for (size_t i = 0; i < this->size; i++)
		{
			if (index == i)
			{
				return tmp->data;
			}
			tmp = tmp->next;
		}
	}
}

template<typename T>
inline void Array_DL<T>::setAt(const size_t& index, const T& data)
{
	if (index >= 0 and index <= size)
	{
		auto tmp = head;
		for (size_t i = 0; i < this->size; i++)
		{
			if (index == i)
			{
				tmp->data = data;
				return;
			}
			tmp = tmp->next;
		}
	}
	cout << "Index error" << endl;
}

template<typename T>
inline T& Array_DL<T>::operator[](const size_t& index)
{
	if (index >= 0 and index <= size)
	{
		auto tmp = head;
		for (size_t i = 0; i < this->size; i++)
		{
			if (index == i)
			{
				return tmp->data;
			}
			tmp = tmp->next;
		}
	}
	cout << "Index error" << endl;
	exit(0);
}

template<typename T>
inline void Array_DL<T>::Add(const T& data)
{
	if (this->full_size == this->size)
	{
		this->setSize(this->size + this->grow, this->grow);
	}
	auto tmp = head;
	for (size_t i = 0; i < this->full_size; i++)
	{
		tmp = tmp->next;
	}
	tmp->data = data;
	++this->full_size;
}

template<typename T>
inline void Array_DL<T>::Append(const Array_DL<T>& arr)
{
	auto tmp = arr.head;
	for (size_t i = 0; i < arr.full_size; i++)
	{
		this->Add(tmp->data);
		tmp = tmp->next;
	}
}

template<typename T>
inline void Array_DL<T>::operator=(const Array_DL<T>& arr)
{
	this->clear();
	this->full_size = 0;
	this->setSize(arr.size, arr.grow);
	auto tmp = arr.head;
	for (size_t i = 0; i < arr.full_size; i++)
	{
		this->Add(tmp->data);
		tmp = tmp->next;
	}
}

template<typename T>
inline Node<T>* Array_DL<T>::getData() const
{
	return this->head;
}

template<typename T>
inline void Array_DL<T>::InsertAt(const size_t& index, const T& data)
{
	if (isEmpty()) {
		this->Add(data);
		return;
	}
	auto tmp = head;
	for (size_t i = 0; i < this->full_size; i++)
	{
		if (index == i)
		{
			auto tmp_2 = this->tail;
			this->Add(tmp_2->data);
			for (size_t j = this->full_size - 1 - 1; j >= index + 1; j--)
			{
				tmp_2->data = tmp_2->prev->data;
				tmp_2 = tmp_2->prev;
			}
			tmp->data = data;
			return;
		}
		tmp = tmp->next;
	}
}
