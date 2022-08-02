#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
	string name;
	string phone;
	string age;
	string gender;
public:
	Person(const string& n = "", const string& p = "", const string& a = "", const string& e = "");
	virtual ~Person();
	virtual void Print(ostream& out = cout)const;
	const string& GetName()const;
	const string& GetPhone()const;
	const string& GetAge()const;
	const string& GetGender()const;
};
