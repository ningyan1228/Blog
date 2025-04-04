#include<iostream>
using namespace std;

int main26()
{

	int score = 0;
	cout << "请输入你的分数：" << endl;

	cin >> score;

	if (score >= 601)
	{
		cout << "你考上了一本大学！" << endl;
	}
	else if (score <= 500&&score>=400)
	{
		cout << "你考上了二本大学！" << endl;
	}
	else
	{
		cout << "你没考上大学" << endl;
	}
	system("pause");
	return 0;
}