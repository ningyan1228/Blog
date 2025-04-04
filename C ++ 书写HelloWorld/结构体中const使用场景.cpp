#include <iostream>
using namespace std;
#include<string>

struct Player {
	int PlayerId;
	int age;
	string name;
	int height;

};

void Playerlist(const Player* play)
{

	// play->age = 28;
	cout << "球员号码：" << play->PlayerId
		<< "球员年龄：" << play->age
		<< "球员姓名：" << play->name
		<< "球员身高：" << play->height << endl;
}


int main160()
{
	struct Player play = { 10,35,"messi",169 };
	Playerlist(&play);
	cout << "球员号码：" << play.PlayerId
		<< "球员年龄：" << play.age
		<< "球员姓名：" << play.name
		<< "球员身高：" << play.height << endl;
	
	system("pause");
	return 0;
}