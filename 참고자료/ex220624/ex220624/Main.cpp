#include <iostream>
#include <vector>
#include "string.h"
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
    StrArray(const Array& arg) :buf(nullptr), count(arg.count)
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
        
    arr.push_back(String(10));
    arr.push_back(String(20));
    arr.push_back(String(30));
    arr.push_back(String(40));
    arr.push_back(String(50));


    arr.at(0) = (100);
    PrintArray(arr);

    Array arr2 = arr;
    arr2 = arr;
}
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
	const int& at(int idx) const{ return buf[idx]; }
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

#include <iostream>
#include <vector>
using namespace std;
class Array
{
public:
	typedef unsigned int size_type;
private:
	int* buf;
	int count;
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
	int size() const { return count; }
};

int main()
{
	Array arr;

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);

	Array arr2 = arr;   //���纻
	arr2.at(0) = 100;   // * ��1�� �߿�


	for (Array::size_type i = 0; i < arr.size(); ++i)  //����
		cout << arr.at(i) << " ";
	cout << endl;

	for (Array::size_type i = 0; i < arr2.size(); ++i) //���纻
		cout << arr2.at(i) << " ";
	cout << endl;
}


#include <iostream>
#include <vector>
using namespace std;

struct Data { int item; };
Data data = { 0 };
Data* GetAddress()
{
	return &::data;
}
Data& GetReference()
{

	return ::data;
}
const Data GetData()
{
	return ::data;
}
int main()
{
	Data d2 = { 1 };

	//*GetAddress() = d2; //�����Ϳ� 200�� �־��
	//GetReference() = d2;
	GetData() = d2;

	cout << GetAddress()->item << endl;
	cout << GetReference().item << endl;
	cout << GetData().item << endl;
}

#include <iostream>
#include <vector>
using namespace std;

struct Data { int item; };
Data data = { 0 };
Data* GetAddress()
{
	return &::data;
}
Data& GetReference()
{

	return ::data;
}
const Data GetData()
{
	return ::data;
}
int main()
{
	//(*GetAddress()).item = 200;  //�����Ϳ� 200�� �־��
	//GetReference().item = 200;
	Data d2 = { 1 };
	GetData() = d2;

	cout << GetAddress()->item << endl;
	cout << GetReference().item << endl;
	cout << GetData().item << endl;
}

#include <iostream>
#include <vector>
using namespace std;

struct Data { int item; };
Data data = { 0 };
Data* GetAddress()
{
	return &::data;
}
Data& GetReference()
{

	return ::data;
}
Data GetData()
{
	return ::data;
}
int main()
{
	(*GetAddress()).item = 200;  //�����Ϳ� 200�� �־��
	GetReference().item = 200;
	//Data d2 = { 1 };
	//GetData() = d2;
	
	cout << GetAddress()->item << endl;
	cout << GetReference().item << endl;
	cout << GetData().item << endl;
}

#include <iostream>
#include <vector>
using namespace std;

int data = 100;
int* GetAddress()
{
	return &::data;
}
int& GetReference()
{

	return ::data;
}
int GetData()
{
	return ::data;
}
int main()
{
	//*GetAddress() = 200;  //�����Ϳ� 200�� �־��
	//GetReference() = 200;
	GetData() = 200;  //�������� ���̴� �̰� �׷��� �ȴ�
	cout << *GetAddress() << endl;
	cout << GetReference() << endl;
	cout << GetData() << endl;
}

#include <iostream>
#include <vector>
using namespace std;

int data = 100;
const int* GetAddress()
{
	return &::data;
}
int& GetReference()
{

	return ::data;
}
int GetData()
{
	return ::data;
}
int main()
{
	*GetAddress() = 200;  //�����Ϳ� 200�� �־�� 
	cout << *GetAddress() << endl;
	cout << GetReference() << endl;
	cout << GetData() << endl;
}

#include <iostream>
#include <vector>
using namespace std;

int data = 100;
int* GetAddress()
{
	return &::data;
}
int& GetReference()
{

	return ::data;
}
int GetData()
{
	return ::data;
}
int main()
{
	*GetAddress() = 200;  //�����Ϳ� 200�� �־�� 
	cout << *GetAddress() << endl;
	cout << GetReference() << endl;
	cout << GetData() << endl;
}

#include <iostream>
#include <vector>
using namespace std;

int data = 100;
int* GetAddress()
{
	return &::data;
}
int& GetReference()
{

	return ::data;
}
int GetData()
{
	return ::data;
}
int main()
{
	cout << *GetAddress() << endl;
	cout << GetReference() << endl;
	cout << GetData() << endl;
}

#include <iostream>
#include <vector>
using namespace std;
class Array
{
public:
	typedef unsigned int size_type;
private:
	int* buf;
	int count;
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
	int at(int idx) const { return buf[idx]; }
	int size() const { return count; }
};

int main()
{
	Array arr;

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);

	Array arr2 = arr;   //���纻
	//arr2.at(0) = 100;   // * ��1�� �߿�


	for (Array::size_type i = 0; i < arr.size(); ++i)  //����
		cout << arr.at(i) << " ";
	cout << endl;

	for (Array::size_type i = 0; i < arr2.size(); ++i) //���纻
		cout << arr2.at(i) << " ";
	cout << endl;
}

#include <iostream>
#include <vector>
using namespace std;
class Array
{
public:
	typedef unsigned int size_type;
private:
	int* buf;
	int count;
public:
	Array() :buf(nullptr), count(0)
	{
		buf = new int[100];
	}
	~Array() { delete[] buf; }
	void push_back(int data)
	{
		buf[count++] = data;
	}
	int at(int idx) const{ return buf[idx]; }
	int size() const{ return count; }
};

int main()
{
	Array arr;

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);

	Array arr2 = arr;   //���纻
	//arr2.at(0) = 100;   // * ��1�� �߿�


	for (Array::size_type i = 0; i < arr.size(); ++i)  //����
		cout << arr.at(i) << " ";
	cout << endl;

	for (Array::size_type i = 0; i < arr2.size(); ++i) //���纻
		cout << arr2.at(i) << " ";
	cout << endl;
}

#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Array;  //������ ��� �迭�� ������� <int>

int main()
{
	Array arr;

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);

	Array arr2 = arr;   //���纻
	arr2.at(0) = 100;   // * ��1�� �߿�


	for (Array::size_type i = 0; i < arr.size(); ++i)  //����
		cout << arr.at(i) << " ";
	cout << endl;

	for (Array::size_type i = 0; i < arr2.size(); ++i) //���纻
		cout << arr2.at(i) << " ";
	cout << endl;
}

#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Array;  //������ ��� �迭�� ������� <int>

int main()
{
	Array arr;

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);

	for (Array::size_type i = 0; i < arr.size(); ++i)
		cout << arr.at(i) << " ";
	cout << endl;
}

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class String
{
public:

    typedef unsigned int Size_type;
private:
    char* buf;
    Size_type length;
    const String& operator = (const String& arg);
public:

    typedef unsigned int Size_type;

public:
    String(const char* s = " ") :buf(nullptr), length(0) {   //nullptr �����͸� �η� �ʱ�ȭ �ϰڤ�
        length = strlen(s);
        buf = new char[length + 1];
        strcpy_s(buf, length + 1, s);
    }
    String(const String& arg) : buf(nullptr), length(arg.length)
    {
        length = arg.length;
        buf = new char[length + 1];
        strcpy_s(buf, length + 1, arg.buf);
    }

    ~String() { delete[] buf; }
    Size_type size()const { return length; }  //  sizetype�� ��ȯ�ϴ��Լ� 
    char at(Size_type i)const { return buf[i]; }
    void append(const char* s) {

        int tlength = length + strlen(s);
        char* t = new char[tlength + 1];
        strcpy_s(t, length + 1, buf);
        strcat_s(t, tlength + 1, s);

        delete[] buf;
        buf = t;
        length = tlength;
    }
    void assign(const char* s) {
        delete[] buf;
        length = strlen(s);
        buf = new char[length + 1];
        strcpy_s(buf, length + 1, s);
    }
    const char* c_str()const { return buf; }

};
int main()
{
    String s("Hello!");
    for (String::Size_type i = 0; i < s.size(); ++i)
        cout << s.at(i) << " ";                    //���ڿ� ���ھ� ���
    cout << endl;

    s.append("12345");
    cout << s.c_str() << endl;  // c��Ÿ���ǹ��ڷ� �������

    s.assign("ABC");
    cout << s.c_str() << endl;               //ABC�� ���ڿ� ��ü

    String s2 = s;
    cout << s2.c_str() << endl;
}

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class String
{
public:

    typedef unsigned int Size_type;
private:
    char* buf;
    Size_type length;
public:

    typedef unsigned int Size_type;

public:
    String(const char* s = " ") :buf(nullptr), length(0) {   //nullptr �����͸� �η� �ʱ�ȭ �ϰڤ�
        length = strlen(s);
        buf = new char[length + 1];
        strcpy_s(buf, length + 1, s);
    }
    ~String() { delete[] buf; }
    Size_type size()const { return length; }  //  sizetype�� ��ȯ�ϴ��Լ� 
    char at(Size_type i)const { return buf[i]; }
    void append(const char* s) {
        
        int tlength = length + strlen(s);
        char* t = new char[tlength + 1];
        strcpy_s(t, length + 1, buf);
        strcat_s(t, tlength + 1, s);

        delete[] buf;
        buf = t;
        length = tlength;
    }
    void assign(const char* s) {
        delete[] buf;
        length = strlen(s);
        buf = new char[length + 1];
        strcpy_s(buf, length + 1, s);
    }
    const char* c_str()const { return buf; }

};
int main()
{
    String s("Hello!");
    for (String::Size_type i = 0; i < s.size(); ++i)
        cout << s.at(i) << " ";                    //���ڿ� ���ھ� ���
    cout << endl;

    s.append("12345");
    cout << s.c_str() << endl;  // c��Ÿ���ǹ��ڷ� �������

    s.assign("ABC");
    cout << s.c_str() << endl;               //ABC�� ���ڿ� ��ü

}

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class String
{
public:

    typedef unsigned int Size_type;
private:
    char* buf;
    Size_type length;
public:

    typedef unsigned int Size_type;

public:
    String(const char* s = " ") :buf(nullptr), length(0) {   //nullptr �����͸� �η� �ʱ�ȭ �ϰڤ�
        length = strlen(s);
        buf = new char[length + 1];
        strcpy_s(buf, length + 1, s);
    }
    ~String() { delete[] buf; }
    Size_type size()const { return length; }  //  sizetype�� ��ȯ�ϴ��Լ� 
    char at(Size_type i)const { return buf[i]; }
    void append(const char* s) {



    }
    void assign(const char* s) {
        delete[] buf;
        length = strlen(s);
        buf = new char[length + 1];
        strcpy_s(buf, length + 1, s);
    }
    const char* c_str()const { return buf; }

};
int main()
{
    String s("Hello!");
    for (String::Size_type i = 0; i < s.size(); ++i)
        cout << s.at(i) << " ";                    //���ڿ� ���ھ� ���
    cout << endl;

    s.append("12345");
    cout << s.c_str() << endl;  // c��Ÿ���ǹ��ڷ� �������

    s.assign("ABC");
    cout << s.c_str() << endl;               //ABC�� ���ڿ� ��ü

}

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class String
{
public:

    typedef unsigned int Size_type;
private:
    char* buf;
    Size_type length;
public:

    typedef unsigned int Size_type;

public:
    String(const char* s = " "):buf(nullptr), length(0) {   //nullptr �����͸� �η� �ʱ�ȭ �ϰڤ�
        length = strlen(s);
        buf = new char[length + 1];
        strcpy_s(buf, length + 1, s);
    }
    ~String() { delete[] buf; }
    Size_type size()const { return length; }  //  sizetype�� ��ȯ�ϴ��Լ� 
    char at(Size_type i)const { return buf[i]; }
    void append(const char* s) {

    }
    void assign(const char* s) {

    }
    const char* c_str()const { return buf; }

};
int main()
{
    String s("Hello!");
    for (String::Size_type i = 0; i < s.size(); ++i)
        cout << s.at(i) << " ";                    //���ڿ� ���ھ� ���
    cout << endl;

    s.append("12345");
    cout << s.c_str() << endl;  // c��Ÿ���ǹ��ڷ� �������

    s.assign("ABC");
    cout << s.c_str() << endl;               //ABC�� ���ڿ� ��ü

}

#include <iostream>
#include <string>
using namespace std;

class String
{

public:

    typedef unsigned int Size_type;

public:
    String(const char* s = " ") {}
    Size_type size() { return 0; }  //  sizetype�� ��ȯ�ϴ��Լ� 
    char at(Size_type i) { return 'A'; }
    void append(const char* s) {

    }
    void assign(const char* s) {

    }
    const char* c_str() { return ""; }

};
int main()
{
    String s("Hello!");
    for (String::Size_type i = 0; i < s.size(); ++i)
        cout << s.at(i) << " ";                    //���ڿ� ���ھ� ���
    cout << endl;

    s.append("12345");
    cout << s.c_str() << endl;  // c��Ÿ���ǹ��ڷ� �������

    s.assign("ABC");
    cout << s.c_str() << endl;               //ABC�� ���ڿ� ��ü

}

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = ("Hello!");

	for (string::size_type i = 0; i < s.size(); ++i)
		cout << s.at(i) << " ";
	cout << endl;
	s.append("12345");
	cout << s.c_str() << endl;
	s.assign("ABC");
	cout << s.c_str() << endl;

}
