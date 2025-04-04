#include <iostream>
using namespace std;
#include<string>

/*
C++中拷贝构造函数调用时机通常有三种情况

* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象
*/


class Person {
public:
    Person() : m_Age(0) {
        cout << "Person默认构造函数调用" << endl;
    }
    Person(int age) {
        cout << "Person有参构造函数调用" << endl;
        m_Age = age;
    }
    Person(const Person& p) {
        cout << "Person拷贝构造函数调用" << endl;
        m_Age = p.m_Age;
    }

    ~Person() {
        cout << "Person析构函数调用" << endl;
    }

    //属性
    int m_Age;
};

//2、使用一个已经创建完毕的对象来初始化一个新对象
void test02()
{
    Person p1(20);
    Person p2(p1); //拷贝构造函数把p1都拷到p2
    cout << "p2的年龄为：" << p2.m_Age << endl;
}

//2、值传递的方式给函数参数传值
void doWork(Person p)
//当以值传递的方式传递对象给函数时，会触发拷贝构造函数
{

}

void test03()
{
    Person p;  // 1. 调用默认构造函数
    //你（main函数）想喝奶茶，
    // 于是你写了个纸条（对象p）告诉外卖员要什么奶茶。
    doWork(p);  // 2. 值传递触发拷贝构造
    //关键操作：你把纸条复印了一份（值传递）
    // 给外卖员（函数doWork）
} // 3. 函数结束时对象被析构
/*
系统会创建一个 p 的副本（拷贝）
触发拷贝构造函数生成形参 Person p（函数参数）
输出：Person拷贝构造函数调用
test03() 执行流程
           │
           ├─ 创建 p (默认构造)
           │
           ├─ 调用 doWork(p)
           │   │
           │   ├─ 拷贝构造生成形参副本
           │   │
           │   └─ doWork 结束，销毁副本
           │
           └─ test03 结束，销毁 p

    为什么需要拷贝构造？
    值传递的本质：函数获得的是参数的独立副本
    保护原始对象：函数内部对参数的修改不会影响原始对象
    数据隔离：确保函数操作的是独立的数据拷贝
*/
//3、以值方式返回局部对象
Person doWork2()
{

    Person p1;
    cout << (int*)&p1 << endl;
    return p1;
}
void test04() {
    Person p = doWork2();
    cout << (int*)&p << endl;
}
// 第108个视频
int main10() {

   // test02();
    //test03();
    test04();
    system("pause");
    return 0;
}