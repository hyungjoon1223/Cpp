#include <iostream>
#include "Point.h"
using namespace std;


	//Point 멤버 함수의 정의 
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
 //namespace MySP
//#include <iostream>
//#include "Point.h"
//using namespace std;
//
//namespace MySP
//{
//	//Point 멤버 함수의 정의 
//	Point::Point(int x, int y) :x(x), y(y)  //초기화
//	{
//	}
//	void Point::Print() const
//	{
//		cout << this->x << "," << this->y << endl;
//	}
//	void Point::SetX(int _x)
//	{
//		x = _x;
//	}
//	void Point::SetY(int _y)
//	{
//		y = _y;
//	}
//	int Point::GetX() const { return x; }
//	int Point::GetY() const { return y; }
//	const Point* Point::GetThis()const {
//		return this;
//	}
//} //namespace MySP