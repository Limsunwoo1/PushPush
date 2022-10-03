#include "Map.h"
#include "SceneManager.h"

#include "Ball.h"
#include "Player.h"


Map::Map()
	: mDatas()
	, mSize({ 0,0 })
{
	memset(mGameObjects, 0, sizeof(GameObject*) * 128);

	void* p = new int();
	srand((int)p);

	delete p;
}

Map::Map(int x, int y)
	: mDatas()
	, mSize({x,y})
{
	memset(mGameObjects, 0, sizeof(GameObject*) * 128);
	mDatas.resize(mSize.y);

	for (size_t i = 0; i < mSize.y; i++)
	{
		mDatas[i].resize(mSize.x);
	}

	for (size_t iy = 0; iy < mSize.y; iy++)
	{
		for (size_t ix = 0; ix < mSize.x; ix++)
		{
			mDatas[iy][ix].ch = L'¤Ô';
			mDatas[iy][ix].isLight = false;
		}
	}
}

Map::~Map()
{
	for (size_t i = 0; i < 128; i++)
	{
		if (mGameObjects[i] != nullptr)
		{
			delete mGameObjects[i];
			mGameObjects[i] = nullptr;
		}
	}

	Ball::ClearBalls();
}

void Map::Initiailize(std::wstring& stageString)
{
	
	int idx = 0;
	for (int iY = 0; iY < mSize.y; iY++)
	{
		for (int iX = 0; iX < mSize.x; iX++)
		{
			mDatas[iY][iX].ch = stageString[idx++];
		}
	}
}

void Map::Update()
{
	BallReset();

	for (size_t i = 0; i < 128; i++)
	{
		if (mGameObjects[i] != nullptr)
			mGameObjects[i]->Update(this);
	}
}

void Map::Render(int x, int y)
{
	Map::intersectHouseToBall();

	for (int iY = 0; iY < mSize.y; iY++)
	{
		for (int iX = 0; iX < mSize.x; iX++)
		{
			//SET_COLOR(COLOR::DARK_SKY_BLUE);
			GOTO_XY((x + (iX * 2)), (y + iY));
			
			if (mDatas[iY][iX].ch == L'¡Ú')
			{
				Pen pen(COLOR::GREEN, mDatas[iY][iX].ch);
			}

			if (mDatas[iY][iX].isLight == false)
			{
				Pen pen(mDatas[iY][iX].ch);
			}
			else
			{
				//void* p = new int();
				//srand((unsigned int)time(NULL));
				//srand((int)p);
				// 0 ~ 15;
				COLOR col = (COLOR)((rand() % 15) + 1);
				Pen pen(col, mDatas[iY][iX].ch);
				
				//delete p;
			}
		}
	}
}

void Map::intersectHouseToBall()
{
	Player* player = nullptr;
	std::vector<GameObject*> houses;
	for (size_t i = 0; i < 128; i++)
	{
		GameObject* temp = nullptr;
		if (mGameObjects[i] != nullptr)
		{
			temp = mGameObjects[i];

			if (temp->GetWChar_t() == L'¡ß')
			{
				houses.push_back(temp);
			}
			else if (temp->GetWChar_t() == L'¡Ú')
			{
				player = dynamic_cast<Player*>(temp);
			}
		}
	}

	int collisionCount = 0;
	std::list<Ball*> balls = Ball::GetBalls();
	for (Ball* ball : balls)
	{
		for (GameObject* house : houses)
		{
			Pos ballPos = (*ball).GetPos();
			Pos housePos = house->GetPos();

			if (ballPos == housePos)
			{
				mDatas[housePos.y][housePos.x].isLight = true;
				collisionCount++;
			}
		}
	}

	if (Ball::GetBallCount() == collisionCount)
	{
		SceneManager::GetInstance()->SetScenechange(SCENECHANGE::NEXTSTAGE);
	}

	for (GameObject* house : houses)
	{
		Pos housePos = house->GetPos();
		mDatas[housePos.y][housePos.x].ch = L'¡ß';
	}

	if (player != nullptr)
	{
		mDatas[player->GetPos().y][player->GetPos().x].ch = L'¡Ú';
	}
}

void Map::SetGameObjectInMap(int x, int y, wchar_t ch)
{
	mDatas[y][x].ch = ch;
}

void Map::SetGameObjectInMap(wchar_t ch, Vector2 pos, Vector2 prevPos)
{
	if (prevPos.y == -1 || prevPos.x == -1)
	{
		
	}
	else
	{
		mDatas[prevPos.y][prevPos.x].ch = L'¤Ô';
	}
	mDatas[pos.y][pos.x].ch = ch;
}

void Map::AddGameObject(GameObject* gameObject)
{
	for (int i = 0; i < 128; i++)
	{
		if (mGameObjects[i] == nullptr)
		{
			mGameObjects[i] = gameObject;
			break;
		}
	}
}

bool Map::IsBarrier(Pos pos)
{
	wchar_t ch = mDatas[pos.y][pos.x].ch;

	if (ch == L'¢Ì')
		return true;

	return false;
}

wchar_t Map::GetPixel(Pos pos)
{
	return mDatas[pos.y][pos.x].ch;
}

wchar_t Map::GetPixel(int y, int x)
{
	return mDatas[y][x].ch;
}

void Map::BallReset()
{
	std::list<Ball*>& balls = Ball::GetBalls();
	for (Ball* ball : balls)
	{
		Pos ballPos = (*ball).GetPos();
		mDatas[ballPos.y][ballPos.x].isLight = false;
		mDatas[ballPos.y][ballPos.x].ch = L'¡Ü';
	}
}