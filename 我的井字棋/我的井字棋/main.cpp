/*
	Author: ��־��
	Date: 2016-05-07 21:15
	Description: ��������Ϸ����˫�˶�ս���˻���ս�����Զ�ս����ģʽ��
	AI���ֲ��ü���С�����㷨���ɱ�֤���Բ��ܡ�
*/


#include<iostream>


#include "Game.h"

using namespace std;
int main()
{
	Game myGame;
	int choice;
	again:
	cout << "Please input your choice. 1.˫�˶�ս 2.�˻���ս 3.���Զ�ս " << endl;
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