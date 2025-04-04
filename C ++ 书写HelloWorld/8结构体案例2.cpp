#include <iostream>
using namespace std;
#include<string>

//1.设计英雄结构体
struct hero {

	string name;
	int age;
	string sex;
};

//冒泡排序，年龄升序排列
void bubbleSort(hero* arr, int len)
{
	{
		for (int i = 0;i < len - 1;i++)
		{
			for (int j = 0;j < len - 1 - i;j++)
			{
				if (arr[j].age > arr[j + 1].age)
				{
					hero temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}
void printHeros(hero arr[], int len) {
	for (int i = 0;i < len;i++) {
		cout << "姓名： " << arr[i].name 
			<< " 性别： " << arr[i].sex 
			<< " 年龄： " << arr[i].age << endl;
	}
}

int main164()
{
	//2.创建数组并存放五名英雄。
	struct hero arr[5] = {
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < len ; i++)
	{
		cout //<< "姓名： " << heroArray->name // 始终操作第一个刘备 
			// 没有移动指针！结果：所有英雄的数据都被覆盖到第一个元素。
			 << "姓名： " << arr[i].name
			 << "年龄： " << arr[i].age 
			 << "性别： " << arr[i].sex << endl;
	}

	//3.对数组进行排序，按照年龄
	bubbleSort(arr, len); //排序

	printHeros(arr, len); //打印

	//cout << "hello world" << endl;
	system("pause");
	return 0;
}