#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
生活中你的家有客厅(Public)，有你的卧室(Private)

客厅所有来的客人都可以进去，
但是你的卧室是私有的，
也就是说只有你能进去

但是呢，你也可以允许你的好闺蜜好基友进去。

在程序里，有些私有属性 也
想让类外特殊的一些函数或者类进行访问，
就需要用到友元的技术

友元的目的就是让一个函数或者类 访问另一个类中私有成员

友元的关键字为  friend



友元的三种实现

* 全局函数做友元  goodgay
* 类做友元
* 成员函数做友元


-------------------------------------------
*/
//全局函数做友元
//房屋类
class Building {
    //告诉编译器 goodGay全局函数 是 Building类的好朋友，
    //可以访问房屋类中的私有内容 
    //两次分别对应 指针和引用传参
    friend void goodGay(Building * building); //指针
    friend void goodGay1(Building & building);//引用
    //goodGay全局函数是Building的好朋友，可以访问Building的私有成员
public:
    //构造函数
    Building() {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";

    }

    string m_SittingRoom;//客厅  公共属性

private:  //私有属性 
    string m_BedRoom;

};

//全局函数  1、指针传递参数
void goodGay(Building *building)//形参传入一个building的对象进来
//void goodGay(Building &building) 指针或者是引用都可以传进来
//目的是访问房屋的公共属性和私有属性
{
    cout << "好基友全局函数 正在访问客厅： " 
         << building->m_SittingRoom << endl;
    // 指针 需用 -> 访问成员

    cout << "好基友全局函数 正在访问卧室： "
         << building->m_BedRoom<< endl;

}
//2、 引用传递参数
void goodGay1(Building & building) {

    cout << "好基友全局函数 正在访问： "
        << building.m_SittingRoom << endl;

    cout << "好基友全局函数 正在访问： "
        << building.m_BedRoom << endl;
    //  引用 用 . 访问成员

}

/*
无论是指针还是引用，本质都是通过 内存地址 间接操作对象。
友元函数 goodGay 被授权访问 Building 的私有成员，
因此只要拿到对象地址（指针或引用），
就能访问私有属性。
*/

void test011() {
    Building building; //实例化对象
    goodGay(&building); //指针传递显式传递对象地址（使用&）

    goodGay1(building);// 引用直接传递对象
}



int main7() {

    test011();
   
    system("pause");
    return 0;
}

/*
对于59 72行的讲解

在 C++ 中，**指针（Pointer）** 和 **引用（Reference）** 都可以用来间接操作对象，
但它们的语法和特性有本质区别。以下是代码中第 54 行和第 55 行的具体差异：

---

### **代码片段**
```cpp
// 第 59 行（实际代码）
void goodGay(Building *building) {  // 指针传递
    cout << building->m_SittingRoom << endl;
    cout << building->m_BedRoom << endl;
}

// 第 72 行（注释中的代码）
void goodGay(Building &building) {  // 引用传递
    cout << building.m_SittingRoom << endl;
    cout << building.m_BedRoom << endl;
}
```

---

### **核心区别**
| **特性**         | **指针传递 (`Building*`)**                     | **引用传递 (`Building&`)**                     |
|------------------|-----------------------------------------------|-----------------------------------------------|
| **语法**         | 使用 `->` 访问成员 属性                            | 使用 `.` 访问成员                              |
| **参数传递方式** | 需显式传递对象地址（`&building`）              | 直接传递对象（`building`）                     |
| **空值风险**     | 可以传递 `nullptr`（需判空）                   | 必须绑定有效对象（不可为空）                    |
| **内存操作**     | 可以修改指针指向其他对象                       | 始终绑定初始对象（不可修改）                    |
| **代码安全性**   | 需手动检查空指针                               | 天然避免空引用                                 |

---

### **具体分析**
#### 1. **指针传递 (`Building*`)**
```cpp
void test011() {
    Building building;
    goodGay(&building); // 传递对象地址
}
```
- **优点**：
  - 可以显式控制是否传递空指针（`nullptr`）
  - 适合需要动态内存管理或修改指针指向的场景
- **缺点**：
  - 需用 `->` 访问成员，语法稍显复杂
  - 需手动检查空指针（否则可能崩溃）

#### 2. **引用传递 (`Building&`)**
```cpp
void test011() {
    Building building;
    goodGay(building); // 直接传递对象
}
```
- **优点**：
  - 语法简洁（直接使用 `.` 访问成员）
  - 天然避免空引用（编译器保证绑定有效对象）
- **缺点**：
  - 无法绑定到空值（必须传递有效对象）
  - 引用一旦绑定，不可修改指向其他对象

---

### **为什么说“都可以传进来”？**
- **底层原理**：
  无论是指针还是引用，本质上都是通过 **内存地址** 间接操作对象。
  友元函数 `goodGay` 被授权访问 `Building` 的私有成员，因此只要拿到对象地址（指针或引用），就能访问私有属性。

- **代码验证**：
  ```cpp
  // 指针版本
  void goodGay(Building *building) {
      cout << building->m_BedRoom << endl; // 合法
  }

  // 引用版本
  void goodGay(Building &building) {
      cout << building.m_BedRoom << endl;  // 合法
  }
  ```

---

### **如何选择？**
| **场景**                     | **推荐方式**       |
|------------------------------|-------------------|
| 需要明确表示“可能无对象”     | 指针（可传 `nullptr`） |
| 需要简洁语法和安全保证        | 引用               |
| 需要动态修改指向              | 指针               |
| 函数参数需支持多态（基类指针）| 指针               |

---

### **总结**
- **指针传递**：灵活但需手动管理空值
- **引用传递**：安全简洁但不可为空
- 在友元函数中，两者均可访问私有成员，但语法和安全性不同。
- 推荐优先使用 **引用传递**（除非需要处理空值或动态内存）。
=============================================================
总结：              指针    vs 引用参数传递
特性	 指针 (Building*)	      引用 (Building&)
语法	 goodGay(&building)	      goodGay(building)
成员访问 building->m_BedRoom	  building.m_BedRoom
空值风险 可能传递 nullptr（需判空）	必须绑定有效对象（不可为空）
*/