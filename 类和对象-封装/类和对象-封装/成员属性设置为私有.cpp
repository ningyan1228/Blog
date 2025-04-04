#include <iostream>
using namespace std;
#include<string>
/*
优点1：将所有成员属性设置为私有，
可以自己控制读写权限

优点2：对于写权限，我们可以检测数据的有效性
*/

//成员属性设置为私有
//人类
class Person
{

public:
    // 设置姓名 写
    void setName(string name)
    {
        m_Name = name;
    }
    //获取姓名 读
    string getName()
    {

        return m_Name;
    }

    //获取年龄
    int getAge()
    {
        return m_Age;
    }
    //设置年龄（0-150）
    void setAge(int age) {

        if (age < 0 || age>150)
        {
            cout << "您输入的年龄：" << age << "有误，赋值失败" << endl;
            return;//不是返回值的意思 
            //只是让程序到这里结束不继续执行

        }

        m_Age = age;
    }


    // 设置偶像 写权限
    void setIdol(string idol) {

        m_Idol = idol;
    }

private:
    string m_Name;  //姓名 可读可写

    int m_Age = 18; //年龄 只读 也可以写（年龄在1-150之间

    string m_Idol; //偶像 只写

};





int main5() 
{



    Person kaka;
    //姓名设置 写
    kaka.setName("巴西传奇卡卡");
    //获取姓名 读
    cout << kaka.getName() << endl;

    //设置年龄
    kaka.setAge(160);
    //获取年龄 读
    cout << kaka.getAge() << endl;
  
    //偶像设置  只写 不能访问
    kaka.setIdol("梅西");
   // cout << kaka.setIdol() << endl; 只写状态 外界访问不到
   //  kaka.m_Name="kaka" 私有成员无法访问




    system("pause");
    return 0;
}