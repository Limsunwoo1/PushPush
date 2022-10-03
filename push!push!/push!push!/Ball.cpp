#include "Ball.h"
#include "Map.h"

int Ball::mBallCount = 0;
std::list<Ball*> Ball::mBalls;

Ball::Ball()
{
	Initalize();
}

Ball::Ball(Pos pos)
{
	Initalize(pos);
}

Ball::~Ball()
{
	
}

void Ball::Initalize(Pos pos)
{
	mPos = pos;
	mCh = L'¡Ü';

	mBallCount++;
	mBalls.push_back(this);
}

void Ball::Update(Map* map)
{
	Pos prevPos = mPos;
	map->SetGameObjectInMap(mCh, mPos, prevPos);
}

void Ball::Render()
{
}
