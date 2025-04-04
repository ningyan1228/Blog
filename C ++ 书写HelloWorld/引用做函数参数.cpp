#include <iostream>
using namespace std;
#include<string>

// 交换函数
//  1、值传递
void mySwap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	//cout << a << b << endl;
}

// 2、地址传递

void mySwap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}

// 3、引用传递
void mySwap03(int &a, int &b)  //m、n的别名
/*
直接告诉函数变量的“地址”（不用复制整个变量），
函数直接操作原数据。
*/

{

	int temp = a;
	a = b;
	b = temp;
}

//函数传参时，可以利用引用的技术让形参修饰实参

int main171()
{
	int m = 10;
	int n = 20;
	//mySwap01(m, n);  // 值传递，形参不会修饰实参
	//	cout << m << n << endl;
	//mySwap02(&m, &n);  //地址传递，形参会修饰实参
	//cout << m << n << endl;
	
	mySwap03(m, n);  //引用传递 形参也会修饰实参
	//引用形参也会更改实参的值 
	cout << m << n << endl;
	system("pause");
	return 0;
}