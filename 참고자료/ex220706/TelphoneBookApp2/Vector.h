#pragma once
template <typename T>
class Vector
{
public:
	class iterator
	{
		T* ptr;
	public:
		explicit iterator(T* p = nullptr) :ptr(p) {}
		T& operator*()
		{
			return *ptr;
		}
		T* operator->()
		{
			return ptr;
		}
		iterator operator++()
		{
			++ptr;
			return *this;
		}
		bool operator==(iterator arg)
		{
			return ptr == arg.ptr;
		}
		bool operator!=(iterator arg)
		{
			return !(*this == arg);
		}
		iterator operator+(int idx)
		{
			return iterator(ptr + idx);
		}
		T* getPtr() { return ptr; }
	};
	class const_iterator
	{
		T* ptr;
	public:
		const_iterator(T* p = nullptr) :ptr(p) {}
		const T& operator*()const
		{
			return *ptr;
		}
		const T* operator->()const
		{
			return ptr;
		}
		const_iterator operator++()
		{
			++ptr;
			return *this;
		}
		bool operator==(const_iterator arg)const
		{
			return ptr == arg.ptr;
		}
		bool operator!=(const_iterator arg)const
		{
			return !(*this == arg);
		}
	};
private:
	T* buf;
	int _size;
	int _capacity;
private:
	T* _initandcopy(int cap)
	{
		T* t = new T[_capacity = cap];
		for (int i = 0; i < _size; ++i)
			t[i] = buf[i];

		return t;
	}
	Vector(const Vector&);
	const Vector& operator=(const Vector&);
public:
	Vector() :buf(nullptr), _size(0), _capacity(0) {}
	~Vector() { delete[] buf; }
	void push_back(const T& data)
	{
		if (_capacity == 0)
			buf = _initandcopy(1);
		else if (_size == _capacity)
		{
			T* t = _initandcopy(_capacity * 2);
			delete[] buf;
			buf = t;
		}
		buf[_size++] = data;
	}
	void erase(iterator iter)
	{
		int delIndex = iter.getPtr() - buf;
		for (int i = delIndex; i < _size - 1; ++i)
			buf[i] = buf[i + 1];
		--_size;
	}
	int size()const { return _size; }
	int capacity()const { return _capacity; }
	T& operator[](int idx) { return buf[idx]; }
	const T& operator[](int idx)const { return buf[idx]; }
	////////
	iterator begin() { return iterator(buf); }
	iterator end() { return iterator(buf + _size); }
	const_iterator cbegin()const { return const_iterator(buf); }
	const_iterator cend()const { return const_iterator(buf + _size); }

};