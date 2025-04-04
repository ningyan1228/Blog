#include<iostream>
using namespace std;

int main14()
{

	int score = 0;
	cout << "请输入考试的分数：" << endl;
	cin >> score;

	cout << "你输入的分数为：" << score << endl;

	if (score > 500)
	{
		cout << "你考上了二本大学！" << endl;

	}
	else
	{
		cout << "你没有考上大学！" << endl;
	}
	system("pause");
	return 0;
}