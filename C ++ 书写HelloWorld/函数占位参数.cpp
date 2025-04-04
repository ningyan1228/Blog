#include <iostream>
using namespace std;
#include<string>

/*
C++中函数的形参列表里可以有占位参数，用来做占位，
调用函数时必须填补该位置
语法：返回值类型 函数名 (数据类型){}
*/

//占位参数
void func(int a,int)  //第二个int属于占位参数，
//占位参数也可以有默认参数 void func(int a,int a=10) 
{
	cout << "这是一个占位学习" << endl;
}

int main203()
{
	func(10,10); //第二个实参必须有

	

	system("pause");
	return 0;
}