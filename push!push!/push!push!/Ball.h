#pragma once
#include "Common.h"
#include "GameObject.h"

class Ball : public GameObject
{
public:
	static std::list<Ball*>& GetBalls() { return mBalls; }
	static void ClearBalls() {mBalls.clear(); mBallCount= 0;}
	const static int GetBallCount() { return mBallCount; }
	

	Ball();
	Ball(Pos pos);
	~Ball();

	void Initalize(Pos pos = Pos(-1, -1));
	virtual void Update(Map* map)override;
	virtual void Render() override;

private:
	static int mBallCount;
	static std::list<Ball*> mBalls;
};

