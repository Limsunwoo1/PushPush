#pragma once
#include "Scene.h"
class EndingScene :
    public Scene
{
public:
	EndingScene();
	~EndingScene();

	virtual void Initiailize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
	
private:

};

