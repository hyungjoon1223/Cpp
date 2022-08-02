#include<iostream>
#include<string>
using namespace std;

class String
{
public:
	typedef unsigned int Size_type;
private:
	char* buf;
	Size_type length;
	//Size_type count;

public:
	String(const char* s = "") :buf(nullptr), length(0) {
		length = strlen(s);
		buf = new char[length + 1];
		strcpy_s(buf, length + 1, s);
	}
	String(const String& arg) :buf(nullptr), length(arg.length)
	{
		buf = new char[length + 1];
		strcpy_s(buf, length + 1, arg.buf);
	}
	~String() { delete[] buf; }
	Size_type size()const { return length; }
	char at(Size_type i)const { return buf[i]; }

	void append(const char* s) {
		int tlength = length += strlen(s);
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

	const String& operator=(const String& arg)  //대입류는 무조건 이형식
	{
		//if (*this == arg)
			delete[] buf;
		length = arg.length;

		buf = new char[length + 1];
		strcpy_s(buf, length + 1, arg.buf);
		return *this;
	}
	const String operator+(const String& arg) const
	{
		int tlength = length + arg.length;
		char* t = new char[tlength + 1];
		strcpy_s(t, length + 1, buf);
		strcat_s(t, tlength + 1, arg.buf);

		return String(t);

	}
	String operator+=(const String& arg)
	{
		*this = *this + arg;
		return *this;

	}
	String operator*(const int s)
	{
		for (int i = 1; i < s; ++i)
		{
			*this = *this + *this;
		}
		return *this;
	}
	bool operator==(const String& s)
	{
		if (strcmp(buf, s.buf) == true)
			return true;
		else
			return false;
	}
	bool operator!=(const String& s)
	{
		return !(*this == s);
	}
	char at(int i)const { return buf[i]; }		

};
int main()
{
	String s1("ABC");
	String s2("DEF");

	String s3 = s1 + s2;

	cout << s3.c_str() << endl;


	//for (String::Size_type i = 0; i < s.size(); ++i)
	//	cout << s.at(i) << " ";
	//cout << endl;

	//s.append("ABC");
	//cout << s.c_str() << endl;

	//s.assign("ABC");
	//cout << s.c_str() << endl;

	//String s2 = s;
	//cout << s3.c_str() << endl;
}