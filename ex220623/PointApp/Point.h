#pragma once
//Point 클래스 정의
class Point
{
	int x, y;
public:

	Point(int x = 0, int y = 0);  //초기화
	void Print() const;
	void SetX(int _x);
	void SetY(int _y);
	int GetX() const;
	int GetY() const;
	const Point* GetThis()const;
};
