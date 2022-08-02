//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Functor
//{
//	string prestring;
//	Functor(const string& msg = "data : ") :prestring(msg) {}
//	void operator()(int data)
//	{
//		cout << "data : " << data << endl;
//	}
//};
//void For_each(int* begin, int* end, Functor f)
//{
//	for (; begin != end; ++begin)
//		f(*begin);
//}
//int main()
//{
//	int arr[] = { 57,12,35,96,82 };
//
//	For_each(arr, arr + 5, Functor("mark:"));
//	For_each(arr, arr + 5, Functor("integer :"));
//}
//
//#include <iostream>   //�������� �ٽ� �ޱ�
//#include <algorithm>
//using namespace std;
//
//struct Functor
//{
//	string prestring;
//	Functor(const string& msg = "data : "):prestring(msg){}
//	void operator()(int data)
//	{
//		cout << "data : " << data << endl;
//	}
//};
//void For_each(int* begin, int* end, Functor f)
//{
//	for (; begin != end; ++begin)
//		f(*begin);
//}
//int main()
//{
//	int arr[] = { 57,12,35,96,82 };
//
//	For_each(arr, arr + 5, Functor("mark:"));
//	For_each(arr, arr + 5, Functor("integer :"));
//}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//void For_each(int* begin, int* end, void(*f)(int))
//{
//	for (; begin != end; ++begin)
//		f(*begin);
//}
//void PrintInt(int data)
//{
//	cout << "data : " << data << endl;
//}
//int main()
//{
//	int arr[] = { 57,12,35,96,82 };
//
//	For_each(arr, arr + 5, PrintInt);
//}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Functor // Function Object(Functor)
//{
//	void operator()(int data)const
//	{
//		cout << "data : " << data << endl;
//	}
//};
//struct Functor2 // Function Object(Functor)
//{
//	~Functor2() { cout << endl; }
//	void operator()(int data)const
//	{
//		cout << data << " ";
//	}
//};
//struct Functor3 // Function Object(Functor)
//{
//	int sum;
//	Functor3(int init):sum(init) { }
//	void operator()(int data)
//	{
//		sum += data;
//	}
//};
//void For_each(int* begin, int* end, Functor3& f)
//{
//	for (; begin != end; ++begin)
//		f(*begin);
//}
//int main()
//{
//	int arr[] = { 57,12,35,96,82 };
//
//	//For_each(arr, arr + 5, Functor());
//	Functor3 f(0);
//	For_each(arr, arr + 5, f);
//	cout << "sum : " << f.sum << endl;
//}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Functor // Function Object(Functor)
//{
//	void operator()(int data)const
//	{
//		cout << "data : " << data << endl;
//	}
//};
//struct Functor2 // Function Object(Functor)
//{
//	~Functor2() { cout << endl; }
//	void operator()(int data)const
//	{
//		cout << data << " ";
//	}
//};
//void For_each(int* begin, int* end, Functor2 f)
//{
//	for (; begin != end; ++begin)
//		f(*begin);
//}
//int main()
//{
//	int arr[] = { 57,12,35,96,82 };
//
//	//For_each(arr, arr + 5, Functor());
//	For_each(arr, arr + 5, Functor2());
//}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Functor // Function Object(Functor)
//{
//	void operator()(int data)const
//	{
//		cout << "data : " << data << endl;
//	}
//};
//struct Functor2 // Function Object(Functor)
//{
//	~Functor2() { cout << endl; }
//	void operator()(int data)const
//	{
//		cout << data <<" ";
//	}
//};
//template <typename F>
//void For_each(int* begin, int* end, F f)
//{
//	for (; begin != end; ++begin)
//		f(*begin);
//}
//int main()
//{
//	int arr[] = { 57,12,35,96,82 };
//
//	For_each(arr, arr + 5, Functor());
//	For_each(arr, arr + 5, Functor2());
//}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Functor // Function Object(Functor)
//{
//	void operator()(int data)const
//	{
//		cout << "data : " << data << endl;
//	}
//};
//void For_each(int* begin, int* end, Functor f)
//{
//	for (; begin != end; ++begin)
//		f(*begin);
//}
//int main()
//{
//	int arr[] = { 57,12,35,96,82 };
//
//	For_each(arr, arr + 5, Functor());
//}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Functor // Function Object(Functor)
//{
//	void operator()(int data)const
//	{
//		cout << "data : " << data << endl;
//	}
//};
//int main()
//{
//	int arr[] = { 57,12,35,96,82 };
//
//	for_each(arr, arr + 5, Functor());
//}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Functor // Function Object(Functor)
//{
//	void operator()(int data)const
//	{
//		cout << "data : " << data << endl;
//	}
//};
//int main()
//{
//	Functor f1;
//	f1(10);   //f1.operator()(10)
//	f1(15);
//	Functor()(100); 
//}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct Functor // Function Object(Functor)
//{
//	void operator()(int data)const
//	{
//		cout << "data : " << data << endl;
//	}
//};
//int main()
//{
//	Functor f1;
//	f1(10);
//	f1(15);
//}
//
//#include <iostream>  
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	greater<int> g;
//	
//	cout << g(1, 2) << endl;
//	cout << g(15, 2) << endl;
//	cout << g(100, 20) << endl;
//}
//
//#include <iostream>  
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int arr[] = { 16,90,30,67,25 };
//
//	for (auto x : arr)
//		cout << x << " ";
//	cout << endl;
//
//	sort(arr, arr + 5);
//
//	for (auto x : arr)
//		cout << x << " ";
//	cout << endl;
//
//	sort(arr, arr + 5, greater<int>());
//
//	for (auto x : arr)
//		cout << x << " ";
//	cout << endl;
//
//}
//
////������3-12��      �ڵ� �� ¥�� �ϼ�
//#include <iostream>  
//using namespace std;
//
//class Array
//{
//public:
//    typedef unsigned int size_type;
//
//private:
//    int* buf;                                       //�������� ��ü  --> ��������� �� ������Կ����� ������
//    size_type count;
//
//public:
//
//    Array() :buf(nullptr), count(0) {
//        buf = new int[100];
//    } //������
//    Array(const Array& arg) :buf(nullptr), count(arg.count)         //���������  
//    {
//        buf = new int[100];
//        for (size_type i = 0; i < count; ++i)
//        {
//            buf[i] = arg.buf[i];
//        }
//    }
//    ~Array() {
//        delete[] buf;
//    }
//    void push_back(int data)
//    {
//        buf[count++] = data;
//    }
//    int& at(int idx) { return buf[idx]; }
//
//    const int& at(size_type idx)const {              //�Լ��� ���    ������ ����� ���ܸ� Ȯ���� �� ������ �ӵ��� ����
//        if (0 <= idx && idx < count)
//            return buf[idx];
//        else
//            throw out_of_range("idx ������ ������ϴ�");
//    }
//
//    const int& operator[](int idx)const { return buf[idx]; }  //�����ڸ� ���         �ӵ��� ����
//    int operator[](int idx) { return buf[idx]; }             //�����ڸ� ���         �ӵ��� ����
//
//    size_type size() const { return count; }
//
//    bool operator==(const Array& arg)         //��ü�� ������ �Ǵ��Ϸ��� �̷��� ���� ��¥�� ���� ��ü�� ���Ϸ��� �� ������ �ּҸ� ��
//    {
//        return this == &arg;   //this�� arg�� ������ �������� �� ! ���� ������ �� ����� ���� ���纻�� �ּ��̱⶧���� 
//    }
//
//    const Array& operator = (const Array& arg)      //���Կ�����
//    {
//        if (*this == arg)
//            // (this->buf == arg.buf)                             // a1 = a1�� ��츦 ���    a2= a1  ���� a2�� this , a1�� arg  �ڱ���� ȸ�� !  ������ ���Կ����ڿ��� �ڱ������ ȸ���ϴ� �ڵ尡 ����־���Ѵ� .
//            throw "�ڽ��� ��ü�� ������ �� ����";
//
//        delete buf;
//
//        count = arg.count;
//        buf = new int[100];
//        for (size_type i = 0; i < count; ++i)
//        {
//            buf[i] = arg.buf[i];
//        }
//        return *this;
//    }
//
//};
//
//int main()
//{
//    Array arr;
//    arr.push_back(10);
//    arr.push_back(20);
//    arr.push_back(30);
//    arr.push_back(40);
//    arr.push_back(50);
//
//    for (Array::size_type i = 0; i < arr.size(); ++i)
//        cout << arr[i] << endl;           //arr�� �����̳� ��ü (�������Ҹ� ����������) 
//
//    Array arr2;
//    arr2 = arr;
//
//    for (Array::size_type i = 0; i < arr2.size(); ++i)
//        cout << arr2[i] << endl;           //arr�� �����̳� ��ü (�������Ҹ� ����������) 
//
//
//}
//
//#include <iostream>  
//using namespace std;
//
//class Array
//{
//public:
//	typedef unsigned int size_type;
//private:
//	int* buf;
//	int count;
//	const Array& operator = (const Array&);
//public:
//	Array() :buf(nullptr), count(0)
//	{
//		buf = new int[100];
//	}
//	Array(const Array& arg) :buf(nullptr), count(arg.count)
//	{
//		buf = new int[100];
//		for (size_type i = 0; i < count; ++i)
//			buf[i] = arg.buf[i];
//	}
//	~Array() { delete[] buf; }
//	void push_back(int data)
//	{
//		buf[count++] = data;
//	}
//	int& at(int idx) { return buf[idx]; }
//	const int size() const { return count; }
//	const int& operator[](int idx) const
//	{ 
//		if (0 <= idx && idx < count)
//			return buf[idx];
//		else
//			throw out_of_range("idx ������ ���� �����!")
//	}
//
//	size_type size()const { return count; }
//};
//int main()
//{
//	Array arr;
//	arr.push_back(10);
//	arr.push_back(20);
//	arr.push_back(30);
//	arr.push_back(40);
//	arr.push_back(50);
//
//	for (Array::size_type i = 0; i < arr.size(); ++i)
//		cout << arr[i] << endl;
//}
//
//#include <iostream>  
//using namespace std;
//
//class Array
//{
//public:
//	typedef unsigned int size_type;
//private:
//	int* buf;
//	int count;
//	const Array& operator = (const Array&);
//public:
//	Array() :buf(nullptr), count(0)
//	{
//		buf = new int[100];
//	}
//	Array(const Array& arg) :buf(nullptr), count(arg.count)
//	{
//		buf = new int[100];
//		for (size_type i = 0; i < count; ++i)
//			buf[i] = arg.buf[i];
//	}
//	~Array() { delete[] buf; }
//	void push_back(int data)
//	{
//		buf[count++] = data;
//	}
//	int& at(int idx) { return buf[idx]; }
//	const int size() const { return count; }
//	const int& operator[](int idx) const { return buf[idx]; }
//	size_type size()const { return count; }
//};
//int main()
//{
//	Array arr;
//	arr.push_back(10);
//	arr.push_back(20);
//	arr.push_back(30);
//	arr.push_back(40);
//	arr.push_back(50);
//
//	for (Array::size_type i = 0; i < arr.size(); ++i)
//		cout << arr[i] << endl;
//}
//
//#include <iostream>  
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) {}
//    Point(const Point& arg) :x(arg.x), y(arg.y) { cout << x << "," << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    int& operator[](int idx)
//    {
//        if (idx == 0)
//            return x;
//        else if (idx == 1)
//            return y;
//        else
//            throw "index ���� ���� ����!";
//    }
//    int operator[](int idx) const
//    {
//        if (idx == 0)
//            return x;
//        else if (idx == 1)
//            return y;
//        else
//            throw "index ���� ���� ����!";
//    }
//};
//int main()
//{
//    Point pt(2, 3);
//
//    pt[0] = 15;
//    cout << pt[0] << endl;  //pt.operator[](0)
//    cout << pt[1] << endl;
//
//    const Point cpt(0, 0);
//    cout << cpt[0] << endl;
//    cout << cpt[1] << endl;
//}
//
//#include <iostream>  
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) {}
//    Point(const Point& arg) :x(arg.x), y(arg.y) { cout << x << "," << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    int& operator[](int idx) 
//    {
//        if (idx == 0)
//            return x;
//        else if (idx == 1)
//            return y;
//        else
//            throw "index ���� ���� ����!";
//    }
//};
//int main()
//{
//    Point pt(2, 3);
//
//    pt[0] = 15;
//    cout << pt[0] << endl;  //pt.operator[](0)
//    cout << pt[1] << endl;
//}
//
//#include <iostream>  
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) {}
//    Point(const Point& arg) :x(arg.x), y(arg.y) { cout << x << "," << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    int operator[](int idx)const
//    {
//        if (idx == 0)
//            return x;
//        else if (idx == 1)
//            return y;
//        else
//            throw "index ���� ���� ����!";
//    }
//};
//int main()
//{
//    Point pt(2, 3);
//
//    cout << pt[0] << endl;  //pt.operator[](0)
//    cout << pt[1] << endl;
//}
//
//#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, *py;
//public:
//    Point(int x = 0, int y = 0) :x(x), py(new int(y)) { cout << "Point()" << endl; }
//    ~Point() { cout << "~Point" << endl; delete py; }
//    Point(const Point& arg) :x(arg.x), py(new int(*arg.y)) { cout << "copy Point()" << endl; }
//    void Print()const { cout << x << ',' << *py << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return *py; }
//    const Point& operator=(const Point& arg)  //���Է��� ������ ������
//    {
//        x = arg.x;
//        *py = *arg.py;   //������ �������ִ� �� 
//        cout << "operator = " << endl;
//        return *this;
//    }
//};
//int main(void)
//{
//    Point p1(2, 3);  //p1.operator+=(p2)
//    Point p2(4, 5);
//
//    p1 = p2;   // p1.operator=(p2)   ���� ���� ������
//
//    p1.Print();
//    p2.Print();
//
//}
//
////#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//    ~Point() { cout << "~Point" << endl; }
//    Point(const Point& arg) :x(arg.x), y(arg.y) { cout << "copy Point()" << endl; }
//    void Print()const { cout << x << ',' << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    const Point& operator++()
//    {
//        ++x;
//        ++y;
//        return *this;
//    }
//    Point& operator++(int)
//    {
//        Point t(*this);
//        ++x;
//        ++y;
//        return t;
//    }
//    const Point& operator=(const Point& arg)  //���Է��� ������ ������
//    {
//        x = arg.x;
//        y = arg.y;
//        cout << "operator = " << endl;
//        return *this;
//    }
//};
//int main(void)
//{
//    Point p1(2, 3);  //p1.operator+=(p2)
//    Point p2(4, 5);
//
//    p1 = p2;   // p1.operator=(p2)   ���� ���� ������
//
//    p1.Print();
//    p2.Print();
//
//}
//
//#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//    ~Point() { cout << "~Point" << endl; }
//    Point(const Point& arg) :x(arg.x), y(arg.y) { cout << "copy Point()" << endl; }
//    void Print()const { cout << x << ',' << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    const Point& operator++()
//    {
//        ++x;
//        ++y;
//        return *this;
//    }
//     Point& operator++(int)
//    {
//        Point t(*this);
//        ++x;
//        ++y;
//        return t;
//    }
//};
//int main(void)
//{
//    Point p1(2, 3);  //p1.operator+=(p2)
//    Point p2(4, 5);
//
//    p2 = p1++; // p1.operator++(0)
//
//    p1.Print();
//    p2.Print();
//
//}
//
//#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//    ~Point() { cout << "~Point" << endl; }
//    Point(const Point& arg) :x(arg.x), y(arg.y) { cout << "copy Point()" << endl; }
//    void Print()const { cout << x << ',' << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    Point operator+(const Point& arg) const
//    {
//        return Point(x + arg.x, y + arg.y);
//    }
//    bool operator==(const Point& arg) const
//    {
//        return x == arg.x && y == arg.y;
//    }
//    bool operator!=(const Point& arg) const
//    {
//        return !(*this == arg);
//    }
//    const Point& operator+=(const Point& arg)
//    {
//        x += arg.x;
//        y += arg.y;
//        
//        return *this;
//    }
//    const Point& operator++()
//    {
//        ++x;
//        ++y;
//        return *this;
//    }
//};
//int main(void)
//{
//    Point p1(2, 3);  //p1.operator+=(p2)
//    Point p2(4, 5);
//
//    p2 = ++p1; // p1.operator++()
//
//    p1.Print();
//    p2.Print();
//
//}
//
//#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//    ~Point() { cout << "~Point" << endl; }
//    Point(const Point& arg) :x(arg.x), y(arg.y) { cout << "copy Point()" << endl; }
//    void Print()const { cout << x << ',' << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    Point operator+(const Point& arg) const
//    {
//        return Point(x + arg.x, y + arg.y);
//    }
//    bool operator==(const Point& arg) const
//    {
//        return x == arg.x && y == arg.y;
//    }
//    bool operator!=(const Point& arg) const
//    {
//        return !(*this == arg);
//    }
//    const Point& operator+=(const Point& arg)
//    {
//        x += arg.x;
//        y += arg.y;
//        
//        return *this;
//    }
//};
//int main(void)
//{
//    Point p1(2, 3);  //p1.operator+=(p2)
//    Point p2(4, 5);
//    Point p3;
//
//    p3 = p1 += p2; 
//    p1.Print();
//    p2.Print();
//    p3.Print();
//}
//
//#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//    ~Point() { cout << "~Point" << endl; }
//    Point(const Point& arg) :x(arg.x), y(arg.y) { cout << "copy Point()" << endl; }
//    void Print()const { cout << x << ',' << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    Point operator+(const Point& arg) const
//    {
//        return Point(x + arg.x, y + arg.y);
//    }
//    bool operator==(const Point& arg) const
//    {
//        return x == arg.x && y == arg.y;
//    }
//    bool operator!=(const Point& arg) const
//    {
//        return !(*this == arg);
//    }
//    void operator+=(const Point& arg)
//    {
//        x += arg.x;
//        y += arg.y;
//    }
//};
//int main(void)
//{
//    Point p1(2, 3);  //p1.operator+=(p2)
//    Point p2(4, 5);
//
//    p1 += p2; // 
//    p1.Print();
//    p2.Print();
//}
//
//#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//    ~Point() { cout << "~Point" << endl; }
//    Point(const Point& arg) :x(arg.x), y(arg.y) { cout << "copy Point()" << endl; }
//    void Print()const { cout << x << ',' << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    Point operator+(const Point& arg) const
//    {
//        return Point(x + arg.x, y + arg.y);
//    }
//    bool operator==(const Point& arg) const
//    {
//        return x == arg.x && y == arg.y;
//    }
//    bool operator!=(const Point& arg) const
//    {
//        return !(*this == arg);
//    }
//};
//int main(void)
//{
//    Point p1(2, 3);
//    Point p2(4, 5);
//
//    if (p1 == p2) //p1.operator==(p2)
//        cout << "true" << endl;
//    else
//        cout << "false" << endl;
//}
//
//#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//    ~Point() { cout << "~Point" << endl; }
//    Point(const Point& arg) :x(arg.x), y(arg.y) { cout << "copy Point()" << endl; }
//    void Print()const { cout << x << ',' << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    Point operator+(const Point& arg)
//    {
//        return Point(x + arg.x, y + arg.y);
//    }
//};
//int main(void)
//{
//    Point p1(2, 3);
//    Point p2(4, 5);
//    Point p3;
//    Point p3 = p1 + p2;
//
//    p3.Print();
//}
//
//#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//    ~Point() { cout << "~Point" << endl; }
//    Point(const Point& arg) :x(arg.x), y(arg.y) { cout << "copy Point()" << endl; }
//    void Print()const { cout << x << ',' << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    Point operator+(const Point& arg)
//    {
//        return Point(x + arg.x, y + arg.y);
//    }
//};
//int main(void)
//{
//    Point p1(2, 3);
//    Point p2(4, 5);
//    //Point p3 = p1.operator+(p2); �Ʒ��� ����
//    Point p3 = p1 + p2;
//    p3.Print();
//}
//
//#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) {}
//    void Print()const { cout << x << ',' << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    Point operator+(const Point& arg)
//    {
//        return Point(x + arg.x, y + arg.y);
//    }
//};
//int main(void)
//{
//    Point p1(2, 3);
//    Point p2(4, 5);
//    //Point p3 = p1.operator+(p2); �Ʒ��� ����
//    Point p3 = p1 + p2;
//    p3.Print();
//}
//
//#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) {}
//    void Print()const { cout << x << ',' << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//    Point Add(const Point& arg)
//    {
//        return Point(x + arg.x, y + arg.y);
//    }
//};
//int main(void)
//{
//    Point p1(2, 3);
//    Point p2(4, 5);
//    Point p3 = p1.Add(p2);
//
//    p3.Print();
//}
//
//#include <iostream>  //������ �ߺ�
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) {}
//    void Print()const { cout << x << ',' << y << endl; }
//    int GetX() const { return x; }
//    int GetY() const { return y; }
//};
//int main(void)
//{
//    Point p1(2, 3);
//    Point p2(4, 5);
//    Point p3 = p1 + p2;
//
//    p3.Print(); 
//}
//
//#include <iostream>
//using namespace std;
//
//class Point
//{
//    int x, y;
//public:
//    Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//    Point(const Point& arg)  // lvalue : �����Լ�, ���� ����� �Ѵ�.
//    {
//        this->x = arg.x;
//        this->y = arg.y;
//    }
//    Point(Point&& arg)  // rvalue : �̵��Լ�, ���� ����� �ϰ� rvalue�� null�� �Ѵ�.
//    {
//        this->x = arg.x;
//        this->y = arg.y;
//    }
//    ~Point() { cout << "~Point()" << endl; }
//
//    void Print() const { cout << x << "," << y << endl; }
//};
//void PrintPoint(const Point& arg)
//{
//    arg.Print();
//    cout << "Point&" << endl;
//}
//
//void PrintPoint(const Point&& arg)
//{
//    arg.Print();
//    cout << "Point&&" << endl;
//}
//
//int main(void)
//{
//    Point p1(2, 3);
//    PrintPoint(p1);
//    PrintPoint(Point(0, 0));  // r value�� �ӽð�ü�� �ǹ��Ѵ� ��������.
//
//    cout << "main() end" << endl;
//    return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//	Point(const Point& arg) { //��������� �������� ��ü �� ��
//		this->x = x;
//		this->y - y;
//	}
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//};
//void PrintPoint(const Point& arg)
//{
//	arg.Print();
//	cout << "Point&()" << endl;
//}
//void PrintPoint(const Point&& arg)
//{
//	arg.Print();
//	cout << "Point&&()" << endl;
//
//}
//int main()
//{
//	Point p1(2, 3);
//	PrintPoint(p1);
//	Point&& rrp = Point(0, 0);
//	cout << "main() end" << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//};
//void PrintPoint(const Point& arg)
//{
//	arg.Print();
//	cout << "Point&()" << endl;
//}
//void PrintPoint(const Point&& arg)
//{
//	arg.Print();
//	cout << "Point&&()" << endl;
//
//}
//int main()
//{
//	Point p1(2, 3);
//	Point& rp = p1;
//	Point&& rrp = Point(0,0);
//	cout << "main() end" << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//};
//void PrintPoint(const Point& arg)
//{
//	arg.Print();
//	cout << "Point&()" << endl;
//}
//void PrintPoint(const Point&& arg)
//{
//	arg.Print();
//	cout << "Point&&()" << endl;
//
//}
//int main()
//{
//	Point p1(2, 3);
//	p1.Print();
//
//	PrintPoint(p1);
//	PrintPoint(Point(2, 3));
//	cout << "main() end" << endl;
//}
//A
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) :x(x), y(y) { cout << "Point()" << endl; }
//
//	~Point() { cout << "~Point()" << endl; }
//	void Print()const { cout << x << ',' << y << endl; }
//};
//void PrintPoint(const Point& arg)
//{
//	arg.Print();
//}
//int main()
//{
//	Point p1(2, 3);
//	p1.Print();
//
//	PrintPoint(p1);
//	PrintPoint(Point(2,3));
//	cout << "main() end" << endl;
//}

//#include <iostream>
////#include <vector>
//using namespace std;
//
//int main()
//{
//	int n = 10;
//	int& r = n;     // l���� ���۷���
//	int&& r2 = 50;  // r���� ���۷���(����)
//	//int&& r2 = n;   // r������ l���� ������ ��� �� �� ����
//
//	cout << n << ", " << r << ", " << r2 << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n = 10;
//	int& r = n;
//	int&& r2 = 50;
//
//	cout << n << ", " << r << ", " << r2 << endl;
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
//class Shape  //�߻�Ŭ����  ������ �߻�ȭ �� Ŭ����(�θ�Ŭ���� parent,base,super)
//{
//protected:
//	Point start;
//public:
//	Shape(const Point& pt) :start(pt) {}
//	virtual void Draw()const = 0; //�������̽��� �ִµ� ������ ����
//	virtual ~Shape() { }
//};
//class Rect : public Shape, public IPoints   //���� ����̶���ϰ� �ڴ� �����̶�� �θ��� (�Ļ� Ŭ����)
//{
//	int width;
//	int height;
//public:
//	Rect(const Point& pt = Point(), int w = 0, int h = 0) :Shape(pt), width(w), height(h) {}
//	void Draw()const { //�������̵�
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
//	Shape* sarr[3] = { new Rect(Point(0, 0), 100, 150),
//	new Circle(Point(5, 5), 12),
//	new Polygon(Point(0, 15), 5) };
//	Fork f;
//
//	for (auto shape : sarr)
//		shape->Draw();
//
//	cout << endl;
//
//	IPoints* points[3] = { (Rect*)sarr[0], (Polygon*)sarr[2], &f };
//
//	for (auto x : points)
//		cout << "point count : " << x->GetPoints() << endl;
//
//	for (auto shape : sarr)
//		delete shape;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//struct ISpawnEgg
//{
//	virtual void GetSqawnEgg()const = 0;
//};
//struct ISound
//{
//	virtual void Getsound()const = 0;
//};
//class Age
//{
//private:
//	int year;
//	int month;
//public:
//	Age(int _year = 0, int _month = 0) : year(_year), month(_month)
//	{
//	}
//	int GetYear() { return year; }
//	int GetMonth() { return month; }
//	void PrintAge()
//	{
//		cout << year << "�� " << month << "���� " << endl;
//	}
//};
//class Animal {
//private:
//	string name;
//	Age age;
//	string gender;
//	string type;
//public:
//	Animal(string _type = "", string _name="", Age _age = Age(0, 0), string _gender = "") :type(_type), name(_name), age(_age), gender(_gender)
//	{
//		cout << type << " " << name << " "  << age.GetYear() << "�� " << age.GetMonth() <<
//			"����" << " " << gender << endl;
//
//	}
//	virtual void PrintInfo() = 0;
//	virtual ~Animal() {
//
//	}
//	Age GetAge() { return age; }
//};
//class Dog : public Animal, public ISound
//{
//
//public:
//	Dog(string _type = "", string _name = "", Age _age = Age(0, 0), string _gender = "") :Animal(_type, _name, _age, _gender)
//	{
//	}
//	void Getsound()const {
//		cout << "�۸� " << endl;
//	}
//	void PrintInfo(){}
//};
//class Cat : public Animal ,public ISound
//{
//public:
//	Cat(string _type = "", string _name = "", Age _age = Age(0, 0), string _gender = "") :Animal(_type, _name, _age, _gender)
//	{
//	}
//	void Getsound()const {
//		cout << "�Ŀ� " << endl;
//	}
//	void PrintInfo() {}
//};
//class lizard : public Animal, public ISpawnEgg
//{
//public:
//	lizard(string _type = "", string _name = "", Age _age = Age(0, 0), string _gender = "") :Animal(_type, _name, _age, _gender)
//	{
//	}
//
//	void GetSqawnEgg() const {
//		cout << "�������� ���� ���´�" << endl;
//	}
//	void PrintInfo() {}
//};
//class sparrow : public Animal, public ISound, public ISpawnEgg
//{
//public:
//	sparrow(string _type, string _name, Age _age = Age(0, 0), string _gender = "") :Animal(_type, _name, _age, _gender)
//	{
//	}
//	void Getsound()const {
//		cout << "±± " << endl;
//	}
//	void GetSqawnEgg() const {
//		cout << "������ ���� ���´�" << endl;
//	}
//	void PrintInfo() {}
//};
//
//int main()
//{
//	Animal* sarr[4] = { new Dog("������", "����", Age(2, 5), "����"),
//						new Cat("�����", "����", Age(3,6),"����"),
//						new lizard("������", "����", Age(5, 7),"����"),
//						new sparrow("���� ", " ����", Age(1, 8), "����")
//	};
//	for (auto animal : sarr)
//		animal->PrintInfo();
//
//	cout << endl;
//
//	ISound* points[3] = { (Dog*)sarr[0], (Cat*)sarr[1],(sparrow*)sarr[3]};
//
//	for (auto pp : points)
//		pp->Getsound();
//
//	ISpawnEgg* sarr2[2]{ (lizard*)sarr[2], (sparrow*)sarr[3]};
//	for (auto pp : sarr2)
//		pp->GetSqawnEgg();
//	for (auto animal : sarr)
//		delete animal;
//	
//}
//
