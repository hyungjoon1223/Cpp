#include "Point.h"
#include <iostream>
using namespace std;

//Point ��� �Լ��� ���� 
Point::Point(int x, int y):x(x),y(y)  //�ʱ�ȭ
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
