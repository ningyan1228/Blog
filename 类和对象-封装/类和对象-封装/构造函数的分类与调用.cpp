#include <iostream>
using namespace std;
#include<string>

/*
两种分类方式：

​	按参数分为： 有参构造和无参构造

​	按类型分为： 普通构造和拷贝构造

三种调用方式：

​	括号法

​	显示法

​	隐式转换法

*/
//1、构造函数的分类与调用
//分类

class Person {
    
    //构造函数
    //按照参数分类 无参（默认）构造 有参构造
public:
    Person() : age(0) {
        cout << "Person的无参（默认）构造函数调用" << endl;
    }

    Person(int a) {
        age = a;
        cout << "Person的有参构造函数调用" << endl;
    }

    //按照类型分类：普通构造 拷贝构造：Person(const Person &p)
    //拷贝构造函数(Person p)复制到Person里面
    Person(const Person &p) {
        //将传入的p这个人身上的属性，拷贝到这个Person身上
        age = p.age; 
        cout << "Person的拷贝构造函数的调用" << endl;

    }

    //析构函数
    ~Person() {
        cout << "Person的析构函数调用" << endl;
    }
   //属性
public:
    int age;
};

//构造函数的 调用
void test()
{
    /*
    //1、括号法  比较常用
   // Person P = Person(); // 显式调用无参构造
    Person P1;//默认构造函数调用(调用无参构造函数）
    Person P2(10); //调用有参构造函数
    Person P3(P2);       //调用拷贝构造函数
    //cout << "P2的年龄为：" << P2.age << endl;
    //cout << "P3的年龄为：" << P3.age << endl;
    //注意事项：
    /*
    调用默认构造函数的时候，不要加（）
    因为下面这行代码，编译器会认为是一个函数的声明,
    不会认为是在创建对象。
    Person P1();
    */

    //2、显示法
    Person p1;               //无参构造
    Person p2 = Person(10);  //有参构造
    //Person(10);//匿名对象，特点：当前行执行结束后，
    //系统会立即回收掉匿名对象
    Person p3 = Person(p2);  //拷贝构造
    //注意事项
    /*
    不要利用拷贝构造函数，初始化匿名对象
    Person(p3)；
    编译器会认为Person(p3)==Person p3;编译器会认为是：对象声明
    */

    //3、隐式转换法
    Person p4 = 10;//相当于Person p4=Person(10); 有参构造调用
    Person p5 = p4; //拷贝构造

}


int main9() {

    test();

    system("pause");
    return 0;
}