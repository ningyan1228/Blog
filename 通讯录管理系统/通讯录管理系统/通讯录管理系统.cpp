#include<iostream>
using namespace std;
#include<string>
#define MAX 1000 // 定义通讯录最大容量为1000

//联系人结构体
struct Person{
	string m_Name;   
	int m_Sex;                        
	int m_Age;
	string m_Phone;
	string m_Addr;

};
// 通讯录结构体
struct Addressbooks
{
 // 通讯录中保存的联系人数组
	struct Person personArray[MAX];//结构体里面嵌套结构体
// 通讯录中当前记录的联系人个数
	int m_Size;   //// 当前联系人数量（不是数组）

};

// 添加联系人函数  
void addPerson(Addressbooks* abs) //结构体做函数参数 地址传递
{
	if (abs->m_Size == MAX)  // 检查通讯录是否已满
	{
		cout << "通讯录已满，无法添加！" << endl;
	}
	else {
		// 添加具体的联系人

//姓名
string name;
cout << "请输入姓名： " << endl;
cin >> name;
abs->personArray[abs->m_Size].m_Name = name;//存储姓名
/*
abs->m_Size  []代表数组

添加新联系人：新联系人
被存入 personArray[n]（因为数组索引从0开始）

表示当前通讯录中已存储的联系人数量
初始值为0（主函数中初始化abs.m_Size = 0）

personArray[abs->m_Size]

当通讯录为空时：personArray[0]（第一个位置）
添加一个联系人后：abs->m_Size会自增为1，
下次添加时使用personArray[1]
赋值操作:
将用户输入的name字符串存入
新联系人的m_namer字段
类比现实场景
想象你有一个空笔记本（通讯录）：

第一页（索引0）准备写第一个联系人
写完第一个联系人后，在封面记录"已用1页"（m_Size=1）
下次添加时，直接翻到第1页（索引1）写第二个联系人

*/

//性别
cout << "请输入性别：  " << endl;
cout << "1---男" << endl;
cout << "2---女" << endl;
int sex = 0;

while (true)
{
	cin >> sex;
	if (sex == 1 || sex == 2)   // 性别输入 带验证
	{
		abs->personArray[abs->m_Size].m_Sex = sex;
		break;
	}
	else {
		cout << "输入有误，请重新输入" << endl;
	}
}
// 年龄
cout << "请输入年龄： " << endl;
int age = 0;
cin >> age;
abs->personArray[abs->m_Size].m_Age = age;

// 电话
cout << "请输入联系电话：" << endl;
string phone;
cin >> phone;
abs->personArray[abs->m_Size].m_Phone = phone;

// 住址
cout << "请输入住址： " << endl;
string address;
cin >> address;
abs->personArray[abs->m_Size].m_Addr = address;

//更新通讯录人数
abs->m_Size++;         // 核心：递增计数器
/*
为什么用abs->m_Size作为索引？
m_Size 表示当前联系人数量
数组索引从0开始，因此：
当有0个联系人时，第一个位置是0
当有n个联系人时，新位置是n
添加完成后执行abs->m_Size++，为下次添加做准备

确保了每次添加联系人后，
通讯录的计数器指向下一个可用位置
这是实现连续添加功能的核心机制之一
*/
cout << "添加成功！" << endl;

system("pause"); //按任意键继续  暂停按任意键继续
system("cls"); //清屏操作 

	}
}

// 显示所有联系人
void showPerson(Addressbooks* abs) //地址传递
{
	//判断通讯录人数是否为0，如果为0，提示记录为空
	//如果不为0，显示所有联系人的信息
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空！" << endl;
	}
	else {
		for (int i = 0;i < abs->m_Size;i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话号码： " << abs->personArray[i].m_Phone << "\t";
			cout << "地址： " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");  //按任意键继续  暂停 按任意键继续
	system("cls"); // 清屏操作

}

  
// 检测联系人是否存在，如果存在，返回联系人所在数组的具体位置，不存在返回-1
// 参数1 通讯录 参数2 对比姓名
int isExist(Addressbooks* abs, string name)
// 输入：通讯录指针 abs 和要查找的姓名 name
/*
int 返回值：用于精确定位数组中的联系人位置
为什么用 int 类型？
(1) 需要返回具体位置
删除操作需要知道联系人在数组中的具体位置（索引）
如果只是返回 bool（存在与否），无法直接定位到要删除的元素
(2) 错误处理
用 -1 表示“未找到”是编程中的常见约定
通过判断返回值是否为 -1，可以明确处理两种场景：
if (isExist(...) == -1) {
	// 未找到，提示错误
} else {
	// 找到，执行删除
}
*/
{

	for (int i = 0;i < abs->m_Size; i++)
	{		
		// 找到了用户输入的姓名
		if(abs->personArray[i].m_Name == name)
		{
			return i;  //找到此人，返回这个人在数组的下标编号
		}
	}
	return -1;// return 放在内部如果第一个检测不对就会直接返回-1
	//，而不继续向下检查了
	// 因为isExist函数中for循环可以取到0，所以否定的返回值只能取-1.
	/*
	返回值：
		int 类型：找到联系人时返回其在数组中的索引位置
		（0 到 m_Size-1）
		-1：未找到联系人
	*/
}


//删除联系人
void deletePerson(Addressbooks* abs) {

	cout << "请输入您要删除的联系人 " << endl;
	string name;
	cin >> name;

	// ret ==-1 未找到
	//ret !=-1 找到了
	int ret = isExist(abs, name);  //ret 就是下标编号
	/*
	isExist 函数的参数不需要加 * 的原因如下：
	 参数类型分析
		deletePerson 函数的参数：
		void deletePerson(Addressbooks* abs) 
		{ // abs 是 Addressbooks 的指针
		  // ...
	int ret = isExist(abs, name); // 直接传递指针
}
		abs 本身就是指针：
		在 deletePerson 函数中，
		abs 已经是 Addressbooks* 类型（指针），
		直接传递即可满足 isExist 的参数要求。

		加 * 会改变类型：
		如果写成 isExist(*abs, name)，
		则 *abs 是 Addressbooks 类型（结构体实例），
		与函数参数类型 Addressbooks* 不匹配，会导致编译错误。
		指针操作原则：需要指针时传指针，需要实例时传实例
	*/

	if (ret != -1) {

		//查找到了此人，要进行删除
		for (int i = ret;i < abs->m_Size;i++) {
			abs->personArray[i] = abs->personArray[i + 1];

		}
		abs->m_Size--;
		cout << "删除成功！" << endl;
	}
	else {
		cout << "查无此人！" << endl;

	}
	system("pause");
	system("cls");


}

//查找指定联系人 显示属于显示所有联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人： " << endl;
	string name;
	cin >> name;
	// 判断指定的联系人是否在通讯录中
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名" << abs->personArray[ret].m_Name << "\t";
		// ret是联系人数组的下标
		cout << "性别" << abs->personArray[ret].m_Sex << "\t";
		cout << "姓名" << abs->personArray[ret].m_Age << "\t";
		cout << "姓名" << abs->personArray[ret].m_Phone << "\t";
		cout << "姓名" << abs->personArray[ret].m_Addr << endl;
	}
	else //未找到联系人
	{
		cout << "查无此人！" << endl;
	}
	
	system("pause");
	system("cls");
	}

// 修改联系人  //指针来接受传进来的通讯录地址
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			
			cout << "输入有误，请重新输入" << endl;
		}
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "请输入家庭地址： " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}


//清空联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0; //将当前记录联系人数量置为0；
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");

}

// 菜单界面 函数

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

// 退出功能 退出通讯录系统



int main()

{

	//创建通讯录结构体变量 通讯录结构体实例
	struct Addressbooks abs;
	//初始化通讯录中人数为0
	abs.m_Size = 0;
	
	int select = 0; //创建用户选择输入的变量
	
	while(true){
	// 菜单调用
	showMenu();

	cin >> select;

	switch (select)  // 根据选择执行操作
	{
	case 1:// 添加

		addPerson(&abs); // 利用地址传递，可以修饰实参
		break;
	case 2:// 显示
		showPerson(&abs);   // 调用

		break;
	case 3: //删除
		/* {
		cout << "请输入删除的联系人姓名： " << endl;
		string name;
		cin >> name;
		if (isExist(&abs, name) == -1)
		{
			cout << "查无此人！" << endl;
		}
		else {
			cout << "找到此人！" << endl;
		}
		}*/
		deletePerson(&abs);

		break;
	case 4: //查找
		findPerson(&abs);

		break;
	case 5: //修改

		modifyPerson(&abs);
		break;
	case 6: //清空
		cleanPerson(&abs);

		break;
	case 0: //退出
		
		cout << "欢迎下次使用！" << endl;
		system("pause");
		return 0;  // 结束程序
		break;
	default:   // 无效输入
		break;
	}

	}

	
}