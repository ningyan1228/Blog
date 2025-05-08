#include <iostream>   // 包含输入输出流库
using namespace std;  // 使用标准命名空间（可以少写std::）
#include <string>     // 字符串库（虽然这里没用到）

/* ----------------------------------------
作用：可以输出自定义数据类型
这段代码演示了如何通过**重载左移运算符（<<）**让 cout 直接输出自定义的类对象。
-------------------------------------------
让 cout << Football对象 能够输出对象的成员变量（如 q_a 和 q_b），
就像输出基本类型（如 int）一样。
*/
//左移运算符（<<)重载  Football 类定义
class Football {
    friend ostream & operator<<(ostream& cout, Football& p);
    //operator<< 是全局函数，默认无法访问类的私有成员（q_a, q_b）。
    // 通过友元声明，允许该函数访问私有数据。


public:
    Football(int a, int b) {   // 构造函数
        q_a = a;
        q_b = b;
    }

private:

    ////利用成员函数重载 左移运算符
    //void operator<<(Football &p)
    //{
    //不利用成员函数重载<<运算符，因为无法实现
    //cout在左侧

    //}
    // 成员属性
    int q_a;  
    int q_b;

};

/*
为什么用全局函数？
因为如果用成员函数重载，调用方式会变成 z << cout（对象在左边），
不符合习惯的 cout << z 写法。
*/
//只能利用全局函数重载左移运算符
ostream & operator<<(ostream &cout,Football & p)
//本质operator<<(cout,p) 等于cout<<p 返回值类型是ostream

//cout的本质 是ostream类的对象 也就是：ostream cout  |cout实质上是ostream生成的对象

/*
作用：教 cout 如何输出 Football 对象
分解理解：
ostream&：返回输出流引用（为了支持连续输出，如 cout << a << b）
operator<<：重载左移运算符(<<)的函数名
返回类型 operator运算符(参数列表) {
    // 实现逻辑
    }
参数1 ostream &cout：输出流对象（可以改名，比如叫 os）
参数2 Football &p：要输出的 类Football 的对象
函数体：告诉 cout 输出 Football 的两个成员变量
返回值：返回 cout 本身，以便连续输出
类比：就像教打印机怎么打印足球比赛报告单
*/
{
    cout << "q_a= " << p.q_a << "  q_b= " << p.q_b;
    return cout;
    /*
    返回引用的原因：
    为了支持链式调用，比如 cout << z << endl; 
    实际上是 (cout << z) << endl;，需要前面的操作返回 cout
    cout<<(cout<<z)<<endl;
    */
}

//测试函数
void testf() {
    Football z(10, 11);   // 创建一个足球数据对象z
 //   z.q_a = 10;
  //  z.q_b = 20;


    //cout << z.q_a << endl; q_a是内置数据类型 是整型
   // cout<<z<<endl; 输出时不知道如何输出Football数据类型
    cout << z<<endl;
    /*
    // 重点！第43行：输出z对象
    执行流程：
    创建对象 z 并设置数据
    使用 cout << z 输出对象
    endl 表示换行并刷新缓冲区
    */
    /*
    参数顺序的奥秘：
    cout << z 实际上被转换为 operator<<(cout, z)，
    所以参数顺序必须是 (输出流, 对象)
    -----------------------------------------------------------------
    执行步骤：

编译器发现 z 是 Football 类型
查找是否有匹配的 operator<< 重载
找到我们写的 operator<<(ostream&, Football&)
调用这个函数，把 z 的数据输出到 cout
继续处理 << endl，输出换行
类比：就像把 z 的数据"喂"给 cout，cout 按照我们教的方式打印出来

    */

}


int main() {

    testf();

    system("pause");
    return 0;
}

