#include <iostream>
#include <vector>
using namespace std;
struct IPoints
{
	virtual int GetPoints()const = 0;
};
class Point
{
	int x, y;
public:
	Point(int x = 0, int y = 0) :x(x), y(y) { }
	int GetX() const { return x; }
	int GetY() const { return y; }
};
class Shape  //�߻�Ŭ����
{
protected:
	Point start;
public:
	Shape(const Point& pt) :start(pt) {}
	virtual void Draw()const = 0;
	virtual ~Shape() { }
};
class Rect : public Shape, public IPoints   //���� ����̶���ϰ� �ڴ� �����̶�� �θ���
{
	int width;
	int height;
public:
	Rect(const Point& pt = Point(), int w = 0, int h = 0) :Shape(pt), width(w), height(h) {}
	void Draw()const {
		cout << "Rect : " << start.GetX() << ", " << start.GetY() << " - "
			<< "w : " << width << ", " << "h : " << height << endl;
	}
	int GetPoints()const { return 4; }
};
class Circle : public Shape
{
	int radius;
public:
	Circle(const Point& pt = Point(), int r = 0) : Shape(pt), radius(r) {}
	void Draw()const {
		cout << "Circle : " << start.GetX() << ", " << start.GetY() << " - "
			<< "r : " << radius << endl;

	}
};
class Polygon : public Shape, public IPoints
{
	vector<Point> list;
public:
	Polygon(const Point& pt = Point(), int points = 0) :Shape(pt)
	{
		list.push_back(start);
		for (int i = 0; i < points; ++i)
			list.push_back(Point(i + 1, i + 1));
	}
	void Draw()const {
		cout << "Polygon : ";
		for (const auto& pt : list)
			cout << pt.GetX() << "," << pt.GetY() << " ";
		cout << endl;

	}
	int GetPoints()const { return list.size(); }
};
class Fork : public IPoints
{
public:
	int GetPoints()const { return 5; }
};
int main()
{

	Shape* sarr[3] = { new Rect(Point(0, 0), 100, 150),
	new Circle(Point(5, 5), 12),
	new Polygon(Point(0, 15), 5) };
	Fork f;

	for (auto shape : sarr)
		shape->Draw();

	cout << endl;

	IPoints* points[3] = { (Rect*)sarr[0], (Polygon*)sarr[2], &f };

	for (auto x : points)
		cout << "point count : " << x->GetPoints() << endl;

	for (auto shape : sarr)
		delete shape;
}

//#include <iostream>
//#include <vector>
//using namespace std;
//struct IPoints
//{
//	virtual int GetPoints()const = 0;
//};
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) { }
//	int GetX() const { return x; }
//	int GetY() const { return y; }
//};
//class Shape  //�߻�Ŭ����
//{
//protected:
//	Point start;
//public:
//	Shape(const Point& pt) :start(pt) {}
//	virtual void Draw()const = 0;
//	virtual ~Shape() { }
//};
//class Rect : public Shape, public IPoints   //���� ����̶���ϰ� �ڴ� �����̶�� �θ���
//{
//	int width;
//	int height;
//public:
//	Rect(const Point& pt = Point(), int w = 0, int h = 0) :Shape(pt), width(w), height(h) {}
//	void Draw()const {
//		cout << "Rect : " << start.GetX() << ", " << start.GetY() << " - "
//			<< "w : " << width << ", " << "h : " << height << endl;
//	}
//	int GetPoints()const { return 4; }
//};
//class Circle : public Shape
//{
//	int radius;
//public:
//	Circle(const Point& pt = Point(), int r = 0) : Shape(pt), radius(r) {}
//	void Draw()const {
//		cout << "Circle : " << start.GetX() << ", " << start.GetY() << " - "
//			<< "r : " << radius << endl;
//
//	}
//};
//class Polygon : public Shape, public IPoints
//{
//	vector<Point> list;
//public:
//	Polygon(const Point& pt = Point(), int points = 0) :Shape(pt)
//	{
//		list.push_back(start);
//		for (int i = 0; i < points; ++i)
//			list.push_back(Point(i + 1, i + 1));
//	}
//	void Draw()const {
//		cout << "Polygon : ";
//		for (const auto& pt : list)
//			cout << pt.GetX() << "," << pt.GetY() << " ";
//		cout << endl;
//
//	}
//	int GetPoints()const { return list.size(); }
//};
//class Fork : public IPoints
//{
//public:
//	int GetPoints()const { return 5; }
//};
//int main()
//{
//
//	Shape* sarr[3] = { new Rect (Point(0, 0), 100, 150),
//	new Circle (Point(5, 5), 12),
//	new Polygon (Point(0, 15), 5) };
//	Fork f;
//
//	for (auto shape : sarr)
//		shape->Draw();
//
//	cout << endl;
//
//	IPoints* points[3] = { (Rect*)sarr[0], (Polygon*)sarr[2], &f};
//
//	for (auto x : points)
//		cout << "point count : " << x->GetPoints() << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//struct IPoints
//{
//	virtual int GetPoints()const = 0;
//};
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) { }
//	int GetX() const { return x; }
//	int GetY() const { return y; }
//};
//class Shape  //�߻�Ŭ����
//{
//protected:
//	Point start;
//public:
//	Shape(const Point& pt) :start(pt) {}
//	virtual void Draw()const = 0;
//	virtual ~Shape() { }
//};
//class Rect : public Shape, public IPoints   //���� ����̶���ϰ� �ڴ� �����̶�� �θ���
//{
//	int width;
//	int height;
//public:
//	Rect(const Point& pt = Point(), int w = 0, int h = 0) :Shape(pt), width(w), height(h) {}
//	void Draw()const {
//		cout << "Rect : " << start.GetX() << ", " << start.GetY() << " - "
//			<< "w : " << width << ", " << "h : " << height << endl;
//	}
//	int GetPoints()const { return 4; }
//};
//class Circle : public Shape
//{
//	int radius;
//public:
//	Circle(const Point& pt = Point(), int r = 0) : Shape(pt), radius(r) {}
//	void Draw()const {
//		cout << "Circle : " << start.GetX() << ", " << start.GetY() << " - "
//			<< "r : " << radius << endl;
//
//	}
//};
//class Polygon : public Shape, public IPoints
//{
//	vector<Point> list;
//public:
//	Polygon(const Point& pt = Point(), int points = 0) :Shape(pt)
//	{
//		list.push_back(start);
//		for (int i = 0; i < points; ++i)
//			list.push_back(Point(i + 1, i + 1));
//	}
//	void Draw()const {
//		cout << "Polygon : ";
//		for (const auto& pt : list)
//			cout << pt.GetX() << "," << pt.GetY() << " ";
//		cout << endl;
//
//	}
//	int GetPoints()const { return list.size(); }
//};
//class Fork : public IPoints
//{
//public:
//	int GetPoints()const { return 5; }
//};
//int main()
//{
//	Rect r(Point(0, 0), 100, 150);
//	Circle c(Point(5, 5), 12);
//	Polygon pg(Point(0, 15), 5);
//	Fork f;
//
//	IPoints* points[3] = { &r, &pg, &f };
//
//	for (auto x : points)
//		cout << "point count : " << x->GetPoints() << endl;
//}

#include <iostream>
#include <vector>
using namespace std;
class Point
{
	int x, y;
public:
	Point(int x =0, int y = 0):x(x),y(y){ }
	int GetX() const { return x; }
	int GetY() const { return y; }
};
class Shape  //�߻�Ŭ����
{
protected:
	Point start;
public:
	Shape(const Point& pt) :start(pt) {}
	virtual void Draw()const = 0;
	virtual ~Shape() { }
};
class Rect : public Shape
{
	int width;
	int height;
public:
	Rect(const Point& pt=Point(), int w =0 , int h= 0):Shape(pt), width(w), height(h){}
	void Draw()const {
		cout << "Rect : " << start.GetX() << ", " << start.GetY() << " - " 
			<< "w : " << width << ", " << "h : " << height << endl;
	}
};
class Circle : public Shape
{
	int radius;
public:
	Circle(const Point& pt =Point(), int r =0 ): Shape(pt), radius(r){}
	void Draw()const {
		cout << "Circle : " << start.GetX() << ", " << start.GetY() << " - "
			<< "r : " << radius << endl;

	}
};
class Polygon : public Shape
{
	vector<Point> list;
public:
	Polygon(const Point& pt = Point(), int points = 0) :Shape(pt)
	{
		list.push_back(start);
		for (int i = 0; i < points; ++i)
			list.push_back(Point(i + 1, i + 1));
	}
	void Draw()const {
		cout << "Polygon : ";
		for (const auto& pt : list)
			cout << pt.GetX() << "," << pt.GetY() << " "; 
		cout << endl;

	}
};
int main()
{
	Rect r(Point(0, 0), 100, 150);
	Circle c(Point(5, 5), 12);
	Polygon pg(Point(0, 15), 5);

	r.Draw();
	c.Draw();
	pg.Draw();
}

//#include <iostream> //��ü�� ���� ����
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a)
//    {
//        cout << "Person()" << endl;
//    }
//    virtual ~Person() { cout << "~Person" << endl; }
//
//    virtual void Print() const = 0; //���� ���� �Լ� 
//    /*{
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }*/
//
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {
//        cout << "Student()" << endl;
//    }
//    ~Student() { cout << "~Student" << endl; }
//    virtual void Print() const  // �޼ҵ� ������(function override) 
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0, const string& pos = "") :Person(n, a), position(pos) {
//        cout << "Professor()" << endl;
//    }
//    ~Professor() { cout << "~Professor" << endl; }
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//            << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main()
//{
//    Person* p = new Student("ȫ�浿", 24, 3);
//
//    p->GetName(); //�� ���� �Լ�
//    p->Print();   // ���� �Լ�
//
//    delete p;   //   ** �� 2��
//}

//#include <iostream> //��ü�� ���� ����
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int arr[5] = { 10,20,30,40,50 };
//	vector<double> v;
//	v.push_back(100);
//	v.push_back(200);
//	v.push_back(300);
//
//	for (auto item : arr)//���� ��� for
//		cout << item << " ";
//	cout << endl;
//
//	for (auto item : v)
//		cout << item << " ";
//	cout << endl;
//}

//#include <iostream> //��ü�� ���� ����
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a)
//    {
//        cout << "Person()" << endl;
//    }
//    virtual ~Person() { cout << "~Person" << endl; }
//
//    virtual void Print() const = 0; //���� ���� �Լ� 
//    /*{
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }*/
//
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {
//        cout << "Student()" << endl;
//    }
//    ~Student() { cout << "~Student" << endl; }
//    virtual void Print() const  // �޼ҵ� ������(function override) 
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0, const string& pos = "") :Person(n, a), position(pos) {
//        cout << "Professor()" << endl;
//    }
//    ~Professor() { cout << "~Professor" << endl; }
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//            << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main()
//{
//    Person* p = new Student("ȫ�浿", 24, 3);
//
//    p->GetName(); //�� ���� �Լ�
//    p->Print();   // ���� �Լ�
//
//    delete p;   //   ** �� 2��
//}

//#include <iostream> //��ü�� ���� ����
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a)
//    {
//        cout << "Person()" << endl;
//    }
//    virtual ~Person() { cout << "~Person" << endl; }
//
//    virtual void Print() const = 0; //���� ���� �Լ� 
//    /*{
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }*/
//
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {
//        cout << "Student()" << endl;
//    }
//    ~Student() { cout << "~Student" << endl; }
//    virtual void Print() const  // �޼ҵ� ������(function override) 
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0, const string& pos = "") :Person(n, a), position(pos) {
//        cout << "Professor()" << endl;
//    }
//    ~Professor() { cout << "~Professor" << endl; }
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//            << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main()
//{
//    Person* p = new Student("ȫ�浿", 24, 3);
//
//    p->Print();
//
//    delete p;   //   ** �� 2��
//}

//#include <iostream> //��ü�� ���� ����
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a)
//    {
//        cout << "Person()" << endl;
//    }
//    ~Person() { cout << "~Person" << endl; }
//
//    virtual void Print() const = 0; //���� ���� �Լ� 
//    /*{
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }*/
//
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {
//        cout << "Student()" << endl;
//    }
//    ~Student() { cout << "~Student" << endl; }
//    virtual void Print() const  // �޼ҵ� ������(function override) 
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0, const string& pos = "") :Person(n, a), position(pos) {
//        cout << "Professor()" << endl;
//    }
//    ~Professor() { cout << "~Professor" << endl; }
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//            << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main()
//{
//    Person* p = new Student ("ȫ�浿", 24, 3);
//
//    p->Print();
//
//    delete p;   //   ** �� 2��
//}

//#include <iostream> //��ü�� ���� ����
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) 
//    {
//        cout << "Person()" << endl;
//    }
//    ~Person() { cout << "~Person" << endl; }
//
//    virtual void Print() const = 0; //���� ���� �Լ� 
//    /*{
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }*/
//
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {
//        cout << "Student()" << endl;
//    }
//    ~Student() { cout << "~Student" << endl; }
//    virtual void Print() const  // �޼ҵ� ������(function override) 
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0, const string& pos = "") :Person(n, a), position(pos) {
//        cout << "Professor()" << endl;
//    }
//    ~Professor() { cout << "~Professor" << endl; }
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//            << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main()
//{
//    Student s1("ȫ�浿", 24, 3);
//    s1.Print();
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) {}
//
//    virtual void Print() const = 0; //���� ���� �Լ� 
//    /*{
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }*/
//
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {}
//
//    virtual void Print() const  // �޼ҵ� ������(function override) 
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0, const string& pos = "") :Person(n, a), position(pos) {}
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//            << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main()
//{
//    Person* parr[5] = { new Student("ȫ�浿", 20, 2), new Professor("�Ӳ���", 30, "������"),
//    new Student("�̸���", 21, 3), new Professor("������", 30, "�α���"),
//    new Student("����", 26, 4) };
//
//    for (Person* p : parr)    //��簴ü �۽������� �����ͼ� �۽��� ����� �۽��� ����� �۽��� �����
//        p->Print();     //�������� ������ ��ü���� �ϳ��� �޼����� ������ �� ����ϰ� �����ϴ� ��
//
//    for (Person* p : parr)
//        delete p;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) {}
//
//    virtual void Print() const = 0; //���� ���� �Լ� 
//    /*{
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }*/
//
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {}
//
//    virtual void Print() const  // �޼ҵ� ������(function override) 
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0, const string& pos = "") :Person(n, a), position(pos) {}
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//            << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main()
//{
//    Person p1("ȫ�浿", 25);      //�߻�Ŭ������ �ν��Ͻ��� ����� �� �� ����.
//    Student s1("�̸���", 29, 3);
//    Professor pf1("�Ӳ���", 40, "������");
//
//    Person* p = &pf1;    // O
//    
//    p->GetAge();
//    p->GetName();
//    p->Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) {}
//
//    virtual void Print() const
//    {
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {}
//
//    virtual void Print() const  // �޼ҵ� ������(function override) 
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0, const string& pos = "") :Person(n, a), position(pos) {}
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//            << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main()
//{
//    Person p1("ȫ�浿", 25);
//    Student s1("�̸���", 29, 3);
//    Professor pf1("�Ӳ���", 40, "������");
//
//    Person* p = &pf1;    // O
//
//    p->GetAge();
//    p->GetName();
//    p->Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) {}
//
//    virtual void Print() const    
//    {
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {}
//
//    virtual void Print() const  // �޼ҵ� ������(function override) 
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0, const string& pos = "") :Person(n, a), position(pos) {}
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//            << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main(void)
//{
//    Person p1("ȫ�浿", 25);
//    Student s1("�̸���", 29, 3);
//    Professor pf1("�Ӳ���", 40, "������");
//
//    Person& rp = s1;    // O
//    Person* p = &s1;    // O
//
//    rp.Print();   //�������� �޼ҵ�
//    p->Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) {}
//
//    void Print() const
//    {
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {}
//
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0, const string& pos = "") :Person(n, a), position(pos) {}
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//            << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main(void)
//{
//    Person p1("ȫ�浿", 25);
//    Student s1("�̸���", 29, 3);
//    Professor pf1("�Ӳ���", 40, "������");
//
//    Person& rp = s1;    // O
//    Person* p = &s1;    // O
//
//    rp.Print();
//    p->Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) {}
//
//    void Print() const
//    {
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {}
//
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0, const string& pos = "") :Person(n, a), position(pos) {}
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//            << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main(void)
//{
//    Person p1("ȫ�浿", 25);
//    Student s1("�̸���", 29, 3);
//    Professor pf1("�Ӳ���", 40, "������");
//
//    p1.Print();
//    s1.Print();
//    pf1.Print();
//
//    Person p2 = s1;     // X
//    Person& rp = s1;    // O
//    Person* p = &s1;    // O
//    
//
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) {}
//
//    void Print() const
//    {
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {}
//
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//class Professor : public Person
//{
//    string position;
//public:
//    Professor(const string& n = "", int a = 0 ,const string& pos=""):Person(n,a), position(pos){}
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", "
//        << "position: " << position << endl;
//    }
//    const string& GetPosition() const { return position; }
//};
//int main(void)
//{
//    Person p1("ȫ�浿", 25);
//    Student s1("�̸���", 29, 3);
//    Professor pf1("�Ӳ���", 40, "������");
//
//    p1.Print();
//    s1.Print();
//    pf1.Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) {}
//
//    void Print() const
//    {
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {}
//
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//int main(void)
//{
//    Person p1("ȫ�浿", 25);
//    Student s1("�̸���", 29, 3);
//
//    p1.Print();
//    s1.Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) {}
//
//    void Print() const
//    {
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {}
//
//    void Print() const
//    {
//        cout << "name : " << GetName() << ", " << "age : " << GetAge() << ", ";
//        cout << "grade : " << GetGrade() << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//int main(void)
//{
//    Person p1("ȫ�浿", 25);
//    Student s1("�̸���", 29, 3);
//
//    p1.Print();
//    s1.Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//public:
//    Person(const string& n = "", int a = 0) : name(n), age(a) {}
//
//    void Print() const
//    {
//        cout << "name : " << name << ", " << "age : " << age << endl;
//    }
//
//    const string& GetName() const { return name; }
//
//    int GetAge() const { return age; }
//};
//
//class Student : public Person
//{
//    int grade;
//public:
//    Student(const string& n = "", int a = 0, int g = 0) : Person(n, a), grade(g) {}
//
//    void Print() const
//    {
//        cout << "name : " << name << ", " << "age : " << age << ", ";
//        cout << "grade : " << grade << endl;
//    }
//
//    int GetGrade() const { return grade; }
//};
//int main(void)
//{
//    Person p1("ȫ�浿", 25);
//    Student s1("�̸���", 29, 3);
//
//    p1.Print();
//    s1.Print();
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//
//	const
//};
//int main()
//{
//	const int* const * pp2 = pp;
//	cout << **pa2 << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Data
//{
//	int data;
//public:
//	Data(int d = 0) :data(d) {
//		cout << "Data()" << endl;
//	}
//	~Data() { cout << "~Data()" << endl; }
//	void Print() const {
//		cout << "Data : " << data << endl;
//	}
//};
//Data CreateData()
//{
//	Data d1;
//	return d1;
//	//return Data();
//}
//int main()
//{
//	//�ӽ� ��ü(���� ��ü)
//
//	vector<Data> v;
//	v.push_back(Data(100));
//	cout << "end main()" << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Data
//{
//	int data;
//public:
//	Data(int d = 0) :data(d) {
//		cout << "Data()" << endl;
//	}
//	~Data() { cout << "~Data()" << endl; }
//	void Print() const {
//		cout << "Data : " << data << endl;
//	}
//};
//Data CreateData()
//{
//	Data d1;
//	return d1;
//	//return Data();
//}
//int main()
//{
//	//�ӽ� ��ü(���� ��ü)
//	cout << "start main()" << endl;
//	Data d1 = CreateData();
//
//	//d1 = CreateData();
//	cout << "end main()" << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Data
//{
//	int data;
//public:
//	Data(int d = 0) :data(d) {
//		cout << "Data()" << endl;
//	}
//	~Data() { cout << "~Data()" << endl; }
//	void Print() const {
//		cout << "Data : " << data << endl;
//	}
//};
//Data CreateData()
//{
//	//Data d1;
//	//return d1;
//	return Data();
//}
//int main()
//{
//	//�ӽ� ��ü(���� ��ü)
//	cout << "start main()" << endl;
//	Data d1 = CreateData();
//	
//	//d1 = CreateData();
//	cout << "end main()" << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Data
//{
//	int data;
//public:
//	Data(int d = 0) :data(d) {
//		cout << "Data()" << endl;
//	}
//	~Data() { cout << "~Data()" << endl; }
//	void Print() const {
//		cout << "Data : " << data << endl;
//	}
//};
//Data CreateData()
//{
//	//Data d1;
//	//return d1;
//	return Data();
//}
//int main()
//{
//	//�ӽ� ��ü(���� ��ü)
//	cout << "start main()" << endl;
//	CreateData();
//	cout << "end main()" << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Data
//{
//	int data;
//public:
//	Data(int d = 0) :data(d) {
//		cout << "Data()" << endl;
//	}
//	~Data() { cout << "~Data()" << endl; }
//	void Print() const {
//		cout << "Data : " << data << endl;
//	}
//};
//int main()
//{
//	//�ӽ� ��ü(���� ��ü)
//	cout << "start main()" << endl;
//	Data d1 = Data();
//	d1.Print();
//	cout << "end main()" << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Data
//{
//	int data;
//public:
//	Data(int d = 0):data(d) {
//		cout << "Data()" << endl;
//	}
//	~Data() { cout << "~Data()" << endl; }
//	void Print() const {
//		cout << "Data : " << data <<  endl;
//	}
//};
//int main()
//{
//	//�ӽ� ��ü(���� ��ü)
//	cout << "start main()" << endl;
//                                   
//	//Data d1 = Data();
//	Data d1(1);   
//	d1 = Data(100);
//	d1.Print();
//	cout << "end main()" << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Data
//{
//public:
//	Data(int = 0) {
//		cout << "Data()" << endl;
//	}
//	~Data() { cout << "~Data()" << endl; }
//	void Print() const {
//		cout << "Data" << endl;
//	}
//};
//int main()
//{
//	//�ӽ� ��ü(���� ��ü)
//	cout << "start main()" << endl;
//	int();
//	double();
//	Data();					 //���Ͱ����ſ��� ���� ��
//	cout << "end main()" << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Data
//{
//public:
//	Data(int = 0) {
//		cout << "Data()" << endl;
//	}
//	~Data() { cout << "~Data()" << endl; }
//	void Print() const {
//		cout << "Data" << endl;
//	}
//};
//int main()
//{
//	//�ӽ� ��ü(���� ��ü)
//	cout << "start main()" << endl;
//
//	Data d1;
//	Data d2 = Data();
//
//	cout << "end main()" << endl;
//}

//#include <iostream>
//using namespace std;
//
//class Data
//{
//public:
//	Data(int = 0) {}
//	void Print() const {
//		cout << "Data" << endl;
//	}
//};
//int main()
//{
//	Data arr[3];
//
//	arr[0].Print();
//
//}

//#include <iostream>
//using namespace std;
//
//class Data
//{
//public:
//	Data(int) {}
//	void Print() const {
//		cout << "Data" << endl;
//	}
//};
//int main()
//{
//	Data arr[3] = {Data(1), Data(2), Data(17)};
//
//	arr[0].Print();
//
//}

//#include <iostream>
//using namespace std;
//
//class Data
//{
//public:
//	void Print() const {
//		cout << "Data" << endl;
//	}
//};
//int main()
//{
//	Data arr[3];
//
//	arr[0].Print();
//}
