#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Student : public Person
{
	int grade;
public:
	Student(const string& n = "", const string& p = "", const string& a = "", const string& e = "", int g = 0);
	void Print(ostream& out= cout)const;
};

