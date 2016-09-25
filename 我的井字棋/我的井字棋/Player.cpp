#include "Player.h"
#include "Board.h"




int PlayerComputer::getBestMove(Board &myBoard) {
	int bestMove = 1, value = 0;
	findCompMove(myBoard, bestMove, value);
	return bestMove;
}

void PlayerComputer::findCompMove(Board &myBoard, int &bestMove, int &value)
{
	if (myBoard.isFull()) {
		value = Draw;//1
	}
	else if (myBoard.compCanWinImmediately(bestMove)) {
		value = CompWin;//2
	}
	else {
		value = 0;//0
		for (int i = 1; i < 10 ; ++i) {
			if (myBoard.isEmpty(i)) {
				myBoard.place(i,'X');

				int temp = -1, response = -1;  
				findHumanMove(myBoard, temp, response);

				myBoard.unplace(i);

				if (response > value) {
					value = response;
					bestMove = i;
				}
			}
		}
	}
}

void PlayerComputer::findHumanMove(Board &myBoard, int &bestMove, int &value)
{
	if (myBoard.isFull()) {
		value = Draw;//1
	}
	else if (myBoard.humanCanWinImmediately(bestMove)) {
		value = CompLoss;//0
	}
	else {
		value = 2;//2
		for (int i = 1; i < 10 ; ++i) {
			if (myBoard.isEmpty(i)) {
				myBoard.place(i, 'O');

				int temp = -1, response = -1;  
				findCompMove(myBoard, temp, response);

				myBoard.unplace(i);

				if (response < value) {
					value = response;
					bestMove = i;
				}
			}
		}
	}
}