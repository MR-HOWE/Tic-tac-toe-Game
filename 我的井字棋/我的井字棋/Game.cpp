#include<ctime>
#include<cstdlib>
#include "Game.h"

Game::Game()
{

}
void Game::startPVP()
{
	myBoard.printinfo();
	myBoard.print();
	int cnt = 1;
	int row, col;
	int pos = 0;
	while (cnt != 10)
	{
		if (cnt % 2 != 0) {
			cout << "Now it is (O)player1's turn ,please input your choice," << endl;
			cout << "Row: ";
			cin >> row;
			cout << "Col: ";
			cin >> col;
			myBoard.isLegalPlacePosition(row, col);
			pos = myBoard.convertInputToPosition(row,col);
			myBoard.place(pos, 'O');
		}
		else {
			cout << "Now it is (X)player2's turn ,please input your choice," << endl;
			cout << "Row: ";
			cin >> row;
			cout << "Col: ";
			cin >> col;
			myBoard.isLegalPlacePosition(row, col);
			pos = myBoard.convertInputToPosition(row,col);
			myBoard.place(pos, 'X');
		}
		myBoard.print();
		if (myBoard.scan())
		{
			if (cnt % 2 == 0)
			{
				cout << "The player" << 2 << " win!!!" << endl;
				cout << "Thanks for playing the game~" << endl;
				system("pause");
				exit(1);
			}
			else
				cout << "The player" << 1 << " win!!!" << endl;
			cout << "Thanks for playing the game~" << endl;
			system("pause");
			exit(1);
		}
		cnt++;
	}
	cout << "Game draw!" << endl;
	cout << "Thanks for playing the game~" << endl;
	myBoard.clear();
	system("pause");
}

void Game::startPVC()
{
	int choice;
	cout << "Who will place the first piece?" << endl;
	cout << "0->Human first" << endl;
	cout << "1->Computer first" << endl;
	cin >> choice;

	int pos = 0;
	PlayerComputer PlayerComputerA("ComputerA");
	//srand(time(0));
	srand(unsigned(time(0)));
	if (choice == 1) {  // Choose computer to be the first
		//pos = PlayerComputerA.getBestMove(myBoard);
		pos = rand()%9 + 1; //generate num 1~9
		cout << "The computer's choice:" << endl;
		myBoard.place(pos, 'X');
	}
	int col = 0, row = 0;
	while (1) {
		myBoard.print();
		if (handleGameOver()) break;

		cout << "Now it is your turn ,please input your choice," << endl;
		cout << "Row: ";
		cin >> row;
		cout << "Col: ";
		cin >> col;
		myBoard.isLegalPlacePosition(row, col);
		pos = myBoard.convertInputToPosition(row,col);
		myBoard.place(pos,'O');

		myBoard.print();
		if (handleGameOver()) break;

		pos = PlayerComputerA.getBestMove(myBoard);
		cout << "The computer's choice:" << endl;
		myBoard.place(pos, 'X');
	}
	cout << "Thanks for playing the game~" << endl;
	myBoard.clear();
	system("pause");
}

void Game::startCVC()
{
	int pos = 0;
	PlayerComputer PlayerComputerA("ComputerA");
	PlayerComputer PlayerComputerB("ComputerA");
	srand(unsigned(time(0)));
	pos = rand()%9 + 1; //generate num 1~9
	cout << "The computerA's choice:" << endl;
	myBoard.place(pos, 'O');

	while (1) {
		myBoard.print();
		if (handleGameOver()) break;

		pos = PlayerComputerB.getBestMove(myBoard);
		cout << "The computerB's choice:" << endl;
		myBoard.place(pos,'X');

		myBoard.print();
		if (handleGameOver()) break;

		pos = PlayerComputerA.getBestMove(myBoard);
		cout << "The computerA's choice:" << endl;
		myBoard.place(pos, 'O');
	}
	cout << "Thanks for playing the game~" << endl;
	myBoard.clear();
	system("pause");
}


bool Game::gameIsOver(bool &draw, int &win) const {
	if (myBoard.compWin()) {
		win = 1;
		draw = false;
		return true;
	}
	else if (myBoard.humanWin()) {
		win = 0;
		draw = false;
		return true;
	}
	else if (myBoard.isFull()) {
		draw = true;
		return true;
	}
	else {
		return false;
	}
}

bool Game::handleGameOver() const {
	bool draw = false;
	int whoWin = 0; // 0 == human
	if (gameIsOver(draw, whoWin)) {
		if (draw) {
			cout << "Draw!" << endl;
		}
		else {
			if (whoWin == 1) {
				cout << "You lose!" << endl;
			}
			else if (whoWin == 0) {
				cout << "Congratulations! You defeat the computer." << endl;
			}
		}
		return true;
	}
	else {
		return false;
	}
}