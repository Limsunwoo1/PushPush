#pragma once
#include "Scene.h"
#include "Player.h"
#include "Stage.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	virtual void Initiailize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;

	const int& GetCurStage() { return RunningStage; }
private:
	void InitializeMap();

private:
	Stage mStage;

	int RunningStage;
};

