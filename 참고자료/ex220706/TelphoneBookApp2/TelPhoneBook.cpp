#include <fstream>
#include <conio.h>
#include "Student.h"
#include "TelPhoneBook.h"
#include "Util.h"
#include "Professor.h"
TelPhoneBook::TelPhoneBook(const string& fn) :FileName(fn)
{
	ifstream ifs(FileName, ios::binary);

	int countData = 0;
	// header���� ����ϴ� ��
	ifs.read((char*)&countData, sizeof(int));

	//body
	for (int i = 0; i < countData; ++i)
	{
		int type = 0;
		ifs.read((char*)&type, sizeof(int));

		Person* p;
		switch (type)
		{
		case 0:    //Person::S
			p = new Student();
			break;
		case 1:    //Person::PF
			p = new Professor();
			break;
		}
//		//p->Read(ifs);
//		phoneList.push_back(p);
//	}
//}
//		int slen;
//		ifs.read((char*)&slen, sizeof(int));
//		char name[20];
//		ifs.read(name, slen);
//	
//		ifs.read((char*)&slen, sizeof(int));
//		char phone[20];
//		ifs.read(phone, slen);
//
//		// ����Ʈ �迭�� ��ü�� �����ϴ� �۾��� ������ȭ ���θ�
//		phoneList.push_back(new Person(name, phone));
//	}
//}
TelPhoneBook::~TelPhoneBook()
{
	ofstream ofs(FileName, ios::binary);
	//header
	int countData = phoneList.size();
	ofs.write((char*)&countData, sizeof(int));
	//body
	for (int i = 0; i < phoneList.size(); ++i)	
		phoneList[i]->Write(ofs);	

		for (int i = 0; i < phoneList.size(); ++i)
			delete phoneList[i];
}
void TelPhoneBook::AddTel()
{
	Util::SubMenu();
	char c = _getch();

	cout << "�̸� �Է�: ";
	char name[20];
	cin >> name;
	cout << "��ȭ �Է�: ";
	char phone[20];
	cin >> phone;
	switch (c)
	{
	case '1':
	{
		cout << "�г� �Է� : ";
		int grade = 0;
		cin >> grade;

		phoneList.push_back(new Student(name, phone, grade));
	}
		break;
	case '2':
	{
		cout << "���� �Է� : ";
		string position = "";
		cin >> position;
		
		phoneList.push_back(new Professor(name, phone, position));
	}
		break;
	default:
		break;
	}
}
void TelPhoneBook::PrintTel()const
{
	for(Vector<Person*>::const_iterator iter = phoneList.cbegin();
		iter != phoneList.cend(); ++iter)
	{
		(*iter)->Print();
	}
}
void TelPhoneBook::SearchTel()const
{
	cout << "ã�� �̸� �Է�:";
	char name[20];
	cin >> name;

	for (Vector<Person*>::const_iterator iter = phoneList.cbegin();
		iter != phoneList.cend(); ++iter)
	{
		if ((*iter)->GetName() == name)
		{
			cout << "ã�� ���� : ";
			(*iter)->Print();
			break;
		}
	}
}
void TelPhoneBook::RemoveTel()
{
	cout << "������ �̸� �Է�:";
	char name[20];
	cin >> name;

	for (int i = 0 ; i < phoneList.size(); ++i)
	{
		if (phoneList[i]->GetName() == name)
		{
			cout << "���� ����: ";
			phoneList[i]->Print();
			delete phoneList[i];
			phoneList.erase(phoneList.begin() + i);
			break;
		}
	}
}
void TelPhoneBook::WriteTextTel()const
{
	ofstream fout("phonebook.txt");
	for (int i = 0; i < phoneList.size(); ++i)
	{
		fout << "[" << i << "]: ";
		phoneList[i]->Print(fout);
	}
}
