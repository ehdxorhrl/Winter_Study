#pragma once

const int LEFT = 75;
const int RIGHT = 77;
const int UP = 72;
const int DOWN = 80;

class Player
{
public:
	int x;
	int y;
	int ax;
	int ay;
	bool attack;
public:
	Player();
	~Player();
	void Render();
	void IsAttack();
	void MoveTo_Player(int num);
	void reset();
};

