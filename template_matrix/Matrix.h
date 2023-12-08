#pragma once
#include <iostream>
#include <string>
using namespace std;


template <typename T = int>
class Matrix
{
public:
	Matrix() = default;
	Matrix(const T& value);

	void Show()
	{
		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = 0; j < 2; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}

	template <typename T>
	friend ostream& operator<< (ostream& out, const Matrix<T>& data);
	template <typename T>
	friend istream& operator>> (istream& in, Matrix<T>& data);
	Matrix<T> operator+(const T& value) const;
	template <typename T>
	friend Matrix<T> operator+(const T& value, Matrix<T> matrix);
	T& operator()(const size_t& i, const size_t& j);
	T max();
	T min();
	bool element(T value);
	T sum();
	Matrix<T> operator+(const Matrix<T> date) const;
	void operator += (const T& value);
	bool operator == (const Matrix<T>& matrix) const;
	bool operator != (const Matrix<T>& matrix) const;
private:
	T arr[2][2];
};

template<typename T>
inline Matrix<T>::Matrix(const T& value)
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			arr[i][j] = value;
		}
	}
}

template<typename T>
inline Matrix<T> Matrix<T>::operator+(const T& value) const
{
	Matrix<T>tmp(*this);
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			tmp.arr[i][j] += value;
		}
	}
	return tmp;
}

template<typename T>
inline T& Matrix<T>::operator()(const size_t& i, const size_t& j)
{
	return arr[i][j];
}

template<typename T>
inline T Matrix<T>::max()
{
	T max = this->arr[0][0];
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	return max;
}

template<typename T>
inline T Matrix<T>::min()
{
	T min = this->arr[0][0];
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			if (min > arr[i][j]) min = arr[i][j];
		}
	}
	return min;
}

template<typename T>
inline bool Matrix<T>::element(T value)
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			if (value == arr[i][j]) return true;
		}
	}
	return false;
}

template<typename T>
inline T Matrix<T>::sum()
{
	T sum = 0;
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			sum = sum + arr[i][j];
		}
	}
	return sum;
}

inline string Matrix<string>::sum()
{
	string sum = "";
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			sum = sum + arr[i][j];
		}
	}
	return sum;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator+(const Matrix<T> date) const
{
	Matrix<T>tmp(*this);
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			tmp.arr[i][j] += date.arr[i][j];
		}
	}
	return tmp;
}

template<typename T>
inline void Matrix<T>::operator+=(const T& value)
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			arr[i][j] += value;
		}
	}
}

template<typename T>
inline bool Matrix<T>::operator==(const Matrix<T>& matrix) const
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			if (this->arr[i][j] != matrix.arr[i][j])
				return false;
		}
	}
	return true;
}

template<typename T>
inline bool Matrix<T>::operator!=(const Matrix<T>& matrix) const
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			if (this->arr[i][j] != matrix.arr[i][j])
				return true;
		}
	}
	return false;
}




template<typename T>
inline ostream& operator<<(ostream& out, const Matrix<T>& data)
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			out << data.arr[i][j] << "\t";
		}
		out << "\n";
	}
	return out;
}

template<typename T>
inline istream& operator>>(istream& in, Matrix<T>& data)
{
	for (size_t i = 0; i < 2; i++)
			{
				for (size_t j = 0; j < 2; j++)
				{
					T value;
					cout << "Enter [" << to_string(i) << "]" << to_string(j) << "]: ";
					in >> value;
					data.arr[i][j] = value;
				}
			}
			return in;
}

template<typename T>
inline Matrix<T> operator+(const T& value, Matrix<T> matrix)
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			matrix.arr[i][j] = matrix.arr[i][j] + value;
		}
	}
	return matrix;
}



