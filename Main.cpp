#include <iostream>
#include <Windows.h>
#include "TicTacToe.h"
#include "ConsoleExtension.h"
#include "CellState.h"
#include "bot.h"

using namespace std;

void readPlayerMove(int* x, int* y) 
{
	cin >> *x >> *y;
	(*x)--;
	(*y)--;
}
void readBotMove(Bot* bot, int* x, int* y) {
	std::pair<int, int> mv = (*bot).makeMove();
	*x = mv.first;
	*y = mv.second;
}

int main()
{
	bool exitGame = false;

	TicTacToe ttt = TicTacToe(1);

	CellState currentState = CellState::Cross;

	Bot bot = Bot(CellState::Circle, &ttt);
	
	ttt.render();

	bool isAi = false;
	int isAiInt = 0;
	cout << "Select game mode [0 - with AI, 1 - with second player]: ";
	cin >> isAiInt;
	isAi = isAiInt == 0;

	while (!exitGame) {
		cout << "\n\n\n";

		int x = 0, y = 0;
		CellState winnerState = CellState::None;

		do {
			if (ttt.checkForEnd(&winnerState)) {
				break;
			}

			cout << "Current player: " << TicTacToe::StateToChar(currentState) << endl;
			cout << "Select cell: ";
			
			if (isAi) 
			{
				if (currentState == bot.PlayState) {
					readBotMove(&bot, &x, &y);
				}
				else {
					readPlayerMove(&x, &y);
				}
			}
			else
			{
				readPlayerMove(&x, &y);
			}

			
		} while (!ttt.place(x, y, currentState));

		currentState = currentState == CellState::Cross ? CellState::Circle : CellState::Cross;
		system("cls");
		ttt.render();

		if (ttt.checkForEnd(&winnerState)) {

			if (winnerState == CellState::None)
				cout << "Tie" << endl;
			else
				cout << "Winner: " << TicTacToe::StateToChar(winnerState) << endl;

			cout << "Do you want to play one more time?" << endl;
			cout << "[y/n]: ";
			char answer;
			cin >> answer;

			if (answer == 'y' || answer == 'Y')
			{
				exitGame = false;
				currentState = CellState::Cross;
				ttt.restart();
				system("cls");
				ttt.render();
			}
			else
			{
				exitGame = true;
			}
		}
	}

	return 0;
}