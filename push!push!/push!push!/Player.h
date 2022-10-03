#pragma once
#include "GameObject.h"

class Ball;

class Player : public GameObject
{
public:
	Player();
	Player(Pos pos);
	~Player();

	virtual void Update(Map* map) override;
	virtual void Render() override;

private:
	DIRECTION InputProcess();
	void OnCollisionBalls(Map* map, DIRECTION dir, Pos& prevPos);

private:
};

