#include "House.h"
#include "Map.h"

House::House()
{
	mPos = Pos(-1, -1);
	mCh = L'¡ß';
}

House::House(Pos pos)
{
	mPos = pos;
	mCh = L'¡ß';
}

House::~House()
{

}

void House::Update(Map* map)
{
	Pos prevPos = mPos;
	map->SetGameObjectInMap(mCh, mPos, prevPos);
}

void House::Render()
{
}
