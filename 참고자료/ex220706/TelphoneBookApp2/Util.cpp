#include <iostream>
#include "Util.h"
using namespace std;

void Util::Menu() //static
{
	cout << "1. 전화 등록" << endl;
	cout << "2. 전화 번호 출력" << endl;
	cout << "3. 전화 번호 검색" << endl;
	cout << "4. 전화 번호 삭제" << endl;
	cout << "5. 전화 번호 텍스트 파일 출력" << endl;
	cout << "0. 프로그램 종료" << endl;
	cout << endl;
}
void Util::SubMenu()
{
	cout << "1. 학생등록" << endl;
	cout << "2. 교수등록" << endl;
	cout << endl;
}