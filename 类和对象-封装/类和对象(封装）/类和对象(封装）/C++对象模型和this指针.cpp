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

    //空对象占用内存空间为  1 字节；
    //因为c++编译器会给每个空对象也分配一个字节空间，
    // 每个空对象都需要占用独一无二的内存空间
    // 是为了区分空对象占内存的位置
    cout << "size of p= " << sizeof(p) << endl;
}

int main() {

    test01();

    system("pause");
    return 0;
}