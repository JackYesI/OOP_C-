#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <fstream>

#include <algorithm>

using namespace std;

void Print(const vector<int>& vec, const string& name = "")
{
	cout << "Print vec " << name << " :: " << endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "\t";
	}cout << endl;
}

void Print(const vector<vector<int>>& vec, const string& name = "")
{
	cout << "Print vec " << name << " :: " << endl;
	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << "\t";
		}cout << endl;
	}
}

int main()
{
	vector<int> v1, v2, v3;
	int size;
	cout << "Enter size empty vec :: ";
	cin >> size;
	for (size_t i = 0; i < size; i++)
	{
		int elem;
		cout << "Emter Elem :: ";
		cin >> elem;
		v1.push_back(elem);
	}
	for (size_t i = 0; i < 10; i++)
	{
		v2.push_back(0);
	}

	cout << "Enter size for random vec :: ";
	cin >> size;
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < size; i++)
	{
		int random = 0 + (rand() % 10);
		v3.push_back(random);
	}
	vector<int> v4(v1.begin(), v1.end());


	vector<int> v5(v3.begin() + 1, v3.end() - 1);
	
	std::reverse(v1.begin(), v1.end());

	/*Print(v1, "V1 :: ");
	Print(v2, "V2 :: ");*/
	Print(v3, "V3 :: ");
	/*Print(v4, "V4 :: ");
	Print(v5, "V5 :: ");*/

	fstream file;
	file.open("numbers.txt", ios_base::in | ios_base::out);

	vector<int> cheack;

	for (size_t i = 0; i < v1.size(); i++)
	{
		file << v1[i] << "\t";
	}
	int i;
	
	file.clear();
	file.seekg(0);
	while (file >> i)
	{
		cout << i << endl;
		cheack.push_back(i);
	}
	file.close();
	Print(cheack, "out of file");

	for (size_t i = 0; i < 10; i++)
	{
		v2[i] = i + 1;
	}
	/*Print(v2, "V2 :: ");*/
	random_shuffle(v2.begin(), v2.end());
	v2.erase(v2.begin() +1 );
	v2.pop_back();
	Print(v2, "V2 (random_shuffle) :: ");

	int count = v4.size();
	Print(v4);
	for (size_t i = 0; i < count; i++)
	{
		v4.insert(v4.begin() + (i * 2) + 1, v4[i * 2]);
	}
	Print(v4);
	v5.clear();
	/*v5.resize(v4.size());*/
	Print(v5);
	for (size_t i = 0; i < v4.size(); i++)
	{
		if (v4[i] % 2 == 0)
		{
			v5.push_back(v4[i]);
		}
	}
	v5.shrink_to_fit();
	Print(v5);
	for (size_t i = 0; i < v5.size(); i++)
	{
		v5[i] = v5[i] / 2;
	}
	Print(v5);


	int value, count_ = 0;
	cout << "Enter value for searching :: ";
	cin >> value;
	for (size_t i = 0; i < v5.size(); i++) {
		if (i == value) {
			cout << i << "\t";
			count_++;
		}
	}cout << endl;
	cout << "Count :: " << count_ << endl;
	v4.swap(v5);

	// * 
	vector<vector<int>> matrix;
	vector<int> vec;
	for (size_t i = 0; i < 10; i++)
	{
		vec.clear();
		for (size_t j = 0; j < 10; j++)
		{
			vec.push_back((i + 1)* (j + 1));
		}
		matrix.push_back(vec);
	}

	Print(matrix, "multiply table :: ");

}