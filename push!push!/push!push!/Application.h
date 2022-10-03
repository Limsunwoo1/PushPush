#pragma once
#include "Common.h"
#include "Scene.h"

enum class SCENETYPE
{
    TITLE,
    PLAY,
    ENDING,
    END,
};

class Application
{
public:
    static Application* GetInstance()
    {
        if (mInstance == nullptr)
        {
            mInstance = new Application();
        }

        return mInstance;
    }

    bool Initiailize();
    void Update();
    void Rendering();
    void Destroy();

    bool GetIsRunning() { return mbRunning; };
    void SetIsRunning(bool running) { mbRunning = running; }
    void SetPlaySceneNumber(int number) { mPlaySceneNumber = number; }

    void UNDO();
    void Reset();

private:
    Application();
    ~Application();

    void clear();

private:
    static Application* mInstance;

    bool mbRunning;

    Scene* mScene[(int)SCENETYPE::END];
    int mPlaySceneNumber;
};

