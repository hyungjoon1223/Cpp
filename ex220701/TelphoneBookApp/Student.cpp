#include "Student.h"

Student::Student(const string& n, const string& p, const string& a, const string& e, int g):
	Person(n,p,a,e), grade(g) { }
void Student::Print(ostream& out)const
{
	out << "name:" << name << ", " << "phone:" << phone << 
		", "<< "age: "<< age << ", " << "gender: " << gender  << ", " << "grade: " << grade << endl;
}