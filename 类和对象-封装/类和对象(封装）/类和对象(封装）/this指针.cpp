#include <iostream>
using namespace std;
#include<string>


/* ----------------------------------------
��C++�г�Ա�����ͳ�Ա�����Ƿֿ��洢��

ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݺ���ʵ����Ҳ����˵���ͬ���͵Ķ���Ṳ��һ�����

��ô�����ǣ���һ���������������Ǹ���������Լ����أ�



c++ͨ���ṩ����Ķ���ָ�룬thisָ�룬����������⡣

 **thisָ��ָ�򱻵��õĳ�Ա���������Ķ���**
 * �ĸ�������ú�����this��ָ��ö���
 
thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��

thisָ�벻��Ҫ���壬ֱ��ʹ�ü���

thisָ�����;��

*  �������βκͳ�Ա���������ԣ�ͬ��ʱ������thisָ��������
*  ����ķǾ�̬��Ա�����з��ض�������ʹ��return *this
-------------------------------------------
*/
class Club {

public:
    Club(int age) {
        //thisָ��ָ����� �����õĳ�Ա���������Ķ���
        //Ҳ����thisָ��Club(int age)���������ģ����õģ�basa����
        //˭���ú���˭�ͱ�thisָ��

    //1��������Ƴ�ͻ
        this->age = age;
        //����this�Ļ�����Ĭ����Ϊ���������age��һ��������
        // ������Ա����age��
        //this->age��age�����Ե�age��һ���£��������ѡ�л���ʾ
       //�βε�age��this->age=�ġ�age����һ����
    }
    //2�����ض�������*this
    Club & Clubguojiageadd(Club &p) { //�ĸ�������� p�����ĸ�����ı���
        this->age += p.age; //��������൱��˭����this->age 
        //this��ָ��˭ Ȼ��ָ��Ķ��������Ҫ���ϴ��ι���������
        
        //this��ָ��agt�����ָ�룬Ҳ����ָ����agt.
        // ��Ϊagt���������������
        // *thisָ��ľ���agt�������ı���
        return *this;//Ҫ���ض���agt�����Ҫ�����õķ�ʽ��һ������
    }


    //��Ա����
    int age=10;
};



//1��������Ƴ�ͻ
void test00() {
    Club basa(20);
    cout << "basa�����䣺 " << basa.age<<endl;
    // ����this��ʱ��������δ�����ȥ20 �����Ὣ��Ա������ֵ10����
}
//2�����ض�������*this
void test10() {

    Club majing(10);
    Club agt(20);
   // agt.Clubguojiageadd(majing);  ����һ�α��˵�majing�������agt
  /*���agt���õĺ���Clubguojiaageadd���ķ���ֵ����age���������
  ��ô�Ϳ���һֱʹ���������agt.Clubguojiageadd(majing)��һֱ׷��
  */
    //agt.Clubguojiageadd(majing)����������30
    //��ʽ���˼��
    agt.Clubguojiageadd(majing).Clubguojiageadd(majing);
    //�ټ�һ������40

     
    cout << "agt������Ϊ�� " << agt.age << endl;
    



}






int main99() {

    //test00();
    test10();
    system("pause");
    return 0;
}