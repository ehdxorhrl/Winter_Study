#include "GameInstance.h"
#include "Common.h"
#include "Player.h"
#include "Board.h"

Board board;
Player player;

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

	key = 0;
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case 224:
			key = _getch();
			if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
			{
				player.MoveTo_Player(key);
			};
			break;
		case space:
			player.attack = true;
			break;
		}
	}
	cout << key << endl;
}

void CGameInstance::Render()
{
	system("cls");

	// ��->Render();
	// �÷��̾�->Render();

	// �� �׸��鼭 �÷��̾� �׸���

	// Player �׸���
	board.Render();
	player.Render();
	board.ReturnCaret();
}

void CGameInstance::Destroy()
{
	std::cout << "Destroy CGameInstance" << std::endl;
}
