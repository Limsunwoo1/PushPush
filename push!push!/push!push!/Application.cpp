#include "Application.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "EndingScene.h"
#include "Sound.h"

Application* Application::mInstance = nullptr;


Application::Application()
	: mbRunning(true)
	, mPlaySceneNumber((int)SCENETYPE::TITLE)
{
	clear();
}

Application::~Application()
{

}

void Application::clear()
{
	for (int i = 0; i < (int)SCENETYPE::END; i++)
	{
		mScene[i] = nullptr;
	}
}

bool Application::Initiailize()
{
	Sound::Play(true);

	mScene[(int)SCENETYPE::TITLE] = new TitleScene();
	mScene[(int)SCENETYPE::PLAY] = new PlayScene();
	mScene[(int)SCENETYPE::ENDING] = new EndingScene();

	for (int i = 0; i < (int)SCENETYPE::END; i++)
	{
		mScene[i]->Initiailize();
	}

	return true;
}

void Application::Update()
{
	mScene[mPlaySceneNumber]->Update();
}

void Application::Rendering()
{
	//system("cls");
	mScene[mPlaySceneNumber]->Render();
	Sleep(200);
}

void Application::Destroy()
{
	for (int i = 0; i < (int)SCENETYPE::END; i++)
	{
		mScene[i]->Destroy();
	}

	for (int i = 0; i < (int)SCENETYPE::END; ++i)
	{
		if (mScene[i] != nullptr)
			delete mScene[i];
	}
}

void Application::UNDO()
{
	Reset();
	mPlaySceneNumber = (int)SCENETYPE::TITLE;
	system("cls");
}

void Application::Reset()
{
	delete mScene[(int)mPlaySceneNumber];
	mScene[(int)mPlaySceneNumber] = nullptr;


	if (mPlaySceneNumber == (int)SCENETYPE::PLAY)
	{
		mScene[(int)mPlaySceneNumber] = new PlayScene();
	}
	else if(mPlaySceneNumber == (int)SCENETYPE::ENDING)
	{
		mScene[(int)mPlaySceneNumber] = new EndingScene();
	}
	else if(mPlaySceneNumber == (int)SCENETYPE::TITLE)
	{
		mScene[(int)mPlaySceneNumber] = new TitleScene();
	}

	mScene[(int)mPlaySceneNumber]->Initiailize();
	system("cls");
}