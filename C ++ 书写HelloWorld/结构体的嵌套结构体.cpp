#include <iostream>
using namespace std;
#include <string>

struct qiuyuan {
	string name;
	int age;
	int qiuyihaoma;

};
struct jiaolian {
	string name;
	int age;
	int id;
	struct qiuyuan stu;

};

int main151()
{
	jiaolian t1;
	t1.age = 66;
	t1.id = 01;
	t1.name = "瓜迪奥拉";
	t1.stu.age = 10;
	t1.stu.name = "messi";
	t1.stu.qiuyihaoma= 10;
	cout<<"教练年龄："
		<< t1.age
		<< "教练ID ："
		<< t1.id 
		<< "教练姓名 ："
		<< t1.name 
		<< "球员年龄 ："
		<< t1.stu.age 
		<< "球员姓名 ："
		<< t1.stu.name 
		<< "球员号码 ："
		<< t1.stu.qiuyihaoma<<endl;

	//cout << "hello world" << endl;
	system("pause");
	return 0;
}