#include <iostream>
using namespace std;
#include<string>

struct student
{
	// 成员列表
	string name;
	int age;
	int score;

};

int main150()
{
	struct student stu1;
	stu1.age = 20;
	stu1.name = "k77";
	stu1.score = 90;
	cout << stu1.age << stu1.name << stu1.score << endl;

	struct student* p = &stu1;
	p->age = 60;
	cout << "姓名：" << p->name 
		<< " 年龄：" << p->age 
		<< " 分数：" << p->score << endl;

	struct student arr[6] = {
		{"梅西",36,100},
		{"莫德里奇",40,100},
		{"罗纳尔多",50,99},
		{"小罗",55,89},
		{"卡卡",56,99},
		{"古力特",60,99}
	};
	for (int i = 0;i < 6;i++)
	{

		cout << "姓名:" << arr[i].name << " "
			<< "年龄:" << arr[i].age << " "
			<< "分数:" << arr[i].score << endl;

	}




	// cout << "hello world" << endl;
	system("pause");
	return 0;
}