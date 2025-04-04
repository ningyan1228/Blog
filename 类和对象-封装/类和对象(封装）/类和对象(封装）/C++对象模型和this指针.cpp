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
public:   
    int m_A; //非静态成员变量  属于类的对象上  只有他属于

    static int m_B; //静态成员变量，不属于类的对象上

    void func(){} //非静态成员函数 不属于类对象上
    /*不属于类对象上意思是没有增加空间输出这段语句的时候：
     cout << "size of p= " << sizeof(p) << endl;
    */
    static void func2() {  //不属于类的对象上

    }
};

int Person::m_B = 10;

void test01() {
    Person p;  //class 里面属性啥也不写的情况下
    //虽然是空对象，但是也不能占用同样的位置
    //空对象占用内存空间为  1 字节；
    //因为c++编译器会给每个空对象也分配一个字节空间，
    // 每个空对象也应该有一个独一无二的内存空间
    // 是为了区分空对象占内存的位置
    cout << "size of p= " << sizeof(p) << endl;
}

void test02() {
    Person p;
    cout << "size of p= " << sizeof(p) << endl;

}

int main1() {

    //test01();
    test02();
    system("pause");
    return 0;
}