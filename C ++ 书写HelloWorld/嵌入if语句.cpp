#include <iostream>
using namespace std;

int main99()
{
	int score = 0;
	cout << "请输入你的成绩：" << endl;
	cin >> score;
	if (score > 600)
	{
		cout << "你考上了一本大学！" <<endl;
		if (score > 700)
		{
			cout << "你考上了北京大学！" << endl;
		}
		else if (score > 650)
		{
			cout << "你考上了清华！" << endl;
		}
		else
		{
			cout << "你考上了山大" << endl;
		}
	}
	else if (score > 500)
	{
		cout << "你考上了二本大学！" << endl;
	}
	else if (score > 400)
	{
		cout << "你考上了三本大学！" << endl;
	}
	else
	{
		cout << "你没考上大学" << endl;
	}

	system("pause");
	return 0;
}