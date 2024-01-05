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
