#pragma once
#include<iostream>
using namespace std;

#define HUMAN_CHAR 'O'
#define COMP_CHAR 'X'
#define BLANK_CHAR ' '


class Board
{
private:
	int check;
	char matrix[11];
public:
	Board();
	void printinfo();
	void cmp(int a);//->for PVP
	bool scan();//scan if someone has won.          ->for PVP
	void place(int pos, char turn);//place the chess onto the board
	void unplace(int pos);
	void print();//print the chess board;
	void clear();
	void isLegalPlacePosition(int& x, int& y);//check whether the coordinates is wrong  
	int convertInputToPosition(int x ,int y);//convert the two-dim-coordinate to one-dim-coordinate

	// Judge whether the chessboard is full
	bool isFull() const;

	// Judge whether the postion on the chessboard is empty
	bool isEmpty(const int pos) const;

	// Judge if the computer can win after placing
	// chess piece at a position, if so, store the position
	bool compCanWinImmediately(int &bestMove);

	// Judge if the human can win after placing
	// chess piece at a position, if so, store the position
	bool humanCanWinImmediately(int &bestMove);

	// Judge if the computer wins the game
	bool compWin() const;

	// Judge if the huamn wins the game
	bool humanWin() const;

	bool sbHasWon(const char c) const;//scan if someone has won.
};