#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
类做友元  做友元目的让一个类可以访问另一个类的私有成员
-------------------------------------------
*/
// 类做友元

class Building;

class CoodGay {

public:
    GoodGay();  //goodgay也给一个构造函数  也在类外写成员函数

    void visit(); //参观属性 访问Building中的属性


    Building *building;
};

class Building {
public:   //构造函数   
    Building();

    //成员属性 变量
public:
    string m_SittingRoom;  //客厅

private:
    string m_BedRoom; //卧室

};

// 类外写成员函数  （类的成员函数）

Building::Building() {
    //在成员函数里面给属性赋初值
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}


GoodGay::GoodGay() {

    //创建建筑物实例化对象
    building = new Building;
}




int main() {



    system("pause");
    return 0;
}