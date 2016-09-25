#pragma once

#include<iostream>

#include "Board.h"
using namespace std;

class Player
{
private:
	string _name;
public:
	Player(){_name = "noname";}
	Player(string name){_name = name;}
};

class PlayerHuman : public Player
{
private:
public:
	PlayerHuman(): Player() {}
	PlayerHuman(string name): Player(name) {}
};

class PlayerComputer : public Player
{
public:
	PlayerComputer(): Player() {}
	PlayerComputer(string name): Player(name) {}

	// Get computer's best movement
	static int getBestMove(Board &myBoard);
private:
	string _name;
	// Find computer's best movement
	// using minimax algorithm 
	static void findCompMove(Board &myBoard, int &bestMove,
		int &value);

	// Find human's best movement
	// using minimax algorithm 

	static void findHumanMove(Board &myBoard, int &bestMove,
		int &value);

	//values in the above two methods
	static const int CompWin = 2;
	static const int Draw = 1;
	static const int CompLoss = 0;
};