#include <iostream>
using namespace std;
//函数定义
int add(int num1,int num2)   // 形参
{
	int sum = num1 + num2;
	return sum;
}


int main142()
{
	int a = 10;
	int b = 20;
	int sum = add(a, b);
	cout << sum << endl;

	system("pause");
	return 0;
}