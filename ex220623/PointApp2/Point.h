#pragma once
//Point Ŭ���� ����
namespace MySP
{
	class Point
	{
		int x, y;
	public:

		Point(int x = 0, int y = 0);  //�ʱ�ȭ
		void Print() const;
		void SetX(int _x);
		void SetY(int _y);
		int GetX() const;
		int GetY() const;
		const Point* GetThis()const;
	};
}