#include <iostream>
using namespace std;

int main141()
{
	int score[3][3] =
	{
		{100,100,100},
		{95,50,100},
		{60,70,80}

	};
	string name[3] = { "张三","李四","王五" };

	for (int i = 0;i < 3;i++)
	{
		int sum = 0;
		for (int j = 0;j < 3;j++)
		{
			sum = sum + score[i][j];
			cout << score[i][j] << " ";
		}
		cout << endl;
		cout << sum << endl;
	}
	
	

	system("pause");
	return 0;
}