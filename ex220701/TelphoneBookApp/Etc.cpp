#include "Etc.h"

Etc::Etc(const string& n, const string& p, const string& a, const string&  e,const string& pos):Person(n, p, a, e), position(pos) { }
void Etc::Print(ostream& out)const
{
	out << "name: " << name << ", " << "phone: " << phone <<  ", " << "age: "<< age << ", " <<"gender: " << gender << ", "<< "position: " << position << endl;
}