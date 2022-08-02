#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Person
{
protected:
	string name;
	int age;
public:
	Person(const string& n = "", int a = 0) :name(n), age(a) {}
	void Print() const { cout << "name:" << name << ", " << "age : " << age << endl; }
	const string& GetName()const { return name; }
	int GetAge() const { return age; }
};
class Student : public Person
{
	int grade;
public:
	Student(const string& n = "", int a = 0, int g = 0) :Person(n, a), grade(g) {}
	void Print() const
	{
		Person::Print();
		cout << "grade : " << grade << endl;
		this->
	}
	int GetGrade() const { return grade; }
};
int main()
{
	Person p1("È«±æµ¿", 25);
	Student s1("ÀÌ¸ù·æ", 29, 3);

	p1.Print();
	s1.Print();
	s1.
}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Person
//{
//	string name;
//	int age;
//public:
//	Person(const string& n = "", int a = 0) :name(n), age(a) {}
//	void Print() const { cout << "name:" << name << ", " << "age : " << age << endl; }
//	const string& GetName()const { return name; }
//	int GetAge() const { return age; }
//};
//class Student : public Person
//{
//	int grade;
//public:
//	Student(const string& n = "", int a = 0, int g = 0) :Person(n, a), grade(g) {}
//	void Print() const
//	{
//		Person::Print();
//		cout << "grade : " << grade << endl;
//		
//	}
//	int GetGrade() const { return grade; }
//};
//int main()
//{
//	Person p1("È«±æµ¿", 25);
//	Student s1("ÀÌ¸ù·æ", 29, 3);
//
//	p1.Print();
//	s1.Print();
//	s1.
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Person
//{
//	string name;
//	int age;
//public:
//	Person(const string& n="", int a = 0) :name(n), age(a){}
//	void Print() const { cout << "name:" << name << ", " << "age : " << age << endl; }
//	const string& GetName()const { return name; }
//	int GetAge() const { return age; }
//};
//class Student
//{
//	string name;
//	int age;
//	int grade;
//public:
//	Student(const string& n = "", int a = 0, int g = 0) :name(n), age(a), grade(g) {}
//	void Print() const 
//	{ cout << "name:" << name << ", " << "age : " << age << ", "<< "grade : "<<grade <<endl; }
//	const string& GetName()const { return name; }
//	int GetAge() const { return age; }
//	int GetGrade() const { return grade; }
//
//};
//int main()
//{
//	Person p1("È«±æµ¿", 25);
//	Student s1("ÀÌ¸ù·æ", 29, 3);
//
//	p1.Print();
//	s1.Print();
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//typedef vector<string> StrArray;
//
//void PrintArray(const StrArray& arr)
//{
//	for (StrArray::size_type i = 0; i < arr.size(); ++i)
//		cout << arr.at(i).c_str() << " ";
//	cout << endl;
//}
//int main()
//{
//	StrArray arr;
//	arr.push_back(string("10"));
//	arr.push_back(string("20"));
//	arr.push_back(string("30"));
//	arr.push_back(string("40"));
//	arr.push_back(string("50"));
//
//	arr.at(0) = string("100");
//	PrintArray(arr);
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Array
//{
//public:
//	typedef unsigned int size_type;
//private:
//	int* buf;
//	size_type count;
//	const Array& operator=(const Array&);
//public:
//	Array() :buf(nullptr), count(0)
//	{
//		buf = new int[100];
//	}
//	Array(const Array& arg) :buf(nullptr), count(arg.count)
//	{
//		buf = new int[100];
//		for (size_type i = 0; i < count; ++i)
//			buf[i] = arg.buf[i];
//	}
//	~Array() { delete[] buf; }
//	void push_back(int data)
//	{
//		buf[count++] = data;
//	}
//	int& at(int idx) { return buf[idx]; }
//	const int& at(int idx)const { return buf[idx]; }
//	size_type size() const { return count; }
//};
//void PrintArray(const Array& arr)
//{
//	for (Array::size_type i = 0; i < arr.size(); ++i)
//		cout << arr.at(i) << " ";
//	cout << endl;
//}
//int main()
//{
//	Array arr;
//	arr.push_back(10);
//	arr.push_back(20);
//	arr.push_back(30);
//	arr.push_back(40);
//	arr.push_back(50);
//
//	arr.at(0) = 100;
//	PrintArray(arr);
//
//	Array arr2 = arr;
//	arr2 = arr;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Array
//{
//public:
//	typedef unsigned int size_type;
//private:
//	int* buf;
//	size_type count;
//	const Array& operator=(const Array&);
//public:
//	Array() :buf(nullptr), count(0)
//	{
//		buf = new int[100];
//	}
//	Array(const Array& arg) :buf(nullptr), count(arg.count)
//	{
//		buf = new int[100];
//		for (size_type i = 0; i < count; ++i)
//			buf[i] = arg.buf[i];
//	}
//	~Array() { delete[] buf; }
//	void push_back(int data)
//	{
//		buf[count++] = data;
//	}
//	int& at(int idx) { return buf[idx]; }
//	const int& at(int idx)const { return buf[idx]; }
//	size_type size() const { return count; }
//};
//void PrintArray(const Array& arr)
//{
//	for (Array::size_type i = 0; i < arr.size(); ++i)
//		cout << arr.at(i) << " ";
//	cout << endl;
//}
//int main()
//{
//	Array arr;
//	arr.push_back(10);
//	arr.push_back(20);
//	arr.push_back(30);
//	arr.push_back(40);
//	arr.push_back(50);
//
//	arr.at(0) = 100;
//	PrintArray(arr);
//
//	Array arr2 = arr;
//	arr2 = arr;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Array
//{
//public:
//	typedef unsigned int size_type;
//private:
//	int* buf;
//	size_type count;
//	const Array& operator=(const Array&);
//public:
//	Array() :buf(nullptr), count(0)
//	{
//		buf = new int[100];
//	}
//	Array(const Array& arg) :buf(nullptr), count(arg.count)
//	{
//		buf = new int[100];
//		for (size_type i = 0; i < count; ++i)
//			buf[i] = arg.buf[i];
//	}
//	~Array() { delete[] buf; }
//	void push_back(int data)
//	{
//		buf[count++] = data;
//	}
//	int& at(int idx) { return buf[idx]; }
//	const int& at(int idx)const { return buf[idx]; }
//	size_type size() const { return count; }
//};
//void PrintArray(const Array& arr)
//{
//	for (Array::size_type i = 0; i < arr.size(); ++i)
//		cout << arr.at(i) << " ";
//	cout << endl;
//}
//int main()
//{
//	Array arr;
//	arr.push_back(10);
//	arr.push_back(20);
//	arr.push_back(30);
//	arr.push_back(40);
//	arr.push_back(50);
//
//	arr.at(0) = 100;
//	PrintArray(arr);
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Array
//{
//public:
//	typedef unsigned int size_type;
//private:
//	int* buf;
//	int count;
//	const Array& operator=(const Array&);
//public:
//	Array() :buf(nullptr), count(0)
//	{
//		buf = new int[100];
//	}
//	Array(const Array& arg) :buf(nullptr), count(arg.count)
//	{
//		buf = new int[100];
//		for (size_type i = 0; i < count; ++i)
//			buf[i] = arg.buf[i];
//	}
//	~Array() { delete[] buf; }
//	void push_back(int data)
//	{
//		buf[count++] = data;
//	}
//	int& at(int idx) { return buf[idx]; }
//	int size() const { return count; }
//};
//int main()
//{
//	Array arr;
//
//	arr.push_back(10);
//	arr.push_back(20);
//	arr.push_back(30);
//	arr.push_back(40);
//	arr.push_back(50);
//
//	Array arr2 = arr;
//	arr2.at(0) = 100;
//
//	for (Array::size_type i = 0; i < arr.size(); ++i)
//		cout << arr.at(i) << " ";
//	cout << endl;
//	for (Array::size_type i = 0; i < arr2.size(); ++i)
//		cout << arr2.at(i) << " ";
//	cout << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct Data { int item; };
//Data data = { 0 };
//Data* GetAddress()
//{
//	return &::data;
//}
//Data& GetReference()
//{
//	return ::data;
//}
//Data GetData()
//{
//	return ::data;
//}
//int main()
//{	
//	Data d2 = { 1 };
//	//*GetAddress() = d2;
//	//GetReference() = d2;
//	GetData() = d2;
//	cout << GetAddress()->item << endl;
//	cout << GetReference().item << endl;
//	cout << GetData().item << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct Data { int item; };
//Data data = { 0 };
//Data* GetAddress()
//{
//	return &::data;
//}
//Data& GetReference()
//{
//	return ::data;
//}
//Data GetData()
//{
//	return ::data;
//}
//int main()
//{
//	//(*GetAddress()).item = 200;
//	//GetReference().item = 200;
//	Data d2 = { 1 };
//	GetData() = d2;
//	cout << GetAddress()->item << endl;
//	cout << GetReference().item << endl;
//	cout << GetData().item << endl;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct Data { int item; };
//Data data = { 0 };
//Data* GetAddress()
//{
//	return &::data;
//}
//Data& GetReference()
//{
//	return ::data;
//}
//const Data GetData()
//{
//	return ::data;
//}
//int main()
//{
//	//(*GetAddress()).item = 200;
//	//GetReference().item = 200;
//	Data d2 = { 1 };
//	GetData() = d2;
//	cout << GetAddress()->item << endl;
//	cout << GetReference().item << endl;
//	cout << GetData().item << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int data = 100;
//int* GetAddress()
//{
//	return &::data;
//}
//int& GetReference()
//{
//	return ::data;
//}
//int GetData()
//{
//	return ::data;
//}
//int main()
//{
//	//*GetAddress() = 200;
//	//GetReference() = 200;
//	GetData() = 200;
//	cout << *GetAddress() << endl;
//	cout << GetReference() << endl;
//	cout << GetData() << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int data = 100;
//const int* GetAddress()
//{
//	return &::data;
//}
//int& GetReference()
//{
//	return ::data;
//}
//int GetData()
//{
//	return ::data;
//}
//int main()
//{
//	*GetAddress() = 200;
//	cout << *GetAddress() << endl;
//	cout << GetReference() << endl;
//	cout << GetData() << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int data = 100;
//int* GetAddress()
//{
//	return &::data;
//}
//int& GetReference()
//{
//	return ::data;
//}
//int GetData()
//{
//	return ::data;
//}
//int main()
//{
//	*GetAddress() = 200;
//	cout << *GetAddress() << endl;
//	cout << GetReference() << endl;
//	cout << GetData() << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int data = 100;
//int* GetAddress()
//{
//	return &::data;
//}
//int& GetReference()
//{
//	return ::data;
//}
//int GetData()
//{
//	return ::data;
//}
//int main()
//{
//	cout << *GetAddress() << endl;
//	cout << GetReference() << endl;
//	cout << GetData() << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Array
//{
//public:
//	typedef unsigned int size_type;
//private:
//	int* buf;
//	int count;
//	const Array& operator=(const Array&);
//public:
//	Array() :buf(nullptr), count(0)
//	{
//		buf = new int[100];
//	}
//	Array(const Array& arg) :buf(nullptr), count(arg.count)
//	{
//		buf = new int[100];
//		for (size_type i = 0; i < count; ++i)
//			buf[i] = arg.buf[i];
//	}
//	~Array() { delete[] buf; }
//	void push_back(int data)
//	{
//		buf[count++] = data;
//	}
//	int at(int idx)const { return buf[idx]; }
//	int size() const { return count; }
//};
//int main()
//{
//	Array arr;
//
//	arr.push_back(10);
//	arr.push_back(20);
//	arr.push_back(30);
//	arr.push_back(40);
//	arr.push_back(50);
//
//	Array arr2 = arr;
//	//arr2.at(0) = 100;
//
//	for (Array::size_type i = 0; i < arr.size(); ++i)
//		cout << arr.at(i) << " ";
//	cout << endl;
//	for (Array::size_type i = 0; i < arr2.size(); ++i)
//		cout << arr2.at(i) << " ";
//	cout << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Array
//{
//public:
//	typedef unsigned int size_type;
//private:
//	int* buf;
//	int count;
//public:
//	Array() :buf(nullptr), count(0)
//	{
//		buf = new int[100];
//	}
//	~Array() { delete[] buf; }
//	void push_back(int data)
//	{
//		buf[count++] = data;
//	}
//	int at(int idx)const  { return buf[idx]; }
//	int size() const { return count; }
//};
//int main()
//{
//	Array arr;
//
//	arr.push_back(10);
//	arr.push_back(20);
//	arr.push_back(30);
//	arr.push_back(40);
//	arr.push_back(50);
//
//	Array arr2 = arr;
//	//arr2.at(0) = 100;
//
//	for (Array::size_type i = 0; i < arr.size(); ++i)
//		cout << arr.at(i) << " ";
//	cout << endl;
//	for (Array::size_type i = 0; i < arr2.size(); ++i)
//		cout << arr2.at(i) << " ";
//	cout << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//typedef vector<int>	Array;
//
//int main()
//{
//	Array arr;
//
//	arr.push_back(10);
//	arr.push_back(20);
//	arr.push_back(30);
//	arr.push_back(40);
//	arr.push_back(50);
//	
//	Array arr2 = arr;
//	arr2.at(0) = 100;
//
//	for (Array::size_type i = 0; i < arr.size(); ++i)
//		cout << arr.at(i) << " ";
//	cout << endl;
//	for (Array::size_type i = 0; i < arr2.size(); ++i)
//		cout << arr2.at(i) << " ";
//	cout << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//typedef vector<int>	Array;
//
//int main()
//{
//	Array arr;
//
//	arr.push_back(10);
//	arr.push_back(20);
//	arr.push_back(30);
//	arr.push_back(40);
//	arr.push_back(50);
//
//	for (Array::size_type i = 0; i < arr.size(); ++i)
//		cout << arr.at(i) << " ";
//	cout << endl;
//}

//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//
//class String
//{
//public:
//	typedef unsigned int Size_type;
//private:
//	char* buf;
//	Size_type length;
//	const String& operator=(const String& arg);
//public:
//	String(const char* s = "") :buf(nullptr), length(0) {
//		length = (Size_type)strlen(s);
//		buf = new char[length + 1];
//		strcpy_s(buf, length + 1, s);
//	}
//	String(const String& arg) :buf(nullptr), length(arg.length)
//	{
//		buf = new char[length + 1];
//		strcpy_s(buf, length + 1, arg.buf);
//	}
//	~String() { delete[] buf; }
//	Size_type size()const { return length; }
//	char at(Size_type i)const { return buf[i]; }
//	void append(const char* s) {
//		int tlength = length + (Size_type)strlen(s);
//		char* t = new char[tlength + 1];
//		strcpy_s(t, length + 1, buf);
//		strcat_s(t, tlength + 1, s);
//
//		delete[] buf;
//		buf = t;
//		length = tlength;
//	}
//	void assign(const char* s) {
//		delete[] buf;
//
//		length = (Size_type)strlen(s);
//		buf = new char[length + 1];
//		strcpy_s(buf, length + 1, s);
//	}
//	const char* c_str()const { return buf; }
//};
//int main()
//{
//	String s("Hello!");
//
//	for (String::Size_type i = 0; i < s.size(); ++i)
//		cout << s.at(i) << " ";
//	cout << endl;
//
//	s.append("12345");
//	cout << s.c_str() << endl;
//
//	s.assign("ABC");
//	cout << s.c_str() << endl;
//
//	String s2 = s;
//	cout << s2.c_str() << endl;
//}

//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//
//class String
//{
//public:
//	typedef unsigned int Size_type;
//private:
//	char* buf;
//	Size_type length;
//	const String& operator=(const String& arg);
//public:
//	String(const char* s = "") :buf(nullptr), length(0) {
//		length = (Size_type)strlen(s);
//		buf = new char[length + 1];
//		strcpy_s(buf, length + 1, s);
//	}
//	String(const String& arg) :buf(nullptr), length(arg.length)
//	{
//		buf = new char[length + 1];
//		strcpy_s(buf, length + 1, arg.buf);
//	}
//	~String() { delete[] buf; }
//	Size_type size()const { return length; }
//	char at(Size_type i)const { return buf[i]; }
//	void append(const char* s) {
//		int tlength = length + (Size_type)strlen(s);
//		char* t = new char[tlength + 1];
//		strcpy_s(t, length + 1, buf);
//		strcat_s(t, tlength + 1, s);
//
//		delete[] buf;
//		buf = t;
//		length = tlength;
//	}
//	void assign(const char* s) {
//		delete[] buf;
//
//		length = (Size_type)strlen(s);
//		buf = new char[length + 1];
//		strcpy_s(buf, length + 1, s);
//	}
//	const char* c_str()const { return buf; }
//};
//int main()
//{
//	String s("Hello!");
//
//	for (String::Size_type i = 0; i < s.size(); ++i)
//		cout << s.at(i) << " ";
//	cout << endl;
//
//	s.append("12345");
//	cout << s.c_str() << endl;
//
//	s.assign("ABC");
//	cout << s.c_str() << endl;
//
//	String s2 = s;
//	cout << s2.c_str() << endl;
//}

//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//
//class String
//{
//public:
//	typedef unsigned int Size_type;
//private:
//	char* buf;
//	Size_type length;
//public:
//	String(const char* s = "") :buf(nullptr), length(0) {
//		length = strlen(s);
//		buf = new char[length + 1];
//		strcpy_s(buf, length + 1, s);
//	}
//	~String() { delete[] buf; }
//	Size_type size()const { return length; }
//	char at(Size_type i)const { return buf[i]; }
//	void append(const char* s) {		
//		int tlength = length + strlen(s);
//		char* t = new char[tlength + 1];
//		strcpy_s(t, length + 1, buf);
//		strcat_s(t, tlength + 1, s);
//
//		delete[] buf;
//		buf = t;
//		length = tlength;
//	}
//	void assign(const char* s) {
//		delete[] buf;
//
//		length = strlen(s);
//		buf = new char[length + 1];
//		strcpy_s(buf, length + 1, s);
//	}
//	const char* c_str()const { return buf; }
//};
//int main()
//{
//	String s("Hello!");
//
//	for (String::Size_type i = 0; i < s.size(); ++i)
//		cout << s.at(i) << " ";
//	cout << endl;
//
//	s.append("12345");
//	cout << s.c_str() << endl;
//
//	s.assign("ABC");
//	cout << s.c_str() << endl;
//}

//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//
//class String
//{
//public:
//	typedef unsigned int Size_type;
//private:
//	char* buf;
//	Size_type length;
//public:
//	String(const char* s = "") :buf(nullptr), length(0) {
//		length = strlen(s);
//		buf = new char[length + 1];
//		strcpy_s(buf, length + 1, s);
//	}
//	~String() { delete[] buf; }
//	Size_type size()const { return length; }
//	char at(Size_type i)const { return buf[i]; }
//	void append(const char* s) {
//
//	}
//	void assign(const char* s) {
//		delete[] buf;
//
//		length = strlen(s);
//		buf = new char[length + 1];
//		strcpy_s(buf, length + 1, s);
//	}
//	const char* c_str()const { return buf; }
//};
//int main()
//{
//	String s("Hello!");
//
//	for (String::Size_type i = 0; i < s.size(); ++i)
//		cout << s.at(i) << " ";
//	cout << endl;
//
//	s.append("12345");
//	cout << s.c_str() << endl;
//
//	s.assign("ABC");
//	cout << s.c_str() << endl;
//}

//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//
//class String
//{
//public:
//	typedef unsigned int Size_type;
//private:
//	char* buf;
//	Size_type length;
//public:
//	String(const char* s = ""):buf(nullptr),length(0) {
//		length = strlen(s);
//		buf = new char[length + 1];
//		strcpy_s(buf, length + 1, s);
//	}
//	~String() { delete[] buf; }
//	Size_type size()const { return length; }
//	char at(Size_type i)const { return buf[i]; }
//	void append(const char* s) {
//
//	}
//	void assign(const char* s) {
//
//	}
//	const char* c_str()const { return buf; }
//};
//int main()
//{
//	String s("Hello!");
//
//	for (String::Size_type i = 0; i < s.size(); ++i)
//		cout << s.at(i) << " ";
//	cout << endl;
//
//	s.append("12345");
//	cout << s.c_str() << endl;
//
//	s.assign("ABC");
//	cout << s.c_str() << endl;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class String
//{
//public:
//	typedef unsigned int Size_type;
//public:
//	String(const char* s=""){}
//
//	Size_type size() { return 0; }
//	char at(Size_type i) { return 'A'; }
//	void append(const char* s) {
//
//	}
//	void assign(const char* s) {
//
//	}
//	const char* c_str() { return ""; }
//};
//int main()
//{
//	String s("Hello!");
//
//	for (String::Size_type i = 0; i < s.size(); ++i)
//		cout << s.at(i) << " ";
//	cout << endl;
//
//	s.append("12345");
//	cout << s.c_str() << endl;
//
//	s.assign("ABC");
//	cout << s.c_str() << endl;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s("Hello!");
//
//	for (string::size_type i = 0; i < s.size(); ++i)
//		cout << s.at(i) << " ";
//	cout << endl;
//
//	s.append("12345");
//	cout << s.c_str() << endl;
//
//	s.assign("ABC");
//	cout << s.c_str() << endl;
//}
