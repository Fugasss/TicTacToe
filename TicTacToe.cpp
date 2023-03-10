#include "TicTacToe.h"

bool TicTacToe::place(int x, int y, CellState state) // state 1 - X, state 2 - O
{
	CellState currentState = gameBoard[x][y];

	if (currentState == CellState::None) {
		gameBoard[x][y] = state;
		movesRemain--;
		return true;
	}

	return false;
}

bool TicTacToe::checkForEnd(CellState* winnerState)
{
	*winnerState = CellState::None;

	for (int s = 1; s <= 2; s++)
	{
		CellState st = static_cast<CellState>(s);

		bool buf = true;
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
				buf = buf && gameBoard[x][y] == st;

			if (buf) {
				*winnerState = st;
				return true;
			}
			buf = true;
		}

		buf = true;
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
				buf = buf && gameBoard[x][y] == st;

			if (buf) {
				*winnerState = st;
				return true;
			}
			buf = true;
		}

		if (gameBoard[0][0] == st && gameBoard[1][1] == st && gameBoard[2][2] == st ||
			gameBoard[2][0] == st && gameBoard[1][1] == st && gameBoard[0][2] == st) {
			*winnerState = st;
			return true;
		}
	}

	if (movesRemain <= 0) {
		*winnerState = CellState::None;
		return true;
	}

	return false;
}

void drawHorizontalLine(int borderSize) {
		for (int i = 0; i < 9 + borderSize * 4; i++)
			cout << "-";
		cout << endl;
}

void drawVerticalLine(int borderSize) {
	for (int i = 0; i < borderSize; i++)
		cout << "|";
}

void TicTacToe::render()
{
	// draw board
	drawHorizontalLine(BorderSize);

	for (int x = 0; x < 3; x++)
	{
		drawVerticalLine(BorderSize);
		for (int y = 0; y < 3; y++)
		{
			CellState state = gameBoard[x][y];
			char ch = ' ';
			if (state == CellState::Cross)
				ch = Cross;
			if (state == CellState::Circle)
				ch = Circle;

			cout << " " << ch << " ";
			drawVerticalLine(BorderSize);
		}
		cout << endl;
		drawHorizontalLine(BorderSize);
	}


	// draw example board

	int offsetX = BorderSize * 4 + 20;
	int offsetY = 0;
	set_cursor(offsetX, offsetY++);
	drawHorizontalLine(BorderSize);

	for (int x = 0; x < 3; x++)
	{
		set_cursor(offsetX, offsetY++);

		drawVerticalLine(BorderSize);
		for (int y = 0; y < 3; y++)
		{
			cout << x + 1 << " " << y + 1;

			drawVerticalLine(BorderSize);
		}
		cout << endl;

		set_cursor(offsetX, offsetY++);
		drawHorizontalLine(BorderSize);
	}
}

void TicTacToe::restart()
{
	movesRemain = 9;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gameBoard[i][j] = CellState::None;
		}
	}
}

const char TicTacToe::StateToChar(CellState state)
{
	char c = ' ';

	if (state == CellState::Cross)
		c = Cross;
	if (state == CellState::Circle)
		c = Circle;

	return c;
}
