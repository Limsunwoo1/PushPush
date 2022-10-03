#include "EndingScene.h"

EndingScene::EndingScene()
{
}

EndingScene::~EndingScene()
{
}

void EndingScene::Initiailize()
{

}

void EndingScene::Update()
{
	if (_kbhit())
	{        //키보드 입력 확인 (true / false)
		char input = _getch();

		if (input == VK_ESCAPE)
		{
			_Exit(0);
		}
	}
}

void EndingScene::Render()
{
	system("cls");
	short x = SIZE_MAP_X * 2;
	short y = 10;
	SET_COLOR(COLOR::DARK_GREEN);
	GOTO_XY(x, (y + 2));   std::wcout << (L"┏━━━━━━━━━━━━━━━━┓");
	GOTO_XY(x, (y + 3));   std::wcout << (L"┃  **Game Clear**┃          ");
	GOTO_XY(x, (y + 4));   std::wcout << (L"┗━━━━━━━━━━━━━━━━┛");


	std::wstring str = L"ESC 눌러서 게임종료...";
	GOTO_XY((x), (y + 5));   std::wcout << str;
}

void EndingScene::Destroy()
{
}
