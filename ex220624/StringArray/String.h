#pragma once
class String
{
public:

    typedef unsigned int Size_type;
private:
    char* buf;
    Size_type length;
    const String& operator = (const String& arg);
public:

    typedef unsigned int Size_type;

public:
    String(const char* s = " ");
    String(const String& arg);
    ~String();
    Size_type size()const;
    char at(Size_type i)const;
    void append(const char* s);
    void assign(const char* s);
    const char* c_str()const;

};
