#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
C++类中的成员可以是另一个类的(实例）对象，
我们称该成员为 对象成员
-------------------------------------------
例如：
class A {}
class B
{
    A a；//A的实例对象，是B类的成员
    类对象作为类成员

}
*/
//类对象作为类成员
//手机类
class Phone 
{
public:
    //构造函数带参 行为
    Phone(string pname) {
        m_pname = pname;
        cout << "Phone的构造函数调用" << endl;
    }
   

    ~Phone() {
        cout << "Phone的析构函数调用" << endl;
        cout.flush(); // 强制刷新输出缓冲区
        //看人和手机谁先调用析构函数
    }

    //手机品牌名称 属性
    string m_pname;
};



//人 类
class Person {
public:
    //行为  初始化列表 构造函数
    Person(string name, string pname) :m_name(name), m_phone(pname) {
        cout << "Person的构造函数调用" << endl;

    }
    ~Person() {
        cout << "Person的析构函数调用" << endl;
        //看人和手机谁先调用析构函数
    }


    //属性
//姓名
    string m_name;
//手机 手机的实例对象
    Phone m_phone;
};

//当其他类对象（手机类对象）作为本类成员，
// 构造时候先构造类对象(手机），再构造自身（人）
//析构函数：析构的顺序与构造相反
void test00() {
    Person p("梅西", "三星");
    cout << p.m_name << p.m_phone.m_pname << endl;
}


int main15() {

    test00();
   
    system("pause");
    return 0;
}