#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	size_t replace;
	Node<T>* next;
	Node<T>* previous;
	Node(const T& data = T(), Node<T>* next = nullptr, Node<T>* previous = nullptr, const size_t& replace = 0)
		: data{ data }, next{ next }, previous{ previous }, replace{ replace }
	{
	}
};

template <typename T >
class DLists
{
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
	bool isEmpty();
	bool find(const T& data) const;
	void popRepeat();
	void replace(Node<T>* first, Node<T>* last);
public:
	DLists() = default;
	~DLists()
	{
		clear();
	}
	size_t getSize() const;
	void addFirst(const T& data);
	void addLast(const T& data);
	void popFirst();
	void popLast();
	void clear();
	void pop(const T& data);
	void printRight();
	void printLeft();
	void addBefore(const T& data, const T& newData);
	void addAfter(const T& data, const T& newData);
	size_t Find(const T& data, const T& newData);
	DLists<T> operator + (const DLists<T>& list) const;
	void operator += (const DLists<T>& list);
	DLists<T> operator * (const DLists<T>& list) const;
	void rotation();
};

template<typename T>
inline bool DLists<T>::isEmpty()
{
	return head == nullptr;
}

template<typename T>
inline bool DLists<T>::find(const T& data) const
{
	auto tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->data == data) return true;
		tmp = tmp->next;
	}
	return false;
}

template<typename T>
inline void DLists<T>::popRepeat()
{
	if (!isEmpty())
	{
		auto tmp = head;
		while (tmp != nullptr)
		{
			auto tmp_2 = tmp->next;
			while (tmp_2 != nullptr)
			{
				if (tmp->data == tmp_2->data)
				{
					this->pop(tmp->data);
					break;
				}
				tmp_2 = tmp_2->next;
			}
			tmp = tmp->next;
		}
	}
}

template<typename T>
inline void DLists<T>::replace(Node<T>* first, Node<T>* last)
{
	++first->replace;
	++last->replace;
	auto last_ = last->next;
	auto last__ = last->previous;
	auto first_ = first->previous;
	auto first__ = first->next;
	last->next = first->next;
	first->next->previous = last;
	first->next = last_;
	last_->previous = first;
	first->previous = last__;
	last->previous->next = first;
	last->previous = first_;
	first_->next = last;
}

template<typename T>
inline size_t DLists<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline void DLists<T>::addFirst(const T& data)
{
	auto tmp = new Node<T>(data, head);
	if (isEmpty())
	{
		tail = tmp;
		head = tmp;
		++size;
	}
	else
	{
		head->previous = tmp;
		head = tmp;
		++size;
	}
	

}

template<typename T>
inline void DLists<T>::addLast(const T& data)
{
	auto tmp = new Node<T>(data, nullptr, tail);
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
inline void DLists<T>::popFirst()
{
	if (!isEmpty() and head != tail)
	{
		head = head->next;
		delete head->previous;
		head->previous = nullptr;
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
inline void DLists<T>::popLast()
{
	if (!isEmpty() and head != tail)
	{
		tail = tail->previous;
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
inline void DLists<T>::clear()
{
	while (!isEmpty())
	{
		popFirst();
	}
}

template<typename T>
inline void DLists<T>::pop(const T& data)
{
	if (!isEmpty())
	{
		auto tmp = head;
		while (tmp != nullptr)
		{
			if (tmp->data == data)
			{
				if (tmp == head) {
					popFirst();
					break;
				}
				else if (tmp == tail) {
					popLast();
					break;
				}
				else
				{
					tmp->previous->next = tmp->next;
					tmp->next->previous = tmp->previous;
					delete tmp;
					--size;
					break;
				}
			}
			tmp = tmp->next;
		}
	}
}

template<typename T>
inline void DLists<T>::printRight()
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
inline void DLists<T>::printLeft()
{
	if (!isEmpty())
	{
		auto tmp = tail;
		while (tmp != nullptr)
		{
			cout << tmp->data << "\t";
			tmp = tmp->previous;
		}
		cout << endl;
	}
}

template<typename T>
inline void DLists<T>::addBefore(const T& data, const T& newData)
{
	if (isEmpty()) {
		addFirst(newData);
		return;
	}
	auto tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->data == data)
		{
			if (tmp == head) {
				addFirst(newData);
				break;
			}
			else
			{
				auto newtmp = new Node<T>(newData, tmp, tmp->previous);
				tmp->previous->next = newtmp;
				tmp->previous = newtmp;
				++size;
				break;
			}
		}
		tmp = tmp->next;
	}
}

template<typename T>
inline void DLists<T>::addAfter(const T& data, const T& newData)
{
	if (isEmpty()) {
		addFirst(newData);
		return;
	}
	auto tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->data == data)
		{
			if (tmp == tail) {
				addLast(newData);
				break;
			}
			else
			{
				auto newtmp = new Node<T>(newData, tmp->next, tmp);
				tmp->next->previous = newtmp;
				tmp->next = newtmp;
				++size;
				break;
			}
		}
		tmp = tmp->next;
	}
}

template<typename T>
inline size_t DLists<T>::Find(const T& data, const T& newData)
{
	auto tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->data == data)
		{
			tmp->data = newData;
			return ++tmp->replace;
		}
		tmp = tmp->next;
	}
	return size_t();
}

template<typename T>
inline DLists<T> DLists<T>::operator+(const DLists<T>& list) const
{
	DLists<T> result;
	auto tmp = this->head;
	while (tmp != nullptr)
	{
		result.addLast(tmp->data);
		tmp = tmp->next;
	}
	tmp = list.head;
	while (tmp != nullptr)
	{
		result.addLast(tmp->data);
		tmp = tmp->next;
	}
	return result;
}

template<typename T>
inline void DLists<T>::operator+=(const DLists<T>& list)
{
	auto tmp = list.head;
	while (tmp != nullptr)
	{
		this->addLast(tmp->data);
		tmp = tmp->next;
	}
}

template<typename T>
inline DLists<T> DLists<T>::operator*(const DLists<T>& list) const
{
	DLists<T> result;
	auto tmp = this->head;
	while (tmp != nullptr)
	{
		auto tmp_2 = list.head;
		while (tmp_2 != nullptr)
		{
			if (tmp->data == tmp_2->data)
			{
				result.addLast(tmp->data);
				break;
			}
			tmp_2 = tmp_2->next;
		}
		tmp = tmp->next;
	}
	result.popRepeat();
	return result;
}

template<typename T>
inline void DLists<T>::rotation()
{
	if (size <= 1) return;
	if (size == 2)
	{
		auto first = head;
		auto last = tail;
		++first->replace;
		++last->replace;
		first->next = nullptr;
		first->previous = last;
		last->previous = nullptr;
		last->next = first;
		head = last;
		tail = first;
		return;
	}
	if (size == 3)
	{
		auto first = head;
		auto last = tail;
		++first->replace;
		++last->replace;
		auto first_ = first->next;
		first->next = nullptr;
		first->previous = first_;
		last->previous = nullptr;
		last->next = first_;
		first_->next = first;
		first_->previous = last;
		head = last;
		tail = first;
		return;
	}
	// head remove tail
	size_t count = (this->size / size_t(2)) - 1 - 1;
	auto first = head;
	auto last = tail;
	++first->replace;
	++last->replace;
	last->next = first->next;
	first->next->previous = last;
	first->next = nullptr;
	first->previous = last->previous;
	last->previous->next = first;
	last->previous = nullptr;

	head = last;
	tail = first;
	

	// center element remove
	for (size_t i = 0; i < count; i++)
	{
		first = head;
		last = tail;
		for (size_t j = 0; j < i + 1; j++)
		{
			first = first->next;
			last = last->previous;
		}
		this->replace(first, last);
	}



	// near element
	size_t count_2 = (this->size / size_t(2));
	if (size >= 6 and (this->size % size_t(2) == 0))
	{
		first = head;
		last = tail;
		++first->replace;
		++last->replace;
		for (size_t j = 0; j < count_2 - 1; j++)
		{
			first = first->next;
			last = last->previous;
		}
		auto last_ = last->next;
		auto first_ = first->previous;

		last->next = first;
		first->next->previous = last->previous->previous;
		first->next = last_;
		first->previous = last;
		first_->next = last;
		last_->previous = first;
	}
	else 
	{
		++first->replace;
		++last->replace;
		first = head;
		last = tail;
		for (size_t j = 0; j < count_2 - 1; j++)
		{
			first = first->next;
			last = last->previous;
		}
		auto last_ = last->next;
		auto first_ = first->previous;
		auto first__ = first->next;

		last->next = first->next;
		first->next->previous = last;
		first->next = last_;
		first->previous = first__;
		first_->next = last;
		last_->previous = first;
		last->previous = first_;
		first__->next = first;

	}
}
