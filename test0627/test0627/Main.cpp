#include <iostream>
#include <string>
using namespace std;
class Age
{
private:
	int year;
	int month;
public:
	Age(int _year = 0, int _month = 0) : year(_year), month(_month)
	{
	}
	int GetYear() { return year; }
	int GetMonth() { return month; }
	void PrintAge()
	{
		cout << year << "�� " << month << "���� " << endl;
	}
};
int CompareAge(Age n1, Age n2)
{
	return 0;
}
class Animal {
private:
	string name;
	Age age;
	bool gender;
	string type;
public:
	Animal(string _type, string _name, Age _age) :type(_type), name(_name), age(_age)
	{

	}
	void PrintInfo()
	{
		cout << type << " " << name << " " << age.GetYear() << "�� " << age.GetMonth() << "����"  << endl;
	}
};
int main()
{
	Animal n1("������", "�ǻ�", Age(2,5));
	n1.PrintInfo();
	Animal n2 ("�����", "����", Age(3,6));
	n2.PrintInfo();
}
//#include <iostream>
//
//using namespace std;
//class Animal
//{
//private:
//	string name;
//	string gender;
//	string type;
//	int age;
//	int year;
//	int month;
//public:
//	
//	Animal();
//	void show_info();
//	void set_animal(int _age, int _year, int _month) 
//	{
//		age = _age;
//		year = _year;
//		month = _month;
//	}
//
//	void PrintInfo(Animal* name, int year, int month ) 
//	{
//		
//	}
//};
//
//int CompareAge() {
//
//	for (int i = 0; i < std::min(string_length, str.string_length); i++) 
//	{
//		if (string_content[i] > str.string_content[i])
//			return 1;
//
//		else if (string_content[i] < str.string_content[i])
//			return -1;
//	}
//}
//int main()
//{
//	Animal Animal1(1, 2021, 3);
//	Animal Animal2(2, 2022, 1);
//
//	Animal1.PrintInfo();
//	Animal2.PrintInfo();
//}
