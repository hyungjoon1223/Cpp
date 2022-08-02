#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Etc : public Person
{
	string position;
public:
	Etc(const string& n = "", const string& p = "", const string& a = "", const string& e = "",
		const string& pos = "");
	void Print(ostream& out = cout)const;
};

