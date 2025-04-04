#include <iostream>
using namespace std;
#include<string>

//三种权限
//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问
//私有权限  private    类内可以访问  类外不可以访问
//保护权限 父亲的儿子就能用 儿子可以访问
// 私有权限 儿子不可以访问父亲的私有内容

class Person1
{
public:
	//公共权限
	string m_Name;   // 姓名
protected:
	//保护权限
	string m_Car;  //汽车 儿子可以使用
private:
	//私有权限
	int m_Password; //银行卡密码 儿子不能知道
public:   
	void func()  //类内都可以访问
	{
		m_Name = "梅西";
		m_Car = "拖拉机";
		m_Password = 123456;
	}
};

//上面是类内 main函数里面是类外
int main3()
{	
	//实例化具体对象
	Person1 p1;
	p1.m_Name = "李四";
	//p1.m_Car = "奔驰";  // 保护权限的内容,在类外访问不到
	//p1.m_Password=123; //私有权限内容，在类外访问不到

	system("pause");
	return 0;
}