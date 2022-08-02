#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
	string name;
	string phone;
public:
	Person(const string& n = "", const string& p = "");
	virtual ~Person();
	virtual void Print(ostream& out = cout)const;
	const string& GetName()const;
	const string& GetPhone()const;
};
