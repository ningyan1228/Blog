#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
**作用：
构造函数就是给类中的属性初始化，除此之外，
C++提供了初始化列表语法，用来初始化属性

语法：构造函数()：属性1(值1),属性2（值2）... {}

-------------------------------------------
*/

//初始化列表
//原来对于类中的属性进行初始化是这样的：
class Milan {
public:
    int m_a;
    int m_b;
    int m_c;
    //使用构造函数进行初始化：传统初始化操作
  /*  Milan(int a,int b,int c) {
        m_a = a;
        m_b = b;
        m_c = c;
    }*/

    //初始化列表初始化属性
    /*Milan() :m_a(10), m_b(20), m_c(30) {

    }*/

    Milan(int a,int b,int c) :m_a(a), m_b(b), m_c(c) {

    }



};
void testMi14() {
    /*int a = 1;
    int b = 2;
    int c = 9;*/

    //Milan kaka(6, 9, 6);
    //cout << kaka.m_a << kaka.m_b << kaka.m_c << endl;
    //Milan gulite;

    Milan gulite(30, 90, 90);
    cout << gulite.m_a << gulite.m_b << gulite.m_c << endl;


}

int main13() {

    testMi14();

    system("pause");
    return 0;
}