#pragma once
#include "Map.h"

class Application;

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Initiailize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;

protected:
	Application* mApplication;

protected:
	Map* mMap;
};

