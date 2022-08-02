#include <fstream>
#include "TelPhoneBook.h"

void TelPhoneBook::AddTel()
{
	cout << "�̸� �Է�: ";
	char name[20];
	cin >> name;
	cout << "��ȭ �Է�: ";
	char phone[20];
	cin >> phone;
	char age[10];
	cout << "���� �Է�: ";
	cin >> age;
	char gender[10];
	cout << "���� �Է�: ";
	cin >> gender;

	phoneList.push_back(new Person(name, phone, age, gender));
}
void TelPhoneBook::PrintTel()const
{
	for (auto& per : phoneList)
	{
		per->Print();
	}
}
void TelPhoneBook::SearchTel()const
{
	cout << "ã�� �̸� �Է�: ";
	char name[20];
	cin >> name;

	for (auto& per : phoneList)
	{
		if (per->GetName() == name)
		{
			cout << "ã�� ���� : ";
			per->Print();
			break;
		}
	}
}
void TelPhoneBook::RemoveTel()
{
	cout << "������ �̸� �Է�: ";
	char name[20];
	cin >> name;

	for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
	{
		if (phoneList[i]->GetName() == name)
		{
			cout << "���� ����: ";
			phoneList[i]->Print();
			phoneList.erase(phoneList.begin() + i);
			break;
		}
	}
}
void TelPhoneBook::WriteTextTel()const
{
	ofstream fout("phonebook.txt");
	for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
	{
		fout << "[" << i << "]: ";
		phoneList[i]->Print(fout);
	}
}
