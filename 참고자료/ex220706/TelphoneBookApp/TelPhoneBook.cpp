#include <fstream>
#include "TelPhoneBook.h"

TelPhoneBook::TelPhoneBook(const string& fn):FileName(fn) 
{
	ifstream ifs(FileName, ios::binary);

	int countData = 0;
	// header���� ����ϴ� ��
	ifs.read((char*)&countData, sizeof(int));

	//body
	for (int i = 0; i < countData; ++i)
	{
		int slen;
		ifs.read((char*)&slen, sizeof(int));
		char name[20];
		ifs.read(name, slen);
	
		ifs.read((char*)&slen, sizeof(int));
		char phone[20];
		ifs.read(phone, slen);

		// ����Ʈ �迭�� ��ü�� �����ϴ� �۾��� ������ȭ ���θ�
		phoneList.push_back(new Person(name, phone));
	}
}
TelPhoneBook::~TelPhoneBook()
{
	ofstream ofs(FileName, ios::binary);
	//header
	int countData = phoneList.size();
	ofs.write((char*)&countData, sizeof(int));
	//body
	for (int i = 0; i < phoneList.size(); ++i)
	{
		const string& name = phoneList[i]->GetName();
		int slen = name.size()+1;
		ofs.write((char*)&slen, sizeof(int));
		ofs.write(name.c_str(), slen);
		const string& phone = phoneList[i]->GetPhone();
		slen = phone.size() + 1;
		ofs.write((char*)&slen, sizeof(int));
		ofs.write(phone.c_str(), slen);   //����ȭ
			
		delete[] phoneList[i];
	}
}
void TelPhoneBook::AddTel()
{
	cout << "�̸� �Է�: ";
	char name[20];
	cin >> name;
	cout << "��ȭ �Է�: ";
	char phone[20];
	cin >> phone;

	phoneList.push_back(new Person(name, phone));
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
