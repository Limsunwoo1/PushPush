#include "GameObject.h"
#include "SceneManager.h"

#include "PlayScene.h"

GameObject::GameObject()
	: mPos()
	,mCh('\0')
{

}

GameObject::~GameObject()
{
}

DIRECTION GameObject::Move(DIRECTION inputDir, Pos& pos)
{
	DIRECTION dir = inputDir;
	switch (dir)
	{
	case DIRECTION::UP:
	{
		pos.y -= 1;
		dir = DIRECTION::UP;
	}
	break;

	case DIRECTION::LEFT:
	{
		pos.x -= 1;
		dir = DIRECTION::LEFT;
	}
	break;

	case DIRECTION::DOWN:
	{
		pos.y += 1;
		dir = DIRECTION::DOWN;
	}
	break;

	case DIRECTION::RIGHT:
	{
		pos.x += 1;
		dir = DIRECTION::RIGHT;
	}
	break;

	default:
		break;
	}

	return dir;
}

DIRECTION GameObject::Move(char ch, Pos& pos)
{
	DIRECTION dir = DIRECTION::NONE;
	Pos prevPos = pos;
	switch (ch)
	{
	case 'w':
	{
		pos.y -= 1;
		dir = DIRECTION::UP;
	}
	break;

	case 'a':
	{
		pos.x -= 1;
		dir = DIRECTION::LEFT;
	}
	break;

	case 's':
	{
		pos.y += 1;
		dir = DIRECTION::DOWN;
	}
	break;

	case 'd':
	{
		pos.x += 1;
		dir = DIRECTION::RIGHT;
	}
	break;

	case VK_ESCAPE:
	{
		SceneManager::GetInstance()->SetScenechange(SCENECHANGE::EXIT);
	}
	break;

	case VK_BACK:
	{
		SceneManager::GetInstance()->SetScenechange(SCENECHANGE::UNDO);
	}
	break;

	case 'r':
	{
		SceneManager::GetInstance()->SetScenechange(SCENECHANGE::RESET);
	}
	break;

	default:
		break;
	}

	if (!(prevPos == pos))
	{
		int move = SceneManager::GetInstance()->GetMoveCount();
		SceneManager::GetInstance()->SetMoveCount(++move);
	}

	if (dir != DIRECTION::NONE)
		Beep(600, 100);

	return dir;
}
