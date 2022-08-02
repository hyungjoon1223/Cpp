#include <iostream>
#include "string.h"
using namespace std;

int main()
{
	String s("Hello!");

	for (String::Size_type i = 0; i < s.size(); ++i)
		cout << s.at(i) << " ";
	cout << endl;

	s.append("12345");
	cout << s.c_str() << endl;

	s.assign("ABC");
	cout << s.c_str() << endl;

	String s2 = s;
	cout << s2.c_str() << endl;
}