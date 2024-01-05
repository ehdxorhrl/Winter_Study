#include "GameInstance.h"
#include "Common.h"

CGameInstance::CGameInstance()
{
	std::cout << "Create CGameInstance" << std::endl;
}

CGameInstance::~CGameInstance()
{
	std::cout << "Delete  CGameInstance" << std::endl;
}

void CGameInstance::Init()
{
	std::cout << "Init CGameInstance" << std::endl;
}

void CGameInstance::Update()
{
	std::cout << "Update CGameInstance" << std::endl;

	int input = _kbhit();
	key = 0;
	if (input)
	{
		key = _getch();
	}
	cout << key << endl;
}

void CGameInstance::Render()
{
	system("cls");

	std::cout << "Render CGameInstance" << std::endl;

	// 판->Render();
	// 플레이어->Render();

	// 판 그리면서 플레이어 그리기

	// Player 그리기

	int PlayerX = 5;
	int PlayerY = 5;

	int BoardY = 15;
	int BoardX = 15;
	
	gotoxy(0, 0);

	for (int i = 0; i < BoardY; ++i) {
		for (int j = 0; j < BoardX; ++j) {
			if (i == 0 || j == 0 || i == BoardY - 1 || j == BoardX - 1) {
				std::cout << "■";
			}
			else if (i == PlayerY && j == PlayerX) {
				std::cout << "▣";
			}
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
	}

	gotoxy(PlayerX * 2, PlayerY);
}

void CGameInstance::Destroy()
{
	std::cout << "Destroy CGameInstance" << std::endl;
}
