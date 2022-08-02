#include<iostream>
#include<string>
#include<cstring>

using namespace std;
class Parent
{
    virtual void Print()const {}
};
class Child1 : public Parent
{

};
class Child2 : public Parent
{
public:
    void Print_Child2()const
    {
        cout << "Child2 Method" << endl;
    }
};
int main()
{
    Parent* parr[] = { new Child1, new Child2, new Child1, new Child2 };
    
    for (Parent* x : parr)
    {
        if (typeid(Child2) == typeid(*x))
            ((Child2*)x)->Print_Child2();
    }
}

//#include<iostream>
//#include<string>
//#include<cstring>
//
//using namespace std;
//class String
//{
//public:
//    typedef unsigned int Size_type;
//private:
//    char* buf;
//    Size_type length;
//    // 객체의 복사를 막는 방법
//// 객체의 복사를 막는 방법
//
//public:
//    String(const char* s = " ") :buf(nullptr), length(0)
//    {
//        length = strlen(s);
//        buf = new char[length + 1];
//        strcpy_s(buf, length + 1, s);
//    }
//    String(const String& arg) :buf(nullptr), length(arg.length)
//    {
//        buf = new char[length + 1];
//        strcpy_s(buf, length + 1, arg.buf);
//    }
//    ~String() { delete[] buf; }
//    Size_type size()const { return length; }  //  sizetype을 반환하는함수 
//    char at(Size_type i)const { return buf[i]; }
//    void append(const char* s)
//    {
//        int tlength = length + strlen(s);
//        char* t = new char[tlength + 1];
//        strcpy_s(t, length + 1, buf);
//        strcat_s(t, tlength + 1, s);
//        delete[] buf;
//        buf = t;
//        length = tlength;
//    }
//    void assign(const char* s)
//    {
//        delete[] buf;
//        length = strlen(s);
//        buf = new char[length + 1];
//        strcpy_s(buf, length + 1, s);
//    }
//    const char* c_str()const { return buf; }
//    const String& operator+=(const String& arg)
//    {
//        if (this == &arg)
//            return *this;
//
//        append(arg.buf);
//        return *this;
//    }
//    const String& operator=(const String& arg)
//    {
//        if (this == &arg)
//            throw"자기대입";
//        assign(arg.buf);
//        return *this;
//    }
//    operator const char* ()
//    {
//        return buf;
//    }
//};
//ostream& operator<<(ostream& out, const String& s)
//{
//    out << s.c_str();
//    return out;
//}
//int main()
//{
//    String s("Hello!");
//    cout << s << endl;
//
//    cout << typeid(s).name() << endl;
//
//    if (typeid(s) == typeid(String))
//        cout << "class String" << endl;
//    else
//        cout << "False" << endl;
//
//    const type_info& ti = typeid(s);
//    const type_info& ti2 = typeid(String);
//    cout << ti.name() << ',' << ti2.name() << endl;
//
//    if (ti == ti2)
//        cout << "class String" << endl;
//    else
//        cout << "False" << endl;
//}

//#include<iostream>
//#include<string>
//#include<cstring>
//
//using namespace std;
//class String
//{
//public:
//    typedef unsigned int Size_type;
//private:
//    char* buf;
//    Size_type length;
//                      // 객체의 복사를 막는 방법
//     // 객체의 복사를 막는 방법
//
//public:
//    String(const char* s = " ") :buf(nullptr), length(0)
//    {
//        length = strlen(s);
//        buf = new char[length + 1];
//        strcpy_s(buf, length + 1, s);
//    }
//    String(const String& arg) :buf(nullptr), length(arg.length)
//    {
//        buf = new char[length + 1];
//        strcpy_s(buf, length + 1, arg.buf);
//    }
//    ~String() { delete[] buf; }
//    Size_type size()const { return length; }  //  sizetype을 반환하는함수 
//    char at(Size_type i)const { return buf[i]; }
//    void append(const char* s)
//    {
//        int tlength = length + strlen(s);
//        char* t = new char[tlength + 1];
//        strcpy_s(t, length + 1, buf);
//        strcat_s(t, tlength + 1, s);
//        delete[] buf;
//        buf = t;
//        length = tlength;
//    }
//    void assign(const char* s)
//    {
//        delete[] buf;
//        length = strlen(s);
//        buf = new char[length + 1];
//        strcpy_s(buf, length + 1, s);
//    }
//    const char* c_str()const { return buf; }
//    const String& operator+=(const String& arg)
//    {
//        if (this == &arg)
//            return *this;
//
//        append(arg.buf);
//        return *this;
//    }
//    const String& operator=(const String& arg)
//    {
//        if (this == &arg)
//            throw"자기대입";
//        assign(arg.buf);
//        return *this;
//    }
//    operator const char* () 
//    {
//        return buf;
//    }
//};
//ostream& operator<<(ostream& out, const String& s)
//{
//    out << s.c_str();
//    return out;
//}
//int main()
//{
//    String s("Hello!");
//    cout << s << endl;
//
//    cout << typeid(s).name() << endl;
//
//    if (typeid(s) == typeid(String))
//        cout << "class String" << endl;
//    else
//        cout << "False" << endl;
//
//    const type_info & ti = typeid(s);
//    const type_info& ti2 = typeid(String);
//    cout << ti.name() << ',' << ti2.name() << endl;
//
//    if (ti == ti2)
//        cout << "class String" << endl;
//    else
//        cout << "False" << endl;
//}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	auto arr = { 10,20,30,40,50,60,70,80,90,100 }; // initialzer_list  배열이아니라 별도의 문법임
//
//	for (auto x : arr)
//		cout << x << " ";
//	cout << endl;
//
//	vector<int> v(arr.begin(), arr.end());
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//
//	reverse<vector<int>::iterator>(v.begin(), v.end());
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//
//	random_shuffle<vector<int>::iterator>(v.begin(), v.end());
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//
//	sort<vector<int>::iterator, less<int>>(v.begin(), v.end(), less<int>());
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	auto arr = { 10,20,30,40,50,60,70,80,90,100 }; // initialzer_list  배열이아니라 별도의 문법임
//
//	for (auto x : arr)
//		cout << x << " ";
//	cout << endl;
//
//	vector<int> v(arr.begin(), arr.end());
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//
//	reverse<vector<int>::iterator> (v.begin(), v.end());
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//
//	random_shuffle<vector<int>::iterator>(v.begin(), v.end());
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//
//	sort<vector<int>::iterator, less<int>>(v.begin(), v.end(),less<int>());
//	for (auto x : v)
//		cout << x << " ";
//	cout << endl;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <deque>
//#include <list>
//using namespace std;
//template <typename T, typename Cont = deque<T>>
//class Stack
//{
//	Cont buf;
//public:
//	Stack() { }
//	void Push(const T& data)  //템플릿 주의점 const참조타입으로 쓴다!
//	{
//		buf.push_back(data);
//	}
//	void Pop()
//	{
//		buf.pop_back();
//	}
//	const T& Top()const
//	{
//		return buf.back();
//	}
//};
//int main()
//{
//	Stack<int> s;
//
//	cout << typeid(s).name() << endl;
//	s.Push(10);
//	s.Push(20);
//	s.Push(30);
//
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//
//	Stack<double, vector<double>> ds;
//	ds.Push(1.5);
//	ds.Push(2.5);
//	ds.Push(6.5);
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//}

//#include <iostream> //다시 해야함
//#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//template <typename T>
//class Stack
//{
//	vector<T> buf;
//public:
//	Stack(){ }
//	void Push(const T& data)  //템플릿 주의점 const참조타입으로 쓴다!
//	{
//		buf.push_back(data);
//	}
//	void Pop()
//	{
//		buf.pop_back();
//	}
//	const T& Top()const
//	{
//		return buf.back();
//	}
//};
//int main()
//{
//	Stack<int> s;
//
//	cout << typeid(s).name() << endl;
//	s.Push(10);
//	s.Push(20);
//	s.Push(30);
//
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//
//	Stack<double> ds;
//	ds.Push(1.5);
//	ds.Push(2.5);
//	ds.Push(6.5);
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//template <typename T=int, int MAXSIZE=100>
//class Stack
//{
//	T buf[MAXSIZE];
//	int top;
//public:
//	Stack() :top(0)
//	{
//		for (auto& x : buf)
//		x = T();
//	}
//	void Push(const T& data)  //템플릿 주의점 const참조타입으로 쓴다!
//	{
//		buf[top++] = data;
//	}
//	void Pop()
//	{
//		--top;
//	}
//	const T& Top()const
//	{
//		return buf[top - 1];
//	}
//};
//int main()
//{
//	Stack<> s;
//
//	cout << typeid(s).name() << endl;
//	s.Push(10);
//	s.Push(20);
//	s.Push(30);
//
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//
//	Stack<double> ds;
//	ds.Push(1.5);
//	ds.Push(2.5);
//	ds.Push(6.5);
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//template <typename T, int MAXSIZE>
//class Stack
//{
//	T buf[MAXSIZE];
//	int top;
//public:
//	Stack() :top(0) {}
//	void Push(const T& data)  //템플릿 주의점 const참조타입으로 쓴다!
//	{
//		buf[top++] = data;
//	}
//	void Pop()
//	{
//		--top;
//	}
//	const T& Top()const
//	{
//		return buf[top - 1];
//	}
//};
//int main()
//{
//	Stack<int,100> s;
//
//	cout << typeid(s).name() << endl;
//	s.Push(10);
//	s.Push(20);
//	s.Push(30);
//
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//
//	Stack<double,50> ds;
//	ds.Push(1.5);
//	ds.Push(2.5);
//	ds.Push(6.5);
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//template <typename T>
//class Stack
//{
//	T buf[100];
//	int top;
//public:
//	Stack() :top(0) {}
//	void Push(const T& data)  //템플릿 주의점 const참조타입으로 쓴다!
//	{
//		buf[top++] = data;
//	}
//	void Pop()
//	{
//		--top;
//	}
//	const T& Top()const
//	{
//		return buf[top - 1];
//	}
//};
//int main()
//{
//	Stack<int> s;
//
//	cout << typeid(s).name() << endl;
//	s.Push(10);
//	s.Push(20);
//	s.Push(30);
//
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//
//	Stack<double> ds;
//	ds.Push(1.5);
//	ds.Push(2.5);
//	ds.Push(6.5);
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//template <typename T> 
//class Stack
//{
//	T buf[100];
//	int top;
//public:
//	Stack() :top(0) {}
//	void Push(T data)
//	{
//		buf[top++] = data;
//	}
//	void Pop()
//	{
//		--top;
//	}
//	T Top()const
//	{
//		return buf[top - 1];
//	}
//};
//int main()
//{
//	Stack<int> s;
//	
//	cout << typeid(s).name() << endl;
//	s.Push(10);
//	s.Push(20);
//	s.Push(30);
//
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//
//	Stack<double> ds;
//	ds.Push(1.5);
//	ds.Push(2.5);
//	ds.Push(6.5);
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//	cout << ds.Top() << endl;
//	ds.Pop();
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//class Stack
//{
//	int buf[100];
//	int top;
//public:
//	Stack():top(0){}
//	void Push(int data)
//	{
//		buf[top++] = data;
//	}
//	void Pop()
//	{
//		--top;
//	}
//	int Top()const
//	{
//		return buf[top-1];
//	}
//};
//int main()
//{
//	Stack s;
//	s.Push(10);
//	s.Push(20);
//	s.Push(30);
//
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//	cout << s.Top() << endl;
//	s.Pop();
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//
//template <typename T, typename F>  //T와 F는 템플릿의 매개변수
//int Find(T begin[], T end[], F pred)
//{
//	cout << typeid(T).name() << ":" << typeid(F).name() << endl;
//	for (int i = 0; begin != end; ++begin, ++i)
//		if (pred(*begin))
//			return i;
//	return -1;
//}
//struct Pred
//{
//	bool operator()(int data)const
//	{
//		return data == 30;
//	}
//};
//bool cmp(int data)
//{
//	return data == 30;
//}
//int main()
//{
//	int arr[] = { 10,20,30,40,50 };
//
//	int idx = Find(arr, arr + 5, Pred());
//	if (idx != -1)
//		cout << idx << " : " << arr[idx] << endl;
//
//	double darr[] = { 1.1,4.5,7.7,8.8,9.1 };
//	idx = Find(darr, darr + 5, [](double data)->bool { return 8.8 == data; });
//	if (idx != -1)
//		cout << idx << " : " << darr[idx] << endl;
//
//	idx = Find(arr, arr + 5, cmp);
//	if (idx != -1)
//		cout << idx << " : " << arr[idx] << endl;
//
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//
//template <typename T, typename F>  //T와 F는 템플릿의 매개변수
//int Find(T begin[], T end[], F pred)
//{
//	cout << typeid(T).name() << ":" << typeid(F).name() << endl;
//	for (int i = 0; begin != end; ++begin, ++i)
//		if (pred(*begin))
//			return i;
//	return -1;
//}
//struct Pred
//{
//	bool operator()(int data)const
//	{
//		return data == 30;
//	}
//};
//bool cmp(int data)
//{
//	return data == 30;
//}
//int main()
//{
//	int arr[] = { 10,20,30,40,50 };
//
//	int idx = Find(arr, arr + 5, Pred());
//	if (idx != -1)
//		cout << idx << " : " << arr[idx] << endl;
//
//	double darr[] = { 1.1,4.5,7.7,8.8,9.1 };
//	idx = Find(darr, darr + 5, [](double data)->bool { return 8.8 == data; });
//	if (idx != -1)
//		cout << idx << " : " << darr[idx] << endl;
//
//	idx = Find(arr, arr + 5, cmp);
//	if (idx != -1)
//		cout << idx << " : " << arr[idx] << endl;
//
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//
//template <typename T, typename F>  //T와 F는 템플릿의 매개변수
//int Find(T begin[], T end[], F pred)
//{
//	for (int i = 0; begin != end; ++begin, ++i)
//		if (pred(*begin))
//			return i;
//	return -1;
//}
//struct Pred
//{
//	bool operator()(int data)const
//	{
//		return data == 30;
//	}
//};
//int main()
//{
//	int arr[] = { 10,20,30,40,50 };
//
//	int idx = Find<int,Pred>(arr, arr + 5, Pred());
//	if (idx != -1)
//		cout << idx << " : " << arr[idx] << endl;
//
//	double darr[] = { 1.1,4.5,7.7,8.8,9.1 };
//	idx = Find<double>(darr, darr + 5, [](double data)->bool { return 8.8 == data; });
//	if (idx != -1)
//		cout << idx << " : " << darr[idx] << endl;
//	auto f = [](double data)->bool { return 8.8 == data; };
//	cout << typeid(f).name() << endl;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//
//template <typename T, typename F>  //T와 F는 템플릿의 매개변수
//int Find(T begin[], T end[], F pred)
//{
//	for (int i = 0; begin != end; ++begin, ++i)
//		if (pred(*begin))
//			return i;
//	return -1;
//}
//struct Pred
//{
//	bool operator()(int data)const
//	{
//		return data == 30;
//	}
//};
//int main()
//{
//	int arr[] = { 10,20,30,40,50 };
//
//	int idx = Find(arr, arr + 5, Pred());
//	if (idx != -1)
//		cout << idx << " : " << arr[idx] << endl;
//
//	double darr[] = { 1.1,4.5,7.7,8.8,9.1 };
//	idx = Find(darr, darr + 5, [](double data)->bool { return 8.8 == data; });
//	if (idx != -1)
//		cout << idx << " : " << darr[idx] << endl;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//
//template <typename F> 
//int Find(int begin[], int end[], F pred)
//{
//	for (int i = 0; begin != end; ++begin, ++i)
//		if (pred(*begin))
//			return i;
//	return -1;
//}
//struct Pred
//{
//	bool operator()(int data)const
//	{
//		return data == 30;
//	}
//};
//int main()
//{
//	int arr[] = { 10,20,30,40,50 };
//
//	int idx = Find(arr, arr + 5, Pred());
//	if (idx != -1)
//		cout << idx << " : " << arr[idx] << endl;
//
//	idx = Find(arr, arr + 5, [](int data)->bool { return 30 == data; });
//	if (idx != -1)
//		cout << idx << " : " << arr[idx] << endl;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//struct Pred
//{
//	bool operator()(int data)const
//	{
//		return data == 30;
//	}
//};
//int Find(int begin[], int end[], Pred pred)
//{
//	for (int i = 0; begin != end; ++begin, ++i)
//		if (pred(*begin))
//			return i;
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 10,20,30,40,50 };
//
//	int idx = Find(arr, arr + 5, Pred());
//	if (idx != -1)
//		cout << idx << " : " << arr[idx] << endl;
//
//	int idx = Find(arr, arr + 5, [](int data)->bool{ return 30 == data; });
//	if (idx != -1)
//		cout << idx << " : " << arr[idx] << endl;
//}


//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//struct Pred
//{
//	bool operator()(int data)const
//	{
//		return data == 30;
//	}
//};
//int Find(int begin[], int end[], Pred pred)
//{
//	for (int i = 0; begin != end; ++begin, ++i)
//		if (pred(*begin))
//			return i;
//	return -1;
//}
//int main()
//{
//	int arr[] = { 10,20,30,40,50 };
//
//	int idx = Find(arr, arr + 5, Pred());
//	if (idx != -1)
//		cout << idx << " : " << arr[idx] << endl;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//template <typename T> //컴파일러가 T를 결정함
//void PrintArray(const T* arr, int size)   //인트형 배열을 출력하는 함수  읽기만 하니까 const
//{
//	cout << typeid(T).name() << endl;
//	for (int i = 0; i < size; ++i)
//		cout << arr[i] << endl;
//	cout << endl;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7 };
//	PrintArray<int>(arr, 10);
//
//	string sarr[] = { "abc","defg","12345" };
//	PrintArray<string>(sarr, 3);
//
//	//int n = 10;
//	//PrintArray(n, 10);
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//template <typename T> //컴파일러가 T를 결정함
//void PrintArray(const T* arr, int size)   //인트형 배열을 출력하는 함수  읽기만 하니까 const
//{
//	cout << typeid(T).name() << endl;
//	for (int i = 0; i < size; ++i)
//		cout << arr[i] << endl;
//	cout << endl;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7 };
//	PrintArray(arr, 10);
//	string sarr[] = { "abc","defg","12345" };
//	PrintArray(sarr, 3);
//
//	//int n = 10;
//	//PrintArray(n, 10);
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//template <typename T> //컴파일러가 T를 결정함
//void PrintArray(T* arr, int size)   //인트형 배열을 출력하는 함수 
//{
//	cout << typeid(T).name() << endl;
//	for (int i = 0; i < size; ++i)
//		cout << arr[i] << endl;
//	cout << endl;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7 };
//	PrintArray(arr, 10);
//	string sarr[] = { "abc","defg","12345" };
//	PrintArray(sarr, 3);
//
//	int n = 10;
//	PrintArray(n, 10);
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//template <typename T> //컴파일러가 T를 결정함
//void PrintArray(T arr, int size)   //인트형 배열을 출력하는 함수 
//{
//	cout << typeid(T).name() << endl;
//	for (int i = 0; i < size; ++i)
//		cout << arr[i] << endl;
//	cout << endl;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7 };
//	PrintArray(arr, 10);
//	string sarr[] = { "abc","defg","12345" };
//	PrintArray(sarr, 3);
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
////template <typename T>  
////void PrintArray(T data, int size)  
////	for (int i = 0; i < size; ++i)
////		cout << data[i] << endl;
////	cout << endl;
////}
//void PrintArray(int* arr, int size)   //인트형 배열을 출력하는 함수
//{
//	for (int i = 0; i < size; ++i)
//		cout << arr[i] << endl;
//	cout << endl;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7 };
//	PrintArray(arr, 10);
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//template <typename T> // 템플릿의 인스턴스 
//void Print(T data)    //함수를 만들어내는 함수 (진짜 함수가아니라 함수의 틀이다)
//{
//	cout << typeid(T).name() << " : " << data << endl;
//}
//int main()
//{
//	Print(10);
//	Print("Hello");
//	Print(5.5);
//	Print(5.5);   //더블형식은 만들어져있기 때문에 인스턴스는 3개다.
//	Print<int>(5.5);
//
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//template <typename T> // 템플릿의 인스턴스 
//void Print(T data)    //함수를 만들어내는 함수 (진짜 함수가아니라 함수의 틀이다)
//{
//	cout << typeid(T).name() << " : " << data << endl;
//}
//int main()
//{
//	Print<int>(10);
//	Print<const char*>("Hello");
//	Print<double>(5.5);
//}

////템플릿 시작!!! template
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//template <typename T>
//void Print(T data) //함수를 만들어내는 함수 (진짜 함수가아니라 함수의 틀이다)
//{
//	cout << typeid(T).name() << " : " << data << endl;
//}
//int main()
//{
//	Print(10);
//	Print("Hello");
//	Print(5.5);
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//struct Util
//{
//	static void Menu()
//	{
//		cout << "1. 메뉴 1" << endl;
//		cout << "2. 메뉴 2" << endl;
//		cout << "3. 메뉴 3" << endl;
//	}
//	static void SubMenu()
//	{
//		cout << "1. 서브 메뉴 1" << endl;
//		cout << "2. 서브 메뉴 2" << endl;
//		cout << "3. 서브 메뉴 3" << endl;
//	}
//};
//
//int main()
//{
//	Util::Menu();
//	Util::SubMenu();
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//class Unit
//{
//	static int count;
//public:
//	static int CreateUnit()
//	{
//		//Unit 생성 !
//		return ++count;
//	}
//	static int GetCount() { return count; }
//private:
//	Unit();
//};
//int Unit::count = 0;
//int main()
//{
//	cout << Unit::GetCount() << endl;
//	//Unit u;
//	//Unit* p = new Unit;
//	cout << Unit::CreateUnit() << endl;
//	cout << Unit::CreateUnit() << endl;
//	cout << Unit::CreateUnit() << endl;
//	cout << Unit::CreateUnit() << endl;
//
//	cout << "unit count : " << Unit::GetCount() << endl;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//class Math
//{
//public:
//	static int Add(int a, int b) { return a + b; }
//	static int Sub(int a, int b) { return a - b; }
//};
//int main()
//{
//	int n1 = 10;
//	int n2 = 20;
//	//Math m;
//	cout << "+ : " << Math::Add(n1, n2) << endl;
//	cout << "- : " << Math::Sub(n1, n2) << endl;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int arr[] = { 15,16,29,30,56,20,40 };
//	string s = "string";
//
//	sort(arr, arr + 7, [s](int a, int b)-> bool {cout << s << endl;  return a > b; });
//	for_each(arr, arr + 7, [](int n)-> void {cout << n << endl; });
//	for_each(arr, arr + 7, [](int n)-> void {cout << n << ", "; });
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int arr[] = { 15,16,29,30,56,20,40 };
//
//	for_each(arr, arr + 7, [](int n)-> void {cout << n << endl; });
//	for_each(arr, arr + 7, [](int n)-> void {cout << n <<", "; });
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	//lamdba
//	string s = "Hello";
//	cout << [&](int a, int b) -> int {
//		cout << s << " : " << a << ',' << b << endl;
//		s = "Done";
//
//		return a + b; }(10, 20) << endl;
//
//		cout << s << endl;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	//lamdba
//	string s = "Hello";
//	cout << [=](int a, int b) -> int {
//		cout << s << " : " << a << ',' << b << endl;
//		return a + b; }(10, 20) << endl;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	//lamdba
//	string s = "Hello";
//	cout << [s](int a, int b) -> int {
//		cout << s << " : " << a << ',' << b << endl;
//		return a + b; }(10, 20) << endl;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	//lamdba
//	cout << [](int a, int b) -> int {
//		cout << a << ',' << b << endl;
//		return a + b; }(10, 20) <<  endl;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	//lamdba
//	auto f = [](int a, int b) -> int { 
//		cout << a << ',' << b << endl;
//		return a + b; };
//
//	cout << f(10, 20) << endl;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	//lamdba
//	auto f = [] (int a, int b) -> int{ return a + b; };
//	cout << f(10, 20) << endl;
//}

//#include <iostream>
//using namespace std;
//
//#include <cstring>
//class String
//{
//public:
//    typedef unsigned int Size_type;
//private:
//    char* buf;
//    Size_type length;
//public:
//    String(const char* s = "") :buf(nullptr), length(0)
//    {
//        length = strlen(s);
//        buf = new char[length + 1];
//        strcpy_s(buf, length + 1, s);
//    }
//    String(const String& arg) :buf(nullptr), length(arg.length)
//    {
//        buf = new char[length + 1];
//        strcpy_s(buf, length + 1, arg.buf);
//    }
//
//    ~String() { delete[] buf; }
//    Size_type size() const { return length; }
//    char at(Size_type i) const { return buf[i]; }
//    void append(const char* s)
//    {
//        int tlength = length + strlen(s);
//        char* t = new char[tlength + 1];
//        strcpy_s(t, length + 1, buf);
//        strcat_s(t, tlength + 1, s);
//
//        delete[] buf;
//        buf = t;
//        length = tlength;
//    }
//    void assign(const char* s)
//    {
//        delete[] buf;
//        length = strlen(s);
//        buf = new char[length + 1];
//        strcpy_s(buf, length + 1, s);
//    }
//    const char* c_str() const { return buf; }
//    const String& operator=(const String& arg)
//    {
//        if (this != &arg)
//        {
//            assign(arg.buf);
//        }
//        return *this;
//    }
//    const String& operator+=(const String& arg)
//    {
//        if (this != &arg)
//        {
//            append(arg.buf);
//        }
//        return *this;
//    }
//    operator const char* ()const
//    {
//        return buf;
//    }
//};
//
//ostream& operator<<(ostream& out, const String& s)
//{
//    cout << s.c_str();
//    return out;
//}
//
//int main(void)
//{
//    String s("hello!");
//
//    cout << s << endl;
//    s = "ABC";
//    cout << s << endl;
//    s += "DEF";
//    cout << s << endl;
//    const char* str = s;
//    cout << str << endl;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//
//int main()
//{
//	string s = ("Hello");
//	cout << s << endl;
//
//	s = "ABC";
//	s = string("ABC");
//	cout << s << endl;
//
//   
//	s += string ("DEF");
//	cout << s << endl;
//
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	//explicit Point(int x=0 , int y=0) :x(x), y(y) {} 
//	Point() :x(0), y(0) {}
//	explicit Point(int x) :x(x)(y.y)
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	operator int()const
//	{
//		return x;
//	}
//	operator const char* ()const
//	{
//		return "class Point";
//	}
//};

//int main()
//{
//	Point p1(2, 3);
//	Point p2(3, 4);
//	Point p3;
//
//	int n = 100;
//	p1 = (Point)n;  //Point(n)
//	p1.Print();
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) {}
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	operator int()const
//	{
//		return x;
//	}
//	operator const char* ()const
//	{
//		return "class Point";
//	}
//};
//
//int main()
//{
//	Point p1(2, 3);
//	Point p2(3, 4);
//
//	int n = 100;
//	p1 = (Point)n;  //Point(n)
//	p1.Print();
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) {}
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	operator int()const
//	{
//		return x;
//	}
//	operator const char*()const
//	{
//		return "class Point";
//	}
//};
//
//int main()
//{
//	Point p1(2, 3);
//	Point p2(3, 4);
//
//	int n = p1;
//	cout << "n: " << n << endl;
//	const char* name = (const char*)p1;
//	cout << "p1: " << name << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) {}
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	Point operator+(int n)const
//	{
//		return Point(x + n, y + n);
//	}
//	friend Point operator+(int n, const Point& pt);
//	friend ostream& operator<<(ostream& out, const Point& pt); //프렌드 함수는 자신의 프렌드로 지정된 객체의 모든 상태멤버를 참조 가능 캡슐화 깨기때문에 별로다 가끔 사용 됨
//	friend istream& operator>>(istream& in, Point& pt);
//
//};
//Point operator+(int n, const Point& pt)
//{
//	return Point(n + pt.GetX(), n + pt.GetY());
//}
//ostream& operator<<(ostream& out, const Point& pt)
//{
//	//out << pt.GetX() << ',' << pt.GetY();
//	out << pt.x << ',' << pt.y;
//	return out;
//}
//istream& operator>>(istream& in, Point& pt)
//{
//	cout << "pt(x,y) 입력 :";
//	in >> pt.x >> pt.y;
//	return in;
//}
//int main()
//{
//	Point p1(2, 3);
//	Point p2(3, 4);
//	cin >> p1 >> p2;
//	cout << p1 << " " << p2 << " " << "Hello" << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) {}
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	Point operator+(int n)const
//	{
//		return Point(x + n, y + n);
//	}
//	friend Point operator+(int n, const Point& pt);
//	friend ostream& operator<<(ostream& out, const Point& pt); //프렌드 함수는 자신의 프렌드로 지정된 객체의 모든 상태멤버를 참조 가능 캡슐화 깨기때문에 별로다 가끔 사용 됨
//	friend istream& operator>>(istream& in, Point& pt);
//
//};
//Point operator+(int n, const Point& pt)
//{
//	return Point(n + pt.GetX(), n + pt.GetY());
//}
//ostream& operator<<(ostream& out, const Point& pt)
//{
//	//out << pt.GetX() << ',' << pt.GetY();
//	out << pt.x << ',' << pt.y;
//	return out;
//}
//istream& operator>>(istream& in, Point& pt)
//{
//	cout << "pt(x,y) 입력 :";
//	in >> pt.x >> pt.y;
//	return in;
//}
//int main()
//{
//	Point p1(2, 3);
//	Point p2(3, 4);
//	cin >> p1 >> p2;
//	cout << p1 << " " << p2 << " " << "Hello" << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) {}
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	Point operator+(int n)const
//	{
//		return Point(x + n, y + n);
//	}
//	friend Point operator+(int n, const Point& pt);
//
//	friend ostream& operator<<(ostream& out, const Point& pt); //프렌드 함수는 자신의 프렌드로 지정된 객체의 모든 상태멤버를 참조 가능 캡슐화 깨기때문에 별로다 가끔 사용 됨
//
//};
//Point operator+(int n, const Point& pt)
//{
//	return Point(n + pt.GetX(), n + pt.GetY());
//}
//ostream& operator<<(ostream& out, const Point& pt)
//{
//	//out << pt.GetX() << ',' << pt.GetY();
//	out << pt.x << ',' << pt.y;
//	return out;
//}
//int main()
//{
//	Point p1(2, 3);
//	Point p2(3, 4);
//
//	cout << p1 << " " << p2 << " " << "Hello" << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) {}
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	Point operator+(int n)const
//	{
//		return Point(x + n, y + n);
//	}
//};
//Point operator+(int n, const Point& pt)
//{
//	return Point(n + pt.GetX(), n + pt.GetY());
//}
//ostream& operator<<(ostream& out, const Point& pt)
//{
//	out << pt.GetX() << ',' << pt.GetY();
//	return out;
//}
//int main()
//{
//	Point p1(2, 3);
//	Point p2(3, 4);
//
//	cout << "Hello!" << endl;
//	operator <<(cout, "Hello!").operator <<(endl);
//	cout << p1 << endl;
//	operator <<(cout, p1).operator<<(endl);
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) {}
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	Point operator+(int n)const
//	{
//		return Point(x + n, y + n);
//	}
//};
//Point operator+(int n, const Point& pt)
//{
//	return Point(n + pt.GetX(), n + pt.GetY());
//}
//ostream& operator<<(ostream& out, const Point& pt)
//{
//	out << pt.GetX() << ',' << pt.GetY();
//	return out;
//}
//int main()
//{
//	Point p1(2, 3);
//	Point p2(3, 4);
//
//	cout << "Hello!" << endl;
//	operator <<(cout,"Hello!").operator <<(endl);
//	cout << p1 << endl;
//	operator <<(cout, p1).operator<<(endl);
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) {}
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	Point operator+(int n)const
//	{
//		return Point(x + n, y + n);
//	}
//};
//Point operator+(int n, const Point& pt)
//{
//	return Point(n + pt.GetX(), n + pt.GetY());
//}
//int main()
//{
//	Point p1(2, 3);
//	Point p2(3, 4);
//	p2 = 10 + p1; //operator+(10,p1);
//	p2.Print();
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) {}
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	Point operator+(int n)const
//	{
//		return Point(x + n, y + n);
//	}
//};
//int main()
//{
//	Point p1(2, 3);
//	Point p2(3, 4);
//	//p2 = 10 + p1; //operator+(10,p1);
//	p2 = p1 + 10;  //p1.operator+(int n);
//	p2.Print();
//}

//#include <iostream>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) {}
//	void Print()const { cout << x <<',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//	Point operator+(int n)const
//	{
//		return Point(x + n, y + n);
//	}
//};
//int main()
//{
//	Point p1(2, 3);
//	Point p2(3, 4);
//
//	p2 = p1 + 10;  //p1.operator+(int n);
//	p2.Print();
//}
