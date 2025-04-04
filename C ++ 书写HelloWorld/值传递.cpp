#include <iostream>
using namespace std;

void swap6(int num1, int num2)
{
	cout << num1 << num2 << endl;
	int temp = num1;
	num1 = num2;
	num2 = temp;


	cout << num1 << num2 << endl;


}
int main143()
{

	int a = 10;
	int b = 20;
	swap(a, b);
	cout << a << b << endl;

	system("pause");
	return 0;
}