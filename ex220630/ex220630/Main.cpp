#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y)
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	vector < shared_ptr<Point> > v;

	v.push_back(make_shared<Point>(1, 1));
	v.push_back(make_shared<Point>(2, 2));
	v.push_back(make_shared<Point>(3, 3));

	for (vector<Point*>::size_type i = 0; i < v.size(); ++i)
		v[i]->Print();

	v.erase(v.begin());
	cout << endl;

	for (vector<Point*>::size_type i = 0; i < v.size(); ++i)
		v[i]->Print();
}

#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y)
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	vector < shared_ptr<Point>> v;

	v.push_back(shared_ptr<Point>(new Point(1, 1)));
	v.push_back(shared_ptr<Point>(new Point(2, 2)));
	v.push_back(shared_ptr<Point>(new Point(3, 3)));

	for (vector<Point*>::size_type i = 0; i < v.size(); ++i)
		v[i]->Print();

	v.erase(v.begin());
	cout << endl;

	for (vector<Point*>::size_type i = 0; i < v.size(); ++i)
		v[i]->Print();
}


#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y)
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	vector<Point*> v;

	v.push_back(new Point(1, 1));
	v.push_back(new Point(2, 2));
	v.push_back(new Point(3, 3));

	for (vector<Point*>::size_type i = 0; i < v.size(); ++i)
		v[i]->Print();
	
	delete* v.begin();
	v.erase(v.begin());
	cout << endl;

	for (vector<Point*>::size_type i = 0; i < v.size(); ++i)
		v[i]->Print();

	for (vector<Point*>::size_type i = 0; i < v.size(); ++i)
		delete v[i];
}


#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y)
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	shared_ptr<Point> p4;
	{
		shared_ptr<Point> p1(new Point(2, 3));
		shared_ptr<Point> p2 = p1;
		shared_ptr<Point> p3 = p1;

		p1->Print();
		p2->Print();
		p3->Print();
		p4 = p3;
	}
	cout << "p4" << endl;
}


#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y)
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	shared_ptr<Point> p1(new Point(2,3));
	p1->Print();

	shared_ptr<Point> p2(new Point(4, 5));
	p2->Print();

	shared_ptr<Point> p3(new Point(*p2));
	p3->Print();
}

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y)
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	shared_ptr<Point> p1 = make_shared<Point>(2, 3);
	p1->Print();

	shared_ptr<Point> p2 = make_shared<Point>(4, 5);
	p2->Print();

	shared_ptr<Point> p3 = make_shared<Point>(*p2);
	p3->Print();
}

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y)
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	shared_ptr<Point> p1 = make_shared<Point>(2, 3);
	p1->Print();

	shared_ptr<Point> p2 = make_shared<Point>(4, 5);
	p2->Print();

	p1 = p2;
	cout << "p1 = p2" << endl;
}

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y)
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	shared_ptr<Point> p1(new Point(2, 3));
	p1->Print();

	shared_ptr<Point> p2(new Point(4, 5));
	p2->Print();

	p1 = p2;
	cout << "p1 = p2" << endl;
}

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y)
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	unique_ptr<Point> p1(new Point(2, 3));
	p1->Print();

	unique_ptr<Point> p2(new Point(4,5));
	p2->Print();

	p1 = p2;
}

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y)
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	unique_ptr<Point> p1(new Point(2, 3));

	p1->Print();
	(*p1).Print();
}

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y)
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	//스마트포인터 (unique_ptr / shared_ptr - weak_ptr)
	unique_ptr<int> p (new int(10));
	unique_ptr<Point> p1(new Point(2, 3));

	cout << *p << endl;
	p1->Print();
}

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y) 
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg) :x(arg.x), y(arg.y) 
	{
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	//스마트포인터 (unique_ptr / shared_ptr - weak_ptr)
	int* p = new int(10);
	Point* p1 = new Point(2, 3);

	cout << *p << endl;
	p1->Print();

	delete p;
	delete p1;
}

#include <iostream>
using namespace std;
class Shape
{
public:
	virtual ~Shape() {}
	virtual void Draw()const = 0;
};
class Rect : public  Shape
{
public:
	void Draw()const { cout << "Rect" << endl; }
};
class Circle : public Shape
{
	int radius;
public:
	Circle(int r = 0) : radius(r) {}
	void Draw()const { cout << "Circle" << endl; }
	void PrintRadius()const { cout << "raidus : " << radius << endl; }
};
void PrintRadius(Shape& s)
{
	try 
	{
		Circle& c = dynamic_cast<Circle&>(s);
		c.PrintRadius();
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
}
int main()
{
	Rect r1;
	Rect r2;
	Circle c1;

	Shape& s1 = r1;
	Shape& s2 = r2;
	Shape& s3 = c1;

	PrintRadius(r1);
	PrintRadius(r2);
	PrintRadius(c1);
}

#include <iostream>
using namespace std;
class Shape
{
public:
	virtual ~Shape() {}
	virtual void Draw()const = 0;
};
class Rect : public  Shape
{
public:
	void Draw()const { cout << "Rect" << endl; }
};
class Circle : public Shape
{
	int radius;
public:
	Circle(int r = 0) : radius(r) {}
	void Draw()const { cout << "Circle" << endl; }
	void PrintRadius()const { cout << "raidus : " << radius << endl; }
};
;
int main()
{
	Shape* shapeList[] = { (Shape*)(Rect*)new Rect, new Circle(10), new Rect, new Rect, new Circle(5) };

	for (auto p : shapeList)
	{
		Circle* pc = static_cast<Circle*>(p);
		if (pc != nullptr)
			pc->PrintRadius();
	}
}

#include <iostream>
using namespace std;
class Shape
{
public:
	virtual ~Shape() {}
	virtual void Draw()const = 0;
};
class Rect : public  Shape
{
public:
	void Draw()const { cout << "Rect" << endl; }
};
class Circle : public Shape
{
public:
	void Draw()const { cout << "Circle" << endl; }
	void PrintRadius()const { cout << "raidus : xxx" << endl; }
};
;
int main()
{
	Shape* shapeList[] = { (Shape*)(Rect*)new Rect, new Circle, new Rect, new Rect, new Circle };

	for (auto p : shapeList)
	{
		Circle* pc = dynamic_cast<Circle*>(p);
		if (pc != nullptr)
			pc->PrintRadius();
	}
}

#include <iostream>
using namespace std;
class Shape
{
public:
	virtual ~Shape() {}
	virtual void Draw()const = 0;
};
class Rect : public  Shape
{
public:
	void Draw()const { cout << "Rect" << endl; }
};
class Circle : public Shape  
{
public:
	void Draw()const { cout << "Circle" << endl; }
	void PrintRadius()const { cout << "raidus : xxx" << endl; }
};
;
int main()
{
	Shape* shapeList[] = { (Shape*)(Rect*)new Rect, new Circle, new Rect, new Rect, new Circle };

	for (auto p : shapeList)
	{
		Circle* pc = dynamic_cast<Circle*>(p);
		if (pc != nullptr)
			pc->PrintRadius();
	}
}


#include <iostream>
using namespace std;

int main()
{
	int n = 0x44434241;
	//char* p = (char*) & n;  //C 3.
	char* p = reinterpret_cast<char*>(&n);

	cout << p[0] << ',' << p[1] << ',' << p[2] << ',' << p[3] << endl;
}

#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	const int* p = &n;

	cout << *p << ',' << n << endl;

	//int* p2 = (int*)p;
	int* p2 = const_cast<int*>(p);  //2.
	*p2 = 100;
	cout << *p << ',' << n << endl;
}

#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	const int* p = &n;

	cout << *p << ',' << n << endl;

	//int* p2 = (int*)p;
	int* p2 = const_cast<int*>(p);
	*p2 = 100;
	cout << *p << ',' << n << endl;
}

#include <iostream>
using namespace std;

class Shape {};
class Rect : public Shape {};
class Circle : public Shape {};
int main()
{
	Shape* ps = new Rect();

	// Rect* pr = (Rect*)ps;  ////C에서는
	Rect* pr = static_cast<Rect*>(ps); //1. 
}

#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	double d = 5.5;

	//n = (int)d;
	n = static_cast<int>(d); //1.
	cout << n << ',' << d << endl;

}

#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class Exception : public exception
{
public:
	Exception(const char* msg) :exception(msg) {}
	virtual const char* what()const { return "예외"; }
	virtual ~Exception() {}
};
class InputException : public Exception
{
public:
	InputException(const char* msg) :Exception(msg) {}
	const char* what()const { return "입력 예외"; }
};
class OperationException : public Exception
{
	int index;
	int value;
	string message;
public:
	OperationException(const char* msg, int idx, int val) :Exception(msg), index(idx), value(val)
	{
		ostringstream oss;
		oss << "연산 예외 : " << "index : " << index << ',' << "value : " << value << endl;
		message = oss.str();
	}
	const char* what()const
	{
		return message.c_str();
	}
};
class OutputException : public Exception
{
public:
	OutputException(const char* msg) :Exception(msg) {}

	const char* what()const { return "출력 예외"; }
};
void func1(bool exFlag)
{
	if (exFlag) throw InputException("입력 예외");
	cout << "1. 입력" << endl;
}
void func2(bool exFlag)
{
	if (exFlag) throw OperationException("연산 예외", 5, 100);
	cout << "2. 연산" << endl;
}
void func3(bool exFlag)
{
	if (exFlag) throw OutputException("출력 예외");
	cout << "3. 출력" << endl;
}
void etc(bool exFlag)
{
	if (exFlag)
		throw Exception("부가적인 예외");
	cout << "부가적인 작업" << endl;
}
int main()
{
	try
	{
		func1(false);   //트라이 문에 묶인 것들은 독립코드는 묶으면 안된다
		func2(true);
		func3(true);
	}
	catch (const OperationException& ex)
	{
		cout << ex.what() << endl;
		cout << "Log ..." << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "예외 : " << endl;
	}
	try
	{
		etc(false);
	}

	catch (...)
	{
		cout << "예외 : " << endl;
	}
}

#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class Exception : public exception
{
public:
	Exception(const char* msg) :exception(msg) {}
	virtual const char* what()const { return "예외"; }
	virtual ~Exception() {}
};
class InputException : public Exception
{
public:
	InputException(const char* msg) :Exception(msg) {}
	const char* what()const { return "입력 예외"; }
};
class OperationException : public Exception
{
	int index;
	int value;
	string message;
public:
	OperationException(const char* msg,int idx, int val) :Exception(msg), index(idx), value(val) 
	{
		ostringstream oss;
		oss << "연산 예외 : " << "index : " << index << ',' << "value : " << value << endl;
		message = oss.str();
	}
	const char* what()const 
	{
		return message.c_str();
	}
};
class OutputException : public Exception
{
public:
	OutputException(const char* msg) :Exception(msg) {}

	const char* what()const { return "출력 예외"; }
};
void func1(bool exFlag)
{
	if (exFlag) throw InputException("입력 예외");
	cout << "1. 입력" << endl;
}
void func2(bool exFlag)
{
	if (exFlag) throw OperationException("연산 예외",5,100);
	cout << "2. 연산" << endl;
}
void func3(bool exFlag)
{
	if (exFlag) throw OutputException("출력 예외");
	cout << "3. 출력" << endl;
}
void etc(bool exFlag)
{
	if (exFlag)
		throw Exception("부가적인 예외");
	cout << "부가적인 작업" << endl;
}
int main()
{
	try
	{
		func1(false);   //트라이 문에 묶인 것들은 독립코드는 묶으면 안된다
		func2(true);
		func3(true);
	}
	catch (const OperationException& ex)
	{
		cout << ex.what() << endl;
		cout << "Log ..." << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "예외 : " << endl;
	}
	try
	{
		etc(false);
	}

	catch (...)
	{
		cout << "예외 : " << endl;
	}
}

#include <iostream>
#include <exception>
using namespace std;

class Exception : public exception
{
public:
	Exception(const char* msg):exception(msg) {}
	virtual const char* what()const { return "예외"; }
	virtual ~Exception() {}
};
class InputException : public Exception
{
public:
	InputException(const char* msg):Exception(msg){}
	const char* what()const { return "입력 예외"; }
};
class OperationException : public Exception
{
public:
	OperationException(const char* msg) :Exception(msg) {}

	const char* what()const { return "연산 예외"; }
};
class OutputException : public Exception
{
public:
	OutputException(const char* msg) :Exception(msg) {}

	const char* what()const { return "출력 예외"; }
};
void func1(bool exFlag)
{
	if (exFlag) throw InputException("입력 예외");
	cout << "1. 입력" << endl;
}
void func2(bool exFlag)
{
	if (exFlag) throw OperationException("연산 예외");
	cout << "2. 연산" << endl;
}
void func3(bool exFlag)
{
	if (exFlag) throw OutputException("출력 예외");
	cout << "3. 출력" << endl;
}
void etc(bool exFlag)
{
	if (exFlag)
		throw Exception("부가적인 예외");
	cout << "부가적인 작업" << endl;
}
int main()
{
	try
	{
		func1(false);   //트라이 문에 묶인 것들은 독립코드는 묶으면 안된다
		func2(true);
		func3(true);
	}
	catch (const OperationException& ex)
	{
		cout << ex.what() << endl;
		cout << "Log ..." << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "예외 : " << endl;
	}
	try
	{
		etc(false);
	}

	catch (...)
	{
		cout << "예외 : " << endl;
	}
}

#include <iostream>
#include <exception>
using namespace std;

class Exception : public exception
{
public:
	virtual const char* what()const { return "예외"; }
	virtual ~Exception() {}
};
class InputException : public Exception
{
public:
	const char* what()const { return "입력 예외"; }
};
class OperationException : public Exception
{
public:
	const char* what()const { return "연산 예외"; }
};
class OutputException : public Exception
{
public:
	const char* what()const { return "출력 예외"; }
};
void func1(bool exFlag)
{
	if (exFlag) throw exception("입력 예외");
	cout << "1. 입력" << endl;
}
void func2(bool exFlag)
{
	if (exFlag) throw exception("연산 예외");
	cout << "2. 연산" << endl;
}
void func3(bool exFlag)
{
	if (exFlag) throw exception("출력 예외");
	cout << "3. 출력" << endl;
}
void etc(bool exFlag)
{
	if (exFlag)
		throw Exception();
	cout << "부가적인 작업" << endl;
}
int main()
{
	try
	{
		func1(false);   //트라이 문에 묶인 것들은 독립코드는 묶으면 안된다
		func2(true);
		func3(true);
	}
	catch (const OperationException& ex)
	{
		cout << ex.what() << endl;
		cout << "Log ..." << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "예외 : " << endl;
	}
	try
	{
		etc(false);
	}

	catch (...)
	{
		cout << "예외 : " << endl;
	}
}

#include <iostream>
#include <exception>
using namespace std;

class Exception : public exception
{
public:
	virtual const char* what()const { return "예외"; }
	virtual ~Exception() {}
};
class InputException : public Exception
{
public:
	const char* what()const { return "입력 예외"; }
};
class OperationException : public Exception
{
public:
	const char* what()const { return "연산 예외"; }
};
class OutputException : public Exception
{
public:
	const char* what()const { return "출력 예외"; }
};
void func1(bool exFlag)
{
	if (exFlag) throw InputException();
	cout << "1. 입력" << endl;
}
void func2(bool exFlag)
{
	if (exFlag) throw OperationException();
	cout << "2. 연산" << endl;
}
void func3(bool exFlag)
{
	if (exFlag) throw OutputException();
	cout << "3. 출력" << endl;
}
void etc(bool exFlag)
{
	if (exFlag)
		throw Exception();
	cout << "부가적인 작업" << endl;
}
int main()
{
	try
	{
		func1(false);   //트라이 문에 묶인 것들은 독립코드는 묶으면 안된다
		func2(true);
		func3(true);
	}
	catch (const OperationException& ex)
	{
		cout << ex.what() << endl;
		cout << "Log ..." << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "예외 : " << endl;
	}
	try
	{
		etc(false);
	}

	catch (...)
	{
		cout << "예외 : " << endl;
	}
}

#include <iostream>
#include <exception>
using namespace std;

class Exception : public exception
{
public:
	virtual const char* what()const { return "예외"; }
	virtual ~Exception() {}
};
class InputException : public Exception
{
public:
	const char* what()const { return "입력 예외"; }
};
class OperationException : public Exception
{
public:
	const char* what()const { return "연산 예외"; }
};
class OutputException : public Exception
{
public:
	const char* what()const { return "출력 예외"; }
};
void func1(bool exFlag)
{
	if (exFlag) throw InputException();
	cout << "1. 입력" << endl;
}
void func2(bool exFlag)
{
	if (exFlag) throw OperationException();
	cout << "2. 연산" << endl;
}
void func3(bool exFlag)
{
	if (exFlag) throw OutputException();
	cout << "3. 출력" << endl;
}
void etc(bool exFlag)
{
	if (exFlag)
		throw Exception();
	cout << "부가적인 작업" << endl;
}
int main()
{
	try
	{
		func1(false);   //트라이 문에 묶인 것들은 독립코드는 묶으면 안된다
		func2(false);
		func3(true);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "예외 : " << endl;
	}
	try
	{
		etc(false);
	}
	catch (...)
	{
		cout << "예외 : " << endl;
	}
}

#include <iostream>
using namespace std;

class Exception
{
public:
	virtual const char* what()const { return "예외"; }
	virtual ~Exception() {}
};
class InputException : public Exception
{
public:
	const char* what()const { return "입력 예외"; }
};
class OperationException : public Exception
{
public:
	const char* what()const { return "연산 예외"; }
};
class OutputException : public Exception
{
public:
	const char* what()const { return "출력 예외"; }
};
void func1(bool exFlag)
{
	if (exFlag) throw InputException();
	cout << "1. 입력" << endl;
}
void func2(bool exFlag)
{
	if (exFlag) throw OperationException();
	cout << "2. 연산" << endl;
}
void func3(bool exFlag)
{
	if (exFlag) throw OutputException();
	cout << "3. 출력" << endl;
}
void etc(bool exFlag)
{
	if (exFlag)
		throw Exception();
	cout << "부가적인 작업" << endl;
}
int main()
{
	try
	{
		func1(false);   //트라이 문에 묶인 것들은 독립코드는 묶으면 안된다
		func2(false);
		func3(true);
	}
	catch (const Exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "예외 : " << endl;
	}
	try
	{
		etc(false);
	}
	catch (...)
	{
		cout << "예외 : " << endl;
	}
}

#include <iostream>
using namespace std;

class Exception
{
public:
	virtual const char* what()const { return "예외"; }
	virtual ~Exception() {}
};
class InputException : public Exception
{
public:
	const char* what()const { return "입력 예외"; }
};
class OperationException : public Exception
{
public:
	const char* what()const { return "연산 예외"; }
};
class OutputException : public Exception
{
public:
	const char* what()const { return "출력 예외"; }
};
void func1(bool exFlag)
{
	if (exFlag) throw InputException();
	cout << "1. 입력" << endl;
}
void func2(bool exFlag)
{
	if (exFlag) throw OperationException();
	cout << "2. 연산" << endl;
}
void func3(bool exFlag)
{
	if (exFlag) throw OutputException();
	cout << "3. 출력" << endl;
}
void etc(bool exFlag)
{
	if (exFlag)
		throw Exception();
	cout << "부가적인 작업" << endl;
}
int main()
{
	try
	{
		func1(false);   //트라이 문에 묶인 것들은 독립코드는 묶으면 안된다
		func2(false);
		func3(true);
	}
	catch (...)
	{
		cout << "예외 : " << endl;
	}
	try
	{
		etc(false);    
	}
	catch (...)
	{
		cout << "예외 : " << endl;
	}
}

#include <iostream>
using namespace std;

class Exception
{
public:
	virtual const char* what()const { return "예외"; }
	virtual ~Exception() {}
};
class InputException : public Exception
{
public:
	const char* what()const { return "입력 예외"; }
};
class OperationException : public Exception
{
public:
	const char* what()const { return "연산 예외"; }
};
class OutputException : public Exception
{
public:
	const char* what()const { return "출력 예외"; }
};
void func1(bool exFlag)
{
	if (exFlag) throw InputException();
	cout << "1. 입력" << endl;
}
void func2(bool exFlag)
{
	if (exFlag) throw OperationException();
	cout << "2. 연산" << endl;
}
void func3(bool exFlag)
{
	if (exFlag) throw OutputException();
	cout << "3. 출력" << endl;
}
int main()
{
	try   
	{
		func1(false);   
		func2(false);
		func3(false);
	}
	catch (...)
	{
		cout << "예외 : "<< endl;
	}
}

#include <iostream>
using namespace std;
void function(int data)
{
	throw "100";
}
int main()
{
	try
	{
		function(1);
	}
	catch (int ex)
	{
		cout << "예외 : " << ex << endl;
	}
}

#include <iostream>
using namespace std;
void function(int data)
{
	throw "임의의 예외!";
}
int main()
{
	
	try   //트라이 블록에서 예외를 체크 여기서 문제가 발생하게 되면
	{
		function(10);
	}
	catch (...)  // ...은 최상위 예외
	{
		cout << "예외 발생!" << endl;
	}
}

//#include <iostream>
//using namespace std;
//class Shape
//{
//public:
//	virtual ~Shape() {}
//	virtual void Draw()const = 0;
//};
//class Rect : public  Shape
//{
//public:
//	void Draw()const { cout << "Rect" << endl; }
//};
//class Circle : public Shape  
//{
//public:
//	void Draw()const { cout << "Circle" << endl; }
//	void PrintRadius()const { cout << "raidus : xxx" << endl; }
//};
//;
//int main()
//{
//	Shape* shapeList[] = { (Shape*)(Rect*)new Rect, new Circle, new Rect, new Rect, new Circle };
//	for (auto p : shapeList)
//		p->Draw();
//	for (auto p : shapeList)
//		if (typeid(Circle) == typeid(*p))
//		((Circle*)(Shape*)p)->PrintRadius();
//}
//
//
//#include <iostream>
//using namespace std;
//class ConstData
//{
//	int arr[5] = { 1,2,3,4,5 };
//public:
//	ConstData() :arr{ 1,2 } { }
//	void Print()const
//	{
//		int n = 100;
//		//arr = &n;
//		//arr[0] = n;
//		for (auto item : arr)
//			cout << item << " ";
//		cout << endl;
//	}
//	const int* GetArray()const
//	{
//		//arr[0]= 100; 콘스트기때문에 못바꿈 오류!
//		return arr;
//	}
//	const int& GetItem()const
//	{
//		//arr[0]= 100; 콘스트기때문에 못바꿈 오류!
//		return arr[0];
//	}
//	bool operator==(const ConstData& arg)const
//	{
//		//arg.arr[0] = 100; 콘스트 떼면 오류는 없지만 arg가 박살
//		return arr == arg.arr;
//	}
//	void SetData(int idx, int data)
//	{
//		arr[0] = data;
//	}
//};
//void PrintData() //함수 뒤에 const는 객체 자신의 내용을 변경하지 않겠다!!! 라는 뜻
//{
//
//}
//int main()
//{
//	const ConstData cd1; //const 를 붙이면 cd1은 이제 변경 불가능하다
//	cd1.Print();
//}
//
//#include <iostream>
//using namespace std;
//class ConstData
//{
//	int arr[5] = { 1,2,3,4,5 };
//public:
//	void Print()const
//	{
//		int n = 100;
//		//arr = &n;
//		//arr[0] = n;
//		for (auto item : arr)
//			cout << item << " ";
//		cout << endl;
//	}
//	const int* GetArray()const
//	{
//		//arr[0]= 100; 콘스트기때문에 못바꿈 오류!
//		return arr;
//	}
//	const int& GetItem()const
//	{
//		//arr[0]= 100; 콘스트기때문에 못바꿈 오류!
//		return arr[0];
//	}
//	bool operator==(const ConstData& arg)const
//	{
//		//arg.arr[0] = 100; 콘스트 떼면 오류는 없지만 arg가 박살
//		return arr == arg.arr;
//	}
//	void SetData(int idx, int data)
//	{
//		arr[0] = data;
//	}
//};
//void PrintData() //함수 뒤에 const는 객체 자신의 내용을 변경하지 않겠다!!! 라는 뜻
//{
//
//}
//int main()
//{
//	const ConstData cd1; //const 를 붙이면 cd1은 이제 변경 불가능하다
//	cd1.Print();
//	//cd1.SetData(0,100);
//	ConstData cd2;
//
//	//cd1.GetArray()[0] = 100;
//	//cd1.GetItem() = 100;
//	//cd1.Print();
//	if(cd2.GetItem() =100)
//		cout << "cd2.GetItem() == 0" << endl;
//	cd2.Print();
//	cout << cd1.GetArray() << endl;
//}
