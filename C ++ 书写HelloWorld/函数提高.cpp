#include <iostream>
using namespace std;
#include<string>

/*
在C++中，函数的形参列表中的形参是可以有默认值的。

语法：返回值类型  函数名 （参数= 默认值）{}`
*/
//函数的默认参数
//返回值类型 函数名 （形参=默认值）
//int func(int a, int b=20, int c=30)  //默认值
//如果我们自己传入了数据，
// 就用自己的数据，如果没有，就用默认值
//{

//	return a + b + c;
//}
//注意事项：
//1、如果某个位置已经有了默认参数，b有了 后面的都得有默认参数w
// 那么从这个位置往后，从左到右都必须有默认值
int func2(int a=1, int b = 10, int c=20,int d = 20)
{
	return a + b +c+ d;

}

//2、如果函数声明有默认参数，函数定义就不能有默认参数
// 声明和定义只能有一个有默认参数
//int func2(int a=10, int b=10); //函数声明
//int func2(int a, int b=20) //函数定义就不能有默认参数
//{ //
//	return a + b;
//}
 

int main200()
{
	//cout << func(10,30) << endl;
	
	cout << func2(1,2,3,4) << endl;
	system("pause");
	return 0;
}
