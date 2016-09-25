#include "Board.h"


Board::Board()
{
	check = 0;
	matrix[10] = '\0';
	for(int i = 0;i<10;i++)
	{
		matrix[i] = ' ';
	}
	
	//memset(matrix, 0, 10 * sizeof(int));
}
void Board::printinfo()
{
	cout << "The first player is represented by O, the second by X." << endl;
	cout << "Enter the coordinates for Rows and Columns" << endl;
	cout << "Strike enter when Done." << endl;
}

void Board::cmp(int num)
{
	int a, b, c;
	a = num / 100;
	b = num / 10 % 10;
	c = num % 10;
	if (matrix[a] == matrix[b] && matrix[b] == matrix[c])
	{
		if (matrix[a] == 'X' || matrix[a] == 'O') {
			check++;
		}
	}
}

bool Board::scan()
{
	cmp(123);
	cmp(456);
	cmp(789);
	cmp(147);
	cmp(258);
	cmp(369);
	cmp(159);
	cmp(357);
	if (check != 0) {
		return true;//True means someone wins.
	}
	else return false;
}

void Board::place(int pos, char turn)
{
	if (matrix[pos] != ' ') {
		cout << "Wrong!The place has already been occupied!" << endl;
		return;
	}
	if (turn == 'O') {
		matrix[pos] = 'O';
	}
	if (turn == 'X') {
		matrix[pos] = 'X';
	}
}

void Board::unplace(int pos)
{
	matrix[pos] = ' ';
}
// char Board::change(int a)
// {
// 	if (a == 0) {
// 		return ' ';
// 	}
// 	if (a == 1) {
// 		return 'O';
// 	}
// 	if (a == 2) {
// 		return 'X';
// 	}
// 	return ' ';
// }
void Board::print()
{
	cout << endl;
	cout << "  1   2   3 " << endl;
	cout << "1 " << matrix[1] << " | " << matrix[2] << " | " << matrix[3] << endl;
	cout << " ---+---+---" << endl;;
	cout << "2 " << matrix[4] << " | " << matrix[5] << " | " << matrix[6] << endl;
	cout << " ---+---+---" << endl;
	cout << "3 " << matrix[7] << " | " << matrix[8] << " | " << matrix[9] << endl;
	cout << endl;
	cout << endl;
}

void Board::clear()
{
	for(int i = 1;i < 10;i++)
	{
		matrix[i] = ' ';
	}
}

void Board::isLegalPlacePosition(int& x, int& y)
{
	while (x > 3 || x < 1 || y > 3 || y < 1 || (matrix[3 * (x - 1) + y] == 'O'
		|| matrix[3 * (x - 1) + y] == 'X'))
	{
		cout << "This coordinate is not allowed, try again" << endl;
		cout << "Row: ";
		cin >> x;
		cout << "Col: ";
		cin >> y;
	}
}

int Board::convertInputToPosition(int row ,int col)
{
	return 3 * (row - 1) + col;
}

bool Board::isFull() const {
	for (int i = 1; i < 10; ++i) {
		if (matrix[i] == BLANK_CHAR) {
			return false;
		}
	}
	return true;
}

bool Board::isEmpty(const int pos) const {
	return matrix[pos] == BLANK_CHAR;
}

bool Board::compCanWinImmediately(int &bestMove) {
	for (int i = 1; i < 10; ++i) {
		if (isEmpty(i)) {
			matrix[i] = COMP_CHAR;
			bool canWin = compWin();
			matrix[i] = BLANK_CHAR;
			if (canWin) {
				bestMove = i;
				return true;
			}
		}
	}
	return false;
}

bool Board::humanCanWinImmediately(int &bestMove) {
	for (int i = 1; i < 10; ++i) {
		if (isEmpty(i)) {
			matrix[i] = HUMAN_CHAR;
			bool canWin = humanWin();
			matrix[i] = BLANK_CHAR;
			if (canWin) {
				bestMove = i;
				return true;
			}
		}
	}
	return false;
}

bool Board::compWin() const {
	return sbHasWon(COMP_CHAR);
}

bool Board::humanWin() const {
	return sbHasWon(HUMAN_CHAR);
}

bool Board::sbHasWon(const char c) const {
	// Check rows
	for (int i = 1; i <= 7; i += 3)
		if (matrix[i] == c && matrix[i] == matrix[i + 1]
			&& matrix[i] == matrix[i + 2]) return true;

	// Check columns
	for (int i = 1; i <= 3; ++i)
		if (matrix[i] == c && matrix[i] == matrix[i + 3]
			&& matrix[i] == matrix[i + 6]) return true;

	// Check diagonals
	if (matrix[5] == c && matrix[1] == matrix[5]
		&& matrix[1] == matrix[9]) return true;

	if (matrix[5] == c && matrix[3] == matrix[5]
		&& matrix[3] == matrix[7]) return true;

	return false;
}