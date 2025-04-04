#include <iostream>
using namespace std;
#include<string>

/*
默认情况下，c++编译器至少给一个类添加3个函数

1．默认构造函数(无参，函数体为空) 空实现

2．默认析构函数(无参，函数体为空) 空实现

3．默认拷贝构造函数，对属性进行值拷贝  值拷贝

构造函数调用规则如下：

*1、 如果用户定义有参构造函数，
c++不在提供默认无参构造，但是会提供默认拷贝构造
------------------------------------------------
*2、 如果用户定义拷贝构造函数，c++不会再提供其他构造函数
*/
class Club {
public:
    //Club() {
    //   // p_id = 10;//在构造函数体内给属性球员号码 赋值
    //    cout << " Club的默认构造函数调用" << endl;
    //}

    //Club(int id) {
    //    //p_id = 10;//在构造函数体内给属性球员号码 赋值
    //    cout << " Club的有参构造函数调用" << endl;
    //    p_id = id;
    //    
    //}
    Club(const Club& p) {
        cout << " Club的拷贝构造函数调用" << endl;
        p_id = p.p_id;

    }

    ~Club() {
        cout << " Club的析构函数调用" << endl;
    }
    int p_id=0;

};

//测试案例
//void test1()
//{
//    //创建类的对象（实例）
//    Club m;
//    m.p_id = 10;
//    Club k(m);  //创建类的对象（实例）
//    cout << "卡的球员号码为： " <<k.p_id<< endl;
//    Club n(9);
//
//}

//如果用户定义有参构造函数，
//c++不在提供默认无参构造，但是会提供默认拷贝构造
//void test2() {

   // Club l;  //c++不在提供默认无参构造 
   // 调用默认构造会输出没有默认构造

    //Club s(11);
    //Club y(s);
    //cout << "s的球员号码为： " << s.p_id << endl;
//}

//如果用户定义拷贝构造函数，c++不会再提供其他构造函数
void test3() {

    //Club p; 
   // 调用默认构造会输出没有默认构造

    //Club s(11);
    //Club y(s);
    //cout << "s的球员号码为： " << s.p_id << endl;
}


int main11() {

    //test1();
    //test2();
    system("pause");
    return 0;
}