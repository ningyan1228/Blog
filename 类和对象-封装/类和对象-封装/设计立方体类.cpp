#include <iostream>
using namespace std;
#include<string>

/*
设计立方体类(Cube)

求出立方体的面积和体积

分别用全局函数和成员函数判断两个立方体是否相等。
*/
//创建立方体的类
//设计属性
//设计行为 获取立方体的面积和体积
//分别利用全局函数和成员函数判断两个立方体是否相等
class Cube
{
public:

    // 设置长
    void setL(int l)
    {
        m_L = l;
    }
    //获取长
    int getL()
    {
        return m_L;

    }

    // 设置宽
    void setW(int w)
    {
        m_W = w;
    }
    //获取宽
    int getW()
    {
        return m_W;

    }

    // 设置高
    void setH(int h)
    {
        m_H = h;
    }
    //获取高
    int getH()
    {
        return m_H;

    }

    // 获取立方体面积
    int calculateS()
    {
        return 2 * m_L * m_W + 2 * m_W * m_H + 2 * m_L * m_H;
    }
    //获取体积
    int calculateV()
    {

        return m_L * m_H * m_W;
    }
    // 成员函数写在类里面
    /*
    函数内部可以直接访问 当前对象（调用该函数的对象）
    的成员变量。你提到的代码中 c1.isSameByClass(c2) 的调用方式，
    实际上是在用 c1 的成员变量和 c2 的成员变量进行比较。
    */
    bool isSameByClass(Cube &c) {
        if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
        /*
         // 这里隐式使用了当前立方体的属性（m_L, m_W, m_H）
        // 和参数立方体c的属性（通过c.getL()等获取）*/
        
        {
            return true;
        }
        return false;

    }

    //设置属性
private:
    int m_L; //长
    int m_W; //宽
    int m_H;//高

};

//利用全局函数判断两个立方体是否相等
bool isSame(Cube& c1, Cube& c2)
{
    if (c1.getL() == c2.getL() && c1.getH() == c2.getH() && c1.getW() == c2.getW())
    {
        return true;
    }
    return false;
}



int main6() {
    //创建立方体对象
    Cube c1;
    c1.setH(10);
    c1.setL(10);
    c1.setW(10);

    cout << "c1的面积为： " << c1.calculateS() << endl;
    cout << "c1的体积为： " << c1.calculateV()<< endl;

    Cube c2;
    c2.setH(11);
    c2.setL(10);
    c2.setW(10);


    bool ret = isSame(c1, c2);
    if (ret) 
    {
        cout << "c1和c2是相等的" << endl;
     }
    else {
        cout << "c1和c2是不相等的" << endl;
    }

    ret = c1.isSameByClass(c2);
    /*
    c1 是调用该成员函数的对象，this 指针指向 c1
    c2 是传入的参数，通过 c.getL() 等方式访问其成员
    为什么必须写成c1.isSameByClass(c2)？
    因为成员函数的工作方式就像对象自带的工具：

    工具归属：isSameByClass是每个立方体自带的比较工具
    使用方式：必须指定用哪个立方体的工具去比较
    比较逻辑：用当前立方体（工具持有者）的属性 vs 参数立方体的属性

    为什么必须写成c1.isSameByClass(c2)？
    因为成员函数的工作方式就像对象自带的工具：

    工具归属：isSameByClass是每个立方体自带的比较工具
    使用方式：必须指定用哪个立方体的工具去比较
    比较逻辑：用当前立方体（工具持有者）的属性 vs 参数立方体的属性

    */
    //成员函数可以直接访问私有数据c1，所以只需要传c2就行了
    if (ret)
    {
        cout << " 成员函数判断c1和c2是相等的" << endl;
    }
    else {
        cout << "成员函数判断c1和c2是不相等的" << endl;
    }
    system("pause");
    return 0;
}