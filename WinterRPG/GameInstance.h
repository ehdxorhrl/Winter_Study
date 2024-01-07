#pragma once

const int Key_ESC = 27;
const int Key_ENTER = 13;
const int Key_SP = 32;

class CGameInstance
{
	enum STATE
	{
		Ingame = 0,
		Pause
	};
public:
	CGameInstance();
	~CGameInstance();

public:
	void Init();
	void Update();
	void Render();
	void Destroy();

	bool IsNeedDestroy() { return key == Key_ESC; };


private:
	int key = 0;
	int state = Ingame;
};

