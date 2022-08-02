#pragma once
#include "vector.h"
#include "Person.h"

class TelPhoneBook
{
	Vector<Person*> phoneList;
	string FileName;
public:
	TelPhoneBook(const string& fn = "telphonebook.ati");
	~TelPhoneBook();
	void AddTel();
	void PrintTel()const;
	void SearchTel()const;
	void RemoveTel();
	void WriteTextTel()const;
};
