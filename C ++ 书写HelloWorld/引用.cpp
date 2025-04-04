#include <iostream>
using namespace std;
#include<string>



int main170()
{
	// 引用必须先初始化才能引用
	int a = 10;// 初始化
	int& b = a;//引用 b一旦初始化a 就不可以更改了
	//是a的别名就不能是其他的别名了；
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;

	b = 100;


	cout << "a:" << a << endl;
	cout << "b:" << b << endl;


	system("pause");
	return 0;
}