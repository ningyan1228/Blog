/*
在C++中 struct和class唯一的区别就在于
**默认的访问权限不同**
区别：
* struct 默认权限为公共public
* class   默认权限为私有private
*/
#include <iostream>
using namespace std;
#include<string>

class C1 {

	int m_A;  //默认权限是私有权限
};

struct C2 {

	int m_A;// 默认权限是公共
};


int main4()
{

	C1 c1;
	//c1.m_A = 100;  //默认权限是私有权限，类外不可访问

	C2 c2;
	c2.m_A = 100;  //struct默认权限是公共权限,可以访问


system("pause");
	return 0;
}