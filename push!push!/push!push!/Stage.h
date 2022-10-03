#pragma once
#include "Common.h"
#include "Map.h"

class Stage
{
public:
	Stage();
	~Stage();

	Map* Load(const char* filepath);
	void CreateGameObject(wchar_t type, int x, int y);

	Map* StageLoad();

	int GetCurStage() { return mCurStage; }

private:
	Map* mMap;

	int mCurStage;
	int mStageChoice;
};

