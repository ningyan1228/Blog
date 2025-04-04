#include <iostream>
using namespace std;
#include<string>
// 结构体定义
struct student {
	int age;
	string name;
	int score;
};

//值传递
void printStudent(student stu)
{
	stu.age = 10;
	cout << stu.age << stu.name << stu.score << endl;
}

//地址传递
void printStudent2(student *stu)
{
	stu->age = 66;
	cout << stu->age << stu->name << stu->score << endl;
}

int main152()
{
	student stu = { 20,"kaka",99};
	//值传递
	printStudent(stu);
	cout << stu.age << stu.name << stu.score << endl;

	//地址传递
	printStudent2(&stu);

	cout << "主函数中 姓名：" 
		<< stu.name << " 年龄： " 
		<< stu.age << " 分数：" 
		<< stu.score << endl;

	
	
	system("pause");
	return 0;
}