#define _USE_MATH_DEFINES
#include <iostream>
#include <set>
#include <cmath>
using namespace std;
class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y) {}
	void Print()const { cout << x << ", " << y << endl; }
	int GetX()const { return x; }
	int GetY()const { return y; }
	int Getdistance()const { return sqrt(x * x + y * y); };
    int GetAngle()const { return; };
};
struct Compare
{
	bool operator()(const Point& a, const Point& b) const
	{
		if (a.Getdistance() < b.Getdistance())
			return true;
		else
			return false;
	}
};
int main()
{
	auto fun = [](const Point& a, const Point& b) -> bool {return a.GetX() < b.GetX(); }; //���ٽ��� �̿��� ����������Ʈ ���̹Ƿ� �������� ����Ŭ��
	set<Point, decltype(fun) > s(fun);

	s.insert(Point(2, 3));
	s.insert(Point(2, 5));
	s.insert(Point(5, 6));
	s.insert(Point(3, 4));
	s.insert(Point(1, 2));

	for (set<Point>::iterator iter = s.begin(); iter != s.end(); ++iter)
		cout << iter->GetX() << ", " << iter->GetY() << " ";
	cout << endl;
}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <conio.h>
//using namespace std;
//
//class Person
//{
//    string name;
//    string day;
//    string month;
//    string year;
//public:
//	Person(const string& n = "", const string& y = "", const string& m = "", const string& d = "") :name(n), year(y), month(m), day(d)
//	{
//	}
//	void Print(ostream& out = cout)const
//	{
//		out << "name:" << name << ", " << "������� : " << year <<" - " << month  << " - " << day << endl;
//	}
//	const string& GetName()const
//	{
//		return name;
//	}
//	const string& GetYear()const
//	{
//		return year;
//	}
//	const string& GetMonth()const
//	{
//		return month;
//	}
//	const string& GetDay()const
//	{
//		return day;
//	}
//};
//struct Compare
//{
//	bool operator()(const Person& a, const Person& b)const
//	{
//		if (a.GetYear() < b.GetYear())
//		{
//			return true;
//		}
//		else if (a.GetYear() > b.GetYear())
//		{
//			return false;
//		}
//		else 
//		{
//			if (a.GetMonth() < b.GetMonth())
//				return true;
//			else if (a.GetMonth() > b.GetMonth())
//				return false;
//			else
//			{
//				if (a.GetDay() < b.GetDay())
//					return true;
//				else if (a.GetDay() > b.GetDay())
//					return false;
//			}
//		}
//	}
//};
//class Birth
//{
//	vector<Person> Birth;
//public:
//	void AddBirth()
//	{
//		cout << "�̸� �Է�: ";
//		char name[20];
//		cin >> name;
//		cout << "�� �Է�: ";
//		char year[20];
//		cin >> year;
//		cout << "�� �Է�: ";
//		char month[20];
//		cin >> month;
//		cout << "�� �Է�: ";
//		char day[20];
//		cin >> day;
//
//		Birth.push_back(Person(name, year, month, day));
//	}
//	void PrintBirth()const
//	{
//		for (auto& per : Birth)
//		{
//			per.Print();
//		}
//	}
//	void PrintSort()
//	{
//		sort(Birth.begin(), Birth.end(), Compare());
//	}
//};
//class Util
//{
//public:
//	static void Menu()
//	{
//		cout << "==========================================" << endl;
//		cout << "1. ���ϵ�� (ex: ȫ�浿 99 11 01)" << endl;
//		cout << "2. ���� ���" << endl;
//		cout << "3. ���� sort" << endl;
//		cout << "0. ���α׷� ����" << endl;
//		cout << "==========================================" << endl;
//		cout << endl;
//	}
//};
//int main()
//{
//	vector<Person> v;
//	Birth b;
//	bool run = true;
//	while (run)
//	{
//		Util::Menu();
//		switch (_getch())
//		{
//		case '1':
//			b.AddBirth();
//			break;
//		case '2':
//			b.PrintBirth();
//			break;
//		case '3':
//			b.PrintSort();
//			break;
//		case '0':
//			run = false;
//			break;
//		default:
//			break;
//		}
//	}
//}
