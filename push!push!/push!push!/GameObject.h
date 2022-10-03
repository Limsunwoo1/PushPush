#pragma once
#include "Common.h"

class Map;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(Map* map) {};
	virtual void Render() {};

	void SetPos(Vector2 pos) { mPos = pos; }
	void SetPos(int x, int y) { mPos.x = x; mPos.y = y; }
	Vector2 GetPos() { return mPos; }

	void SetWChar_t(wchar_t ch) { mCh = ch; }
	wchar_t GetWChar_t() { return mCh; }

	DIRECTION Move(DIRECTION inputDir, Pos& pos);
	DIRECTION Move(char ch, Pos& pos);

protected:
	Vector2 mPos;
	wchar_t mCh;
};

