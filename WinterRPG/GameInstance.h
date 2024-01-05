#pragma once

const int Key_ESC = 27;

class CGameInstance
{
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
};

