#include "Player.h"
#include "Common.h"

void Player::Render()
{
	gotoxy(x * 2, y);
	std::cout << "▣";
}

Player::Player()
{
	x = 5; //일단 고정
	y = 5;
}

Player::~Player()
{
}
