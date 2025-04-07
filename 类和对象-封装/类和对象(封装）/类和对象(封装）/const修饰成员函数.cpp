#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
**常函数：**

* 成员函数后加const后我们称为这个函数为**常函数**
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改



**常对象：**

* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数


-------------------------------------------
*/
//常函数
class China {
public:
    /*
    this 指针的本质就是 指针常量 指针的指向是不可以修改的
    const China *cost this;=void showChina ()const
    在成员函数后面加const，
    修饰的是this指向，让指针指向的值也不可以修改

    */
    //构造函数初始化属性
    China() :c_A(1), c_B(0) {}

    void showChina()const
        //成员函数后加const后我们称为这个函数为常函数
    {
      //  c_A = 100;   //常函数内不可以修改成员属性
        //c_A其实 就等于 this->c_A

        this->c_B = 100;//可以修改常函数的属性的值了
        //=c_B=100;
    }
    void func() {

    }

    int c_A;
    mutable int c_B;//特殊变量在常函数中也可以修改这个变量的值
};

void test000() {
    China p;
    p.showChina();
}

//常对象
void test001() {

    const China p1; //在对象前面加const，变为常对象
    //p1.c_A = 100;//常对象的属性也不允许被修改
    p1.c_B = 100; //c_B是特殊值 在常对象下也可以修改
    //常对象只能调用常函数
    p1.showChina();
    //p1.func();//常对象不能调用普通成员函数
    /*因为在func()普通的非常函数里面可以修改属性的值，所以
    作为常对象不能修改属性值，所以说不能调用非”常函数“*/

}


int main007() {

    test000();
    test001();
    system("pause");
    return 0;
}