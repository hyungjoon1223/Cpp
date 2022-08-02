#include <iostream>
#include "String.h"
using namespace std;
int main()
{
    String s("Hello!");
    for (String::Size_type i = 0; i < s.size(); ++i)
        cout << s.at(i) << " ";                    //문자열 한자씩 출력
    cout << endl;

    s.append("12345");
    cout << s.c_str() << endl;  // c스타일의문자로 출력해줘

    s.assign("ABC");
    cout << s.c_str() << endl;               //ABC로 문자열 교체

    String s2 = s;
    cout << s2.c_str() << endl;
}
