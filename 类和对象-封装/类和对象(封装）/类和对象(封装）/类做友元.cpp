#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
类做友元  做友元目的让一个类可以访问另一个类的私有成员
-------------------------------------------
*/
// 类做友元

class Building01;  // 前向声明 表明我有这个Building01类 GoodGay可以用

class GoodGay {

public:
    GoodGay();  //goodgay也给一个构造函数  也在类外写成员函数
    // 构造函数声明
    void visit(); //参观属性 访问Building中的属性  也在类外实现
    // 访问函数声明
private:
    Building01 *building;   // 指针(building)为私有成员变量（属性）
    
    /*
    将building指针设为私有，外部无法直接访问指针
    必须通过公有方法（如visit()）操作指针，符合面向对象封装原则

    声明指针成员变量：
    Building01 是之前通过前向声明引入的类名
    *building 表示声明一个指向Building01类对象的指针变量
    这个指针变量作为GoodGay类的私有(private)成员存在
    GoodGay对象：
┌───────────┐             堆内存
│ building             │───→  Building01对象
└───────────┘
                            ┌──────────────┐
                            │ m_SittingRoom              │
                            │ m_BedRoom                  │
                            └──────────────┘
    虽然指针是private的，但通过public的visit()方法对外提供访问接口

    */
};

class Building01 {
   friend class GoodGay; //类做友元 // 友元声明
   // GoodGay 类是本类的好朋友 可以访问本类中的私有成员
public:   //构造函数   
    Building01();

    //成员属性 变量
public:
    string m_SittingRoom;  //客厅  // 公有属性-客厅

private:
    string m_BedRoom; //卧室  私有属性-卧室

};

// 类外写成员函数  （类的成员函数）
//函数的实现等同于函数的定义 类内声明 类外定义
//Building01构造函数实现
Building01::Building01() {  //Building01构造函数实现
    //在成员函数里面给属性赋初值
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

// GoodGay构造函数实现
GoodGay::GoodGay() {

    //创建建筑物实例化对象
    building = new Building01;  //在堆区创建对象 给building
    // 堆内存分配
    /*
    building = new Building01;这行代码是C++动态内存分配的关键操作
    building    =      new           Building01;
   │           │      │           │
   └指针变量  赋值  内存分配操作符  要实例化的类

   执行过程详解：

    1、内存分配：new操作符在堆(heap)内存中开辟一块足够存放
    Building01对象的内存空间
    2、对象构造：调用Building01类的构造函数，初始化这个新对象
    3、地址返回：将新创建对象的内存地址返回
    4、指针赋值：将这个地址值存储到building指针变量中

    栈内存 (Stack)        堆内存 (Heap)
┌─────── ┐     ┌──────────────┐
│ GoodGay对象   │       │ Building01类的实例  │
│ ┌─────┐│     │ m_SittingRoom    │
│ │ building ├┼  → │ m_BedRoom        │
│ └─────┘│     └──────────────┘
└─────── ┘

Building01 *building; 和 building = new Building01;
是C++中指针使用的两个关键步骤：
1、角色分工（先声明后使用）
Building01 *building; 声明阶段  
内存状态示意：[🗳️ 空盒子] → □□□□□
类比说明： 准备一个空信封（未写地址）

building = new Building01; 初始化
内存状态示意：[📦 盒子] → 0x123456 (堆对象)
类比说明：把信件地址写在信封上
2、技术实现
// 阶段一：指针声明（第22行）
Building01 *building;
// 在栈内存中分配一个指针变量（4/8字节），
此时值为随机地址（野指针）

// 阶段二：动态内存分配（构造函数中）
building = new Building01;
// 1. 调用operator new分配sizeof(Building01)字节堆内存
// 2. 调用Building01构造函数初始化该内存区域
// 3. 将获得的内存地址存入building指针

3. 内存变化对比
执行前（仅声明指针）：

TEXT
GoodGay对象内存布局
┌──────────────┐
│ ...          │
│ building: ?  │  → 指向随机地址（可能为0xcccccccc等调试模式标记）
└──────────────┘
执行后（完成new操作）：

TEXT
GoodGay对象内存布局            堆内存
┌──────────────┐           ┌──────────────────┐
│ ...          │           │ Building01实例   │
│ building: 0x78│────────→ │ - m_SittingRoom  │
└──────────────┘           │ - m_BedRoom      │
                           └──────────────────┘

    */
}

// GoodGay访问函数实现
//虽然指针是private的，但通过public的visit()方法对外提供访问接口
void GoodGay::visit() {
    // 表明building指针是GoodGay的成员函数
  cout << "好基友类正在访问： " << building->m_SittingRoom << endl;
  cout << "好基友类正在访问： " << building->m_BedRoom << endl;
}

//测试函数  测试案例
void test010() {
    GoodGay gg;  //利用GoodGay这个类实例化一个对象gg
    gg.visit();   // 通过公有接口访问

}

int main009() {

    test010();

    system("pause");
    return 0;
}
/*

*/