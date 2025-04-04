#include <iostream>
using namespace std;
#include<string>
// 常量引用主要用来修饰形参，防止误操作
// 在函数形参列表中，可以加const修饰实参，防止形参改变实参

//打印数据的函数
void showValue(const int & val)
{

	// val = 1000;//防止形参更改实参
	//形参位置加入const
	cout << "val= " << val;


}


int main181()
{

	//常量引用
	// 使用场景：用来修饰形参，防止误操作！
	//int a = 10;

	//int & ref = a; //合法
	// int& ref = 10; // 引用必须引一块合法的内存空间
	//const int & ref = 10;
	// 加上 const之后可以，先创建临时变量是10
	//编译器将代码修改 int temp=10;const int & ref=temp;
	// ref = 20;  加入const之后变为只读，不可以修改
	
	
	int a = 100;
	showValue(a);
	cout << a << endl;

	system("pause");
	return 0;
}