#pragma once
#include "Common.h"
#include "Scene.h"
#include "Application.h"

enum class SCENECHANGE
{
	EXIT,
	RESET,
	UNDO,
	NEXTSTAGE,
	ENDING,
	NONE
};

class SceneManager
{
public:
	static SceneManager* GetInstance();
	void Initialize();
	void Update();

	void SetScenechange(SCENECHANGE NextScene) {mScenechange = NextScene;}

	int GetMoveCount() { return moveCount; }
	void SetMoveCount(int move) { moveCount = move; }


private:
	SceneManager();
	~SceneManager();

	void SceneChanger();
	void NextStage();
private:
	static SceneManager* mInstance;

	int moveCount;
	SCENECHANGE mScenechange;
};

