#pragma once
#include <iostream>
using namespace std;


template <typename T>
struct Node
{
	T data;
	Node* next;
	Node(const T& data = T(), Node* next = nullptr)
		:data{ data }, next{ next }
	{

	}
};

template <typename T>
class FList
{
public:
	FList() = default;
	void addHead(const T& data);
	void removeHead();
	void print() const;
	bool isEmpty() const;
	size_t getSize() const;
	Node<T>* copy() const; // dz
	void clear(); // clear all list
	~FList()
	{
		clear();
	}
	void addTail(const T& data);
	void removeTail();
	// += overload (merge two list)
	void operator += (FList<T>& list);
	void operator = (FList<T>& list); // dz
	Node<T>* operator + (FList<T>& list); // dz
	Node<T>* operator * (FList<T>& list); // dz
	void print(Node<T>* head_) const; // dz

private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
};

template<typename T>
inline void FList<T>::addHead(const T& data)
{
	auto tmp = new Node<T>(data, head);
	if (isEmpty()) {
		tail = tmp;
	}
	head = tmp;
	++size;
}

template<typename T>
inline void FList<T>::removeHead()
{
	if (isEmpty()) {
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = head;
	head = head->next;
	delete tmp;
	--size;
}

template<typename T>
inline void FList<T>::print() const
{
	auto tmp = head;
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}cout << endl;
}

template<typename T>
inline bool FList<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline size_t FList<T>::getSize() const
{
	return size;
}

template<typename T>
inline Node<T>* FList<T>::copy() const
{
	return this->head;
}

template<typename T>
inline void FList<T>::clear()
{
	while (!isEmpty())
	{
		removeHead();
	}
}

template<typename T>
inline void FList<T>::addTail(const T& data)
{
	auto tmp = new Node<T>(data);
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
inline void FList<T>::removeTail()
{
	if (isEmpty()) {
		cout << "List is empty" << endl;
		return;
	}
	if (head == tail)
	{
		removeHead();
		return;
	}
	auto tmp = head;
	while (true)
	{
		if (tmp->next == tail)
		{
			tail = tmp;
			tmp = tmp->next;
			delete tmp;
			--size;
			tail->next = nullptr;
			break;
		}
		tmp = tmp->next;
	}
}

template<typename T>
inline void FList<T>::operator+=(FList<T>& list)
{
	auto tmp = list.head;
	while (tmp != nullptr)
	{
		this->addTail(tmp->data);
		tmp = tmp->next;
		++size;
	}
}

template<typename T>
inline void FList<T>::operator=(FList<T>& list)
{
	clear();
	auto tmp = list.head;
	while (tmp != nullptr)
	{
		this->addHead(tmp->data);
		tmp = tmp->next;
	}
}

template<typename T>
inline Node<T>* FList<T>::operator+(FList<T>& list)
{
	FList<T>* newList = new FList<T>();
	auto tmp = this->head;
	while (tmp != nullptr)
	{
		newList->addTail(tmp->data);
		tmp = tmp->next;
	}
	auto tmp_2 = list.head;
	while (tmp_2 != nullptr)
	{
		newList->addTail(tmp_2->data);
		tmp_2 = tmp_2->next;
	}
	return newList->head;
}

template<typename T>
inline Node<T>* FList<T>::operator*(FList<T>& list)
{
	FList<T>* newList = new FList<T>();
	auto tmp = this->head;
	while (tmp != nullptr)
	{
		auto tmp_2 = list.head;
		while (tmp_2 != nullptr)
		{
			if (tmp->data == tmp_2->data) {
				newList->addTail(tmp_2->data);
				break;
			}
			tmp_2 = tmp_2->next;
		}
		tmp = tmp->next;
	}
	return newList->head;
}

template<typename T>
inline void FList<T>::print(Node<T>* head_) const
{
	auto tmp = head_;
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}cout << endl;
}




