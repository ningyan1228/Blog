#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��

����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��
-------------------------------------------
*/

class Basa {
public:
    void showClassName() {
        cout << "����һ��Basa�� " << endl;
    }

    void showBasaAge() {
        //����ԭ������Ϊ�����ָ����Ϊ��NULL

        if (this == NULL) {
            return;
        }
        cout << "age= " << m_Age << endl;
        //������Ĭ�ϻ���� this->m_Age
    }


    int m_Age;
};

void test() {
   Basa* p = NULL;  //��ָ��
   p->showBasaAge();
 //  p->showClassName();
}

int main() {

    test();

    system("pause");
    return 0;
}