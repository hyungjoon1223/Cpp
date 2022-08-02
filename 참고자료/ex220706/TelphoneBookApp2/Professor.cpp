#include "Professor.h"

Professor::Professor(const string& n, const string& p,
	const string& pos):Person(n,p),position(pos){ }
void Professor::Print(ostream& out)const
{
	out << "name:" << name << ", " << "phone:" << phone <<
		", " << "position:" << position << endl;
}
void Professor::Write(ostream& out)const
{
	int type = Person::PF;
	out.write((char*)&type, sizeof(int));

	int slen = name.size() + 1;
	out.write((char*)&slen, sizeof(int));
	out.write(name.c_str(), slen);

	slen = phone.size() + 1;
	out.write((char*)&slen, sizeof(int));
	out.write(phone.c_str(), slen);   //Á÷·ÄÈ­

	slen = position.size() + 1;
	out.write((char*)&position, sizeof(int));
	out.write(position.c_str(), slen);
}