#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string name = "ȫ�浿";
	string phone = "010-1111-2222";

	ofstream ofs("text.txt", ios::binary); // fopen_s("text.txt","wb");
	int dataCount = 1;
	ofs.write((char*)&dataCount, sizeof(int));

	int slen = name.size()+1;
	ofs.write((char*)&slen, sizeof(int));
	ofs.write(name.c_str(), slen);

	slen = phone.size()+1;
	ofs.write((char*)&slen, sizeof(int));
	ofs.write(phone.c_str(), slen + 1);
	ofs.close();

	ifstream ifs("text.txt", ios::binary);
	ifs.read((char*)&dataCount, sizeof(int));

	ifs.read((char*)&slen, sizeof(int));
	char* buf = new char[slen];
	ifs.read(buf, slen);
	name = buf;
	delete[] buf;

	ifs.read((char*)&slen, sizeof(int));
	buf = new char[slen];
	ifs.read(buf, slen);
	phone = buf;
	delete[] buf;

	cout << name << ", " << phone << endl;
	ifs.close();
}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//
//	cout << arr << endl;
//	cout << arr + 2 << endl;
//	cout << &arr[2] - &arr[0] << endl;
//}

//#pragma warning(disable : 6386)
//#include <iostream>
//#include <vector>
//using namespace std;
////1��
//template <typename T>
//class Vector
//{
//
//public:
//    //template <typename T>
//    class iterator {
//    private:
//        T* ptr;
//
//    public:
//        iterator(T* p = nullptr) :ptr(p) {}
//
//        T& operator*()        //*�� -> ���۷����ʹ� �׻� ¦
//        {
//            return *ptr;     //����
//        }
//
//        T* operator->()
//        {
//            return ptr;        //�ּ�
//        }
//        iterator operator ++ ()
//        {
//            ++ptr;
//            return *this;
//        }
//
//        bool operator== (iterator arg)
//        {
//            return ptr == arg.ptr;
//        }
//
//        bool operator != (iterator arg)
//        {
//            return !(*this == arg.ptr);
//        }
//
//    };
//    class const_iterator {
//    private:
//        T* ptr;
//    public:
//        const_iterator(T* p = nullptr) :ptr(p) {}
//
//        const T& operator*()const        //*�� -> ���۷����ʹ� �׻� ¦
//        {
//            return *ptr;     //����
//        }
//
//       const T* operator->()const
//        {
//            return ptr;        //�ּ�
//        }
//        const_iterator operator ++ ()
//        {
//            ++ptr;
//            return *this;
//        }
//
//        bool operator== (const_iterator arg)const
//        {
//            return ptr == arg.ptr;
//        }
//
//        bool operator != (const_iterator arg)const
//        {
//            return !(*this == arg.ptr);
//        }
//    };
//private:
//    T* buf;
//    int _size;
//    int _capacity;
//
//private:
//    T* _initandcopy(int cap)
//    {
//        T* t = new T[_capacity = cap];
//        for (int i = 0; i < _size; ++i)
//            t[i] = buf[i];
//        return t;
//    }
//    Vector(const Vector&);
//    const Vector& operator=(const Vector&);
//public:
//    Vector() :buf(nullptr), _size(0), _capacity(0) {}
//    ~Vector() { delete[] buf; }
//
//    void push_back(const T& data) {
//        if (_capacity == 0)
//        {
//            buf = _initandcopy(1);
//        }
//
//        else if (_capacity <= _size)
//        {
//            T* t = _initandcopy(_capacity * 2);
//            delete[] buf;
//            buf = t;
//        }
//        buf[_size++] = data;
//    }                               // ���빰 �����Ŵϱ� const data x
//
//    int size() const { return _size; }
//    int capacity() const { return _capacity; }
//    T& operator[](int idx) { return buf[idx]; }
//    //////
//    //iterator begin() { return iterator<T>buf; }   
//    iterator begin() { return buf; }
//    iterator end() { return iterator(buf + _size); }   
//    const_iterator cbegin()const { return  buf; }
//    const_iterator cend()const { return const_iterator(buf + _size); }
//};
//class Person
//{
//public:
//    void Print()const { cout << "Person()" << endl; }
//};
//int main()
//{
//    Vector<Person*>v;
//    v.push_back(new Person());
//    v.push_back(new Person());
//    v.push_back(new Person());
//
//    for (int i = 0; i < (int)v.size(); ++i)
//        v[i]->Print();
//
//    for (Vector<Person*>::const_iterator iter = v.cbegin(); iter != v.cend(); ++iter)
//        (*iter)->Print();
//
//    //for (auto item : v)
//    //    cout << item << endl;
//}
// 
//#include <iostream>
//#include <list>
//#include <numeric>   // ���а� ���� �� �˰������ ���� ������� ���� ���⿨
//using namespace std;
//
//template <typename T>
//class List
//{
//private:
//	class Node
//	{
//		Node* prev;   //���� ���
//		Node* next;   // �� ���
//		T data;       //�����͸� �����ϴ� ��
//	public:
//		Node(const T& d = T()) :prev(nullptr), next(nullptr), data(d) {}
//		friend class List<T>;  //struct�� �ƴ� class�� �ϸ� �� �ڵ尡 �ʿ���
//	};
//public:
//	class iterator
//	{
//		Node* ptr;
//	public:
//		iterator(Node* p = nullptr) :ptr(p) {}
//		T& operator*() { return ptr->data; }
//		T& operator->() { return &ptr->data; }
//		iterator operator++() // ���� ++
//		{
//			ptr = ptr->next;
//			return *this;
//		}
//		bool operator==(iterator arg)const
//		{
//			return ptr == arg.ptr;
//		}
//		bool operator!=(iterator arg)const
//		{
//			return !(*this == arg);
//		}
//	};
//private:
//	Node* head;
//	Node* tail;
//	int count;
//private:
//	void _linkNode(Node* left, Node* right, const T& data)
//	{
//		++count;
//		Node* n = new Node(data);
//
//		left->next = n;
//		n->prev = left;
//		n->next = right;
//		right->prev = n;
//	}
//	List(const List&);
//	const List& operator=(const List&);
//public:
//	List() :head(nullptr), tail(nullptr), count(0)
//	{
//		head = new Node();
//		tail = new Node();
//		head->next = tail;
//		tail->prev = head;
//	}
//	~List()
//	{
//		Node* p = head;
//		while (p)
//		{
//			Node* np = p->next;
//			delete p;
//			p = np;
//		}
//	}
//	void push_back(const T& data)
//	{
//		_linkNode(tail->prev, tail, data);
//	}
//	void push_front(const T& data)
//	{
//		_linkNode(head, head->next, data);
//	}
//
//	int size()const { return count; }
//	// ��ȸ�� �ϱ����� ���ͷ�����
//	iterator begin() { return iterator(head->next); }
//	iterator end() { return iterator(tail); }
//};
//struct Multi
//{
//	int operator()(int acc, int data)
//	{
//		return acc * data;
//	}
//};
//int main()
//{
//	List<int> lt;
//
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_front(100);
//	lt.push_front(200);
//
//	cout << accumulate(lt.begin(), lt.end(), 1, Multi()) << endl;
//	cout << accumulate(lt.begin(), lt.end(), 0, [](int acc, int data)->int {return acc + data; }) << endl;
//}

//#include <iostream>
//#include <list>
//#include <numeric>   // ���а� ���� �� �˰������ ���� ������� ���� ���⿨
//using namespace std;
//
//template <typename T>
//class List
//{
//private:
//	class Node
//	{
//		Node* prev;   //���� ���
//		Node* next;   // �� ���
//		T data;       //�����͸� �����ϴ� ��
//	public:
//		Node(const T& d = T()) :prev(nullptr), next(nullptr), data(d) {}
//		friend class List<T>;  //struct�� �ƴ� class�� �ϸ� �� �ڵ尡 �ʿ���
//	};
//public:
//	class iterator
//	{
//		Node* ptr;
//	public:
//		iterator(Node* p = nullptr) :ptr(p) {}
//		T& operator*() { return ptr->data; }
//		T& operator->() { return &ptr->data; }
//		iterator operator++() // ���� ++
//		{
//			ptr = ptr->next;
//			return *this;
//		}
//		bool operator==(iterator arg)const
//		{
//			return ptr == arg.ptr;
//		}
//		bool operator!=(iterator arg)const
//		{
//			return !(*this == arg);
//		}
//	};
//private:
//	Node* head;
//	Node* tail;
//	int count;
//private:
//	void _linkNode(Node* left, Node* right, const T& data)
//	{
//		++count;
//		Node* n = new Node(data);
//
//		left->next = n;
//		n->prev = left;
//		n->next = right;
//		right->prev = n;
//	}
//	List(const List&);
//	const List& operator=(const List&);
//public:
//	List() :head(nullptr), tail(nullptr), count(0)
//	{
//		head = new Node();
//		tail = new Node();
//		head->next = tail;
//		tail->prev = head;
//	}
//	~List()
//	{
//		Node* p = head;
//		while (p)
//		{
//			Node* np = p->next;
//			delete p;
//			p = np;
//		}
//	}
//	void push_back(const T& data)
//	{
//		_linkNode(tail->prev, tail, data);
//	}
//	void push_front(const T& data)
//	{
//		_linkNode(head, head->next, data);
//	}
//
//	int size()const { return count; }
//	// ��ȸ�� �ϱ����� ���ͷ�����
//	iterator begin() { return iterator(head->next); }
//	iterator end() { return iterator(tail); }
//};
//struct Multi
//{
//	int operator()(int acc, int data)
//	{
//		return acc * data;
//	}
//};
//int main()
//{
//	List<int> lt;
//
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_front(100);
//	lt.push_front(200);
//
//	cout << accumulate(lt.begin(), lt.end(), 1, Multi()) << endl;
//	cout << accumulate(lt.begin(), lt.end(), 0, [](int acc, int data)->int{return acc+data;}) << endl;
//}

//#include <iostream>
//#include <list>
//#include <numeric>   // ���а� ���� �� �˰������ ���� ������� ���� ���⿨
//using namespace std;
//
//template <typename T>
//class List
//{
//private:
//	class Node
//	{
//		Node* prev;   //���� ���
//		Node* next;   // �� ���
//		T data;       //�����͸� �����ϴ� ��
//	public:
//		Node(const T& d = T()) :prev(nullptr), next(nullptr), data(d) {}
//		friend class List<T>;  //struct�� �ƴ� class�� �ϸ� �� �ڵ尡 �ʿ���
//	};
//public:
//	class iterator
//	{
//		Node* ptr;
//	public:
//		iterator(Node* p = nullptr) :ptr(p) {}
//		T& operator*() { return ptr->data; }
//		T& operator->() { return &ptr->data; }
//		iterator operator++() // ���� ++
//		{
//			ptr = ptr->next;
//			return *this;
//		}
//		bool operator==(iterator arg)const
//		{
//			return ptr == arg.ptr;
//		}
//		bool operator!=(iterator arg)const
//		{
//			return !(*this == arg);
//		}
//	};
//private:
//	Node* head;
//	Node* tail;
//	int count;
//private:
//	void _linkNode(Node* left, Node* right, const T& data)
//	{
//		++count;
//		Node* n = new Node(data);
//
//		left->next = n;
//		n->prev = left;
//		n->next = right;
//		right->prev = n;
//	}
//	List(const List&);
//	const List& operator=(const List&);
//public:
//	List() :head(nullptr), tail(nullptr), count(0)
//	{
//		head = new Node();
//		tail = new Node();
//		head->next = tail;
//		tail->prev = head;
//	}
//	~List()
//	{
//		Node* p = head;
//		while (p)
//		{
//			Node* np = p->next;
//			delete p;
//			p = np;
//		}
//	}
//	void push_back(const T& data)
//	{
//		_linkNode(tail->prev, tail, data);
//	}
//	void push_front(const T& data)
//	{
//		_linkNode(head, head->next, data);
//	}
//
//	int size()const { return count; }
//	// ��ȸ�� �ϱ����� ���ͷ�����
//	iterator begin() { return iterator(head->next); }
//	iterator end() { return iterator(tail); }
//};
//int main()
//{
//	List<int> lt;
//
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_front(100);
//	lt.push_front(200);
//
//	cout << accumulate(lt.begin(), lt.end(), 0) << endl;
//}

//#include <iostream>
//#include <vector>
//#include <list>
//using namespace std;
//
//template <typename T>
//class List
//{
//private:
//	class Node
//	{
//		Node* prev;   //���� ���
//		Node* next;   // �� ���
//		T data;       //�����͸� �����ϴ� ��
//	public:
//		Node(const T& d = T()) :prev(nullptr), next(nullptr), data(d) {}
//		friend class List<T>;  //struct�� �ƴ� class�� �ϸ� �� �ڵ尡 �ʿ���
//	};
//public:
//	class iterator
//	{
//		Node* ptr;
//	public:
//		iterator(Node* p = nullptr) :ptr(p){}
//		T& operator*() { return ptr->data; }
//		T& operator->() { return &ptr->data; }
//		iterator operator++() // ���� ++
//		{
//			ptr = ptr->next;
//			return *this;
//		}
//		bool operator==(iterator arg)const
//		{
//			return ptr == arg.ptr;
//		}
//		bool operator!=(iterator arg)const
//		{
//			return !(*this == arg);
//		}
//	};
//private:
//	Node* head;
//	Node* tail;
//	int count;
//private:
//	void _linkNode(Node* left, Node* right, const T& data)
//	{
//		++count;
//		Node* n = new Node(data);
//
//		left->next = n;
//		n->prev = left;
//		n->next = right;
//		right->prev = n;
//	}
//	List(const List&);
//	const List& operator=(const List&);
//public:
//	List():head(nullptr),tail(nullptr), count(0)
//	{
//		head = new Node();
//		tail = new Node();
//		head->next = tail;
//		tail->prev = head;
//	}
//	~List()
//	{
//		Node* p = head;
//		while (p)
//		{
//			Node* np = p->next;
//			delete p;
//			p = np;
//		}
//	}
//	void push_back(const T& data)
//	{
//		_linkNode(tail->prev, tail, data);
//	}
//	void push_front(const T& data)
//	{
//		_linkNode(head, head->next , data);
//	}
//	
//	int size()const { return count; }
//	// ��ȸ�� �ϱ����� ���ͷ�����
//	iterator begin() { return iterator(head->next); }
//	iterator end() { return iterator(tail); }
//};
//int main()
//{
//	List<int> lt;
//
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_front(100);
//	lt.push_front(200);
//
//	cout << "size : " << lt.size() << endl;
//
//	for (List<int>::iterator iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << endl;
//
//	for (auto item : lt)
//		cout << item << endl;
//}

//#include <iostream>
//#include <vector>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt;
//
//	lt.push_back(10);
//	lt.push_back(20);
//	lt.push_back(30);
//	lt.push_front(100);
//	lt.push_front(200);
//
//	cout << "size : " << lt.size() << endl;
//
//	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); ++iter)
//		cout << *iter << endl;
//
//	for (auto item : lt)
//		cout << item << endl;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//template <typename T>
//class Vector
//{
//public:
//	class iterator
//	{
//		T* ptr;
//	public:
//		iterator(T* p=nullptr):ptr(p) {}
//		T& operator*()   //���� ��ȯ 
//		{
//			return *ptr;
//		}
//		T& operator->()  //�ּ� ��ȯ ������ ����� ������ ¦���� ����������
//		{
//			return ptr;
//		}
//		iterator operator++()  //���� �ּ��� ������ ����Ű�� ���ͷ�����
//		{
//			++ptr;
//			return *this;
//		}
//		bool operator==(iterator arg)
//		{
//			return ptr == arg.ptr;
//		}
//		bool operator!=(iterator arg)
//		{
//			return !(*this == arg);
//		}
//	};
//private:
//	T* buf;
//	int _size;
//	int _capacity;
//private:
//	T* _initandcopy(int cap)
//	{
//		T* t = new T[_capacity = cap];
//		for (int i = 0; i < _size; ++i)
//			t[i] = buf[i];
//
//		return t;
//	}
//public:
//	Vector() :buf(nullptr), _size(0), _capacity(0) { }
//	void push_back(const T& data)
//	{
//		if (_capacity == 0)
//			buf = _initandcopy(1);
//		else if (_size == _capacity)
//		{
//			T* t = _initandcopy(_capacity * 2);
//			delete[] buf;
//			buf = t;
//		}
//		buf[_size++] = data;
//	}
//	int size()const { return _size; }
//	int capacity()const { return _capacity; }
//	int& operator[](int idx) { return buf[idx]; }
//	//////
//	iterator begin() { return iterator(buf); }
//	iterator end() { return iterator(buf+_size); }
//};
//int main()
//{
//	Vector<int> v;
//
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//
//	cout << "capacity : " << v.capacity() << endl;
//	for (int i = 0; i < (int)v.size(); ++i)
//		cout << v[i] << endl;
//
//	for (Vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
//		cout << *iter << endl;
//
//	for (auto item : v)
//		cout << item << endl;
//}
