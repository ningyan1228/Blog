#include <iostream>
using namespace std;

int main11() {
	char ch = 'a';

	cout << "short 类型所占内存空间为： " << sizeof(short) << endl;

	cout << "int 类型所占内存空间为： " << sizeof(int) << endl;

	cout << "long 类型所占内存空间为： " << sizeof(long) << endl;

	cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;

	cout << ch << endl;
	cout << sizeof('a') << endl;

	cout << (int)ch << endl;

	system("pause");

	return 0;
}