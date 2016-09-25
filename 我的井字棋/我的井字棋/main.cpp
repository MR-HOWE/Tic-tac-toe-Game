/*
	Author: 黄志浩
	Date: 2016-05-07 21:15
	Description: 井字棋游戏，有双人对战，人机对战，电脑对战三种模式。
	AI部分采用极大极小搜索算法，可保证电脑不败。
*/


#include<iostream>


#include "Game.h"

using namespace std;
int main()
{
	Game myGame;
	int choice;
	again:
	cout << "Please input your choice. 1.双人对战 2.人机对战 3.电脑对战 " << endl;
	cin >> choice;
	while (choice > 3 || choice <1)
	{
		cout << "Your choice is illegal.Please input again." << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
		myGame.startPVP();
		break;
	case 2:
		myGame.startPVC();
		break;
	case 3:
		myGame.startCVC();
		break;
	}
	cout << "Do you want to play again ? Input 1 to play again, 2 to exit the procedure." << endl;
	cin >> choice;
	if(choice == 1 ){
		goto again;
	}

}