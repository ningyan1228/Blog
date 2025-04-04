#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
静态成员函数特点：
1 程序共享一个函数
2 静态成员函数只能访问静态成员变量(成员属性）
-------------------------------------------
*/

//
class Xby 
{
public:
    //静态成员函数
    static void nizu()
    {
        age = 39; //静态成员函数可以访问静态成员变量
        //因为静态成员属性是共享的不用区分是哪一个对象的
        //id=19；静态成员函数不可以访问 非静态成员变量
        //因为无法区分是哪个对象的id属性
        cout << "静态成员函数 static void nizu 的调用" << endl;
    }
private:
    static void nizu1() {

        cout << "静态成员函数 私有的static void nizu 的调用" << endl;
    }


    int id; //非静态成员变量
    //静态成员变量（属性）
    static int age;
};
//类外初始化静态成员变量
int Xby::age = 19;


//测试  用户自定义的全局函数 独立于类，
void qiuyuan() 
{
    //静态成员函数的调用（访问）也是通过对象访问或者是类名访问
    //1、通过对象访问
    Xby yamaer;
    yamaer.nizu();


    //2、通过类名访问
    Xby::nizu();

    // 静态成员函数也有访问权限
   // Xby::nizu1();  不可访问 类外不可访问私有的静态成员函数


}


int main() {


    qiuyuan();
    system("pause");
    return 0;
}