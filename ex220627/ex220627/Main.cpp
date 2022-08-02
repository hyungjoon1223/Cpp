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
class Shape  //추상클래스
{
protected:
	Point start;
public:
	Shape(const Point& pt) :start(pt) {}
	virtual void Draw()const = 0;
	virtual ~Shape() { }
};
class Rect : public Shape, public IPoints   //앞은 상속이라고하고 뒤는 구현이라고 부른다
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
//class Shape  //추상클래스
//{
//protected:
//	Point start;
//public:
//	Shape(const Point& pt) :start(pt) {}
//	virtual void Draw()const = 0;
//	virtual ~Shape() { }
//};
//class Rect : public Shape, public IPoints   //앞은 상속이라고하고 뒤는 구현이라고 부른다
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
//class Shape  //추상클래스
//{
//protected:
//	Point start;
//public:
//	Shape(const Point& pt) :start(pt) {}
//	virtual void Draw()const = 0;
//	virtual ~Shape() { }
//};
//class Rect : public Shape, public IPoints   //앞은 상속이라고하고 뒤는 구현이라고 부른다
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
class Shape  //추상클래스
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

//#include <iostream> //객체의 사용과 수명
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
//    virtual void Print() const = 0; //순수 가상 함수 
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
//    virtual void Print() const  // 메소드 재정의(function override) 
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
//    Person* p = new Student("홍길동", 24, 3);
//
//    p->GetName(); //비 가상 함수
//    p->Print();   // 가상 함수
//
//    delete p;   //   ** 별 2개
//}

//#include <iostream> //객체의 사용과 수명
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
//	for (auto item : arr)//범위 기반 for
//		cout << item << " ";
//	cout << endl;
//
//	for (auto item : v)
//		cout << item << " ";
//	cout << endl;
//}

//#include <iostream> //객체의 사용과 수명
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
//    virtual void Print() const = 0; //순수 가상 함수 
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
//    virtual void Print() const  // 메소드 재정의(function override) 
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
//    Person* p = new Student("홍길동", 24, 3);
//
//    p->GetName(); //비 가상 함수
//    p->Print();   // 가상 함수
//
//    delete p;   //   ** 별 2개
//}

//#include <iostream> //객체의 사용과 수명
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
//    virtual void Print() const = 0; //순수 가상 함수 
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
//    virtual void Print() const  // 메소드 재정의(function override) 
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
//    Person* p = new Student("홍길동", 24, 3);
//
//    p->Print();
//
//    delete p;   //   ** 별 2개
//}

//#include <iostream> //객체의 사용과 수명
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
//    virtual void Print() const = 0; //순수 가상 함수 
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
//    virtual void Print() const  // 메소드 재정의(function override) 
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
//    Person* p = new Student ("홍길동", 24, 3);
//
//    p->Print();
//
//    delete p;   //   ** 별 2개
//}

//#include <iostream> //객체의 사용과 수명
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
//    virtual void Print() const = 0; //순수 가상 함수 
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
//    virtual void Print() const  // 메소드 재정의(function override) 
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
//    Student s1("홍길동", 24, 3);
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
//    virtual void Print() const = 0; //순수 가상 함수 
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
//    virtual void Print() const  // 메소드 재정의(function override) 
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
//    Person* parr[5] = { new Student("홍길동", 20, 2), new Professor("임꺽정", 30, "조교수"),
//    new Student("이몽룡", 21, 3), new Professor("성춘향", 30, "부교수"),
//    new Student("장길산", 26, 4) };
//
//    for (Person* p : parr)    //모든객체 퍼슨형으로 가져와서 퍼슨아 출력해 퍼슨아 출력해 퍼슨아 출력해
//        p->Print();     //다형성은 유사한 객체들을 하나의 메세지를 보냈을 때 비슷하게 동작하는 것
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
//    virtual void Print() const = 0; //순수 가상 함수 
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
//    virtual void Print() const  // 메소드 재정의(function override) 
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
//    Person p1("홍길동", 25);      //추상클래스는 인스턴스를 만들어 낼 수 없다.
//    Student s1("이몽룡", 29, 3);
//    Professor pf1("임꺽정", 40, "조교수");
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
//    virtual void Print() const  // 메소드 재정의(function override) 
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
//    Person p1("홍길동", 25);
//    Student s1("이몽룡", 29, 3);
//    Professor pf1("임꺽정", 40, "조교수");
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
//    virtual void Print() const  // 메소드 재정의(function override) 
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
//    Person p1("홍길동", 25);
//    Student s1("이몽룡", 29, 3);
//    Professor pf1("임꺽정", 40, "조교수");
//
//    Person& rp = s1;    // O
//    Person* p = &s1;    // O
//
//    rp.Print();   //다형적인 메소드
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
//    Person p1("홍길동", 25);
//    Student s1("이몽룡", 29, 3);
//    Professor pf1("임꺽정", 40, "조교수");
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
//    Person p1("홍길동", 25);
//    Student s1("이몽룡", 29, 3);
//    Professor pf1("임꺽정", 40, "조교수");
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
//    Person p1("홍길동", 25);
//    Student s1("이몽룡", 29, 3);
//    Professor pf1("임꺽정", 40, "조교수");
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
//    Person p1("홍길동", 25);
//    Student s1("이몽룡", 29, 3);
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
//    Person p1("홍길동", 25);
//    Student s1("이몽룡", 29, 3);
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
//    Person p1("홍길동", 25);
//    Student s1("이몽룡", 29, 3);
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
//	//임시 객체(무명 객체)
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
//	//임시 객체(무명 객체)
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
//	//임시 객체(무명 객체)
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
//	//임시 객체(무명 객체)
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
//	//임시 객체(무명 객체)
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
//	//임시 객체(무명 객체)
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
//	//임시 객체(무명 객체)
//	cout << "start main()" << endl;
//	int();
//	double();
//	Data();					 //벡터같은거에서 자주 씀
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
//	//임시 객체(무명 객체)
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
