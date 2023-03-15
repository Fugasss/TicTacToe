#pragma once

#include <iostream>
#include "ConsoleExtension.h"
#include "TicTacToeView.h"
#include "CellState.h"
#include "Move.h"

using namespace std;

class TicTacToeModel
{
public:
	TicTacToeModel(TicTacToeView* view) : _view(view)
	{
		restart();
	}

	bool place(Move move, CellState state);
	bool isFree(Move move );
	void unplace(Move move );

	bool checkForEnd(CellState* winnerState);
	void restart();



private:
	int _movesRemain;
	CellState gameBoard[3][3];
	TicTacToeView* _view;
};