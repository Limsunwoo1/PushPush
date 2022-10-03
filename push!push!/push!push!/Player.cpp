#include "Player.h"
#include "SceneManager.h"

#include "Ball.h"
#include "Map.h"

Player::Player()
{
	mCh = L'★';
	mPos.y = 4;
	mPos.x = 4;
}

Player::Player(Pos pos)
{
	mCh = L'★';
	mPos.y = pos.y;
	mPos.x = pos.x;
}

Player::~Player()
{
}

void Player::Update(Map* map)
{
	Pos prevPos = mPos;
	DIRECTION dir = InputProcess();

	if (map->IsBarrier(mPos))
	{
		mPos = prevPos;
		int move = SceneManager::GetInstance()->GetMoveCount();
		SceneManager::GetInstance()->SetMoveCount(--move);
	}

	OnCollisionBalls(map, dir, prevPos);

	map->SetGameObjectInMap(mCh, mPos, prevPos);
}

void Player::Render()
{

}

DIRECTION Player::InputProcess()
{
	DIRECTION dir = DIRECTION::NONE;

	if (_kbhit())
	{
		char input = _getch();

		dir = Move(input, mPos);
	}

	return dir;
}

void Player::OnCollisionBalls(Map* map, DIRECTION dir, Pos& prevPos)
{
	std::list<Ball*> balls = Ball::GetBalls();
	for (std::list<Ball*>::iterator iter = balls.begin()
		; iter != balls.end()
		; iter++)
	{
		Pos ballPos = (*iter)->GetPos();
		Pos prevBallPos = ballPos;
		if (mPos == ballPos)
		{
			Move(dir, ballPos);

			// 공 벽충돌 체크
			if (map->GetPixel(ballPos) == L'▩'
				|| map->GetPixel(ballPos) == L'●')
			{
				ballPos = prevBallPos;

				// 플레이어도 움직이지 못하게 돌려주어야 한다.
				mPos = prevPos;

				int move = SceneManager::GetInstance()->GetMoveCount();
				SceneManager::GetInstance()->SetMoveCount(--move);
			}
			else if(map->GetPixel(ballPos) == L'◆')
			{
				Beep(800, 100);
			}

			(*iter)->SetPos(ballPos);
			map->SetGameObjectInMap((*iter)->GetWChar_t(), ballPos, prevBallPos);
		}
	}
}
