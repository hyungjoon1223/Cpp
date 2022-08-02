//#pragma warning( disable : 4507 34; once : 4385; error : 164 )
#pragma warning( disable : 6386)
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vector
{
public:
	class iterator 
	{
	private:
		T* t;
	public:
		iterator(T* a=nullptr) :t(a) {}
		T& operator*()
		{
			return *t;
		}
		iterator operator++()  //주소가 다음칸으로 이동
		{
			t = t + 1;
			return *this;
		}
		bool operator==(iterator arg)   // 비교
		{
			if (arg.t == t)
			{
				return true;
			}
			else
				return false;
		}
		bool operator!=(iterator arg)   
		{
			return !(*this == arg);
		}
	};
private:
	T* buf;
	int _size;
	int _capacity;
private:
	T* _initandcopy(int cap)
	{
		T* t = new T[_capacity = cap];
		for (int i = 0; i < _size; ++i)
			t[i] = buf[i];

		return t;
	}
public:
	Vector() :buf(nullptr), _size(0), _capacity(0) { }
	void push_back(const T& data)
	{
		if (_capacity == 0)
			buf = _initandcopy(1);
		else if (_size == _capacity)
		{
			T* t = _initandcopy(_capacity * 2);
			delete[] buf;
			buf = t;
		}
		buf[_size++] = data;
	}
	int size()const { return _size; }
	int capacity()const { return _capacity; }
	T& operator[](int idx) { return buf[idx]; }
	//////////////////////////////////////////////////
	iterator begin() 
	{
		return buf;
	}
	iterator end() 
	{
		return buf +(_size);
	}
};
int main()
{
	Vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	cout << "capacity : " << v.capacity() << endl;
	for (int i = 0; i < (int)v.size(); ++i)
		cout << v[i] << endl;

	for (Vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << endl;

	for (auto item : v)
		cout << item << endl;
}