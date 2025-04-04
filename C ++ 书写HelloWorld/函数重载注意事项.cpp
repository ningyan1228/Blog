#include <iostream>
using namespace std;
#include<string>

/*
#### 函数重载注意事项
* 引用作为重载条件
* 函数重载碰到函数默认参数
*/
//1、* 引用作为重载条件

void func(int & a)  //可读可写 int &a=10,传10不合法
{
	cout << "func (int &a) 调用 " << endl;
}

void func(const int & a)  //类型不同  const只能读不能写
// const int &a=10 合法 func（10）
{
	cout << "func (const int &a) 调用 " << endl;
}

//函数重载碰到函数默认参数
void func2(int a,int b=10) {

	cout << "func2(int a，int b)的调用" << endl;

}

void func2(int a) {

	cout << "func2(int a)的调用" << endl;

}

int main1910()
{
	//int a = 10;
	//func(a); //调用无const

	//func(10);//调用有const
	

	//func2(10);  //只传了一个值，func2俩函数都能调用，
	//此时编译器蒙了不知道选谁了，出现了二义性，尽量避免
	func2(10, 20);
	system("pause");
	return 0;
}