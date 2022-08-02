#include "Student.h"

Student::Student(const string& n, const string& p, int g):
	Person(n,p), grade(g) { }
void Student::Print(ostream out)const
{
	out << "name:" << name << ", " << "phone:" << phone << 
		", "<< "grade:" << grade << endl;
}