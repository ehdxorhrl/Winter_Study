#pragma once
class Monster
{
public:
	int x;
	int y;
	int speed;
	bool live;
public:
	Monster();
	~Monster();
	void Create();
	void Render();
	void MoveTo_Player(int _x, int _y, int speed);
	void Check_Range(int ax, int ay);
};

