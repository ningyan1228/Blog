#include <iostream>
using namespace std;
#include<string>

// 引用做函数的返回值
//1、不要返回局部变量的引用
int & test01()
/*
int& 表示函数的返回值类型是一个整型变量的引用
（即返回的是一个int类型变量的别名）
注意：&符号在这里是引用声明符，不是取地址符
test01 函数名
()空参数列表，表示这个函数不需要参数

函数声明	返回值类型	特点
int test01()	整型值	返回值的拷贝（新内存）
int* test01()	整型指针	返回一个指针（需要管理内存）
int& test01()	整型引用	返回变量的别名（直接操作原数据）

*/
{
	
	int a = 10;  // 局部变量a，分配在栈区  
	//生命周期仅限于函数执行期间
	//栈区分配变量a，值为10,函数调用时，a在栈上创建
	return a;	// 返回局部变量的引用（危险！）！！！
	//返回的引用本质是a的地址（如0x1000）
 }  // 函数结束，a被销毁
//栈内存释放，地址0x1000不再属于程序控制
//永远不要返回局部变量的引用（栈内存会被回收）
// 
// 栈内存特性：函数内的局部变量在函数执行期间分配在栈内存中，
// 函数结束时自动释放。
// 
// 引用本质：引用是变量的别名，底层通过指针实现。
// 当局部变量被销毁后，引用指向的内存已无效。
// 引用本质是“有地址的别名”，必须确保其指向的内存有效。
// 
//2、函数的调用可以作为左值
int& test02()  //test02() 返回的是静态变量a的引用
{

	static int a = 10;  // a就不会被释放
	//静态变量，存在全局区（程序结束才释放）
	//静态变量，存放在全局区，全局区上的数据在程序结束后系统释放
	return a;

}


int main177()
{
	int& ref = test01(); //ref指向已销毁的内存（悬空引用）
	//test01（）：调用函数 test01()，该函数返回一个 int 类型的引用
	// int& 声明一个引用变量 ref，类型是 int 的引用
	// =将 ref 绑定到 test01() 返回的引用上
	// test01() 返回的是函数内部局部变量 a 的引用
	// 但 a 是局部变量，函数结束后会被销毁（内存被回收）
	//  ref指向已释放的内存（悬空引用）
	// ref 成为指向已销毁内存的引用（称为悬空引用或野引用）
	// 后续通过 ref 访问数据是未定义行为（可能崩溃、输出垃圾值或看似正常）
	cout << "ref=" << ref << endl;
	// // 第一次输出（可能正确）
	cout << "ref=" << ref << endl;
	// 第二次输出（可能错误）因为a的内存已经释放
	// 
	// test01流程：
	//调用test01() → 创建a=10 → 
	// 返回a的地址 → 函数结束a销毁 → ref指向无效内存

	/*
	
	类比理解
	想象你租了一间房子（局部变量 a），退租后（函数结束），
	房东把房子转租给了别人。
	但你仍然保留着旧钥匙（引用 ref），
	试图用旧钥匙开门（访问 ref）——结果可能是：

	门锁没换，还能进（输出原值，但这是巧合）
	新租客换了锁（内存被覆盖，输出乱码）
	房子被拆了（程序崩溃）
	*/


	int& ref2 = test02();
	cout << "ref2=" << ref2 << endl;
	cout << "ref2=" << ref2 << endl;
	test02() = 1000;  //直接修改全局区的a（相当于a=1000）
	//如果函数的返回值是引用，这个函数调用可以作为左值
	cout << "ref2=" << ref2 << endl; //ref2本身就是a的别名
	cout << "ref2=" << ref2 << endl;


	//test02流程：
	//调用test02() → 静态a = 10 → 返回a的地址 →
	// 通过引用修改a → 所有访问都有效
	system("pause");
	return 0;
}