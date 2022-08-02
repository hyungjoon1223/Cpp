#include <iostream>
using namespace std;
//���� ����, ���� ����
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
    return pt;   // 3. ��ü�� ����(�� ��ü)
}
int main()
{
    Point pt1(2, 3);
    Point& pt2 = pt1; //1. ���

    PrintPoint(pt1); //2. �Լ��� �μ�(�� ��ü)�� ����
    CreatePoint() = Point(0,0);
    pt.Print();
}

#include <iostream>
using namespace std;
//���� ����, ���� ����
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
    
    return pt;   // 3. ��ü�� ����(�� ��ü)
}
int main()
{
    Point pt1(2, 3);
    Point pt2 = pt1; //1. ���

    PrintPoint(pt1); //2. �Լ��� �μ�(�� ��ü)�� ����
    CreatePoint();
}

#include <iostream>
using namespace std;
//���� ����, ���� ����
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
    //Point(const Point& arg) :x(arg.x), y(arg.y)  //���� �������� �⺻�� ����
    //{  // �޸� ����, ����� ��� ����, ���� ����
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

    pt2 = pt1;   //���� ���� ������(�ߺ�) 
    pt1.Print();
    pt2.Print();
    return 0;
}

#include <iostream>
using namespace std;
//���� ����, ���� ����
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
    //Point(const Point& arg) :x(arg.x), y(arg.y)  //���� �������� �⺻�� ����
    //{  // �޸� ����, ����� ��� ����, ���� ����
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
//���� ����, ���� ����
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
    //Point(const Point& arg) :x(arg.x), y(arg.y)  //���� �������� �⺻�� ����
    //{  // �޸� ����, ����� ��� ����, ���� ����
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
	int x, * py;  //�������� ��ü
public:
	Point(int x = 0, int y = 0) :x(x), py(NULL)
	{
		py = new int(y);
		cout << "Point()" << endl;
	}
	//Point(const Point& arg) :x(arg.x), y(arg.y) { //���� ������ arg�� �����ؼ� �ڽ��� ����� �Ȱ��� ������
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
	//Point(const Point& arg) :x(arg.x), y(arg.y) { //���� ������ arg�� �����ؼ� �ڽ��� ����� �Ȱ��� ������
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
	Point(const Point& arg):x(arg.x),y(arg.y) { //���� ������ arg�� �����ؼ� �ڽ��� ����� �Ȱ��� ������
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
private:   //���� ���������� struct�� �����ϸ� public�� ��.
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
	Point pt2(pt1);//Point pt2 = pt1; cpp�� �ʱ�ȭ / c�� �ʱ�ȭ

	pt1.Print();
	pt2.Print();
}

#include <iostream>
using namespace std;
class Point
{
private:   //���� ���������� struct�� �����ϸ� public�� ��.
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
Point::Point(int x, int y) :x(x), y(y)  //�ʱ�ȭ
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

	Point(int x = 0, int y = 0)  //�ʱ�ȭ
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
void PrintPoint(const Point& arg)  //const �������̽��� ��밡��!
{
	arg.Print();
}
int main()  //�ʱ�ȭ
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

	Point(int x = 0, int y = 0)  //�ʱ�ȭ
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
void PrintPoint(const Point& arg)  //const �������̽��� ��밡��!
{
	arg.Print();
}
int main()  //�ʱ�ȭ
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

	Point(int x = 0, int y = 0)  //�ʱ�ȭ
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
void PrintPoint(const Point& arg)  //const �������̽��� ��밡��!
{
	arg.Print();
}
int main()  //�ʱ�ȭ
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

	Point(int _x = 0, int _y = 0) :x(_x), y(_y)  //�ʱ�ȭ
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
void PrintPoint(const Point& arg)  //const �������̽��� ��밡��!
{
	arg.Print();
}
int main()  //�ʱ�ȭ
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

	Point(int _x = 0, int _y = 0) :x(_x), y(_y)  //�ʱ�ȭ
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
void PrintPoint(const Point& arg)  //const �������̽��� ��밡��!
{
	arg.Print();
}
int main()  //�ʱ�ȭ
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
void PrintPoint(const Point& arg)  //const �������̽��� ��밡��!
{
	arg.Print();
}
int main()  //�ʱ�ȭ
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
void PrintPoint(const Point& arg)  //const �������̽��� ��밡��!
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
void PrintPoint(const Point& arg)  //const �������̽��� ��밡��!
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
void PrintPoint(const Point& arg)  //const �������̽��� ��밡��!
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
	static Point pt;  //���α׷� ���۽� �����Ǿ ����� ����� = static
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
	{ //��ȿ���� �����ֱ�
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
class Point   //struct�� class�� �Ȱ���
{
	int x, y;
public:
	Point()   //�μ� ���� ������
	{
		x = 0;
		y = 0;
		cout << "Point()" << endl;
	}// ������ 
	Point(int _x, int _y) //�μ��� ������ ������ 
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
class Point   //struct�� class�� �Ȱ���
{
	int x, y;
public:
	Point()   //�μ� ���� ������
	{
		x = 0;
		y = 0;
		cout << "Point()" << endl;
	}// ������ 
	Point(int _x, int _y) //�μ��� ������ ������ 
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
class Point   //struct�� class�� �Ȱ���
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
class Point   //struct�� class�� �Ȱ���
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
