#include "bot.h"

pair<int, int> Bot::makeMove()
{
	if (Ttt->isFree(1, 1)) 
	{
		return make_pair(1, 1);
	}

	int x = 0, y = 0;

	int bestValue = -1000;

	//int values[3][3] = { {0,0,0},{0,0,0},{0,0,0} };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			if (!Ttt->isFree(i, j)) continue;

			Ttt->place(i, j, PlayState);

			int moveValue = minimax(0, true);

			//values[i][j] = moveValue;

			Ttt->unplace(i, j); //undo

			if (moveValue > bestValue) {
				bestValue = moveValue;
				x = i;
				y = j;
			}
		}
	}


	////TEST VISUALIZING
	//std::cout << std::endl;
	//std::cout << std::endl;

	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		std::cout << values[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	//system("pause");
	////TEST VISUALIZING

	return make_pair(x, y);
}

int Bot::minimax(int depth, bool isMax)
{
	CellState state = CellState::None;
	bool isEnd = Ttt->checkForEnd(&state);

	CellState oppositeToBot = (PlayState == CellState::Cross ? CellState::Circle : CellState::Cross);

	if (isEnd)
	{
		if (state == PlayState)
			return 10;
		else if (state == oppositeToBot)
			return -10;
		else
			return 0;
	}

	int best = isMax ? -1000 : 1000;
	CellState player = isMax ? PlayState : oppositeToBot;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!Ttt->isFree(i, j)) continue;

			Ttt->place(i, j, player);

			if (isMax)
				best = max(best, minimax(depth + 1, !isMax)) - depth;
			else
				best = min(best, minimax(depth + 1, !isMax)) + depth;

			Ttt->unplace(i, j);
		}
	}

	return best;
}