#include "GameInstance.h"
#include "Common.h"
#include "Player.h"
#include "Board.h"
#include "Monster.h"

Board board;
Player player;
Monster monster;

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
		if (state == Ingame) 
		{
			switch (key)
			{
			case 224:
				key = _getch();
				if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
				{
					player.MoveTo_Player(key);
				};
				break;
			case Key_SP:
				player.attack = true;
				break;
			case 'p':
			case 'P':
				state = Pause;
				break;
			}
		}
		else if (state == Pause)
		{
			switch (key)
			{
			case Key_ENTER:
				state = Ingame;
				break;
			}
		}
	}
	cout << key << endl;
}

void CGameInstance::Render()
{
	if (state == Ingame)
	{
		system("cls");

		// ��->Render();
		// �÷��̾�->Render();

		// �� �׸��鼭 �÷��̾� �׸���

		// Player �׸���
		board.Render();
		player.Render();
		monster.Render();
		player.IsAttack();
		board.ReturnCaret();
	}
	else if (state == Pause)
	{
		system("cls");
		cout << "����ϱ⸦ ���ϱ�� ENTER�� �����ּ���";
	}
}

void CGameInstance::Destroy()
{
	std::cout << "Destroy CGameInstance" << std::endl;
}
