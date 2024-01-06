#include "Player.h"
#include "Common.h"

void Player::Render()
{
	gotoxy(x * 2, y);
	std::cout << "▣";
	IsAttack();
}

void Player::IsAttack()
{
	if (attack)
	{
		gotoxy(ax * 2, ay);
		std::cout << "◈";
		attack = false;
	}
}

void Player::MoveTo_Player(int num)
{
	switch (num)
	{
	case LEFT:
		if (x > 0)
		{
			x -= 1;
			ax = x - 1;
			ay = y;
		}
		break;
	case RIGHT:
		if (x < BoardX - 1)
		{
			x += 1;
			ax = x + 1;
			ay = y;
		}
		break;
	case UP:
		if (y > 0)
		{
			y -= 1;
			ay = y - 1;
			ax = x;
		}
		break;
	case DOWN:
		if (y < BoardY - 1)
		{
			y += 1;
			ay = y + 1;
			ax = x;
		}
		break;
	}
}

Player::Player()
{
	x = 5; //일단 고정
	y = 5;
	ax = 6; //오른쪽 바라봄
	ay = 5;
	attack = false;
}

Player::~Player()
{
	
}
