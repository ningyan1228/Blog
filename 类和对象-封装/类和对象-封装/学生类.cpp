#include <iostream>
using namespace std;
#include<string>


//设计一个学生类，属性有姓名和学号，
//可以给姓名和学号赋值，可以显示学生的姓名和学号

//设计学生类
class Student {
	
public:         //公共权限

	//类中的属性和行为，我们统一称为 成员
	//属性  也称为 成员属性 成员变量
	string m_Name;
	int m_Id;

	//行为 又叫做成员函数 成员方法
	//显示姓名和学号
	void showStudent()
	{

	cout << "姓名： " << m_Name << "学号： " << m_Id << endl;

	}
	//给姓名赋值 通过行为给属性赋值
	void setName(string name)
	{
		m_Name = name;
	}
	void setId(int Id)
	{
		m_Id = Id;
	}

};




int main2()
{
	//创建具体的学生
	//创建一个具体学生 实例化对象
	Student s1;
	//给s1对象 进行属性赋值
	//s1.m_Name = "卡卡";
	s1.setName("卡卡"); //
	//s1.m_Id = 22;
	s1.setId(22);
	s1.showStudent();

	Student s2;
	s2.m_Name = "莱万多夫斯基";
	s2.m_Id = 9;
	
	s2.showStudent();
	system("pause");
	return 0;
}