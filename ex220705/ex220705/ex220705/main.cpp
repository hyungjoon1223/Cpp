#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vector
{
public:
	class iterator
	{
	public:
		T& operator*()
		{
			int n = 0;
			return n;
		}
		iterator operator++()
		{
			return *this;
		}
		bool operator==(iterator arg)
		{
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
			T* t = _initandcopy(_capacity*2);
			delete[] buf;
			buf = t;
		}
		buf[_size++] = data;
	}
	int size()const { return _size; }
	int capacity()const { return _capacity; }
	int& operator[](int idx) { return buf[idx]; }
	//////
	iterator begin() { return iterator(); }
	iterator end() { return iterator(); }
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

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vector
{
public:
	class iterator
	{
	public:
		T& operator*()
		{
			int n = 0;
			return n;
		}
		iterator operator++()
		{
			return *this;
		}
		bool operator==(iterator arg)
		{
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
	T* _init()
	{
		T* t = new T[_capacity];
		for (int i = 0; i < _size; ++i)
			t[i] = buf[i];

		return t;
	}
public:
	Vector() :buf(nullptr), _size(0), _capacity(0) { }
	void push_back(const T& data)
	{
		if (_capacity == 0)
		{
			_capacity = 1;
			buf = _init();
		}
		else if (_size == _capacity)

		{
			_capacity *= 2;
			T* t = _init();
			delete[] buf;
			buf = t;
		}
		buf[_size++] = data;
	}
	int size()const { return _size; }
	int capacity()const { return _capacity; }
	int& operator[](int idx) { return buf[idx]; }
	////////
	iterator begin() { return iterator(); }
	iterator end() { return iterator(); }
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

	//for (Vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	//	cout << *iter << endl;

	//for (auto item : v)
	//	cout << item << endl;
}

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vector
{
public:
	class iterator
	{
	public:
		T& operator*()
		{
			int n = 0;
			return n;
		}
		iterator operator++()
		{
			return *this;
		}
		bool operator==(iterator arg)
		{
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
public:
	Vector() :buf(nullptr), _size(0), _capacity(0) { }
	void push_back(const T& data)
	{
		if (_capacity == 0)
		{
			_capacity = 1;
			buf = new T[_capacity];
		}
		else if(_size == _capacity)
			
		{
			_capacity *= 2;
			T* t = new T[_capacity];
			for (int i = 0; i < _size; ++i)
				t[i] = buf[i];
			delete[] buf;
			buf = t;
		}		
		buf[_size++] = data;
	}
	int size()const { return _size; }
	int capacity()const { return _capacity; }
	int& operator[](int idx) { return buf[idx]; }
	////////
	iterator begin() { return iterator(); }
	iterator end() { return iterator(); }
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

	//for (Vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	//	cout << *iter << endl;

	//for (auto item : v)
	//	cout << item << endl;
}

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vector
{
public:
	class iterator
	{
	public:
		T& operator*()
		{
			int n = 0;
			return n;
		}
		iterator operator++()
		{
			return *this;
		}
		bool operator==(iterator arg)
		{
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
public:
	Vector():buf(nullptr), _size(0), _capacity(0) { }
	void push_back(const T& data) 
	{
		if (_capacity == 0)
		{
			_capacity = 1;
			buf = new T[_capacity];
			buf[_size++] = data;
		}
		else
		{
			if (_size < _capacity)
				buf[_size++] = data;
			else
			{
				_capacity *= 2;
				T* t = new T[_capacity];
				for (int i = 0; i < _size; ++i)
					t[i] = buf[i];
				delete[] buf;
				buf = t;

				buf[_size++] = data;
			}
		}
	}
	int size()const { return _size; }
	int& operator[](int idx) { return buf[idx]; }
	////////
	iterator begin() { return iterator(); }
	iterator end() { return iterator(); }
};
int main()
{
	Vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	for (int i = 0; i < (int)v.size(); ++i)
		cout << v[i] << endl;

	//for (Vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	//	cout << *iter << endl;

	//for (auto item : v)
	//	cout << item << endl;
}

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vector
{
public:
	class iterator 
	{ 
	public:
		T& operator*()
		{
			int n = 0;
			return n;
		}
		iterator operator++()
		{
			return *this;
		}
		bool operator==(iterator arg)
		{
			return false;
		}
		bool operator!=(iterator arg)
		{
			return !(*this == arg);
		}
	};
public:
	void push_back(const T& data)
	{

	}
	int size()const { return 0; }
	int& operator[](int idx) { int n = 0;  return n; }
	////////
	iterator begin() { return iterator(); }
	iterator end() { return iterator(); }
};
int main()
{
	Vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	for (int i = 0; i < (int)v.size(); ++i)
		cout << v[i] << endl;

	for (Vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << endl;

	for (auto item : v)
		cout << item << endl;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	for (int i = 0; i < (int)v.size(); ++i)
		cout << v[i] << endl;

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << endl;

	for (auto item : v)
		cout << item << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	
	const vector<int>::const_iterator iter = v.begin();
	//const int* const p - ^n
	++iter;
	*iter = 100;
	//	vector<int>::iterator iter = v.begin();
	vector<int>::const_iterator citer = v.begin();
	vector<int>::const_iterator citer2 = v.end();
	vector<int>::reverse_iterator riter = v.rbegin();
	vector<int>::const_reverse_iterator criter = v.rbegin();
	vector<int>::const_reverse_iterator criter2 = v.rend();
	cout << v[1] << endl;

}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	vector<int>::const_iterator iter = v.begin();
	++iter;
	*iter = 100;
	cout << v[1] << endl;

}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	vector<int>::iterator iter = v.begin();
	++iter;
	*iter = 100;
	cout << v[1] << endl;

}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin();
	vector<int>::const_iterator citer = v.begin();
	vector<int>::const_iterator citer2 = v.end();
	vector<int>::reverse_iterator riter = v.rbegin();
	vector<int>::const_reverse_iterator criter = v.rbegin();
	vector<int>::const_reverse_iterator criter2 = v.rend();
	
	//cout << *iter << ',' << *citer << endl;
	//cout << *riter << ',' << *citer << endl;

	sort(v.begin(), v.end());
	sort(v.rbegin, v.rend);
	sort(citer, citer2);
	sort(criter, criter2);
}

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin();
	vector<int>::const_iterator citer = v.begin();
	vector<int>::reverse_iterator riter = v.rbegin();
	vector<int>::const_reverse_iterator criter= v.rbegin();

	cout << *iter << ',' << *citer << endl;
	cout << *riter << ',' << *citer << endl;

}

#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Point
{
    int x, y;
public:
    explicit Point(int x = 0, int y = 0) :x(x), y(y) {}
    void Print() const { cout << x << "," << y << endl; }
    int GetX()const { return x; }
    int GetY()const { return y; }
};

template<typename _Pri, typename _Data>
struct Pred
{
    bool operator()(const pair<_Pri, _Data>& a, const pair<_Pri, _Data>& b)const
    {
        return a.first > b.first;
    }
};


int main()
{
    priority_queue<pair<int, Point>, deque<pair<int, Point>>, Pred<int, Point>> pq;

    pq.push(pair<int, Point>(3, Point(3, 5)));
    pq.push(pair<int, Point>(1, Point(0, 0)));
    pq.push(pair<int, Point>(3, Point(4, 5)));
    pq.push(pair<int, Point>(2, Point(8, 9)));
    pq.push(pair<int, Point>(4, Point(10, 5)));

    while (!pq.empty())
    {
        const auto& item = pq.top();
        cout << item.first << ':';
        item.second.Print();
        pq.pop();
    }


    priority_queue<pair<int, string>, deque<pair<int, string>>, Pred<int, string>> pq2;
    pq2.push(pair<int, string>(2, "ABC"));
    pq2.push(pair<int, string>(3, "BBC"));
    pq2.push(pair<int, string>(4, "KBC"));
    pq2.push(pair<int, string>(1, "ATI"));
    pq2.push(pair<int, string>(5, "DBC"));


    for (int i = 0; i < 3; ++i)
    {
        cout << pq2.top().second << endl;
        pq2.pop();
    }
}

#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y) {}
	void Print()const { cout << x << ", " << y << endl; }
	int GetX()const { return x; }
	int GetY()const { return y; }
};
struct Pred
{
	bool operator()(const pair<int, Point>& a, const pair<int, Point>& b) const
	{
		return a.first < b.first;   //    < less(오름차순 정렬)
	}
};
int main()
{
	priority_queue<pair<int, Point>, vector<pair<int, Point>>, Pred> pq;

	pq.push(pair<int, Point>(3, Point(3, 5)));
	pq.push(pair<int, Point>(1, Point(0, 0)));
	pq.push(pair<int, Point>(3, Point(4, 5)));
	pq.push(pair<int, Point>(2, Point(8, 9)));
	pq.push(pair<int, Point>(4, Point(10, 5)));
	while (!pq.empty())
	{
		const auto& item = pq.top();
		cout << item.first << ' : '; item.second.Print();
		pq.pop();
	}
}

#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y) {}
	void Print()const { cout << x << ", " << y << endl; }
	int GetX()const { return x; }
	int GetY()const { return y; }
};
struct Pred
{
	bool operator()(const pair<int, Point>& a, const pair<int, Point>& b) const
	{
		return a.first < b.first;   //    < less(오름차순 정렬)
	}
};
int main()
{
	priority_queue<pair<int, Point>, vector<pair<int,Point>>, Pred> pq;

	pq.push(pair<int, Point>(3, Point(3, 5)));
	pq.push(pair<int, Point>(1, Point(0, 0)));
	pq.push(pair<int, Point>(3, Point(4, 5)));
	pq.push(pair<int, Point>(2, Point(8, 9)));
	pq.push(pair<int, Point>(4, Point(10, 5)));
	while (!pq.empty())
	{
		const auto& item = pq.top();
		cout << item.first << ' : '; item.second.Print();
		pq.pop();
	}
}

#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x =0, int y= 0):x(x),y(y){}
	void Print()const { cout << x << ", " << y << endl; }
	int GetX()const { return x; }
	int GetY()const { return y; }
};

int main()
{
	priority_queue<pair<int, Point>> pq;

	pq.push(pair<int, Point>(3, Point(3, 5)));
	pq.push(pair<int, Point>(1, Point(0, 0)));
	pq.push(pair<int, Point>(3, Point(4, 5)));
	pq.push(pair<int, Point>(2, Point(8, 9)));
	pq.push(pair<int, Point>(4, Point(10, 5)));
	while (!pq.empty())
	{
		const auto& item = pq.top();
		cout << item.first << ' : '; item.second.Print();
		pq.pop();
	}
}

#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main()
{
	priority_queue<int> pq;

	pq.push(30);
	pq.push(40);
	pq.push(10);
	pq.push(50);
	pq.push(20);

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}

#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main()
{
	queue<int, list<int>> q;   //어뎁터 컨테이너라고 부름 (다른 컨테이너의 인터페이스만 변환)

	q.push(10);
	q.push(20);
	q.push(30);

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> st;   //어뎁터 컨테이너라고 부름 (다른 컨테이너의 인터페이스만 변환)
	
	st.push(10);
	st.push(20);
	st.push(30);

	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
}

#include <iostream>
#include <array>
using namespace std;

void PrintArray(const int arr[], int size)
{
	for (auto item : initializer_list<int>(arr, arr + size))
		cout << item << " ";
	cout << endl;
}
int main()
{
	array<int, 10> arr;

	arr.fill(0);
	for (int i = 0; i < (int)arr.size(); ++i)
		cout << arr[i] << endl;

	int arr2[5] = { 10,20,30,40,50 };
	PrintArray(arr2, 5);
	PrintArray(arr.data(), arr.size());

	for (int i = 0; i < (int)arr.size(); ++i)
		cout << arr.data()[i] << endl;
}

#include <iostream>
#include <array>
using namespace std;

void PrintArray(const int arr[], int size)
{
	for (auto item : initializer_list<int>(arr, arr + size))
		cout << item << " ";
	cout << endl;
}
void PrintArray(const array<int, 10>& arr)
{
	for (auto item : arr)
		cout << item << " ";
	cout << endl;
}
int main()
{
	int arr[10] = { 10,20,30,40,50 };
	array<int, 10> arr2({ 10,20,30,40,50 });

	for (int i = 0; i < 10; ++i)
		arr[i] = i + 1;
	for (int i = 0; i < arr2.size(); ++i)
		arr2[i] = i + 1;

	PrintArray(arr, 10);
	PrintArray(arr2);
}

#include <iostream>
#include <array>
using namespace std;

void PrintArray(const int arr[], int size)
{
	for (auto item : initializer_list<int>(arr,arr+size))
		cout << item << " ";
	cout << endl;
}
void PrintArray(const array<int,10>& arr)
{
	for (auto item : arr)
		cout << item << " ";
	cout << endl;
}
int main()
{
	int arr[10] = { 10,20,30,40,50 };
	array<int, 10> arr2({ 10,20,30,40,50 });

	PrintArray(arr,10);
	PrintArray(arr2);
}

#include <iostream>
#include <array>
using namespace std;

int main()
{
	int arr[10] = { 10,20,30,40,50 };
	array<int, 10> arr2({ 10,20,30,40,50 });

	for (auto& item : arr)
		cout << item <<", " << &item << " ";
	cout << endl;

	for (auto& item : arr2)
		cout << item << ", " << &item << " ";
	cout << endl;
}

#include <iostream>
#include <array>
using namespace std;

int main()
{
	int arr[10] = { 10,20,30,40,50 };
	array<int, 10> arr2({ 10,20,30,40,50 });

	for (auto item : arr)
		cout << item << " ";
	cout << endl;

	for (auto item : arr2)
		cout << item << " ";
	cout << endl;
}

#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_multiset<int> s;

	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(40);
	s.insert(20);

	s.insert(30);

	for (const auto& item : s)
	{
		cout << item << endl;
	}
	cout << endl;
	auto piter = s.equal_range(30);
	if (piter.first != piter.second)
	{
		for (auto iter = piter.first; iter != piter.second; ++iter)
		{
			cout << *iter << endl;
		}
	}
}

#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_set<int> s;    

	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(40);
	s.insert(20);

	s.insert(30);

	for (const auto& item : s)
	{
		cout << item << endl;
	}
	cout << endl;
	auto piter = s.equal_range(30);
	if (piter.first != piter.second)
	{
		for (auto iter = piter.first; iter != piter.second; ++iter)
		{
			cout << *iter << endl;
		}
	}
}

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_multimap<int, string> m;     //map은 이진탐색트리 사용

	//m[1] = "one";
	//m[3] = "three";
	//m[5] = "five";
	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(5, "five"));

	//m[3] = "THREE";
	m.insert(pair<int, string>(3, "THREE"));

	for (const auto& item : m)
	{
		cout << item.first << " : " << item.second << endl;
	}

	auto piter = m.equal_range(3);
	if (piter.first != piter.second)
	{
		for (auto iter = piter.first; iter != piter.second; ++iter)
		{
			cout << iter->first << " : " << iter->second << endl;
		}
	}
}

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<int, string> m;     //map은 이진탐색트리 사용

	m[1] = "one";
	m[3] = "three";
	m[5] = "five";
	//m.insert(pair<int, string>(1, "one"));
	//m.insert(pair<int, string>(3, "three"));
	//m.insert(pair<int, string>(5, "five"));

	m[3] = "THREE";
	//m.insert(pair<int, string>(3, "THREE"));

	for (const auto& item : m)
	{
		cout << item.first << " : " << item.second << endl;
	}

	auto piter = m.equal_range(3);
	if (piter.first != piter.second)
	{
		for (auto iter = piter.first; iter != piter.second; ++iter)
		{
			cout << iter->first << " : " << iter->second << endl;
		}
	}
}

#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, string> m;

	m[1] = "one";
	m[3] = "three";
	m[5] = "five";
	//m.insert(pair<int, string>(1, "one"));
	//m.insert(pair<int, string>(3, "three"));
	//m.insert(pair<int, string>(5, "five"));
	
	m[3] = "THREE";
	//m.insert(pair<int, string>(3, "THREE"));

	for (const auto& item : m)
	{
		cout << item.first << " : " << item.second << endl;
	}

	auto piter = m.equal_range(3);
	if (piter.first != piter.second)
	{
		for (auto iter = piter.first; iter != piter.second; ++iter)
		{
			cout << iter->first << " : " << iter->second << endl;
		}
	}
}

#include <iostream>
#include <map>
using namespace std;

int main()
{
	multimap<int, string> m;


	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(5, "five"));
	m.insert(pair<int, string>(3, "THREE"));

	for (const auto& item : m)
	{
		cout << item.first << " : " << item.second << endl;
	}

	auto piter = m.equal_range(3);
	if (piter.first != piter.second)
	{
		for (auto iter = piter.first; iter != piter.second; ++iter)
		{
			cout << iter->first << " : " << iter->second << endl;
		}
	}
}

#include <iostream>
#include <map>
using namespace std;

int main()
{
	multimap<int, string> m;


	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(5, "five"));
	m.insert(pair<int, string>(3, "THREE"));

	for (const auto& item : m)
	{
		cout << item.first << " : " << item.second << endl;
	}
	auto liter = m.lower_bound(3);
	auto riter = m.upper_bound(3);

	if (liter != riter)
	{
		for (auto iter = liter; iter != riter; ++iter)
		{
			cout << iter->first << " : " << iter->second << endl;
		}
	}
}

#include <iostream>
#include <map>
using namespace std;


struct cmp
{
	bool operator()(int data)const
	{
		return data == 40;
	}
};

int main()
{
	int arr[5] = { 10,50,30,40,20 };

	cmp c;

	find_if(arr, arr + 5, cmp());
	find_if(arr, arr + 4, cmp());

}


#include <iostream>
#include <map>
using namespace std;

int main()
{
	multimap<int, string> m;


	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(5, "five"));
	m.insert(pair<int, string>(3, "THREE"));

	for (const auto& item : m)
	{
		cout << item.first << " : " << item.second << endl;
	}

	auto iter = m.find(3);
	if (iter != m.end())
	{
		cout << iter->second << endl;
	}
}

#include <iostream>
#include <map>
using namespace std;

int main()
{
	multimap<int, string> m;

	//m[1] = "one"; // 멀티맵에서 지원하지 않음

	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(5, "five"));
	m.insert(pair<int, string>(3, "THREE"));

	for (const auto& item : m)
	{
		cout << item.first << " : " << item.second << endl;
	}
}

#include <iostream>
#include <map>
using namespace std;

int main()
{
	multimap<int, string> m;

	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(5, "five"));

	m.insert(pair<int, string>(3, "THREE"));

	for (const auto& item : m)
	{
		cout << item.first << " : " << item.second << endl;
	}
}

#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, string> m;

	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(5, "five"));

	m.insert(pair<int, string>(3, "THREE"));

	for (const auto& item : m)
	{
		cout << item.first << " : " << item.second << endl;
	}
}


#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, string> m;

	//m[1] = "one";		//1. insert
	//m[3] = "three";
	//m[5] = "five";
	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(5, "five"));



	m[3] = "THREE";		//2. updata
	map<int,string>::iterator iter = m.find(4);
	if (iter != m.end())
		iter->second = "THREE";

	map<int, string>::iterator iter2 = m.find(1);
	if (iter2 != m.end())
		cout << iter2->second << endl;

	cout << m[1] << endl;	//3. read
	cout << m[3] << endl;
	cout << m[5] << endl;

}

#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, string> m;

	m[1] = "one";		//1. insert
	m[3] = "three";
	m[5] = "five";

	m[3] = "THREE";		//2. updata

	cout << m[1] << endl;	//3. read
	cout << m[3] << endl;
	cout << m[5] << endl;

}


#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, string> m;

	m[1] = "one";
	m[3] = "three";
	m[5] = "five";

	cout << m[1] << endl;
	cout << m[3] << endl;
	cout << m[5] << endl;

}

#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, string> m;

	m[1]= "one";
	m[3] = "three";
	m[5] = "five";


	for (map<int, string>::iterator iter = m.begin(); iter != m.end(); ++iter)
	{
		cout << iter->first << ',' << iter->second << endl;
	}
}

#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, string> m;
	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(5, "five"));

	for (map<int, string>::iterator iter = m.begin(); iter != m.end(); ++iter)
	{
		cout << iter->first << ',' << iter->second << endl;
	}
}

#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, string> m;
	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	m.insert(pair<int, string>(5, "five"));

	for (map<int, string>::iterator iter = m.begin(); iter != m.end(); ++iter)
	{
		cout << (*iter).first << ',' << (*iter).second << endl;
	}
}
