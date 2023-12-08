#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* parrent, * left, * right;
	Node(const T& data = T(), Node* parrent = nullptr, Node* left = nullptr, Node* right = nullptr)
		:data{ data }, parrent{ parrent }, left{ left }, right{ right }
	{

	}
};

template <typename T>
class Binary
{
public:
	Binary() = default;
	~Binary()
	{
		clear();
	}
	void add(const T& data);
	size_t getSize() const;
	void print() const;
	bool isEmpty() const;
	void clear();
	void clearRecursia();
	T min() const;
	T max() const;
	void popMin();
	void popMax();
	void helperPrintFind(Node<T>* node, const T& data, const T& data_2) const;
	void popNode(Node<T>* node);
	Node<T>* getNode(const T& data) const;
	void findDataDiapazon(const T& data, const T& data_2) const;
private:
	Node<T>* root = nullptr;
	void helperPrint(Node<T>* node) const;
	void helperClear(Node<T>* node);
	size_t size = 0;
};

template<typename T>
inline void Binary<T>::add(const T& data)
{
	auto new_node = new Node<T>(data);
	if (isEmpty()) {
		root = new_node;
		++size;
		return;
	}
	Node<T>* tmp = root;
	while (true)
	{
		if (data < tmp->data) {
			if (tmp->left == nullptr) {
				new_node->parrent = tmp;
				tmp->left = new_node;
				++size;
				break;
			}
			tmp = tmp->left;
		}
		else {
			if (tmp->right == nullptr) {
				new_node->parrent = tmp;
				tmp->right = new_node;
				++size;
				break;
			}
			tmp = tmp->right;
		}
	}
}

template<typename T>
inline size_t Binary<T>::getSize() const
{
	return size;
}

template<typename T>
inline void Binary<T>::print() const
{
	cout << "Print :: ";
	helperPrint(root);
	cout << endl;
}

template<typename T>
inline bool Binary<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
inline void Binary<T>::clear()
{
	if (!isEmpty())
	{
		auto tmp = root;
		while (true)
		{
			if (tmp->left != nullptr)
			{
				tmp = tmp->left;
				if (tmp->left == nullptr and tmp->right == nullptr)
				{
					tmp = tmp->parrent;
					auto ptr = tmp->left;
					tmp->left = nullptr;
					if (ptr != root)
						delete ptr;
					--size;
				}
			}
			else if (tmp->right != nullptr)
			{
				tmp = tmp->right;
				if (tmp->left == nullptr and tmp->right == nullptr)
				{
					tmp = tmp->parrent;
					auto ptr = tmp->right;
					tmp->right = nullptr;
					if (ptr != root)
						delete ptr;
					--size;
				}
			}
			else if (tmp->right == nullptr and tmp->left == nullptr and tmp != root)
			{
				tmp = tmp->parrent;
			}
			else 
			{
				delete root;
				root = nullptr;
				--size;
				return;
			}
		}
	}
}

template<typename T>
inline void Binary<T>::clearRecursia()
{
	cout << "Clear Recursivno" << endl;
	helperClear(root);
	delete root;
	root = nullptr;
	--size;
}

template<typename T>
inline T Binary<T>::min() const
{
	auto node = root;
	while (node->left != nullptr)
	{
		node = node->left;
	}
	return node->data;
}

template<typename T>
inline T Binary<T>::max() const
{
	auto node = root;
	while (node->right != nullptr)
	{
		node = node->right;
	}
	return node->data;
}

template<typename T>
inline void Binary<T>::popMin()
{
	auto node = root;
	while (node->left != nullptr)
	{
		node = node->left;
	}
	if (node->right == nullptr and node != root)
	{
		node = node->parrent;
		auto ptr = node->left;
		node->left = nullptr;
		delete ptr;
		--size;
	}
	else if (node->right != nullptr and node != root)
	{
		auto ptr = node->right;
		node = node->parrent;
		auto del = node->left;
		node->left = node->left->right;
		ptr->parrent = node;
		delete del;
		--size;
	}
	else if (node->right == nullptr and node == root)
	{
		delete root;
		root = nullptr;
		--size;
	}
	else if (node->right != nullptr and node == root)
	{
		root = node->right;
		delete node;
		root->parrent = nullptr;
		--size;
	}
}

template<typename T>
inline void Binary<T>::popMax()
{
	auto node = root;
	while (node->right != nullptr)
	{
		node = node->right;
	}
	if (node->left == nullptr and node != root)
	{
		node = node->parrent;
		auto ptr = node->right;
		node->right = nullptr;
		delete ptr;
		--size;
	}
	else if (node != root and node->left != nullptr)
	{
		auto ptr = node->left;
		node = node->parrent;
		auto del = node->right;
		node->right = node->right->left;
		ptr->parrent = node;
		delete del;
		--size;
	}
	else if (node->left == nullptr and node == root)
	{
		delete root;
		root = nullptr;
		--size;
	}
	else if (node->left != nullptr and node == root)
	{
		root = node->left;
		delete node;
		root->parrent = nullptr;
		--size;
	}
}

template<typename T>
inline void Binary<T>::findDataDiapazon(const T& data, const T& data_2) const
{
	helperPrintFind(root, data, data_2);
	cout << endl;
}

template<typename T>
inline void Binary<T>::helperPrintFind(Node<T>* node, const T& data, const T& data_2) const
{
	if (node != nullptr)
	{
		if (data <= node->data and node->data <= data_2)
			cout << node->data << "\t";
		helperPrintFind(node->left, data, data_2);
		helperPrintFind(node->right, data, data_2);
	}
}

template<typename T>
inline void Binary<T>::popNode(Node<T>* node)
{
	auto tmp = root;
	auto tmp_2 = node->parrent;
	if (tmp_2->data < node->data)
		tmp_2->right = nullptr;
	else if (tmp_2->data > node->data)
		tmp_2->left = nullptr;
	root = node;
	this->clear();
	root = tmp;
}

template<typename T>
inline Node<T>* Binary<T>::getNode(const T& data) const
{
	auto node = root;
	if (root->data != data)
	{
		while (node->data != data)
		{
			if (node->data > data)
			{
				node = node->left;
			}
			else if (node->data < data)
			{
				node = node->right;
			}
		}
		return node;
	}
	else
		return root;
}

template<typename T>
inline void Binary<T>::helperPrint(Node<T>* node) const
{
	if (node != nullptr)
	{
		helperPrint(node->left);
		cout << node->data << " ";
		helperPrint(node->right);
	}
}

template<typename T>
inline void Binary<T>::helperClear(Node<T>* node)
{
	if (node != nullptr)
	{
		helperClear(node->left);
		helperClear(node->right);
		if (node == root) return;
		if (node->left == nullptr and node->right == nullptr)
		{
			auto ptr = node;
			node = node->parrent;
			if (node->data > ptr->data)
				node->left = nullptr;
			else if (node->data > ptr->data)
				node->right = nullptr;
			delete ptr;
			--size;
		}
	}
}
