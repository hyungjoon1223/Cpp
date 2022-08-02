#pragma once
#include <vector>
#include "Person.h"

class TelPhoneBook
{
	std::vector<Person*> phoneList;
public:
	void AddTel();
	void PrintTel()const;
	void SearchTel()const;
	void RemoveTel();
	void WriteTextTel()const;
};
