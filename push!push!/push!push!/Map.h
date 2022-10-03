#pragma once
#include "Common.h"
#include "GameObject.h"

#define SIZE_MAP_Y 30
#define SIZE_MAP_X 24

struct Pixel
{
	wchar_t ch;
	bool isLight;
};

class Map : public GameObject
{
public:
	Map();
	Map(int x, int y);
	~Map();

	void Initiailize(std::wstring& stageString);
	void Update();
	void Render(int x, int y);
	void intersectHouseToBall();
	void SetGameObjectInMap(int x, int y, wchar_t ch);
	void SetGameObjectInMap(wchar_t ch, Vector2 pos, Vector2 prevPos = Vector2(-1,-1));

	void AddGameObject(GameObject* gameObject);
	bool IsBarrier(Pos pos);

	wchar_t GetPixel(Pos pos);
	wchar_t GetPixel(int y, int x);

	void BallReset();

private:
	std::vector<std::vector<Pixel>> mDatas;

	Size mSize;

	GameObject* mGameObjects[128];
};

