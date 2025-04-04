#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
#### 成员变量和成员函数分开存储



在C++中，类内的成员变量(属性）和成员函数分开存储

只有非静态成员变量才属于类的对象上
-------------------------------------------
*/
//成员变量和成员函数分开存储
class Person {



};

void test01() {
    Person p;
}

int main() {

    test01();

    system("pause");
    return 0;
}