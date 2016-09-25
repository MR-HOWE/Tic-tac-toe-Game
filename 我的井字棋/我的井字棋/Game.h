#pragma once //ֻҪ��ͷ�ļ����ʼ����������ע�����ܹ���֤ͷ�ļ�ֻ������һ�Ρ���ifndef��ʽ��
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