#include <iostream>
using namespace std;

int main147()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;
	for (int i = 0;i <10;i++)
	{ 
		cout << *p << endl;
	p++;
	
	}
	//cout <<* p << endl;
	system("pause");
	return 0;
}