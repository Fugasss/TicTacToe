#include "TicTacToeView.h"

void drawHorizontalLine(int borderSize) {
	for (int i = 0; i < 9 + borderSize * 4; i++)
		cout << "-";
	cout << endl;
}

void drawVerticalLine(int borderSize) {
	for (int i = 0; i < borderSize; i++)
		cout << "|";
}

void TicTacToeView::render(CellState board[3][3])
{
	system("cls");

	// draw board
	drawHorizontalLine(_borderSize);

	for (int x = 0; x < 3; x++)
	{
		drawVerticalLine(_borderSize);
		for (int y = 0; y < 3; y++)
		{
			CellState state = board[x][y];
			char ch = TicTacToe::StateToChar(state);

			cout << " " << ch << " ";
			drawVerticalLine(_borderSize);
		}
		cout << endl;
		drawHorizontalLine(_borderSize);
	}


	// draw example board
	int offsetX = _borderSize * 4 + 20;
	int offsetY = 0;
	set_cursor(offsetX, offsetY++);
	drawHorizontalLine(_borderSize);

	for (int x = 0; x < 3; x++)
	{
		set_cursor(offsetX, offsetY++);

		drawVerticalLine(_borderSize);
		for (int y = 0; y < 3; y++)
		{
			cout << x + 1 << " " << y + 1;

			drawVerticalLine(_borderSize);
		}
		cout << endl;

		set_cursor(offsetX, offsetY++);
		drawHorizontalLine(_borderSize);
	}
}
