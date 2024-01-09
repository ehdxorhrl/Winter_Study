#include "Player.h"
#include "Common.h"

void Player::Render()
{
	gotoxy(x * 2, y);
	std::cout << "▣";
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
		if (x > 1)
		{
			x -= 1;
		}
		ax = x - 1;
		ay = y;
		break;
	case RIGHT:
		if (x < BoardX - 2)
		{
			x += 1;
		}
		ax = x + 1;
		ay = y;
		break;
	case UP:
		if (y > 1)
		{
			y -= 1;
		}
		ay = y - 1;
		ax = x;
		break;
	case DOWN:
		if (y < BoardY - 2)
		{
			y += 1;
		}
		ay = y + 1;
		ax = x;
		break;
	}
}

void Player::reset()
{
	x = 1; //일단 고정
	y = 1;
	ax = 2; //오른쪽 바라봄
	ay = 1;
	attack = false;
}

Player::Player()
{
	x = 1; //일단 고정
	y = 1;
	ax = 2; //오른쪽 바라봄
	ay = 1;
	attack = false;
}

Player::~Player()
{
	
}
