#include "GameInstance.h"
#include "Common.h"
#include "Player.h"
#include "Board.h"
#include "Monster.h"
#include <random>

Board board;
Player player;
Monster monster;
time_t start_time;

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
	time(&start_time);
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
				monster.Check_Range(player.ax, player.ay);
				break;
			case 'p':
			case 'P':
				state = Pause;
				break;
			case 'r':
			case 'R':
				monster.Create();
				player.reset();
				break;
			}
			monster.MoveTo_Player(player.x, player.y, monster.speed);
			
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

		// 판->Render();
		// 플레이어->Render();

		// 판 그리면서 플레이어 그리기

		// Player 그리기
		board.Render();
		player.Render();
		monster.Render();
		player.IsAttack();
		board.ReturnCaret();
		cout << endl;
		View_time();
	}
	else if (state == Pause)
	{
		system("cls");
		cout << "계속하기를 원하기면 ENTER를 눌러주세요" << endl;
	}
}

void CGameInstance::Destroy()
{
	std::cout << "Destroy CGameInstance" << std::endl;
}

void CGameInstance::View_time()
{
	time_t current_time;
	time(&current_time);
	cout << "플레이시간: " << current_time - start_time;
}

// system("cls") -> 더블 버퍼링으로 변경할것
