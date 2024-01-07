#include "Monster.h"
#include "Common.h"
#include <random>

Monster::Monster()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> rand_coord(6, 13);
	uniform_int_distribution<int> rand_sp(1, 2);
	x = rand_coord(gen);
	y = rand_coord(gen);
	speed = rand_sp(gen);
}

Monster::~Monster()
{
}

void Monster::Render()
{
	gotoxy(x * 2, y);
	std::cout << "¢Á";
}
