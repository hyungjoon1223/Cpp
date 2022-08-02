#include <iostream>
using namespace std;
//깊은 복사, 옅은 복사
class Point
{
    int x, y;
public:
    Point(int x = 0, int y = 0) :x(x), y(y)
    {

        cout << "Point()" << endl;
    }
    Point(const Point& arg) :x(arg.x), y(arg.y)
    {
        cout << "copy Point()" << endl;
    }

    void Print() const
    {
        cout << x << ',' << y << endl;
    }
};
void PrintPoint(Point& arg)
{
    arg.Print();
}
Point pt;
Point& CreatePoint()
{
    return pt;   // 3. 객체가 리턴(값 객체)
}
int main()
{
    Point pt1(2, 3);
    Point& pt2 = pt1; //1. 경우

    PrintPoint(pt1); //2. 함수의 인수(값 객체)로 전달
    CreatePoint() = Point(0,0);
    pt.Print();
}

#include <iostream>
using namespace std;
//깊은 복사, 옅은 복사
class Point
{
    int x, y;
public:
    Point(int x = 0, int y = 0) :x(x), y(y)
    {

        cout << "Point()" << endl;
    }
    Point(const Point& arg) :x(arg.x), y(arg.y)
    {
        cout << "copy Point()" << endl;
    }

    void Print() const
    {
        cout << x << ',' << y << endl;
    }
};
void PrintPoint(Point arg)
{
    arg.Print();
}
Point pt;
Point CreatePoint()
{
    
    return pt;   // 3. 객체가 리턴(값 객체)
}
int main()
{
    Point pt1(2, 3);
    Point pt2 = pt1; //1. 경우

    PrintPoint(pt1); //2. 함수의 인수(값 객체)로 전달
    CreatePoint();
}

#include <iostream>
using namespace std;
//깊은 복사, 옅은 복사
class Point
{
    int x, * py;
public:
    Point(int x = 0, int y = 0) :x(x), py(NULL)
    {
        py = new int(y);
        cout << "Point()" << endl;
    }
    Point(const Point& arg) :x(arg.x), py(NULL)
    {
        py = new int(*arg.py);
    }
    //Point(const Point& arg) :x(arg.x), y(arg.y)  //복사 생성자의 기본적 형태
    //{  // 메모리 복사, 멤버대 멤버 복사, 얕은 복사
    //   cout << "copy Point()" << endl;
    //}
    ~Point()
    {
        delete py;
        cout << "~Point()" << endl;
    }
    void Print() const
    {
        cout << x << ',' << *py << endl;
    }
};
int main(void)
{
    Point pt1(2, 3);
    Point pt2(4, 5);

    pt2 = pt1;   //복사 대입 연산자(중복) 
    pt1.Print();
    pt2.Print();
    return 0;
}

#include <iostream>
using namespace std;
//깊은 복사, 옅은 복사
class Point
{
    int x, * py;
public:
    Point(int x = 0, int y = 0) :x(x), py(NULL)
    {
        py = new int(y);
        cout << "Point()" << endl;
    }
    Point(const Point& arg) :x(arg.x), py(NULL)
    {
        py = new int(*arg.py);
    }
    //Point(const Point& arg) :x(arg.x), y(arg.y)  //복사 생성자의 기본적 형태
    //{  // 메모리 복사, 멤버대 멤버 복사, 얕은 복사
    //   cout << "copy Point()" << endl;
    //}
    ~Point()
    {
        delete py;
        cout << "~Point()" << endl;
    }
    void Print() const
    {
        cout << x << ',' << *py << endl;
    }
};
int main(void)
{
    Point pt1(2, 3);
    Point pt2(pt1);

    pt1.Print();
    //pt2.Print();
    return 0;
}

#include <iostream>
using namespace std;
//깊은 복사, 옅은 복사
class Point
{
    int x, * py;
public:
    Point(int x = 0, int y = 0) :x(x), py(NULL)
    {
        py = new int(y);
        cout << "Point()" << endl;
    }
    Point(const Point& arg) :x(arg.x), py(NULL)
    {
        py = new int(*arg.py);
    }
    //Point(const Point& arg) :x(arg.x), y(arg.y)  //복사 생성자의 기본적 형태
    //{  // 메모리 복사, 멤버대 멤버 복사, 얕은 복사
    //   cout << "copy Point()" << endl;
    //}
    ~Point()
    {
        delete py;
        cout << "~Point()" << endl;
    }
    void Print() const
    {
        cout << x << ',' << *py << endl;
    }
};
int main(void)
{
    Point pt1(2, 3);
    Point pt2(pt1);

    pt1.Print();
    //pt2.Print();
    return 0;
}

#include <iostream>
using namespace std;
class Point
{
private:   
	int x, * py;  //참조상태 객체
public:
	Point(int x = 0, int y = 0) :x(x), py(NULL)
	{
		py = new int(y);
		cout << "Point()" << endl;
	}
	//Point(const Point& arg) :x(arg.x), y(arg.y) { //복사 생성자 arg를 복사해서 자신의 멤버를 똑같이 만들어낸다
	//	cout << "copy Point()" << endl;
	//}
	~Point() {
		delete py;
		cout << "~Point()" << endl;
	}
	void Print() const { cout << x << ',' << *py << endl; }
};
int main()
{
	Point pt1(2, 3);
	Point pt2(pt1);

	pt1.Print();
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point
{
private:
	int x, *py;
public:
	Point(int x = 0, int y = 0) :x(x), py(NULL)
	{
		py = new int(y);
		cout << "Point()" << endl;
	}
	//Point(const Point& arg) :x(arg.x), y(arg.y) { //복사 생성자 arg를 복사해서 자신의 멤버를 똑같이 만들어낸다
	//	cout << "copy Point()" << endl;
	//}
	~Point() { 
		delete py;
		cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << py << endl; }
};
int main()
{
	Point pt1(2, 3);
	Point pt2(pt1);

	pt1.Print();
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point
{
private:   
	int x, y;
public:
	Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	Point(const Point& arg):x(arg.x),y(arg.y) { //복사 생성자 arg를 복사해서 자신의 멤버를 똑같이 만들어낸다
		cout << "copy Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	Point pt1(2, 3);
	Point pt2(pt1);

	pt1.Print();
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point
{
private:   //생략 가능하지만 struct는 생략하면 public이 됨.
	int x, y;
public:
	Point(int x = 0, int y = 0) :x(x), y(y)
	{
		cout << "Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	Point pt1(2, 3);
	Point pt2(pt1);//Point pt2 = pt1; cpp의 초기화 / c의 초기화

	pt1.Print();
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point
{
private:   //생략 가능하지만 struct는 생략하면 public이 됨.
	int x, y;
public:
	Point(int x = 0, int y = 0) :x(x), y(y)
	{
	}
	void Print() const { cout << x << ',' << y << endl; }
};
int main()
{
	Point pt1(2, 3);
	Point pt2 = pt1;

	pt1.Print();
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int x = 0, int y = 0);
	void Print() const;
	void SetX(int _x);
	void SetY(int _y);
	int GetX() const;
	int GetY() const;
	const Point* GetThis()const;
	
};
Point::Point(int x, int y) :x(x), y(y)  //초기화
{
}
void Point::Print() const
{
	cout << this->x << "," << this->y << endl;
}
void Point::SetX(int _x)
{
	x = _x;
}
void Point::SetY(int _y)
{
	y = _y;
}
int Point::GetX() const { return x; }
int Point::GetY() const { return y; }
const Point* Point::GetThis()const {
	return this;
}

void PrintPoint(const Point& arg)  
{
	arg.Print();
}
int main()  
{
	Point pt(2, 3);
	pt.Print();
	cout << &pt << ',' << pt.GetThis() << endl;

	Point pt2(4, 5);
	pt2.Print();
	cout << &pt2 << ',' << pt2.GetThis() << endl;

}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int x = 0, int y = 0)  //초기화
	{
		this->x = x;
		(*this).y = y;
	}
	void Print() const
	{
		cout << this->x << "," << this->y << endl;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
	const Point* GetThis()const {
		return this;
	}
};
void PrintPoint(const Point& arg)  //const 인터페이스만 사용가능!
{
	arg.Print();
}
int main()  //초기화
{
	Point pt(2, 3);
	pt.Print();
	cout << &pt << ',' << pt.GetThis() << endl;

	Point pt2(4, 5);
	pt2.Print();
	cout << &pt2 << ',' << pt2.GetThis() << endl;

}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int x = 0, int y = 0)  //초기화
	{
		this->x = x;
		(*this).y = y;
	}
	void Print() const
	{
		cout << this->x << "," << this->y << endl;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
	const Point* GetThis()const {
		return this;
	}
};
void PrintPoint(const Point& arg)  //const 인터페이스만 사용가능!
{
	arg.Print();
}
int main()  //초기화
{
	Point pt(2, 3);
	pt.Print();
	cout << &pt << ',' << pt.GetThis() << endl;

	Point pt2(4, 5);
	pt2.Print();
	cout << &pt2 << ',' << pt2.GetThis() << endl;

}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int x = 0, int y = 0)  //초기화
	{
		this->x = x;
		(*this).y = y;
	}
	void Print() const
	{
		cout << this->x << "," << this->y << endl;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
};
void PrintPoint(const Point& arg)  //const 인터페이스만 사용가능!
{
	arg.Print();
}
int main()  //초기화
{
	Point pt(2, 3);
	pt.Print();

	Point pt2(4, 5);
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0) :x(_x), y(_y)  //초기화
	{
	}
	void Print() const
	{
		cout << this->x << "," << this->y << endl;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
};
void PrintPoint(const Point& arg)  //const 인터페이스만 사용가능!
{
	arg.Print();
}
int main()  //초기화
{
	Point pt(2, 3);
	pt.Print();

	Point pt2(4, 5);
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0) :x(_x), y(_y)  //초기화
	{
	}
	void Print() const
	{
		cout << x << "," << y << endl;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
};
void PrintPoint(const Point& arg)  //const 인터페이스만 사용가능!
{
	arg.Print();
}
int main()  //초기화
{
	Point pt(2, 3);

	pt.Print();

	const Point cpt(4, 5);
	cpt.Print();

}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0) :x(_x), y(_y)
	{
		//x = _x;
		//y = _y;
	}
	void Print() const
	{
		cout << x << "," << y << endl;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
};
void PrintPoint(const Point& arg)  //const 인터페이스만 사용가능!
{
	arg.Print();
}
int main()  //초기화
{
	Point pt(2, 3);

	pt.Print();

	const Point cpt(4, 5);
	cpt.Print();

	int a;
	a = 10;

	int b = 20;
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	void Print() const
	{
		cout << x << "," << y << endl;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
};
void PrintPoint(const Point& arg)  //const 인터페이스만 사용가능!
{
	arg.Print();
}
int main()
{
	Point pt(2, 3);

	pt.Print();

	pt.SetX(pt.GetX() + 10);
	pt.SetY(pt.GetY() + 10);
	pt.Print();
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	void Print() const
	{
		cout << x << "," << y << endl;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
};
void PrintPoint(const Point& arg)  //const 인터페이스만 사용가능!
{
	arg.Print();
}
int main()
{
	Point pt(2, 3);

	pt.Print();

	pt.SetX(pt.GetX() + 10);
	pt.SetY(pt.GetY() + 10);
	pt.Print();
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	void Print() const
	{
		cout << x << "," << y << endl;
	}
	void SetX (int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	int GetX() const { return x; }
	int GetY() const { return y; }
};
void PrintPoint(const Point& arg)  //const 인터페이스만 사용가능!
{
	arg.Print();
}
int main()
{
	Point pt(2, 3);

	pt.Print();

	pt.SetX(pt.GetX() + 10);
	pt.SetY(pt.GetY() + 10);
	pt.Print();
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
};
int main()
{
	Point* pa = new Point[5];
	for (int i = 0; i < 5; ++i)
		pa[i].Print();

	for (int i = 0; i < 5; ++i)
	{
		pa[i].SetX(i + 1);
		pa[i].SetY(i + 1);
	}
	for (int i = 0; i < 5; ++i)
		pa[i].Print();
		

	delete []pa;

}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
void CreatePoint1()
{
	static Point pt;
	pt.Print();
}
void CreatePoint2()
{
	static Point pt2;
	pt2.Print();
}
void CreatePoint3()
{
	static Point pt3;
	pt3.Print();
}
int main()
{
	Point* p = new Point;
	p->Print();
	
	delete p;
	cout << "end main()" << end;
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
void CreatePoint1()
{
	static Point pt; 
	pt.Print();
}
void CreatePoint2()
{
	static Point pt2;
	pt2.Print();
}
void CreatePoint3()
{
	static Point pt3;
	pt3.Print();
}
int main()
{
	CreatePoint1();
	CreatePoint1();
	CreatePoint1();
	//CreatePoint2();
	//CreatePoint3();
}


#include <iostream>
using namespace std;
void PrintInteger()
{
	int n = 0;
	static int sn = 0;

	n = 0;
	sn = 0;
	cout << ++n << ',' << ++sn << endl;
}
int main()
{
	PrintInteger();
	PrintInteger();
	PrintInteger();
}

#include <iostream>
using namespace std;
void PrintInteger()
{
	int n = 0;
	static int sn = 0;

	cout << ++n << ',' << ++sn << endl;
}
int main()
{
	PrintInteger();
	PrintInteger();
	PrintInteger();
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
void CreatePoint1()
{
	static Point pt; 
	pt.Print();
}
void CreatePoint2()
{
	static Point pt2;
	pt2.Print();
}
void CreatePoint3()
{
	static Point pt3;
	pt3.Print();
}
int main()
{
	CreatePoint1();
	CreatePoint1();
	CreatePoint1();
	//CreatePoint2();
	//CreatePoint3();
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
void CreatePoint() 
{
	static Point pt;  //프로그램 시작시 생성되어서 종료시 사라짐 = static
	pt.Print();
}
int main()
{
	CreatePoint();
	CreatePoint();
	CreatePoint();
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
void CreatePoint()
{
	Point pt;
	pt.Print();
}
int main()
{
	CreatePoint();
	CreatePoint();
	CreatePoint();
}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	cout << "start main()" << endl;
	{ 
		static Point spt(4, 5);
		Point pt1;
		Point pt2(2, 3);

		pt1.Print();
		pt2.Print();

		cout << "pt1 : " << sizeof(pt1) << endl;
		cout << "pt1 : " << sizeof(pt1) << endl;
	}
	cout << "end main()" << endl;

}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
Point gpt(4, 5);
int main()
{
	cout << "start main()" << endl;
	{ //유효범위 생명주기
		Point pt1;
		Point pt2(2, 3);

		pt1.Print();
		pt2.Print();

		cout << "pt1 : " << sizeof(pt1) << endl;
		cout << "pt1 : " << sizeof(pt1) << endl;
	}
	cout << "end main()" << endl;

}

#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	Point pt1;
	Point pt2(2, 3);

	pt1.Print();
	pt2.Print();

	cout << "pt1 : " << sizeof(pt1) << endl;
	cout << "pt1 : " << sizeof(pt1) << endl;
}

#include <iostream>
using namespace std;
class Point   
{
	int x, y;
public:

	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	Point pt1;
	Point pt2(2, 3);

	pt1.Print();
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point   //struct와 class는 똑같음
{
	int x, y;
public:
	Point()   //인수 없는 생성자
	{
		x = 0;
		y = 0;
		cout << "Point()" << endl;
	}// 오버훅 
	Point(int _x, int _y) //인수를 가지는 생성자 
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	Point pt1;
	Point pt2(2, 3);

	pt1.Print();
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point   //struct와 class는 똑같음
{
	int x, y;
public:
	Point()   //인수 없는 생성자
	{
		x = 0;
		y = 0;
		cout << "Point()" << endl;
	}// 오버훅 
	Point(int _x, int _y) //인수를 가지는 생성자 
	{
		x = _x;
		y = _y;
		cout << "Point(int, int)" << endl;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	Point pt1;
	Point pt2(2, 3);

	pt1.Print();
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point   //struct와 class는 똑같음
{
	int x, y;
public:
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	Point pt1;
	Point pt2(2, 3);

	pt1.Print();
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point   //struct와 class는 똑같음
{
	int x, y;
public:
	void Print() 
	{
		cout << x << "," << y << endl;
	}
};
int main()
{
	Point pt1;
	Point pt2(2,3);

	pt1.Print();
	pt2.Print();
}
