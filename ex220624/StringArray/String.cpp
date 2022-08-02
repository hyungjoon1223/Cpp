#include <cstring>
#include "String.h"


String::String(const char* s) :buf(nullptr), length(0)
{
	length = strlen(s);
	buf = new char[length + 1];
	strcpy_s(buf, length + 1, s);
}
String::String(const String& arg) :buf(nullptr), length(arg.length)
{
	buf = new char[length + 1];
	strcpy_s(buf, length + 1, arg.buf);
}

String::~String() { delete[] buf; }
String::Size_type String::size() const { return length; }
char String::at(Size_type i) const { return buf[i]; }
void String::append(const char* s)
{
	int tlength = length + strlen(s);
	char* t = new char[tlength + 1];
	strcpy_s(t, length + 1, buf);
	strcat_s(t, tlength + 1, s);

	delete[] buf;
	buf = t;
	length = tlength;
}
void String::assign(const char* s)
{
	delete[] buf;
	length = strlen(s);
	buf = new char[length + 1];
	strcpy_s(buf, length + 1, s);
}
const char* String::c_str() const { return buf; }