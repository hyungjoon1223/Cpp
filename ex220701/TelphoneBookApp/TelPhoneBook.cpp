#include <fstream>
#include "TelPhoneBook.h"

void TelPhoneBook::AddTel()
{
	cout << "이름 입력: ";
	char name[20];
	cin >> name;
	cout << "전화 입력: ";
	char phone[20];
	cin >> phone;
	char age[10];
	cout << "나이 입력: ";
	cin >> age;
	char gender[10];
	cout << "성별 입력: ";
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
	cout << "찾을 이름 입력: ";
	char name[20];
	cin >> name;

	for (auto& per : phoneList)
	{
		if (per->GetName() == name)
		{
			cout << "찾은 원소 : ";
			per->Print();
			break;
		}
	}
}
void TelPhoneBook::RemoveTel()
{
	cout << "삭제할 이름 입력: ";
	char name[20];
	cin >> name;

	for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
	{
		if (phoneList[i]->GetName() == name)
		{
			cout << "삭제 원소: ";
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
