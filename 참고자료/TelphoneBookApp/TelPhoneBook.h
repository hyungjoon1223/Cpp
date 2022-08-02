#pragma once
#include "vector.h"
#include "Person.h"

class TelPhoneBook
{
	Vector<Person*> phoneList;
public:
	void AddTel();
	void PrintTel()const;
	void SearchTel()const;
	void RemoveTel();
	void WriteTextTel()const;
};
