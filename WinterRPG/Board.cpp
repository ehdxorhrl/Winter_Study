#include "Board.h"
#include "Common.h"

void Board::Render()
{
	gotoxy(0, 0);

	for (int i = 0; i < BoardY; ++i) {
		for (int j = 0; j < BoardX; ++j) {
			if (i == 0 || i == BoardY - 1 || j == 0 || j == BoardX - 1)
			{
				std::cout << "бс ";
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void Board::ReturnCaret()
{
	gotoxy(BoardX * 2, BoardY - 1);
}


