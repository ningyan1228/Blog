#include <iostream>
using namespace std;

void bubbleSort(int* arr, int len)
{
	for (int i = 0;i < len - 1;i++)
	{
		for (int j = 0;j < len - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j ] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}
}
void printArray(int arr[], int len)
{
	for (int i = 0;i < len;i++)
	{
		cout << arr[i] << endl;
	}
}

int main148()
{
	int arr[10] = { 4,3,5,6,9,7,8,2,9,10 };
	int len = sizeof(arr) / sizeof(int);

	bubbleSort(arr, len);
	printArray(arr, len);




	


	system("pause");
	return 0;
}