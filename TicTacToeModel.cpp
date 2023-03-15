#include "TicTacToeModel.h"

bool TicTacToeModel::place(Move move, CellState state)
{
	int x = move.row;
	int y = move.column;

	CellState currentState = gameBoard[x][y];

	if (currentState == CellState::None) {
		gameBoard[x][y] = state;
		_movesRemain--;

		_view->render(gameBoard);

		return true;
	}

	return false;
}

bool TicTacToeModel::isFree(Move move)
{
	int x = move.row;
	int y = move.column;

	return gameBoard[x][y] == CellState::None;
}

void TicTacToeModel::unplace(Move move)
{
	int x = move.row;
	int y = move.column;

	if (gameBoard[x][y] != CellState::None) {
		_movesRemain++;
	}
	gameBoard[x][y] = CellState::None;

	_view->render(gameBoard);
}

bool TicTacToeModel::checkForEnd(CellState* winnerState)
{
	*winnerState = CellState::None;

	for (int s = 1; s <= 2; s++)
	{
		CellState st = static_cast<CellState>(s);

		//rows
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

		//columns
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

		//diagonals
		if (gameBoard[0][0] == st && gameBoard[1][1] == st && gameBoard[2][2] == st ||
			gameBoard[2][0] == st && gameBoard[1][1] == st && gameBoard[0][2] == st) {
			*winnerState = st;
			return true;
		}
	}

	if (_movesRemain <= 0) {
		*winnerState = CellState::None;
		return true;
	}

	return false;
}




void TicTacToeModel::restart()
{
	_movesRemain = 9;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gameBoard[i][j] = CellState::None;
		}
	}

	_view->render(gameBoard);
}

