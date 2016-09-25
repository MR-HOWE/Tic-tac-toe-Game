#pragma once //只要在头文件的最开始加入这条杂注，就能够保证头文件只被编译一次。比ifndef新式。
#include<iostream>

#include "Board.h"
#include "Player.h"

using namespace std;

class Game
{
private:
	Board myBoard;
	//Player* playerA;
	//Player* playerB;
public:
	Game();

	void startPVP();
	void startPVC();
	void startCVC();

	// Judge if game is over
	// Return true if the game is over, and if @param draw
	// equals true, the @param win is useless.
	bool gameIsOver(bool &draw, int &win) const;

	// If game is over, handle it
	// Return true means game is over.
	bool handleGameOver() const;
};