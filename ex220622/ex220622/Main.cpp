#include <iostream> 
using namespace std;
struct Point
{
private:
	int x = 0;
	int y = 0;
	char _mark() { return ','; }
public:
	void Print()
	{
		cout << x << _mark() << y << endl;
	}
	void SetX(int _x)
	{
		x = _x;
	}
};
int main()
{
	Point pt;
	Point pt2;
	Point pt3;

	if (pt.y >= 0)
	pt.y = 100; 

	pt.SetX(10);
	pt.Print();
	pt.SetX(20);
	pt2.Print();
	pt.SetX(30);

	pt3.Print();

}

#include <iostream> 
using namespace std;
struct Point
{
	int x = 0;
	int y = 0;

	void Print()
	{
		cout << x << "," << y << endl;
	}
	void SetX(int _x)
	{
		x = _x;
	}
};
//포인트 클래스의 클라이언트
int main()
{
	Point pt;
	Point pt2;
	Point pt3;

	//if (pt.y >= 0)

	//pt.y = 100; //캡슐화를 꺴음.

	pt.SetX(10);
	pt.Print();
	pt.SetX(20);

	pt2.Print();
	pt.SetX(30);

	pt3.Print();

}

#include <iostream> 
using namespace std;
struct Point
{
	int x = 0;
	int y = 0;

	void Print()
	{
		cout << x << "," << y << endl;
	}
	void SetX(int _x)
		x = _x;
};
int main()
{	
	Point pt;
	Point pt2;
	Point pt3;

	pt.SetX(10);
	pt.Print();
	pt.SetX(20);

	pt2.Print();
	pt.SetX(30);

	pt3.Print();

}

#include <iostream> 
using namespace std;
struct Point
{
	int x = 0;
	int y = 0;

	void Print()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	Point pt;
	Point pt2;
	Point pt3;
	pt.Print();
	pt2.Print();
	pt3.Print();

}

#include <iostream> 
using namespace std;
struct Point
{
	int x=0;
	int y=0;

	void Print()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	Point pt ;
	pt.Print();

}

#include <iostream> 
using namespace std;
struct Point
{
	int x;
	int y;

	void Print()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	Point pt = { 2,3 };
	pt.Print();

}

#include <iostream> 
using namespace std;
struct Point
{
	int x;
	int y;

	Point(int _x, int _y)  //생성자 (약속 된 함수)객체가 생성 될 때 자동적으로 생성되는 함수
	{   //객체를 
		x = _x;
		y = _y;
		cout << "Point()" << endl;
	}
	~Point()  //소멸자
	{
		x = 0;
		y = 0;
		cout << "~Point()" << endl;

	}
	void PrintPoint()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	{
		Point pt(2, 3);

		pt.PrintPoint();
	}
	cout << "end main()" << endl;
}

#include <iostream> 
using namespace std;
struct Point
{
	int x;
	int y;

	Point(int _x, int _y)  //생성자 (약속 된 함수)객체가 생성 될 때 자동적으로 생성되는 함수
	{   //객체를 
		x = _x;
		y = _y;
		cout << "Point()" << endl;
	}
	~Point()  //소멸자
	{
		x = 0;
		y = 0;
		cout << "~Point()" << endl;

	}
	void PrintPoint()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	{
		Point pt(2, 3);

		pt.PrintPoint();
	}
	cout << "end main()" << endl;
}

#include <iostream> 
using namespace std;
struct Point
{
	int x;
	int y;

	void InitPoint(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void UninitPoint()
	{
		x = 0;
		y = 0;
	}
	void PrintPoint()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	Point pt;

	pt.InitPoint(2, 3);
	pt.PrintPoint();
	pt.UninitPoint();
}

#include <iostream> 
using namespace std;
struct Point
{
	int x;
	int y;

	void InitPoint(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void UninitPoint()
	{
		x = 0;
		y = 0;
	}
	void PrintPoint()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	Point pt;

	pt.InitPoint( 2, 3);
	pt.PrintPoint();
	pt.UninitPoint();
}

#include <iostream> 
using namespace std;

inline int Max(int a, int b)
{
	return (((a) > (b)) ? (a) : (b));
}
int main()
{
	int n1 = 10;
	int n2 = 20;

	cout << Max(++n1, ++n2) << endl;
	cout << Max(++n1, ++n2) << endl;
	cout << Max(++n1, ++n2) << endl;

	++n1, ++n2;
	cout << (((n1) > (n2)) ? (n1) : (n2)) << endl;
	cout << Max(++n1, ++n2) << endl;
	cout << Max(++n1, ++n2) << endl;
	cout << Max(++n1, ++n2) << endl;
	cout << n1 << ',' << n2 << endl;
}

#include <iostream> 
using namespace std;

inline int Max(int a, int b) 
{
	return (((a) > (b)) ? (a) : (b));
}
int main()
{
	int n1 = 10;
	int n2 = 20;

	cout << Max(++n1, ++n2) << endl;
	cout << Max(++n1, ++n2) << endl;
	cout << Max(++n1, ++n2) << endl;

	++n1, ++n2;
	cout << (((n1) > (n2)) ? (n1) : (n2)) << endl;
	cout << Max(++n1, ++n2) << endl;
	cout << Max(++n1, ++n2) << endl;
	cout << Max(++n1, ++n2) << endl;
	cout << n1 << ',' << n2 << endl;
}

#include <iostream> 
using namespace std;

#define Max(a,b)(( (a) > (b)) ? (a) : (b))
int main()
{
	int n1 = 10;
	int n2 = 20;

	cout << Max(++n1, ++n2) << endl;
	cout << n1 << ',' << n2 << endl;
}

#include <iostream> 
using namespace std;

int main()
{
	bool b = true;

	if (b)
		cout << "true" << endl;

	cout << b << endl;
	cout << false << endl;
}

#include <iostream> 
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string s = "Hello!";

	cout << s << endl;
	if (s == "Hello!")
		cout << "True" << endl;
	cout << s[0] << ',' << s[1] << endl;

	s = "Hi!";
	s[0] = 'Z';
	cout << s <<  endl;
}

#include <iostream> 
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	const char* s1 = "Hello!";
	string s2 = "Hello!";

	//s1 += "?";
	s2 += "?";
	cout << s1 << endl;
	cout << s2 << endl;
}

#include <iostream> 
#include <cstdio>
using namespace std;
namespace MyName
{
	int x = 100;
	void Print(int data)
	{
		cout << "MyName::Print() : " << data << endl;
	}
}
int main()
{
	cout << "Hello!" << endl;
	cout << "x : " << MyName::x << endl;
	MyName::Print(100);
}

#include <iostream> 
#include <cstdio>
namespace MyName
{
	int x = 100;
	void Print(int data)
	{
		std::cout << "MyName::Print() : " << data << std::endl;
	}
}
using namespace MyName; 
int main()
{
	std::cout << "Hello!" << std::endl;
	std::cout << "x : " << x << std::endl;
	Print(100);
}

#include <iostream> 
#include <cstdio>
namespace MyName
{
	int x = 100;
	void Print(int data)
	{
		std::cout << "MyName::Print() : " << data << std::endl;
	}
}
using MyName::x;
using MyName::Print;
int main()
{
	std::cout << "Hello!" << std::endl;
	std::cout << "x : " << x << std::endl;
	Print(100);
}

#include <iostream> 
#include <cstdio>
namespace MyName
{
	int x = 100;
	void Print(int data)
	{
		std::cout << "MyName::Print() : " << data << std::endl;
	}
}
int main()
{
	std::cout << "Hello!" << std::endl;
	std::cout << "x : " << MyName::x << std::endl;
	MyName::Print(100);
}

#include <iostream> 
#include <cstdio>
using namespace std;

void Print(int a = 0, int b = 0, int c = default())
{
	cout << a << ',' << b << ',' << c << endl;
}
int main()
{
	Print(10, 20);
}

#include <iostream> 
#include <cstdio>
using namespace std;

void Print(int a = 0, int b = 0, int c = int())
{
	cout << a << ',' << b << ',' << c << endl;
}
int main()
{
	Print(10, 20);
}

#include <iostream> 
#include <cstdio>
using namespace std;

struct Data
{
	int a = 0;
	int b = 0;
};
int main()
{
	cout << Data().a << endl; //Data = 타입  ()는 기본 값  - 기본객체 이름없는 객체 임시객체
	cout << Data().b << endl;
	int(); //정수객체

	auto v = Data(); //데이터형식을 하나 만들어서 그 형식을 만든 다음 v에 넣어라
	cout << v.a << ',' << v.b << endl;
	
	auto v2 = Data{ 10,20 };
	cout << v2.a << ',' << v2.b << endl;

}

#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{
	cout << int() << endl;
	cout << double() << endl;

	int n = int();
	double b = double(); 
	cout << n << endl;
	cout << b << endl;

	auto v = 10L;// C언어의 auto는 변수를 의미 C++ 의 auto는 타입을 의미
	cout << v << endl;
	cout << typeid(v).name() << endl;

	auto v2 = 5.5F;
	cout << v2 << endl;
	cout << typeid(v2).name() << endl;

}

#include <iostream> 
#include <cstdio>
using namespace std;
struct Point
{
	int x = 0;
	int y = 0;
};
int main()
{
	Point* p = new Point[5];
	
	for (int i = 0; i < 5; ++i)
		cout << p[i].x << ", " << p[i].y << endl;

	delete []p;
}

#include <iostream> 
#include <cstdio>
using namespace std;
struct Point
{
	int x = 0;
	int y = 0;
};
int main()
{
	Point* p = new Point;

	cout << p->x << "," << p->y << endl;

	delete p;
}

#include <iostream> 
#include <cstdio>
using namespace std;
struct Point
{
	int x = 0;
	int y = 0;
};
int main()
{
	Point ptArray[5];

	for (int i = 0; i < 5; ++i)
		cout << ptArray[i].x << "," << ptArray[i].y << endl;
}

#include <iostream> 
#include <cstdio>
using namespace std;
struct Point
{
	int x = 0;
	int y = 0;
};
int main()
{
	Point pt;

	cout << pt.x << ',' << pt.y << endl;
}

#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{
	int* pa = new int[5]{ 10,20,30,40,50 };  //1개 초기화 유니폼초기화 여러개 이니셜라이즈 초기화
	
	for (int i = 0; i < 5; ++i)
		cout << pa[i] << endl;

	delete[]pa; //**
}

#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{

	//int* pn = new int(10);   //일반적으로 이걸사용

	int* pn = new int{ 10 };   // 특수할 경우 이걸 사용
	cout << *pn << endl;

	delete pn;
}

#include <iostream> 
#include <cstdio>
using namespace std;
//new delete
int main()
{
	//malloc은 메모리 할당만 하지만 new는 내부함수 호출까지 하게해줌
	int* pn = new int; // int 포인터
	
	*pn = 10;
	cout << *pn << endl;

	delete pn;
}

#include <iostream> 
#include <cstdio>
using namespace std;
struct Data
{
	char name[20];
	int age;
	char addr[50];
};
void Print(int data)
{
	cout << "int : " << data << endl;
}
void Print(const Data& data)   //인파라미터 참조  **
{
	//data.age = 100;
	cout << "name : " << data.name << ',' << "age : " << data.age << ',' << "addr : " << data.addr << endl;
}

int main()
{
	Print(10);
	Data d = { "홍길동", 25, "경기 파주시" };
	Print(d);
}

#include <iostream> 
#include <cstdio>
using namespace std;
struct Data
{
	char name[20];
	int age;
	char addr[50];
};
void Print(int data)
{
	cout << "int : " << data << endl;
}
void Print(Data data)
{
	cout << "name : " << data.name << ',' << "age : " << data.age << ',' << "addr : " << data.addr << endl;
}

int main()
{
	Print(10);
	Data d = { "홍길동", 25, "경기 파주시" };
	Print(d);
}

#include <iostream> 
#include <cstdio>
 using namespace std;
struct DataParam
{
	int a = 0;
	int b = 0;
	int c = 0;
};
void Print(DataParam d)
{
	cout << d.a << ',' << d.b << ',' << d.c << endl;
}

int main(void)
{
	Print(DataParam());
	//Print(DataParam(10, 20, 30)); 이 방식으로 하려면 생성자가 필요하다.
	Print(DataParam{});
	Print(DataParam{ 10, 20, 30 });
	return 0;
}


#include <iostream> 
#include <cstdio>
using namespace std;
//FUNTION OVERLODING  <==> FINTION OFERRDING(함수 재정의)
void Print(int a = 0,  int b =0 , int c= 0)
{
	cout << a < b << c << std::endl;
}
void Print(const char* s)
{
	cout << s << endl;
}
int main()
{
	//함수 오버로딩
	Print(10, 20, 30);
	Print("C");
}

#include <iostream> 
#include <cstdio>
 using namespace std;
//FUNTION OVERLODING  <==> FINTION OFERRDING(함수 재정의)
void Print(int a, int b, int c)   
{
	cout << a <  b << c << std::endl;  
}
void Print(const char* s)
{
	cout << s << endl;
}
int main()
{
	//함수 오버로딩
	Print(10, 20, 30);
	Print("'C");
}

#include <iostream> 
#include <cstdio>
using namespace std;

void Print(int a, int b)    // 인파라미터
{
	cout << a << ',' << b << endl;
}
void Swap(int& a, int& b)  // 아웃파라미터
{
	int t = a;
	a = b;
	b = t;
}
int main()
{
	int a = 10;
	int b = 20;

	Print(a, b);
	Swap(a, b);
	Print(a, b);
}

#include <iostream> 
#include <cstdio>
using namespace std;

void Print(int a, int b)
{
	cout << a << ',' << b << endl;
}
void Swap(int& a , int& b)
{
	int t = a;
	a = b;
	b = t;
}
int main()
{
	int a = 10;
	int b = 20;

	Print(a, b);
	Swap(a, b);
	Print(a, b);
}

#include <iostream> 
#include <cstdio>
using namespace std;

void Print(int a, int b)
{
	cout << a << ',' << b << endl;
}
void Swap(int* pa, int* pb)
{
	int t = *pa;
	*pa = *pb;
	*pb = t;
}
int main()
{
	int a = 10;
	int b = 20;

	Print(a, b);
	Swap(&a, &b);
	Print(a, b);
}

#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{
	int a = 10;
	int* p = &a;
	int& r = a;    //초기화 시에만 참조 할당 가능 !!!

	int& rr;
	rr = a;

	cout << a << "," << *p << "," << r << endl;
	cout << &a << "," << p << "," << &r << endl;
}

#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{
	int a = 10;
	int* p = &a;
	int& r = a;

	cout << a << "," << *p << "," << r << endl;
	cout << &a << "," << p << "," << &r << endl;
}

#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{
	int a = 10;
	int b = a;
	int& c = a;

	cout << a << "," << b << "," << c << endl;
	cout << &a << "," << &b << "," << &c << endl;
}

#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{//cpp 초기화 문법
	int a = 100;
	int b(100);
	int c{ 100 };

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{
	int n = 100;
	cout << &n << endl;
	cout << n << endl;
	cout << (int)'A' << endl; // 정수로 나타내조 'A'를 ! 타입을 인식한당
}

#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;    // >> 입력스트림연산자   

	int b;
	scanf_s("%d", &b);
	cout << "int : " << n << "," << b << endl;
}

#include <iostream> 
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int b;
	scanf_s("%d", &b);
	cout << "int : " << n << "," << b << endl;
}

#include <iostream> 
using namespace std; 

int main()
{
	int n;
	cin >> n;
	cout << "int : " << n << endl;
}

#include <iostream> //기본헤더
using namespace std; // std = 스탠다드

int main()
{
	//  cout : ostream 객체
	//   << : ostream 연산자 
	//  endl : '\n'상수값
	cout << 100 << " " << 5.5 << " " << 'A' << " " << "Hello!" << endl;
}

#include <iostream> //기본헤더
using namespace std; // std = 스탠다드

int main()
{
	//  cout : ostream 객체
	//   << : ostream 연산자 
	//  endl : '\n'상수값
	cout << 100 << endl;
	cout << 5.5 << endl;
	cout << 'A' << endl;
	cout << "Hello!" << endl;
}
