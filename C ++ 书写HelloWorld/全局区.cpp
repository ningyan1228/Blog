#include <iostream>
using namespace std;
#include<string>




int main1666()
{

	//创建局部变量
	int a = 10;
	int b = 20;
	cout << "局部变量a的地址为："<<(int)&a << endl;
	cout << "局部变量b的地址为：" << (int)&b << endl;

	static int s_a = 10;
	 

	system("pause");
	return 0;
}