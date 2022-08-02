#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

class Person
{
	string name;
	string phone;
public:
	Person(const string& n = "", const string& p = "") :name(n), phone(p)
	{
	}
	void Print(ostream& out = cout)const
	{
		out << "name:" << name << ", " << "phone:" << phone << endl;
	}
	const string& GetName()const
	{
		return name;
	}
	const string& GetPhone()const
	{
		return phone;
	}
};
class TelPhoneBook
{
	vector<Person> phoneList;
public:
	void AddTel()
	{
		cout << "이름 입력: ";
		char name[20];
		cin >> name;
		cout << "전화 입력: ";
		char phone[20];
		cin >> phone;

		phoneList.push_back(Person(name, phone));
	}
	void PrintTel()const
	{
		for (auto& per : phoneList)
		{
			per.Print();
		}
	}
	void SearchTel()const
	{
		cout << "찾을 이름 입력:";
		char name[20];
		cin >> name;

		for (auto& per : phoneList)
		{
			if (per.GetName() == name)
			{
				cout << "찾은 원소 : ";
				per.Print();
				break;
			}
		}
	}
	void RemoveTel()
	{
		cout << "삭제할 이름 입력:";
		char name[20];
		cin >> name;

		for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
		{
			if (phoneList[i].GetName() == name)
			{
				cout << "삭제 원소: ";
				phoneList[i].Print();
				phoneList.erase(phoneList.begin() + i);
				break;
			}
		}
	}
	void WriteTextTel()const
	{
		ofstream fout("phonebook.txt");
		for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
		{
			fout << "[" << i << "]: ";
			phoneList[i].Print(fout);
		}
	}
};
class Util
{
public:
	static void Menu()
	{
		cout << "1. 전화 등록" << endl;
		cout << "2. 전화 번호 출력" << endl;
		cout << "3. 전화 번호 검색" << endl;
		cout << "4. 전화 번호 삭제" << endl;
		cout << "5. 전화 번호 텍스트 파일 출력" << endl;
		cout << "0. 프로그램 종료" << endl;
		cout << endl;
	}
};
int main()
{
	TelPhoneBook tpb;
	bool run = true;

	while (run)
	{
		Util::Menu();
		switch (_getch())
		{
		case '1':
			tpb.AddTel();
			break;
		case '2':
			tpb.PrintTel();
			break;
		case '3':
			tpb.SearchTel();
			break;
		case '4':
			tpb.RemoveTel();
			break;
		case '5':
			tpb.WriteTextTel();
			break;
		case '0':
			run = false;
			break;
		default:
			break;
		}
	}	
}

//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//using namespace std;
//
//class Person
//{
//	string name;
//	string phone;
//public:
//	Person(const string& n = "", const string& p = ""):name(n),phone(p)
//	{
//	}
//	void Print(ostream& out = cout)const
//	{
//		out << "name:" << name << ", " << "phone:" << phone << endl;
//	}
//	const string& GetName()const
//	{
//		return name;
//	}
//	const string& GetPhone()const
//	{
//		return phone;
//	}
//};
//class TelPhoneBook
//{
//	vector<Person> phoneList;
//public:
//	void AddTel()
//	{
//		cout << "이름 입력: ";
//		char name[20];
//		cin >> name;
//		cout << "전화 입력: ";
//		char phone[20];
//		cin >> phone;
//
//		phoneList.push_back(Person(name, phone));
//	}
//	void PrintTel()const
//	{
//		for (auto& per : phoneList)
//		{
//			per.Print();
//		}
//	}
//	void SearchTel()const
//	{
//		cout << "찾을 이름 입력:";
//		char name[20];
//		cin >> name;
//
//		for (auto& per : phoneList)
//		{
//			if (per.GetName() == name)
//			{
//				cout << "찾은 원소 : ";
//				per.Print();
//				break;
//			}
//		}
//	}
//	void RemoveTel()
//	{
//		cout << "삭제할 이름 입력:";
//		char name[20];
//		cin >> name;
//
//		for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
//		{
//			if (phoneList[i].GetName() == name)
//			{
//				cout << "삭제 원소: ";
//				phoneList[i].Print();
//				phoneList.erase(phoneList.begin() + i);
//				break;
//			}
//		}
//	}
//	void WriteTextTel()const
//	{
//		ofstream fout("phonebook.txt");
//		for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
//		{
//			fout << "[" << i << "]: ";
//			phoneList[i].Print(fout);
//		}
//	}
//};
//int main()
//{
//	TelPhoneBook tpb;
//
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.PrintTel();
//	tpb.SearchTel();
//	tpb.RemoveTel();
//	tpb.WriteTextTel();
//	tpb.PrintTel();
//}

//#include <iostream>
//#include <vector>
//#include <fstream>
//using namespace std;
//
//class Person
//{
//	char* name;
//	char* phone;
//private:
//	void _copy(const char* n, const char* p)
//	{
//		name = new char[strlen(n) + 1];
//		phone = new char[strlen(p) + 1];
//		strcpy_s(name, strlen(n) + 1, n);
//		strcpy_s(phone, strlen(p) + 1, p);
//	}
//public:
//	Person(const char* n = "", const char* p = "")
//	{
//		_copy(n, p);
//	}
//	Person(const Person& arg)
//	{
//		_copy(arg.name, arg.phone);
//	}
//	~Person() {
//		delete[] name;
//		delete[] phone;
//	}
//	void Print(ostream& out = cout)const
//	{
//		out << "name:" << name << ", " << "phone:" << phone << endl;
//	}
//	const char* GetName()const
//	{
//		return name;
//	}
//	const char* GetPhone()const
//	{
//		return phone;
//	}
//	const Person& operator=(const Person& arg)
//	{
//		if (this == &arg)
//			return *this;
//
//		delete[]name;
//		delete[]phone;
//		_copy(arg.name, arg.phone);
//
//		return *this;
//	}
//};
//class TelPhoneBook
//{
//	vector<Person> phoneList;
//public:
//	void AddTel()
//	{
//		cout << "이름 입력: ";
//		char name[20];
//		cin >> name;
//		cout << "전화 입력: ";
//		char phone[20];
//		cin >> phone;
//
//		phoneList.push_back(Person(name, phone));
//	}
//	void PrintTel()const
//	{
//		for (auto& per : phoneList)
//		{
//			per.Print();
//		}
//	}
//	void SearchTel()const
//	{
//		cout << "찾을 이름 입력:";
//		char name[20];
//		cin >> name;
//
//		for (auto& per : phoneList)
//		{
//			if (strcmp(per.GetName(), name) == 0)
//			{
//				cout << "찾은 원소 : ";
//				per.Print();
//				break;
//			}
//		}
//	}
//	void RemoveTel()
//	{
//		cout << "삭제할 이름 입력:";
//		char name[20];
//		cin >> name;
//
//		for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
//		{
//			if (strcmp(phoneList[i].GetName(), name) == 0)
//			{
//				cout << "삭제 원소: ";
//				phoneList[i].Print();
//				phoneList.erase(phoneList.begin() + i);
//				break;
//			}
//		}
//	}
//	void WriteTextTel()const
//	{
//		ofstream fout("phonebook.txt");
//		for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
//		{
//			fout << "[" << i << "]: ";
//			phoneList[i].Print(fout);
//		}
//	}
//};
//int main()
//{
//	TelPhoneBook tpb;
//
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.PrintTel();
//	tpb.SearchTel();
//	tpb.RemoveTel();
//	tpb.WriteTextTel();
//	tpb.PrintTel();
//}

//#include <iostream>
//#include <vector>
//#include <fstream>
//using namespace std;
//
//class Person
//{
//	char* name;
//	char* phone;
//private:
//	void _copy(const char* n, const char* p)
//	{
//		name = new char[strlen(n) + 1];
//		phone = new char[strlen(p) + 1];
//		strcpy_s(name, strlen(n) + 1, n);
//		strcpy_s(phone, strlen(p) + 1, p);
//	}
//public:
//	Person(const char* n = "", const char* p = "")
//	{
//		_copy(n, p);
//	}
//	Person(const Person& arg)
//	{
//		_copy(arg.name, arg.phone);
//	}
//	~Person() {
//		delete[] name;
//		delete[] phone;
//	}
//	void Print(ostream& out=cout)const
//	{
//		out << "name:" << name << ", " << "phone:" << phone << endl;
//	}
//	const char* GetName()const
//	{
//		return name;
//	}
//	const char* GetPhone()const
//	{
//		return phone;
//	}
//	const Person& operator=(const Person& arg)
//	{
//		if (this == &arg)
//			return *this;
//
//		delete[]name;
//		delete[]phone;
//		_copy(arg.name, arg.phone);
//
//		return *this;
//	}
//};
//class TelPhoneBook
//{
//	vector<Person> phoneList;
//public:
//	void AddTel()
//	{
//		cout << "이름 입력: ";
//		char name[20];
//		cin >> name;
//		cout << "전화 입력: ";
//		char phone[20];
//		cin >> phone;
//
//		phoneList.push_back(Person(name, phone));
//	}
//	void PrintTel()const
//	{
//		for (auto& per : phoneList)
//		{
//			per.Print();
//		}
//	}
//	void SearchTel()const
//	{
//		cout << "찾을 이름 입력:";
//		char name[20];
//		cin >> name;
//
//		for (auto& per : phoneList)
//		{
//			if (strcmp(per.GetName(), name) == 0)
//			{
//				cout << "찾은 원소 : ";
//				per.Print();
//				break;
//			}
//		}
//	}
//	void RemoveTel()
//	{
//		cout << "삭제할 이름 입력:";
//		char name[20];
//		cin >> name;
//
//		for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
//		{
//			if (strcmp(phoneList[i].GetName(), name) == 0)
//			{
//				cout << "삭제 원소: ";
//				phoneList[i].Print();
//				phoneList.erase(phoneList.begin() + i);
//				break;
//			}
//		}
//	}
//	void WriteTextTel()const
//	{
//		ofstream fout("phonebook.txt");
//		for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
//		{
//			fout << "[" << i << "]: ";
//			phoneList[i].Print(fout);
//		}
//	}
//};
//int main()
//{
//	TelPhoneBook tpb;
//
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.PrintTel();
//	tpb.SearchTel();
//	tpb.RemoveTel();
//	tpb.WriteTextTel();
//	tpb.PrintTel();
//}

//#include <iostream>
//#include <fstream>
//using namespace std;
//int main()
//{
//	ofstream fout("test.txt");
//	int arr[10] = { 10,20,30,40,50 };
//
//	for (int i = 0; i < 10; ++i)
//		fout << "[" << i << "]: " << arr[i] << endl;
//
//	fout.close();
//}
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Person
//{
//	char* name;
//	char* phone;
//private:
//	void _copy(const char* n, const char* p)
//	{
//		name = new char[strlen(n) + 1];
//		phone = new char[strlen(p) + 1];
//		strcpy_s(name, strlen(n) + 1, n);
//		strcpy_s(phone, strlen(p) + 1, p);
//	}
//public:
//	Person(const char* n = "", const char* p = "")
//	{
//		_copy(n, p);
//	}
//	Person(const Person& arg)
//	{
//		_copy(arg.name, arg.phone);
//	}
//	~Person() {
//		delete[] name;
//		delete[] phone;
//	}
//	void Print()const
//	{
//		cout << "name:" << name << ", " << "phone:" << phone << endl;
//	}
//	const char* GetName()const
//	{
//		return name;
//	}
//	const char* GetPhone()const
//	{
//		return phone;
//	}
//	const Person& operator=(const Person& arg)
//	{
//		if (this == &arg)
//			return *this;
//
//		delete[]name;
//		delete[]phone;
//		_copy(arg.name, arg.phone);
//
//		return *this;
//	}
//};
//class TelPhoneBook
//{
//	vector<Person> phoneList;
//public:
//	void AddTel()
//	{
//		cout << "이름 입력: ";
//		char name[20];
//		cin >> name;
//		cout << "전화 입력: ";
//		char phone[20];
//		cin >> phone;
//
//		phoneList.push_back(Person(name, phone));
//	}
//	void PrintTel()const
//	{
//		for (auto& per : phoneList)
//		{
//			per.Print();
//		}
//	}
//	void SearchTel()const
//	{
//		cout << "찾을 이름 입력:";
//		char name[20];
//		cin >> name;
//
//		for (auto& per : phoneList)
//		{
//			if (strcmp(per.GetName(), name) == 0)
//			{
//				cout << "찾은 원소 : ";
//				per.Print();
//				break;
//			}
//		}
//	}
//	void RemoveTel()
//	{
//		cout << "삭제할 이름 입력:";
//		char name[20];
//		cin >> name;
//
//		for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
//		{
//			if (strcmp(phoneList[i].GetName(), name) == 0)
//			{
//				cout << "삭제 원소: ";
//				phoneList[i].Print();
//				phoneList.erase(phoneList.begin() + i);
//				break;
//			}
//		}
//	}
//	void WriteTextTel()const
//	{
//
//	}
//};
//int main()
//{
//	TelPhoneBook tpb;
//
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.PrintTel();
//	tpb.SearchTel();
//	tpb.RemoveTel();
//	tpb.WriteTextTel();
//	tpb.PrintTel();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Person
//{
//	char* name;
//	char* phone;
//private:
//	void _copy(const char* n, const char* p)
//	{
//		name = new char[strlen(n) + 1];
//		phone = new char[strlen(p) + 1];
//		strcpy_s(name, strlen(n) + 1, n);
//		strcpy_s(phone, strlen(p) + 1, p);
//	}
//public:
//	Person(const char* n = "", const char* p = "")
//	{
//		_copy(n, p);
//	}
//	Person(const Person& arg)
//	{
//		_copy(arg.name, arg.phone);
//	}
//	~Person() {
//		delete[] name;
//		delete[] phone;
//	}
//	void Print()const
//	{
//		cout << "name:" << name << ", " << "phone:" << phone << endl;
//	}
//	const char* GetName()const
//	{
//		return name;
//	}
//	const char* GetPhone()const
//	{
//		return phone;
//	}
//	const Person& operator=(const Person& arg)
//	{
//		if (this == &arg)
//			return *this;
//
//		delete[]name;
//		delete[]phone;
//		_copy(arg.name, arg.phone);
//
//		return *this;
//	}
//};
//class TelPhoneBook
//{
//	vector<Person> phoneList;
//public:
//	void AddTel()
//	{
//		cout << "이름 입력: ";
//		char name[20];
//		cin >> name;
//		cout << "전화 입력: ";
//		char phone[20];
//		cin >> phone;
//
//		phoneList.push_back(Person(name, phone));
//	}
//	void PrintTel()const
//	{
//		for (auto& per : phoneList)
//		{
//			per.Print();
//		}
//	}
//	void SearchTel()const
//	{
//		cout << "찾을 이름 입력:";
//		char name[20];
//		cin >> name;
//
//		for (auto& per : phoneList)
//		{
//			if (strcmp(per.GetName(), name) == 0)
//			{
//				cout << "찾은 원소 : ";
//				per.Print();
//				break;
//			}
//		}
//	}
//	void RemoveTel()
//	{
//		cout << "삭제할 이름 입력:";
//		char name[20];
//		cin >> name;
//
//		for (vector<Person>::size_type i = 0; i < phoneList.size(); ++i)
//		{
//			if (strcmp(phoneList[i].GetName(), name) == 0)
//			{
//				cout << "삭제 원소: ";
//				phoneList[i].Print();
//				phoneList.erase(phoneList.begin() + i);
//				break;
//			}
//		}
//	}
//	void WriteTextTel()const
//	{
//
//	}
//};
//int main()
//{
//	TelPhoneBook tpb;
//
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.PrintTel();
//	tpb.SearchTel();
//	tpb.RemoveTel();
//	tpb.WriteTextTel();
//	tpb.PrintTel();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Person
//{
//	char* name;
//	char* phone;
//private:
//	void _copy(const char* n, const char* p)
//	{
//		name = new char[strlen(n) + 1];
//		phone = new char[strlen(p) + 1];
//		strcpy_s(name, strlen(n) + 1, n);
//		strcpy_s(phone, strlen(p) + 1, p);
//	}
//public:
//	Person(const char* n = "", const char* p = "")
//	{
//		_copy(n, p);
//	}
//	Person(const Person& arg)
//	{
//		_copy(arg.name, arg.phone);
//	}
//	~Person() {
//		delete[] name;
//		delete[] phone;
//	}
//	void Print()const
//	{
//		cout << "name:" << name << ", " << "phone:" << phone << endl;
//	}
//	const char* GetName()const
//	{
//		return name;
//	}
//	const char* GetPhone()const
//	{
//		return phone;
//	}
//	const Person& operator=(const Person& arg)
//	{
//		if (this == &arg)
//			return *this;
//
//		delete[]name;
//		delete[]phone;
//		_copy(arg.name, arg.phone);
//
//		return *this;
//	}
//};
//class TelPhoneBook
//{
//	vector<Person> phoneList;
//public:
//	void AddTel()
//	{
//		phoneList.push_back(Person("홍길동", "010-1234-1234"));
//	}
//	void PrintTel()const
//	{
//		for (auto& per : phoneList)
//		{
//			per.Print();
//		}
//	}
//	void SearchTel()const
//	{
//		for (auto& per : phoneList)
//		{
//			if (strcmp(per.GetName(), "홍길동") == 0)
//			{
//				cout << "찾은 원소 : ";
//				per.Print();
//				break;
//			}
//		}
//	}
//	void RemoveTel()
//	{
//		for (vector<Person>::size_type i = 0 ; i < phoneList.size(); ++i)
//		{
//			if (strcmp(phoneList[i].GetName(), "홍길동") == 0)
//			{
//				cout << "삭제 원소: ";
//				phoneList[i].Print();
//				phoneList.erase(phoneList.begin() + i);
//				break;
//			}
//		}
//	}
//	void WriteTextTel()const
//	{
//
//	}
//};
//int main()
//{
//	TelPhoneBook tpb;
//
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.PrintTel();
//	tpb.SearchTel();
//	tpb.RemoveTel();
//	tpb.WriteTextTel();
//	tpb.PrintTel();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Person
//{
//	char* name;
//	char* phone;
//private:
//	void _copy(const char* n, const char* p)
//	{
//		name = new char[strlen(n) + 1];
//		phone = new char[strlen(p) + 1];
//		strcpy_s(name, strlen(n) + 1, n);
//		strcpy_s(phone, strlen(p) + 1, p);
//	}
//public:
//	Person(const char* n = "", const char* p = "")
//	{
//		_copy(n, p);
//	}
//	Person(const Person& arg)
//	{
//		_copy(arg.name, arg.phone);
//	}
//	~Person() {
//		delete[] name;
//		delete[] phone;
//	}
//	void Print()const
//	{
//		cout << "name:" << name << ", " << "phone:" << phone << endl;
//	}
//	const char* GetName()const
//	{
//		return name;
//	}
//	const char* GetPhone()const
//	{
//		return phone;
//	}
//	const Person& operator=(const Person& arg)
//	{
//		if (this == &arg)
//			return *this;
//
//		delete[]name;
//		delete[]phone;
//		_copy(arg.name, arg.phone);
//
//		return *this;
//	}
//};
//class TelPhoneBook
//{
//	vector<Person> phoneList;
//public:
//	void AddTel()
//	{
//		phoneList.push_back(Person("홍길동", "010-1234-1234"));
//	}
//	void PrintTel()const
//	{
//		for (auto& per : phoneList)
//		{
//			per.Print();
//		}
//	}
//	void SearchTel()const
//	{
//
//	}
//	void RemoveTel()
//	{
//
//	}
//	void WriteTextTel()const
//	{
//
//	}
//};
//int main()
//{
//	TelPhoneBook tpb;
//
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.AddTel();
//	tpb.PrintTel();
//	tpb.SearchTel();
//	tpb.RemoveTel();
//	tpb.WriteTextTel();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Person
//{
//	char* name;
//	char* phone;
//private:
//	void _copy(const char* n, const char* p)
//	{
//		name = new char[strlen(n) + 1];
//		phone = new char[strlen(p) + 1];
//		strcpy_s(name, strlen(n) + 1, n);
//		strcpy_s(phone, strlen(p) + 1, p);
//	}
//public:
//	Person(const char* n = "", const char* p = "")
//	{
//		_copy(n, p);
//	}
//	Person(const Person& arg)
//	{
//		_copy(arg.name, arg.phone);
//	}
//	~Person() {
//		delete[] name;
//		delete[] phone;
//	}
//	void Print()const
//	{
//		cout << "name:" << name << ", " << "phone:" << phone << endl;
//	}
//	const char* GetName()const
//	{
//		return name;
//	}
//	const char* GetPhone()const
//	{
//		return phone;
//	}
//	const Person& operator=(const Person& arg)
//	{
//		if (this == &arg)
//			return *this;
//
//		delete[]name;
//		delete[]phone;
//		_copy(arg.name, arg.phone);
//
//		return *this;
//	}
//};
//class TelPhoneBook
//{
//	vector<Person> phoneList;
//public:
//	void AddTel()
//	{
//
//	}
//	void PrintTel()const
//	{
//
//	}
//	void SearchTel()const
//	{
//
//	}
//	void RemoveTel()
//	{
//
//	}
//	void WriteTextTel()const
//	{
//
//	}
//};
//int main()
//{
//	TelPhoneBook tpb;
//
//	tpb.AddTel(); //전화 번호를 등록
//	tpb.PrintTel(); //전화 번호 출력
//	tpb.SearchTel(); //전화 검색(이름 or 전화 번호)
//	tpb.RemoveTel(); //전화 삭제(이름 or 전화 번호)
//	tpb.WriteTextTel(); //텍스트 파일의 등록 전화번호 출력
//
//	Person p1("홍길동", "010-1234-1234");
//	Person p2 = p1;
//	p2 = p1;
//
//	p1.Print();
//	p2.Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Person
//{
//	char* name;
//	char* phone;
//public:
//	Person(const char* n = "", const char* p = "")
//	{
//		name = new char[strlen(n) + 1];
//		phone = new char[strlen(p) + 1];
//		strcpy_s(name, strlen(n) + 1, n);
//		strcpy_s(phone, strlen(p) + 1, p);
//	}
//	~Person() {
//		delete[] name;
//		delete[] phone;
//	}
//	void Print()const
//	{
//		cout << "name:" << name << ", " << "phone:" << phone << endl;
//	}
//	const char* GetName()const
//	{
//		return name;
//	}
//	const char* GetPhone()const
//	{
//		return phone;
//	}
//};
//class TelPhoneBook
//{
//	vector<Person> phoneList;
//public:
//	void AddTel()
//	{
//
//	}
//	void PrintTel()const
//	{
//
//	}
//	void SearchTel()const
//	{
//
//	}
//	void RemoveTel()
//	{
//
//	}
//	void WriteTextTel()const
//	{
//
//	}
//};
//int main()
//{
//	TelPhoneBook tpb;
//
//	tpb.AddTel(); //전화 번호를 등록
//	tpb.PrintTel(); //전화 번호 출력
//	tpb.SearchTel(); //전화 검색(이름 or 전화 번호)
//	tpb.RemoveTel(); //전화 삭제(이름 or 전화 번호)
//	tpb.WriteTextTel(); //텍스트 파일의 등록 전화번호 출력
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Person
//{
//	char* name;
//	char* phone;
//public:
//	Person(const char* n = "", const char* p = "")
//	{
//		name = new char[strlen(n) + 1];
//		phone = new char[strlen(p) + 1];
//		strcpy_s(name, strlen(n) + 1, n);
//		strcpy_s(phone, strlen(p) + 1, p);
//	}
//	~Person() {
//		delete[] name;
//		delete[] phone;
//	}
//	void Print()const
//	{
//		cout << "name:" << name << ", " << "phone:" << phone << endl;
//	}
//	const char* GetName()const
//	{
//		return name;
//	}
//	const char* GetPhone()const
//	{
//		return phone;
//	}
//};
//class TelPhoneBook
//{
//	vector<Person> phoneList;
//public:
//	void AddTel()
//	{
//
//	}
//	void PrintTel()const
//	{
//
//	}
//	void SearchTel()const
//	{
//
//	}
//	void RemoveTel()
//	{
//
//	}
//	void WriteTextTel()const
//	{
//
//	}
//};
//int main()
//{
//	TelPhoneBook tpb;
//
//	tpb.AddTel(); //전화 번호를 등록
//	tpb.PrintTel(); //전화 번호 출력
//	tpb.SearchTel(); //전화 검색(이름 or 전화 번호)
//	tpb.RemoveTel(); //전화 삭제(이름 or 전화 번호)
//	tpb.WriteTextTel(); //텍스트 파일의 등록 전화번호 출력
//}

//#include <iostream>
////#include <vector>
////using namespace std;
//
//class TelPhoneBook
//{
//public:
//	void AddTel();
//	void PrintTel()const;
//	void SearchTel()const;
//	void RemoveTel();
//	void WriteTextTel()const;
//};
//int main()
//{
//	TelPhoneBook tpb;
//
//	tpb.AddTel(); //전화 번호를 등록
//	tpb.PrintTel(); //전화 번호 출력
//	tpb.SearchTel(); //전화 검색(이름 or 전화 번호)
//	tpb.RemoveTel(); //전화 삭제(이름 or 전화 번호)
//	tpb.WriteTextTel(); //텍스트 파일의 등록 전화번호 출력
//}

//#include <iostream>
//#include <vector>
//using namespace std;

//class Point
//{
//	int x, y;
//public:
//	explicit Point(int x = 0, int y = 0) :x(x), y(y) {
//		cout << "Point()" << endl;
//	}
//	Point(const Point& arg) :x(arg.x), y(arg.y) {
//		cout << "copy Point()" << endl;
//	}
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//};
//template <typename T>
//class Shared_ptr
//{
//	T* ptr;
//	int* pCount;
//public:
//	Shared_ptr(T* p = nullptr) :ptr(p), pCount(nullptr) {
//		if (ptr != nullptr)
//			pCount = new int(1);
//	}
//	Shared_ptr(const Shared_ptr& arg) :ptr(arg.ptr), pCount(arg.pCount) {
//		++* pCount;
//	}
//	~Shared_ptr() {
//		reset();
//	}
//	int use_count()const
//	{
//		if (ptr)
//			return *pCount;
//		else
//			return 0;
//	}
//	void reset()
//	{
//		if (ptr == nullptr)
//			return;
//
//		--* pCount;
//		if (*pCount == 0)
//		{
//			delete pCount;
//			delete ptr;
//			pCount = nullptr;
//			ptr = nullptr;
//		}
//	}
//	void reset(T* p)
//	{
//		reset();
//
//		ptr = p;
//		pCount = new int(1);
//	}
//	T* operator->()
//	{
//		return ptr;
//	}
//	T& operator*()
//	{
//		return *ptr;
//	}
//	const Shared_ptr& operator=(const Shared_ptr& arg)
//	{
//		if (&*this == &arg)
//			return *this;
//
//		reset();
//		ptr = arg.ptr;
//		pCount = arg.pCount;
//		++* pCount;
//
//		return *this;
//	}
//};
//int main()
//{
//	Shared_ptr<Point> p1(new Point(1, 2));
//	Shared_ptr<Point> p2(new Point(3, 4));
//
//	p1 = p2;
//	p1->Print();
//	(*p1).Print();
//	p2->Print();
//	cout << p1.use_count() << endl;
//	p1.reset(new Point(5, 5));
//	p1->Print();
//	cout << p1.use_count() << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	explicit Point(int x = 0, int y = 0) :x(x), y(y) {
//		cout << "Point()" << endl;
//	}
//	Point(const Point& arg) :x(arg.x), y(arg.y) {
//		cout << "copy Point()" << endl;
//	}
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//};
//template <typename T>
//class Shared_ptr
//{
//	T* ptr;
//	int* pCount;
//public:
//	Shared_ptr(T* p=nullptr):ptr(p),pCount(nullptr) {
//		if( ptr != nullptr)
//			pCount = new int(1);
//	}
//	Shared_ptr(const Shared_ptr& arg) :ptr(arg.ptr), pCount(arg.pCount) {
//		++* pCount;
//	}
//	~Shared_ptr() {
//		reset();
//	}
//	int use_count()const
//	{
//		if (ptr)
//			return *pCount;
//		else
//			return 0;
//	}
//	void reset()
//	{
//		if (ptr == nullptr)
//			return;
//
//		--* pCount;
//		if (*pCount == 0)
//		{
//			delete pCount;
//			delete ptr;
//			pCount = nullptr;
//			ptr = nullptr;
//		}
//	}
//	void reset(T* p)
//	{
//		reset();
//
//		ptr = p;
//		pCount = new int(1);
//	}
//	T* operator->()
//	{
//		return ptr;
//	}
//	T& operator*()
//	{
//		return *ptr;
//	}
//	const Shared_ptr& operator=(const Shared_ptr& arg)
//	{
//		if (&*this == &arg)
//			return *this;
//
//		reset();
//		ptr = arg.ptr;
//		pCount = arg.pCount;
//		++* pCount;
//
//		return *this;
//	}
//};
//int main()
//{
//	Shared_ptr<Point> p1(new Point(1, 2));
//	Shared_ptr<Point> p2(new Point(3, 4));
//
//	p1 = p2;
//	p1->Print();
//	(*p1).Print();
//	p2->Print();
//	cout << p1.use_count() << endl;
//	p1.reset(new Point(5, 5));
//	p1->Print();
//	cout << p1.use_count() << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	explicit Point(int x = 0, int y = 0) :x(x), y(y) {
//		cout << "Point()" << endl;
//	}
//	Point(const Point& arg) :x(arg.x), y(arg.y) {
//		cout << "copy Point()" << endl;
//	}
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//};
//
//class Rect
//{
//	shared_ptr<Point> ploc;
//	int width;
//	int height;
//public:
//	Rect(int x, int y, int w, int h) :ploc(nullptr), width(w), height(h)
//	{
//		ploc=shared_ptr<Point>(new Point(x, y));
//	}
//	Rect(const Rect& arg) :ploc(nullptr), width(arg.width), height(arg.height)
//	{
//		ploc = shared_ptr<Point>(new Point(*arg.ploc));
//	}
//	const Rect& operator=(const Rect& arg)
//	{
//		if (&*this == &arg)
//			return *this;
//		ploc.reset(new Point(*arg.ploc));
//		width = arg.width;
//		height = arg.height;
//
//		return *this;
//	}
//	void Print()const
//	{
//		cout << "Rect:" << ploc->GetX() << ',' << ploc->GetY() << " - " <<
//			"w:" << width << ',' << "h:" << height << endl;
//	}
//};
//int main()
//{
//	Rect r1(0, 0, 45, 60);
//	r1.Print();
//
//	Rect r2 = r1;
//	r2.Print();
//
//	r2 = r1;
//	r2.Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	explicit Point(int x = 0, int y = 0) :x(x), y(y){
//		cout << "Point()" << endl;
//	}
//	Point(const Point& arg) :x(arg.x), y(arg.y){
//		cout << "copy Point()" << endl;
//	}
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//	int GetX()const { return x; }
//	int GetY()const { return y; }
//};
//
//class Rect
//{
//	Point* ploc;
//	int width;
//	int height;
//public:
//	Rect(int x, int y, int w, int h) :ploc(nullptr), width(w), height(h)
//	{
//		ploc = new Point(x, y);
//	}
//	Rect(const Rect& arg) :ploc(nullptr), width(arg.width), height(arg.height)
//	{
//		ploc = new Point(*arg.ploc);
//	}
//	~Rect() { delete ploc; }
//	const Rect& operator=(const Rect& arg)
//	{
//		if (&*this == &arg)
//			return *this;
//		delete ploc;
//
//		ploc = new Point(*arg.ploc);
//		width = arg.width;
//		height = arg.height;
//
//		return *this;
//	}
//	void Print()const 
//	{
//		cout << "Rect:" << ploc->GetX() << ',' << ploc->GetY() << " - " <<
//			"w:" << width << ',' << "h:" << height << endl;
//	}
//};
//int main()
//{
//	Rect r1(0, 0, 45, 60);
//	r1.Print();
//
//	Rect r2 = r1;
//	r2.Print();
//
//	r2 = r1;
//	r2.Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	explicit Point(int x = 0, int y = 0) :x(x), y(y)
//	{
//		cout << "Point()" << endl;
//	}
//	Point(const Point& arg) :x(arg.x), y(arg.y)
//	{
//		cout << "copy Point()" << endl;
//	}
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//};
//int main()
//{
//	shared_ptr<Point> p1(new Point(2, 3));
//	shared_ptr<Point> p2 = p1;
//	shared_ptr<Point> p3 = p2;
//
//	weak_ptr<Point> w1 = p1;
//	weak_ptr<Point> w2 = w1;
//
//	cout << p1.use_count() << endl;
//	cout << p2.use_count() << endl;
//	cout << p3.use_count() << endl;
//	cout << w1.use_count() << endl;
//	cout << w2.use_count() << endl;
//
//	p1->Print();
//	w1.lock()->Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	explicit Point(int x = 0, int y = 0) :x(x), y(y)
//	{
//		cout << "Point()" << endl;
//	}
//	Point(const Point& arg) :x(arg.x), y(arg.y)
//	{
//		cout << "copy Point()" << endl;
//	}
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//};
//int main()
//{
//	shared_ptr<Point> p1(new Point(2, 3));
//	p1->Print();
//
//	shared_ptr<Point> p2(new Point(4, 5));
//	p2->Print();
//
//	p2.reset(new Point(1, 1));
//	p2->Print();
//
//	cout << endl;
//	p1.swap(p2);
//	p1->Print();
//	p2->Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	explicit Point(int x = 0, int y = 0) :x(x), y(y)
//	{
//		cout << "Point()" << endl;
//	}
//	Point(const Point& arg) :x(arg.x), y(arg.y)
//	{
//		cout << "copy Point()" << endl;
//	}
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//};
//int main()
//{
//	shared_ptr<Point> p1(new Point(2, 3));
//	p1->Print();
//
//	shared_ptr<Point> p2(new Point(4, 5));
//	p2->Print();
//
//	p2.reset(new Point(1, 1));
//	p2->Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	explicit Point(int x = 0, int y = 0) :x(x), y(y)
//	{
//		cout << "Point()" << endl;
//	}
//	Point(const Point& arg) :x(arg.x), y(arg.y)
//	{
//		cout << "copy Point()" << endl;
//	}
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//};
//int main()
//{
//	shared_ptr<Point> p1(new Point(2, 3));
//	p1->Print();
//
//	shared_ptr<Point> p2 = p1;
//	cout << p1.use_count() << endl;
//
//	shared_ptr<Point> p3 = p1;
//	cout << p1.use_count() << endl;
//
//	p1.reset();
//	p2.reset();
//	cout << p2.use_count() << endl;
//	p3.reset();
//	cout << p3.use_count() << endl;
//	cout << "end main()" << endl;
//}


//#include<iostream>
//#include<string>
//#include<cstring>
//using namespace std;
//class Matrix
//{
//    int* matrix;
//    int row;
//    int col;
//public:
//    explicit Matrix(int _row = 0, int _col = 0) :matrix(nullptr), row(_row), col(_col)
//    {
//        matrix = new int[_row * _col];
//        for (int i = 0; i < row; ++i)
//            for (int j = 0; j < col; ++j)
//                matrix[(col * i) + j] = 0;
//    }
//    Matrix(int _matrix[], int _row = 0, int _col = 0) :matrix(nullptr), row(_row), col(_col)
//    {
//        matrix = new int[_row * _col];
//        for (int i = 0; i < row; ++i)
//            for (int j = 0; j < col; ++j)
//                matrix[(col * i) + j] = _matrix[(col * i) + j];
//    }
//    Matrix(const Matrix& arg) :matrix(nullptr), row(arg.row), col(arg.col)
//    {
//        matrix = new int[arg.row * arg.col];
//        row = arg.row;
//        col = arg.col;
//        for (int i = 0; i < arg.row; ++i)
//            for (int j = 0; j < arg.col; ++j)
//                matrix[(arg.col * i) + j] = arg.matrix[(arg.col * i) + j];
//    }
//    ~Matrix() { cout << "~Matrix" << endl;  delete[] matrix; }
//    int* Getmatrix()const
//    {
//        return matrix;
//    }
//    int Getrow()const
//    {
//        return row;
//    }
//    int Getcol()const
//    {
//        return col;
//    }
//    int GetElement(int _row, int _col)const
//    {
//        return matrix[(col * (_row - 1)) + _col - 1];
//    }
//    void Setmatrix(int _matrix[], int size)
//    {
//
//        if (row * col != size)
//            throw 1;
//
//        for (int i = 0; i < row; ++i)
//            for (int j = 0; j < col; ++j)
//                matrix[(col * i) + j] = matrix[(col * i) + j] + _matrix[(col * i) + j];
//    }
//    void SetElement(int data, int _row, int _col)
//    {
//        if (row < _row || col < _col)
//        {
//            throw 1;
//        }
//        matrix[(col * (_row - 1)) + _col - 1] = data;
//    }
//    void Setrow(int _row)
//    {
//        row = _row;
//    }
//    void Setcol(int _col)
//    {
//        col = _col;
//    }
//    void Print()const
//    {
//        for (int i = 0; i < row; ++i)
//        {
//
//            for (int j = 0; j < col; ++j)
//            {
//                cout << matrix[(col * i) + j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//    bool operator==(const Matrix& arg)const
//    {
//        return this == &arg;
//    }
//    bool operator!=(const Matrix& arg)const
//    {
//        return !(*this == arg);
//    }
//    const Matrix& operator=(const Matrix& arg)
//    {
//        if (*this == arg)
//            return*this;
//
//        delete[] matrix;
//
//        int size = arg.col * arg.row;
//        matrix = new int[size];
//        row = arg.row;
//        col = arg.col;
//        for (int i = 0; i < arg.row; ++i)
//            for (int j = 0; j < arg.col; ++j)
//                matrix[(arg.col * i) + j] = arg.matrix[(arg.col * i) + j];
//        return *this;
//    }
//    const Matrix operator+(const Matrix& arg)
//    {
//
//        if (row == arg.row && col == arg.col)
//        {
//            for (int i = 0; i < arg.row; ++i)
//                for (int j = 0; j < arg.col; ++j)
//                    matrix[(arg.col * i) + j] = matrix[(arg.col * i) + j] + arg.matrix[(arg.col * i) + j];
//        }
//        else
//            throw 1;
//
//        return *this;
//    }
//    const Matrix operator-(const Matrix& arg)
//    {
//        if (row == arg.row && col == arg.col)
//        {
//            for (int i = 0; i < arg.row; ++i)
//                for (int j = 0; j < arg.col; ++j)
//                    matrix[(arg.col * i) + j] = matrix[(arg.col * i) + j] - arg.matrix[(arg.col * i) + j];
//        }
//        else
//            throw 1;
//        return *this;
//    }
//    const Matrix operator*(const Matrix& arg)
//    {
//        if (col == arg.row && row == arg.col)
//        {
//            int size = arg.col * row;
//            Matrix tempMatrix(row, arg.col);
//            //mtrix.matrix;
//
//            /*for (int p = 0; p < row; ++p)
//            {
//                for (int i = 0; i < arg.row; ++i)
//                {
//                    for (int j = 0; j < arg.col; ++j)
//                    {
//                        tempMatrix.matrix[(arg.col * p) + i] = tempMatrix.matrix[(arg.col * p) + i] + (matrix[(arg.col * p) + j] * arg.matrix[(arg.col * j) + i]);
//                    }
//                }
//            }*/
//
//            return tempMatrix;
//        }
//        else
//            throw 1;
//    }
//
//};
//
//int main()
//{
//    Matrix arr1(2, 1);
//    Matrix arr2(1, 2);
//    Matrix arr3(2, 2);
//
//    arr3 = arr1 * arr2;
//}
