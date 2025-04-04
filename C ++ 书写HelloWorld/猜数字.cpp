#include <iostream>
using namespace std;
#include <ctime>
int main110()

{
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1; //生成随机的1-100的随机数  
	//cout << num << endl;

	int cai = 0;

	while (cai!=num)
	{
		cin >> cai;
		if (cai > num)
		{
			cout << "您猜的大于正确数值,请重新输入：" << endl;

		}
		else if (cai < num)
		{
			cout << "您猜的小于正确数值,请重新输入" << endl;
		}
		else
		{
			cout << "您猜对了！" << endl;
			//break;
		}

	}
	system("pause");
	return 0;
}