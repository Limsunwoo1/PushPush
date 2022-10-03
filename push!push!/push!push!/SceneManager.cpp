#include "SceneManager.h"
#include "Application.h"
#include "Ball.h"

SceneManager* SceneManager::mInstance = nullptr;

SceneManager::SceneManager()
    : mScenechange(SCENECHANGE::NONE)
{
    moveCount = 0;
}

SceneManager::~SceneManager()
{
    delete mInstance;
}

SceneManager* SceneManager::GetInstance()
{
    if (mInstance == nullptr)
    {
        mInstance = new SceneManager();
    }

    return mInstance;
}

void SceneManager::Initialize()
{
    
}


void SceneManager::Update()
{
    SceneChanger();
}


void SceneManager::SceneChanger()
{
    switch (mScenechange)
    {
    case SCENECHANGE::RESET:
    {
        Application::GetInstance()->Reset();
        moveCount = 0;
    }
    break;

    case SCENECHANGE::UNDO:
    {
        Application::GetInstance()->UNDO();
        moveCount = 0;
    }
    break;

    case SCENECHANGE::NEXTSTAGE:
    {
        NextStage();
        Application::GetInstance()->Reset();
        moveCount = 0;
    }
    break;

    case SCENECHANGE::EXIT:
    {
        _Exit(0);
    }
    break;

    case SCENECHANGE::ENDING:
    {
        Application::GetInstance()->SetPlaySceneNumber((int)SCENETYPE::ENDING);
    }
    break;
    }
    
    mScenechange = SCENECHANGE::NONE;
}

void SceneManager::NextStage()
{
    // 현재스테이지 넘버
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

    fclose(fp);

    selectStage++;

    // 다음 스테이지 넘버
    FILE* fp2 = nullptr;
    errno_t error2 = fopen_s(&fp2, "..\\Stages\\CurStageNum.txt", "w");
    if (error2 != 0)
    {
        std::wcout << L"스테이지 파일이 없습니다.\n";
        std::wcout << L"파일 경로를 확인해주세요.\n";
        exit(0);
    }
    else
    {
        std::string input = std::to_string(selectStage);

        if (selectStage >= MAXSTAGE)
        {
            Application::GetInstance()->SetPlaySceneNumber((int)SCENETYPE::ENDING);
        }

        fputs(input.c_str(), fp2);

        fclose(fp2);
    }
}