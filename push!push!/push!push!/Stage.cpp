#include "Stage.h"
#include "SceneManager.h"

#include "Player.h"
#include "Ball.h"
#include "House.h"

Stage::Stage()
    : mMap(nullptr)
    , mStageChoice(0)
    , mCurStage (0)
{
}

Stage::~Stage()
{
}

Map* Stage::Load(const char* filepath)
{
    FILE* fp = nullptr;
    errno_t error = fopen_s(&fp, filepath, "rt,ccs=UTF-8");

    if (error != 0)
    {
        std::wcout << L"스테이지 파일이 없습니다.\n";
        std::wcout << L"파일 경로를 확인해주세요.\n";
        exit(0);
    }
    wchar_t buff[64] = L"";

    std::wstring x = fgetws(buff, 63, fp);
    std::wstring y = fgetws(buff, 63, fp);

    int mapX = std::stoi(x);
    int mapY = std::stoi(y);
    mMap = new Map(mapX, mapY);

    for (size_t y = 0; y < mapY; y++)
    {
        fgetws(buff, 63, fp);
        for (size_t x = 0; x < mapX; x++)
        {
            if (buff[x] == L'ㅤ' || buff[x] == L'▩')
                mMap->SetGameObjectInMap(x, y, buff[x]);
            else
                CreateGameObject(buff[x], x, y);
        }
    }


    fclose(fp);

    return mMap;
}

void Stage::CreateGameObject(wchar_t type, int x, int y)
{
    switch (type)
    {
    case L'★':
    {
        Player* player = new Player(Pos(x, y));
        mMap->AddGameObject(dynamic_cast<GameObject*>(player));
    }
    break;

    case L'●':
    {
        Ball* ball = new Ball(Pos(x, y));
        mMap->AddGameObject(dynamic_cast<GameObject*>(ball));
    }
    break;

    case L'◆':
    {
        House* house = new House(Pos(x, y));
        mMap->AddGameObject(dynamic_cast<GameObject*>(house));
    }
    break;

    case L'♥':
    {
        House* house = new House(Pos(x, y));
        mMap->AddGameObject(dynamic_cast<GameObject*>(house));

        Ball* ball = new Ball(Pos(x, y));
        mMap->AddGameObject(dynamic_cast<GameObject*>(ball));
    }
    break;

    default:
        break;
    }
}

Map* Stage::StageLoad()
{
    FILE* fp = nullptr;
    errno_t error = fopen_s(&fp, "..\\Stages\\CurStageNum.txt", "rt,ccs=UTF-8");
    if (error != 0)
    {
        std::wcout << L"스테이지 파일이 없습니다.\n";
        std::wcout << L"파일 경로를 확인해주세요.\n";
        exit(0);
    }

    wchar_t buff[64] = L"";

    std::wstring stageCode = fgetws(buff, 63, fp);

    int selectStage = std::stoi(stageCode);

    mCurStage = selectStage;

    Map* map = nullptr;

    switch (selectStage)
    {
    case 1:
    {
       const char filepath[256] = { "..\\Stages\\Stage01.txt" };
       map = Load(filepath);
    }
    break;

    case 2:
    {
        const char filepath[256] = { "..\\Stages\\Stage02.txt" };
        map = Load(filepath);
    }
    break;

    case 3:
    {
        const char filepath[256] = { "..\\Stages\\Stage03.txt" };
        map = Load(filepath);
    }
    break;

    case 4:
    {
        const char filepath[256] = { "..\\Stages\\Stage04.txt" };
        map = Load(filepath);
    }
    break;

    case 5:
    {
        const char filepath[256] = { "..\\Stages\\Stage05.txt" };
        map = Load(filepath);
    }
    break;

    case MAXSTAGE:
    {
        fclose(fp);
        Application::GetInstance()->SetPlaySceneNumber((int)SCENETYPE::ENDING);
        return map;
    }
    break;
    }

    fclose(fp);

    return map;
}
