#include "PlayScene.h"
#include "Application.h"
#include "SceneManager.h"
#include "Sound.h"


PlayScene::PlayScene()
	: RunningStage (0)
{
	
}

PlayScene::~PlayScene()
{
	Destroy();
}

void PlayScene::Initiailize()
{
	InitializeMap();
	RunningStage = mStage.GetCurStage();
}

void PlayScene::Update()
{
	mMap->Update();
}

void PlayScene::Render()
{
	std::string str = "STAGE " + std::to_string(RunningStage);
	short x = SIZE_MAP_X * 2;
	short y = 3;
	SET_COLOR(COLOR::DARK_RED);
	GOTO_XY(x, (y + 2));   std::wcout << (L"������������������������������������ ");
	GOTO_XY(x, (y + 3));   std::wcout << (L"��   PLAY SCENE   �� ");
	GOTO_XY(x, (y + 4));   std::wcout << (L"��    ") << str.c_str() << (L"     �� ");
	GOTO_XY(x, (y + 5));   std::wcout << (L"������������������������������������ ");

	y += 7;
	SET_COLOR(COLOR::WHITE);
	GOTO_XY((x + 5), y); printf("MOVE : %d", SceneManager::GetInstance()->GetMoveCount());

	y = 5;
	SET_COLOR(COLOR::DARK_GREEN);
	GOTO_XY((x - 35), y++); printf("[ Backspace ] : undo\n");
	GOTO_XY((x - 35), y++); printf("[ Reset ] : R \n");
	GOTO_XY((x - 35), y++); printf("[ Esc ] : Exit \n");
	SET_COLOR(BLUE);


	SET_COLOR(GRAY);
	y = 5;
	GOTO_XY((x + 35), y++); printf("      W      ");
	GOTO_XY((x + 35), y++); printf("     ��      ");
	GOTO_XY((x + 35), y++); printf(" A ��   �� S ");
	GOTO_XY((x + 35), y++); printf("     ��      ");
	GOTO_XY((x + 35), y++); printf("      D      ");



	/*y++;
	y++;
	y++;
	SET_COLOR(COLOR::WHITE);
	GOTO_XY((x + 25), y++); printf("MOVE : %d", SceneManager::GetInstance()->GetMoveCount());*/

	x = SIZE_MAP_X * 2 + 1;
	y = (7 + 6);
	GOTO_XY(x, y);
	mMap->Render(x, y);
}

void PlayScene::Destroy()
{
	delete mMap;
}

void PlayScene::InitializeMap()
{
	mMap = mStage.StageLoad();

	/*mMap = new Map(8, 8);
	std::wstring stageData = L"";

	stageData += L"�ԤԢ̢̢̤ԤԤ�";
	stageData += L"�ԤԢ̤Ԣ̤ԤԤ�";
	stageData += L"�ԤԢ̤Ԣ̢̢̢�";
	stageData += L"�̢̢̤ԤԤԤԢ�";
	stageData += L"�̤ԤԤԤԢ̢̢�";
	stageData += L"�̢̢̢̤Ԣ̤Ԥ�";
	stageData += L"�ԤԤԢ̤Ԣ̤Ԥ�";
	stageData += L"�ԤԤԢ̢̢̤Ԥ�";

	mMap->Initiailize(stageData);
	mMap->SetGameObjectInMap(mPlayer.GetPos(), mPlayer.GetWChar_t());*/
}
