#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Professor : public Person
{
	string position;
public:
	Professor(const string& n = "", const string& p = "",
		const string& pos = "");
	void Print(ostream& out = cout)const;
	void Write(ostream& out) const;
};

