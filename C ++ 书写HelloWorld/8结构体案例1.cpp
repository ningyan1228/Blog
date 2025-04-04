#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Student {
    string sName;
    int score;
};

struct Teacher {
    string tName;
    Student sArray[5]; // C++中可省略struct
};
//操作结构体数组时，必须通过索引明确指定要修改的元素位置。
//通过正确使用数组索引 [i] 和 [j]，即可解决所有数据重复的问题
void allocateSpace(Teacher* tArray, int len) {
	//tArray指向的是main中tArray[3]的首地址
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++) {
        // 修正1：使用tArray[i]访问每个老师
        tArray[i].tName = "Teacher_" + string(1, nameSeed[i]);//索引
		//tArray[i].sArray[j].sName 不是值传递，而是通过指针直接修改原数据。原因在于：
//tArray 是指针：它指向数组的首地址,数组索引本质是指针运算：
        for (int j = 0; j < 5; j++) {
            // 修正2：使用sArray[j]访问每个学生
            tArray[i].sArray[j].sName = "Student_" + string(1, nameSeed[j]);
			/*
			tArray：指向 main 中 tArray[3] 的首地址
			tArray[i]：通过指针运算找到第 i 个老师
			sArray[j]：直接操作该老师的学生数组的第 j 个元素
			所有操作都在原数组的内存空间中进行，没有值拷贝。
			*/
            // 修正3：为每个学生生成独立随机数
            tArray[i].sArray[j].score = rand() % 61 + 40;
        }
    }
}

void printInfo(Teacher* tArray, int len) {
    for (int i = 0; i < len; i++) {
        cout << "老师姓名：" << tArray[i].tName << endl;
        for (int j = 0; j < 5; j++) {
            cout << "\t学生姓名：" << tArray[i].sArray[j].sName
                << " 分数：" << tArray[i].sArray[j].score << endl;
        }
    }
}

int main163() {
     
	srand((unsigned int)time(NULL));
	//用于初始化随机数生成器，确保程序每次运行时生成的随机数序列不同。
	//解决什么问题：避免每次程序运行时产生的随机数序列相同

    Teacher tArray[3];
    int len = sizeof(tArray) / sizeof(tArray[0]);

    allocateSpace(tArray, len);
    printInfo(tArray, len);

    system("pause");
    return 0;
}
/*
tArray->tName 和 tArray[i].tName 都是地址传递，但操作方式不同
tArray-> 只能操作第一个元素，而 tArray[i] 可以操作任意元素
在循环中必须用 tArray[i] 或 移动指针 来访问不同元素

两种写法的对比分析:
场景设定：
Teacher teachers[3]; // 包含3个老师
Teacher* tArray = teachers; // 指针指向数组首地址

写法一：直接使用指针（错误）❌
for (int i=0; i<3; i++) {
	tArray->tName = "Teacher"; // 始终操作第一个老师
	tArray->sArray[0].score = 90; // 始终操作第一个老师的学生
	// 没有移动指针！
}
结果：所有老师的数据都被覆盖到第一个元素。

写法2：使用索引（正确）
for (int i=0; i<3; i++) {
	tArray[i].tName = "Teacher"; // 操作第i个老师
	tArray[i].sArray[0].score = 90; // 操作第i个老师的学生
}
结果：每个老师独立赋值。
感知：
误解1：认为 tArray[i] 是值传递
真相：tArray[i] 本质是 *(tArray+i)，仍然通过指针直接操作原数据
误解2：认为 -> 是唯一的地址传递方式
真相：-> 和 [] 都是地址传递的不同语法形式

最终结论
在操作数组时：

优先使用索引 tArray[i]：更直观、更安全
谨慎直接操作指针 tArray->：需要手动移动指针，容易出错
两种方式本质相同：都是直接操作原数据（地址传递）
你的代码需要改用索引 tArray[i] 才能正确为每个老师和学生赋值。
*/


/*

#include <iostream>
using namespace std;
#include<string>
#include<ctime>
struct Student {
	string sName;
	int score;
};

struct Teacher {
	string tName;
	struct Student sArray[5];

};
//地址传递
void allocateSpace(Teacher* tArray, int len) {

	string nameSeed = "ABCDE";
	for (int i = 0;i < len;i++)
	{
		//tArray[i].tName= "Teacher_" + string(1, nameSeed[i]);
		tArray->tName = "Teacher_";
		//使用 tArray->tName 会导致所有老师同名，始终操作第一个老师

		tArray->tName += nameSeed;//所有老师名字相同
		for (int j = 0;j < 5;j++)
		{
			//tArray->sArray->sName = "Student_";
			//tArray->sArray->sName += nameSeed;

			tArray[i].sArray[j].sName = "Student_" + string(1, nameSeed[j]);
			int random = rand() % 61 + 40;
			tArray->sArray->score = random;
		}

	}
}


void printInfo(Teacher* tArray, int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << "老师姓名：" << tArray->tName << endl;
		for (int j = 0;j < 5;j++)
		{
			cout << "\t学生姓名：" << tArray->sArray->sName
				<< " 考试分数：" << tArray->sArray->score << endl;
				//而 tArray->sArray->score 会导致所有学生分数相同
		}
	}
}

int main()
{

	srand((unsigned int)time(NULL));

	Teacher tArray[3];
	//Student sArray[5];
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, len); // &tArray[0]等价于tArray
	printInfo(tArray, len);
	/*数组名即指针：tArray 自动转换为 Teacher*
	不要对数组名取地址：& tArray 得到的是完全不同的类型
	当处理非数组的单个变量时，如果需要传递地址（指针），必须使用 &
	
system("pause");
return 0;
}
*/