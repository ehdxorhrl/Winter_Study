#include "Player.h"
#include "Common.h"

void Player::Render()
{
	gotoxy(x * 2, y);
	std::cout << "��";
}

Player::Player()
{
	x = 5; //�ϴ� ����
	y = 5;
}

Player::~Player()
{
}
