#include "Common.h"
#include "GameInstance.h"

int main()
{
	CGameInstance* Instance = new CGameInstance;

	Instance->Init();

	while (true)
	{
		Instance->Update();
		Instance->Render();
		Sleep(200);

		if (Instance->IsNeedDestroy()) break;
	}

	Instance->Destroy();
	delete Instance;

	std::cout << "End" << std::endl;

	return 0;
}

