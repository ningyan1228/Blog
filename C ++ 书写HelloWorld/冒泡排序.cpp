#include <iostream>
using namespace std;

int main108() {

	int arr[10] = { 20,99,55,99,600,200,400,66,800 };

	for (int i = 0; i < 10 - 1;i++)
	{
		for (int j = 0;j < 10 - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			
		}

	}

	for (int i = 0;i < 10;i++)
	{

		cout << arr[i] << endl;
	}

	system("pause");

	return 0;
}