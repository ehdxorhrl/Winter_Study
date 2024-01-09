#include "Monster.h"
#include "Common.h"
#include <random>

Monster::Monster()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> rand_coord(10, 13);
	uniform_int_distribution<int> rand_sp(1, 2);
	x = rand_coord(gen);
	y = rand_coord(gen);
	speed = rand_sp(gen);
	live = true;
}

Monster::~Monster()
{
}

void Monster::Create()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> rand_coord(10, 13);
	uniform_int_distribution<int> rand_sp(1, 2);
	x = rand_coord(gen);
	y = rand_coord(gen);
	speed = rand_sp(gen);
	live = true;
}

void Monster::Render()
{
	if (live) 
	{
		gotoxy(x * 2, y);
		std::cout << "＠";
	}
}

void Monster::MoveTo_Player(int _x, int _y, int speed)
{
	if (live)
	{
		int monster_turn = 0;
		while (monster_turn < speed) 
		{
			if (x == _x && y == _y)
			{
				return;
			}

			if (x != _x && y != _y)
			{
				random_device rd;
				mt19937 gen(rd());
				uniform_int_distribution<int> rand_XY(0, 1);
				if (rand_XY(gen) == 0)
				{
					if (_x > x)
						x = x + 1;
					else
						x = x - 1;
					// x값 비교 후 이동
				}
				else
				{
					if (_y > y)
						y = y + 1;
					else
						y = y - 1;
					// y값 비교 후 이동
				}
			}
			else
			{
				if (y == _y)
				{
					if (_x > x)
						x = x + 1;
					else
						x = x - 1;
				}
				else if (x == _x)
				{
					if (_y > y)
						y = y + 1;
					else
						y = y - 1;
				}
				// 그냥 이동
			}

			monster_turn++;
		}

	}
}

void Monster::Check_Range(int ax, int ay)
{
	if (x == ax && y == ay)
	{
		live = false;
	}
}
