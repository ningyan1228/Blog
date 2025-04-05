#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针

如果用到this指针，需要加以判断保证代码的健壮性
-------------------------------------------
*/

class Basa {
public:
    void showClassName() {
        cout << "这是一个Basa类 " << endl;
    }

    void showBasaAge() {
        //报错原因是因为传入的指针是为空NULL

        if (this == NULL) {
            return;
        }
        cout << "age= " << m_Age << endl;
        //编译器默认会加上 this->m_Age
    }


    int m_Age;
};

void test() {
   Basa* p = NULL;  //空指针
   p->showBasaAge();
 //  p->showClassName();
}

int main() {

    test();

    system("pause");
    return 0;
}