#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person(const string& n, const string& p, const string& a, const string& e) :name(n), phone(p), age(a), gender(e)
{
}
Person::~Person(){ }
void Person::Print(ostream& out)const
{
	out << "name: " << name << ", " << "phone: " << phone << ", " << "age: " << age << ", " << "gender: " << gender << endl;
}
const string& Person::GetName()const
{
	return name;
}
const string& Person::GetPhone()const
{
	return phone;
}
const string& Person::GetAge()const
{
	return age;
}
const string& Person::GetGender()const
{
	return gender;
}