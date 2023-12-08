#pragma once
#include <iostream>

using namespace std;
template<typename T>
struct Node
{
	int pr;
	T data;
	Node(const T& data = T(), const int& pr = 0) :
		data{ data }, pr{ pr }
	{

	}
};

template <typename T>
class PQueue
{
public:
	PQueue(const size_t& size, const size_t& step = 4) :
		capacity{ size }, step{ step }
	{
		queue = new Node<T>[capacity];
	}
	~PQueue()
	{
		delete[] queue;
	}
	void push(const Node<T>& data);
	void pop();
	size_t getSize() const;
	void Show() const;
	Node<T> Peek() const;
private:
	int back_ = -1;
	Node<T>* queue = nullptr;
	size_t capacity;
	size_t step;
	bool isEmpty() const;
	bool isFull() const;
	void resize();
	int getPos(const Node<T>& data) const;
};

template<typename T>
inline void PQueue<T>::push(const Node<T>& data)
{
	back_++;
	if (isFull())
	{
		resize();
	}
	int index = getPos(data);
	if (isEmpty() or index == -1)
	{
		queue[back_] = data;
		return;
	}
	for (int i = back_; i > index; i--)
	{
		queue[i] = queue[i - 1];
	}
	queue[index] = data;
}

template<typename T>
inline void PQueue<T>::pop()
{
	for (size_t i = 0; i < back_ - 1; i++)
	{
		queue[i] = queue[i + 1];
	}
	back_ -= 1;
}

template<typename T>
inline size_t PQueue<T>::getSize() const
{
	return back_ + 1;
}

template<typename T>
inline void PQueue<T>::Show() const
{
	for (size_t i = 0; i <= back_; i++)
	{
		cout << queue[i].data << "(" << queue[i].pr << ")" << "\t";
	}cout << endl;
}

template<typename T>
inline Node<T> PQueue<T>::Peek() const
{
	if (!isEmpty())
		return queue[0];
	return Node<T>();
}

template<typename T>
inline bool PQueue<T>::isEmpty() const
{
	return back_ == -1;
}

template<typename T>
inline bool PQueue<T>::isFull() const
{
	return capacity == back_;
}

template<typename T>
inline void PQueue<T>::resize()
{
	capacity += step;
	step *= 2;
	Node<T>* tmp = new Node<T>[capacity];
	for (size_t i = 0; i <= back_; i++)
	{
		tmp[i] = queue[i];
	}
	delete[] queue;
	queue = tmp;
}

template<typename T>
inline int PQueue<T>::getPos(const Node<T>& data) const
{
	for (size_t i = 0; i <= back_; i++)
	{
		if (data.pr > queue[i].pr) {
			return i;
		}
	}
	return -1;
}
