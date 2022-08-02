#include "Student.h"

Student::Student(const string& n, const string& p, int g):
	Person(n,p), grade(g) { }
void Student::Print(ostream& out)const
{
	out << "name:" << name << ", " << "phone:" << phone << 
		", "<< "grade:" << grade << endl;
}
void Student::Write(ostream& out) const
{
	int type = Person::S;
	out.write((char*)&type, sizeof(int));

	int slen = name.size() + 1;
	out.write((char*)&slen, sizeof(int));
	out.write(name.c_str(), slen);

	slen = phone.size() + 1;
	out.write((char*)&slen, sizeof(int));
	out.write(phone.c_str(), slen);   //Á÷·ÄÈ­

	out.write((char*)&grade, sizeof(int));
}