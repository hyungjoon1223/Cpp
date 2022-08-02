#include <iostream>
#include <vector>
#include "String.h"
using namespace std;
class StrArray
{
public:
	typedef unsigned int size_type;
private:
	String* buf;
	size_type count;
	const StrArray& operator=(const StrArray&);
public:
	StrArray() :buf(nullptr), count(0)
	{
		buf = new String[100];
	}
	StrArray(const StrArray& arg) :buf(nullptr), count(arg.count)
	{
		buf = new String[100];
		for (size_type i = 0; i < count; ++i)
			buf[i] = arg.buf[i];
	}
	~StrArray() { delete[] buf; }
	void push_back(const String& data)
	{
		buf[count++] = data;
	}
	String& at(int idx) { return buf[idx]; }
	const String& at(int idx)const { return buf[idx]; }
	size_type size() const { return count; }
};
void PrintArray(const StrArray& arr)
{
	for (StrArray::size_type i = 0; i < arr.size(); ++i)
		cout << arr.at(i).c_str() << " ";
	cout << endl;
}
int main()
{
	StrArray arr;
	arr.push_back(String("10"));
	arr.push_back(String("20"));
	arr.push_back(String("30"));
	arr.push_back(String("40"));
	arr.push_back(String("50"));

	arr.at(0) = String("100");
	PrintArray(arr);
}