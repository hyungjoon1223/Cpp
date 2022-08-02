
#include <iostream>
#include <vector>
using namespace std;
class Array
{
public:
	typedef unsigned int size_type;
private:
	int* buf;
	size_type count;
	const Array& operator = (const Array&);
public:
	Array() :buf(nullptr), count(0)
	{
		buf = new int[100];
	}
	Array(const Array& arg) :buf(nullptr), count(arg.count)
	{
		buf = new int[100];
		for (size_type i = 0; i < count; ++i)
			buf[i] = arg.buf[i];
	}
	~Array() { delete[] buf; }
	void push_back(int data)
	{
		buf[count++] = data;
	}
	int& at(int idx) { return buf[idx]; }
	const int& at(int idx) const { return buf[idx]; }
	int size() const { return count; }
};
void PrintArray(const Array& arr)
{
	for (Array::size_type i = 0; i < arr.size(); ++i)
		cout << arr.at(i) << " ";
	cout << endl;
}
int man()
{
	Array arr;
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);

	arr.at(0) = 100;
	PrintArray(arr);
}
