#include <iostream>
#include <set>
#include <algorithm>
#include <initializer_list>
using namespace std;
int main()
{
	int arr[5] = { 1,2,3,4,5 };

	for (auto x : arr)
		cout << x << " ";
	cout << endl;

	for (auto x : initializer_list<int>(arr,arr+5))
		cout << x << " ";
	cout << endl;

	auto arr2 = { 1,2,3,4,5 };
	for (auto x : arr2)
		cout << x << " ";
	cout << endl;
}

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	pair<int, int> pr(1, 2);  //�ΰ��� ���� �����Ϸ��� ������ pair�� ����Ѵ� stl������

	cout << pr.first << ',' << pr.second << endl;
	cout << pair<int, string>(1, "one").second << endl;

	pair<vector<int>::iterator, vector<int>::iterator> pv; 
}

#include <iostream>
#include <set>
#include <algorithm>
#include <initializer_list>
using namespace std;
int main()
{
	multiset<int> s;  

	s.insert(30);
	s.insert(20);
	s.insert(10);
	s.insert(40);
	s.insert(50);
	s.insert(20);
	s.insert(20);

	for (auto& x : s)
		cout << x << " ";
	cout << endl;

	pair<set<int>::iterator, set<int>::iterator> piter = s.equal_range(20);
	if (piter.first != piter.second)
		cout << *piter.first << endl;

	//for(auto& x : initializer_list<int>(piter.first,piter.second)
	for (multiset<int>::iterator iter = piter.first; iter != piter.second; ++iter)
		cout << *iter << " ";
	cout << endl;
}

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	multiset<int> s;   //set�� ���ٶ�°� ������ Ű�� ã��ʹ�

	s.insert(30);
	s.insert(20);
	s.insert(10);
	s.insert(40);
	s.insert(50);
	s.insert(20);
	s.insert(20);

	for (auto& x : s)
		cout << x << " ";
	cout << endl;

	//set<int>::iterator iter = find(s.begin(), s.end(), 20);  //find�� �����˻��� �ؼ� ȿ���� ���� �ʴ�
	//if (iter != s.end())
	//	cout << *iter << endl;
	//s.find();
	//s.lower_bound();
	//s.upper_bound();
	//s.equal_range();
	
	multiset<int>::iterator iter = s.find(20); //log2
	if (iter != s.end())
		cout << *iter << endl;

	multiset<int>::iterator liter = s.lower_bound(20);
	multiset<int>::iterator uiter = s.upper_bound(20);
	if (liter != uiter)
		cout << *iter << endl;

	for (multiset<int>::iterator iter = liter; iter != uiter; ++iter)
		cout << *iter << " ";
	cout << endl;
	//cout << *uiter << endl; �̷��� ���� �ȵ� ���������� ����Ű�� �ΰ��� �����⶧����
}

#include <iostream>
#include <set>
using namespace std;
class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y) {}
	void Print()const { cout << x << ", " << y << endl; }
	int GetX()const { return x; }
	int GetY()const { return y; }
};
struct Compare
{
	bool operator()(const Point& a, const Point& b) const
	{
		if (a.GetX() < b.GetX())
			return true;
		else if (a.GetX() > b.GetX())
			return false;
		else if (a.GetY() > b.GetY())
			return true;
		else
			return false;
	}
};
int main()
{
	auto fun = [](const Point& a, const Point& b) -> bool {return a.GetX() < b.GetX(); }; //���ٽ��� �̿��� ����������Ʈ ���̹Ƿ� �������� ����Ŭ��
	set<Point, decltype(fun) > s(fun);

	s.insert(Point(2, 3));
	s.insert(Point(2, 5));
	s.insert(Point(5, 6));
	s.insert(Point(3, 4));
	s.insert(Point(1, 2));

	for (set<Point>::iterator iter = s.begin(); iter != s.end(); ++iter)
		cout << iter->GetX() << ", " << iter->GetY() << " ";
	cout << endl;
}

#include <iostream>
#include <set>
using namespace std;
class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y) {}
	void Print()const { cout << x << ", " << y << endl; }
	int GetX()const { return x; }
	int GetY()const { return y; }
};
struct Compare
{
	bool operator()(const Point& a, const Point& b) const
	{
		if (a.GetX() < b.GetX())
			return true;
		else if (a.GetX() > b.GetX())
			return false;
		else if (a.GetY() > b.GetY())
			return true;
		else
			return false;
	}
};
int main()
{
	[](int n)-> void {cout << n << endl; } (10);
	auto fun = [](int n)-> void {cout << n << endl; };
	fun(10);

	cout << typeid(fun).name() << endl;
	
	int n = 10;
	decltype(n) m = n;
	double d = 5.5;

	cout << typeid(decltype(n)).name() << endl;
	cout << typeid(decltype(d)).name() << endl;
}

#include <iostream>
#include <set>
using namespace std;
class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y) {}
	void Print()const { cout << x << ", " << y << endl; }
	int GetX()const { return x; }
	int GetY()const { return y; }
};
struct Compare
{
	bool operator()(const Point& a, const Point& b) const
	{
		if (a.GetX() < b.GetX())
			return true;
		else if (a.GetX() > b.GetX())
			return false;
		else if (a.GetY() > b.GetY())
			return true;
		else
			return false;
	}
};
int main()
{
	set<Point, Compare> s;

	s.insert(Point(2, 3));
	s.insert(Point(2, 5));
	s.insert(Point(5, 6));
	s.insert(Point(3, 4));
	s.insert(Point(1, 2));


	for (set<Point>::iterator iter = s.begin(); iter != s.end(); ++iter)
		cout << iter->GetX() << ", " << iter->GetY() << " ";
	cout << endl;
}

#include <iostream>
#include <set>
using namespace std;
class Point
{
	int x, y;
public:
	explicit Point(int x = 0, int y = 0) :x(x), y(y) {}
	void Print()const { cout << x << ", " << y << endl; }
	int GetX()const { return x; }
	int GetY()const { return y; }
};
struct Compare
{
	bool operator()(const Point& a, const Point& b) const
	{
		if (a.GetX() < b.GetX())
			return true;
		else if (a.GetX() > b.GetX())
			return false;
		else if (a.GetY() > b.GetY())
			return true;
		else
			return false;
	}
};
int main()
{
	set<Point, Compare> s;

	s.insert(Point(2, 3));
	s.insert(Point(2, 5));
	s.insert(Point(5, 6));
	s.insert(Point(3, 4));
	s.insert(Point(1, 2));


	for (set<Point>::iterator iter = s.begin(); iter != s.end(); ++iter)
		cout << iter->GetX() << ", " << iter->GetY() << " ";
	cout << endl;
}

#include <iostream>
#include <set>
using namespace std;
class Point
{
	int x, y;
public:
	explicit Point(int x=0, int y= 0):x(x), y(y){}
	void Print()const { cout << x << ", " << y << endl; }
	int GetX()const { return x; }
	int GetY()const { return y; }
	//   <�� less�� ����
	bool operator < (const Point& arg) const 
	{
		return x < arg.x;
	}
};
int main()
{
	set<Point> s;
	//set<Point, greater<Point> > s;
	s.insert(Point(2, 3));
	s.insert(Point(2, 5));
	s.insert(Point(5, 6));
	s.insert(Point(3, 4));
	s.insert(Point(1, 2));


	for (set<Point>::iterator iter = s.begin(); iter != s.end(); ++iter)
		cout << iter->GetX() << ", " << iter->GetY() << " ";
	cout << endl;
}

#include <iostream>
#include <set>
using namespace std;
int main()
{
	set<int, greater<int> > s; 

	s.insert(10);
	s.insert(50);
	s.insert(40);
	s.insert(20);
	s.insert(30);
	s.insert(40);  //���� ����ũ�ؼ� ������ ���� Ű�� �ִٸ� �ȵ���
	s.insert(40);

	for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

#include <iostream>
#include <set>
using namespace std;
int main()
{
	set<int> s;

	s.insert(10);
	s.insert(50);
	s.insert(40);
	s.insert(20);
	s.insert(30);
	s.insert(40);  //���� ����ũ�ؼ� ������ ���� Ű�� �ִٸ� �ȵ���
	s.insert(40);

	for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

#include <iostream>
#include <set>
using namespace std;
int main()
{
	set<int> s;

	s.insert(10);
	s.insert(50);
	s.insert(40);
	s.insert(20);
	s.insert(30);
	
	for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_front(100);
	dq.push_front(200);

	for (int& item : dq)
		cout << item << " ";
	cout << endl;

	vector<int> v;
	v.push_back(60);
	v.push_back(70);
	v.push_back(80);

	dq.insert(dq.begin()+3, v.begin(), v.end());
}

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_front(100);
	dq.push_front(200);

	for (int& item : dq)
		cout << item << " ";
	cout << endl;
}

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	forward_list<int> flt;

	flt.push_front(10);
	flt.push_front(20);
	flt.push_front(30);
	flt.push_front(40);
	flt.push_front(50);

	for (auto& item : flt)
		cout << item << " ";
	cout << endl;

	forward_list<int>::iterator iter = flt.begin();
	iter++;
	iter++;
	flt.insert_after(iter, 100);
	for (auto& item : flt)
		cout << item << " ";
	cout << endl;
}

//forward_list
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	forward_list<int> flt;

	flt.push_front(10);
	flt.push_front(20);
	flt.push_front(30);
	flt.push_front(40);
	flt.push_front(50);

	for (auto& item : flt)
		cout << item << " ";
	cout << endl;
}

//���߿��� list
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);

	list<int> lt2;
	lt.push_front(100);
	lt.push_front(200);

	lt.splice(++lt.begin(), lt2, lt2.begin(), lt2.end());  //��ü�ϰų� �ڸ� �� ���� �޼ҵ�

	cout << "lt: ";
	for (auto item : lt)
		cout << item << " ";
	cout << endl;
	cout << "lt2: ";
	for (auto item : lt2)
		cout << item << " ";
	cout << endl;
}

//���߿��� list
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);

	list<int> lt2;
	lt.push_front(100);
	lt.push_front(200);

	lt.splice(++lt.begin(), lt2, lt2.begin(),lt2.end());  //��ü�ϰų� �ڸ� �� ���� �޼ҵ�

	cout << "lt: ";
	for (auto item : lt)
		cout << item << " ";
	cout << endl;
	cout << "lt2: ";
	for (auto item : lt2)
		cout << item << " ";
	cout << endl;
}

//���߿��� list //���� ����ð��� �μ�Ʈ�� �̷����� ����(������)
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);

	lt.push_front(100);
	lt.push_front(200);
	for (const auto& item : lt)
		cout << item << " ";
	cout << endl;
}


#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);

	vector<int> v(lt.begin(), lt.end());

	for (auto& item : v)
		cout << item << " ";
	cout << endl;
}

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	vector<int> v(5, 1);

	for (auto& item : v)
		cout << item << " ";
	cout << endl;
}

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

template <typename Cont>
void PrintContainer(const Cont& v) // �����̳ʿ� ���� �Ⱦ���
{
	for (typename Cont::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}
int main()
{
	vector<int> v;
	list<int> lt;

	v.push_back(10); lt.push_back(10);
	v.push_back(20); lt.push_back(20);
	v.push_back(30); lt.push_back(30);

	list<int>::iterator iter = lt.begin();
	iter++; iter++;
	cout << *(v.begin() + 2) << ',' << *iter << endl;;
}

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

template <typename Cont>
void PrintContainer(const Cont& v) // �����̳ʿ� ���� �Ⱦ���
{
	for (typename Cont::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}
int main()
{
	vector<int> v;
	list<int> lt;

	v.push_back(10); lt.push_back(10);
	v.push_back(20); lt.push_back(20);
	v.push_back(30); lt.push_back(30);

	list<int>::iterator iter = lt.begin();
	iter++; iter++;
	cout << *(v.begin() + 2) << ',' << *iter << endl;;
}

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

template <typename Cont>
void PrintContainer(const Cont& v) // �����̳ʿ� ���� �Ⱦ���
{
	for (typename Cont::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	PrintContainer(v);

	vector<int>::iterator iter = v.begin();   //���氡���� ���ͷ�����
	vector<int>::const_iterator citer= v.begin();        //����Ұ����� ���ͷ�����
	vector<int>::reverse_iterator riter = v.rbegin();
	vector<int>::const_reverse_iterator criter = v.rbegin();

	cout << *iter << ',' << *citer << endl;
	cout << *riter << ',' << *criter << endl;

}

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

template <typename Cont>
void PrintVector(const Cont& v) // �����̳ʿ� ���� �Ⱦ���
{           
	for (typename Cont::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}
void PrintContainer(const Cont& lt)
{
	for (typename Cont::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}
{

}
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	PrintVector(v);

	list<int> lt;
	lt.push_back(100);
	lt.push_back(200);
	lt.push_back(300);

	v.insert(v.begin(), lt.begin(), lt.end());
	PrintContainer(v);
	PrintContainer(lt);

	v.erase(v.begin(), v.begin() + 3);
	PrintContainer(v);

	sort(v.begin(), v.end());
	PrintContainer(lt);

}

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

void PrintVector(const vector<int>& v) // �����̳ʿ� ���� �Ⱦ���
{
	for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	PrintVector(v);
	
	list<int> lt;
	lt.push_back(100);
	lt.push_back(200);
	lt.push_back(300);

	v.insert(v.begin(),lt.begin(), lt.end());
	PrintVector(v);
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void PrintVector(const vector<int>& v) // �����̳ʿ� ���� �Ⱦ���
{
	for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	PrintVector(v);

	v.pop_back();
	PrintVector(v);

	v.insert(v.begin() + 2, 100);
	PrintVector(v);

	v.erase(v.begin() + 2);
	PrintVector(v);
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	vector<int> v; 

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";   
	cout << endl;

	cout << "first : " << v.front() << " last : " << v.back() << endl;
	v.front() = 100;
	v.back() = 200;
	cout << "first : " << v.front() << " last : " << v.back() << endl;
	
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	vector<int> v;   //���ʹ� ���Ӹ޸� ����� ������ �����̳� �̴�

	v.reserve(10); // ���Ϳ��� �ִ� reserve
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(10);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(20);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(30);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(40);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(50);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(60);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(70);
	cout << v.size() << " : " << v.capacity() << endl;


	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";   //array , forward+list ���ͷ�����
	cout << endl;               //uno
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	vector<int> v;   //���ʹ� ���Ӹ޸� ����� ������ �����̳� �̴�

	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(10);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(20);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(30);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(40);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(50);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(60);
	cout << v.size() << " : " << v.capacity() << endl;
	v.push_back(70);
	cout << v.size() << " : " << v.capacity() << endl;


	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";   //array , forward+list ���ͷ�����
	cout << endl;               //uno
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	vector<int> v;   //�����̳�
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";   //���ͷ�����
	cout << endl;
}

// STL standard Template Lib
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	vector<int> v;   //�����̳ʶ�� �θ�
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";   //���ͷ�����
	cout << endl;

	for (auto elm : v)          //���ͷ�����
		cout << elm << " ";
	cout << endl;

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));   //�˰���� ���ͷ����� ���ͷ���Ʈ�ʴ�(v.begin(), v.end()
		cout << endl;

	sort(v.begin(), v.end(), greater<int>()); //�˰���, ���ͷ�����, �Լ���
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct cpu {
	string property1;
	string property2;
	string property3;
	int value;

public:
	static bool compareCpusByValue(cpu& a, cpu& b) {
		return a.value < b.value;
	}

	static bool compareCpusByProperty1(cpu& a, cpu& b) {
		return a.property1 < b.property1;
	}
} typedef cpu;

void printVector(vector<cpu>& vec)
{
	for (const auto& item : vec) {
		cout << item.property1 << " : "
			<< item.property2 << " : "
			<< item.property3 << " : "
			<< item.value << endl;
	}
	cout << endl;
}

int main() {
	vector<cpu> vec3 = { {"WMP", "GR", "01", 99},
						 {"TPS", "US", "02",  91},
						 {"EOM", "GB", "03", 93},
						 {"AAW", "GE", "04", 96} };

	printVector(vec3);
	sort(vec3.begin(), vec3.end(), cpu::compareCpusByProperty1);
	sort(vec3.begin(), vec3.end(), cpu::compareCpusByValue);
	printVector(vec3);

	return EXIT_SUCCESS;
}
