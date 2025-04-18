#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
成员函数做友元
-------------------------------------------
*/
class Building06;
class GoodGay01
{
public:
    //函数声明
    GoodGay01();

    void visit(); //让visit函数可以访问building06中的私有成员

    void visit1();//让visit1函数不可以访问building06中的私有成员

    Building06* building;

};

class Building06
{
    //告诉编译器GoodGay下的visit成员函数作为本类的好朋友，
    // 可以访问本类的私有成员属性
    friend void GoodGay01 :: visit();
public:
    Building06();
public:
    string m_SittingRoom;
private:
    string m_BedRoom;



};

//类外实现构造函数 等其他函数
Building06::Building06() {
    m_BedRoom = "卧室";
    m_SittingRoom = "客厅";
}

GoodGay01::GoodGay01() {
    building = new Building06;
}
void GoodGay01::visit() {
    cout << "visit函数正在访问： " << building->m_SittingRoom << endl;

    cout << "visit函数正在访问： " << building->m_BedRoom<< endl;
}
void GoodGay01::visit1()
{
    cout << "visit函数正在访问： " << building->m_SittingRoom << endl;
   // cout << "visit函数正在访问： " << building->m_BedRoom << endl;
}

void test00001() {
    GoodGay01 gm;
    gm.visit();
    gm.visit1();
}

int main100() {


    test00001();
    system("pause");
    return 0;
}