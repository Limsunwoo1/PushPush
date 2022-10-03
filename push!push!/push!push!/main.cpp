#include <iostream>
#include "Application.h"
#include "SceneManager.h"



int main()
{
    setlocale(LC_ALL, "");

    Application::GetInstance()->Initiailize();

    while (Application::GetInstance()->GetIsRunning())
    {
        Application::GetInstance()->Update();
        Application::GetInstance()->Rendering();
        SceneManager::GetInstance()->Update();
    }
    Application::GetInstance()->Destroy();


    return 0;
}

// 최종스테이지 저장해뒀다가 다시키면 그 스테이지에서 시작

// 배경음악과  이동 비프음, 돌맹이 넣엇을때 비프음

