#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
在C++中成员变量和成员函数是分开存储的

每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码

那么问题是：这一块代码是如何区分那个对象调用自己的呢？



c++通过提供特殊的对象指针，this指针，解决上述问题。

 **this指针指向被调用的成员函数所属的对象**
 * 哪个对象调用函数，this就指向该对象
 
this指针是隐含每一个非静态成员函数内的一种指针

this指针不需要定义，直接使用即可

this指针的用途：

*  当函数形参和成员变量（属性）同名时，可用this指针来区分
*  在类的非静态成员函数中返回对象本身，可使用return *this
-------------------------------------------
*/
class Club {

public:
    Club(int age) {
        //this指针指向的是 被调用的成员函数所属的对象
        //也就是this指向Club(int age)函数所属的（调用的）basa对象
        //谁调用函数谁就被this指向

    //1、解决名称冲突
        this->age = age;
        //不加this的话，会默认认为上面的三个age是一个东西，
        // 不带成员变量age玩
        //this->age的age和属性的age是一回事，可以鼠标选中会显示
       //形参的age和this->age=的“age”是一回事
    }
    //2、返回对象本身用*this
    Club & Clubguojiageadd(Club &p) { //哪个对象调用 p就是哪个对象的别名
        this->age += p.age; //这个函数相当于谁调用this->age 
        //this就指向谁 然后被指向的对象的年龄要加上传参过来的年龄
        
        //this是指向agt对象的指针，也就是指向了agt.
        // 因为agt调用了这个函数，
        // *this指向的就是agt这个对象的本体
        return *this;//要返回对象agt本体就要用引用的方式做一个返回
    }


    //成员变量
    int age=10;
};



//1、解决名称冲突
void test00() {
    Club basa(20);
    cout << "basa的年龄： " << basa.age<<endl;
    // 不加this的时候根本传参传不过去20 并不会将成员变量的值10更改
}
//2、返回对象本身用*this
void test10() {

    Club majing(10);
    Club agt(20);
   // agt.Clubguojiageadd(majing);  加了一次别人的majing的年龄给agt
  /*如果agt调用的函数Clubguojiaageadd，的返回值还是age这个对象本身
  那么就可以一直使用下面这个agt.Clubguojiageadd(majing)，一直追加
  */
    //agt.Clubguojiageadd(majing)；加完马竞是30
    //链式编程思想
    agt.Clubguojiageadd(majing).Clubguojiageadd(majing);
    //再加一次马竞是40

     
    cout << "agt的年龄为： " << agt.age << endl;
    



}






int main99() {

    //test00();
    test10();
    system("pause");
    return 0;
}