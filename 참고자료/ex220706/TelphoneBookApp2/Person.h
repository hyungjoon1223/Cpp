#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	const int S = 0;
	const int PF = 1;
protected:
	string name;
	string phone;
public:
	Person(const string& n = "", const string& p = "");
	virtual ~Person();
	virtual void Print(ostream& out = cout)const;
	virtual void Write(ostream& out)const=0;
	const string& GetName()const;
	const string& GetPhone()const;
};
