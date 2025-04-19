#include <iostream>
using namespace std;
#include<string>

/* ----------------------------------------
运算符重载概念：对已有的运算符重新进行定义，
赋予其另一种功能，
以适应不同的数据类型
两个整型数据 1 2 相加 编译器知道怎么做 
但是对于Person自定义的数据类型 编译器就不知道怎么做了

-------------------------------------------
对于内置的数据类型，编译器知道如何进行运算

*/
// 加号运算符重载 定义一个类 人
class Person {
public:
    //1、成员函数重载 +号
    /* 基本语法：
    返回类型 operator运算符(参数列表) {
    // 实现逻辑
    }
    用于让两个 Person 对象可以通过 + 号直接相加
    */
    //🚩关键点1：运算符重载函数
    //Person operator+(Person& p)
    // 作用：重载 + 号运算符，使其能处理 Person 类型的对象
    // 解读：
    //当执行 Person对象1 + Person对象2 时，自动调用此函数
    //    Person & p：传入的另一个 Person 对象
    // （这里是 对象2 的引用）
    // 
    //{
    //    Person temp;  // 创建临时实例化对象
    // 作用：创建一个新的临时 Person 对象，
    // 用于存储相加结果
    //类比：就像计算 1 + 2 时，
    // 先准备一张白纸（temp）记录结果 3
    // 
    //    temp.m_A = this->m_A + p.m_A;
    //    // 当前对象的m_A + 参数对象的m_A
    // 
    // 作用：将两个 Person 对象的属性分别相加
    //详细解释：
     //   this->m_A：当前对象（对象1）的 m_A 值
      //  p.m_A：参数对象（对象2）的 m_A 值
      //  temp.m_A：将两者之和存入临时对象的 m_A
      //  m_B 同理
    // 
    //    temp.m_B = this->m_B + p.m_B;
    //    // 当前对象的m_B + 参数对象的m_B

    //    return temp; // 返回合并后的新对象
    // 类比：把记录结果的白纸（temp）交给使用者
    //}



   //成员属性 （变量）
    int m_A;
    int m_B;
};

//2、全局函数重载+号
//形参用指针或者引用 避免拷贝 节省空间时间
Person operator+(Person& p1, Person& p2) {

    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}
//3、函数重载的版本
/*
函数重载是 C++ 中允许在同一作用域内定义多个同名函数，
但要求这些函数的参数列表（参数类型、数量或顺序）
必须不同的特性。
其核心目的是通过统一的函数名处理不同类型或数量的参数
operator实质上是函数名
*/
Person operator+(Person &p1,int num) {
    Person temp;
    temp.m_A = p1.m_A + num;
    temp.m_B = p1.m_B + num;
    return temp;

}


void testms()
{
    // 🚩关键点2：对象初始化
    Person p1;  // 创建对象p1（未初始化时m_A/m_B是随机值）
    p1.m_A = 10; // 显式赋值m_A = 10
    p1.m_B = 11;  // 显式赋值m_B = 11
    Person p2;  // 创建对象p2
    p2.m_A = 20;  // 显式赋值m_A = 20
    p2.m_B = 21;  // 显式赋值m_B = 21

    // 🚩关键点3：运算符重载调用
    Person p3 = p1 + p2;  
    // 成员函数重载本质调用 等价于Person p3= p1.operator+(p2)
    //全局函数重载本质调用： Person p3=operator+(p1,p2);

    //运算符重载，也可以发生函数重载
    Person p4 = p3 + 10;  //Person + int


    cout << "p3.m_A= " << p3.m_A << endl;
    cout << "p3.m_B= " << p3.m_B << endl;
    cout << "p4.m_A= " << p4.m_A << endl;
    cout << "p4.m_B= " << p4.m_B << endl;
}


int main111() {

    testms();

    system("pause");
    return 0;
}