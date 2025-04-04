#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
静态成员就是在类中 成员变量和成员函数前加上关键字static，称为静态成员
static
静态成员分为：

*  静态成员变量（成员属性）
   *  所有对象共享同一份数据
   *  在编译阶段分配内存
   *  类内声明，类外初始化
   * 
*  静态成员函数（成员方法）
   *  所有对象共享同一个函数
   *  静态成员函数只能访问静态成员变量
-------------------------------------------
*/
//-------------------------------------------
/*
静态成员变量（成员属性）
   *  所有对象共享同一份数据
   *  在编译阶段分配内存 程序还没有运行之前就分配了内存
   *  类内声明，类外初始化
*/
//静态成员变量  类中所有的属性都成了静态成员了
class Agt 
{
public:

    //所有对象共享同一份数据,在编译阶段分配内存
    // 类内声明，类外初始化  必须的操作
    static int m_A; //类内做了声名
    int age;

    //静态成员变量（属性）也有访问权限
    //静态成员变量仍受访问控制符
    // （public/private/protected）约束：
private:
    static int heigth;//类内声明类外必须初始化

};
int Agt:: m_A = 100;  //类外初始化
int Agt::heigth = 170;


//测试  用户自定义的全局函数 独立于类，
void skln() {
    Agt m; //实例化对象
    cout << m.m_A << endl;

    Agt m1;
    m1.m_A = 1019;
    cout << m.m_A << endl;
}

void skln2() {
   //静态成员变量 不属于某个对象上，所有对象都共享同一份数据
   // 不像其他的非静态 每个对象都可以自己设置一个属性值 比如年龄 
    Agt messi;
    messi.age = 37;
    messi.m_A = 10;
    cout << messi.age << messi.m_A << endl;

    Agt dima;
    dima.age = 39;
   // dima.m_A = 11;
    
    cout << dima.age << dima.m_A << endl;
    //静态变量有两种访问方式
    //1、通过对象进行访问
    Agt mading;
    cout << mading.m_A << endl;
    //2、通过类名就行访问
    cout << Agt::m_A << endl;
    //cout << Agt::age << endl; 
    //非静态成员变量只能通过对象去访问

    //静态成员变量仍受访问控制符（public/private/protected）约束：
   // cout << Agt::heigth << endl; 类外访问不到私有静态成员变量

}





int main66() {

   // skln();
    skln2();
    system("pause");
    return 0;
}