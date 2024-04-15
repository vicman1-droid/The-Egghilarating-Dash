#include "NormalSpawner.h"
#include "../Car.h"
#include "Math.h"

using namespace std;



NormalSpawner::NormalSpawner()
{

}

void NormalSpawner::Spawn(const BackBuffer* pBackBuffer)
{

	DIRECTION direction;

	if (Random())
		direction = DIR_LEFT;
	else
		direction = DIR_RIGHT;
	
	Enemy* enemy = new Car(pBackBuffer, direction);

	if (direction == DIR_LEFT && Random())
		enemy->Position() = Vec2(800, 150);
	else if (direction == DIR_LEFT)
		enemy->Position() = Vec2(800, 250);

	if (direction == DIR_RIGHT && Random())
		enemy->Position() = Vec2(0, 350);
	else if (direction == DIR_RIGHT)
		enemy->Position() = Vec2(0, 450);

	enemyList.push_back(enemy);

}

bool NormalSpawner::Random()
{

	int roll;
	roll = (rand() % 100) + 1;

	if(roll <= 50 )
		return false;
	if (roll > 50)
		return true;

}

void NormalSpawner::Delete(std::vector<Enemy*>::iterator& it)
{
	it = enemyList.erase(it);
}

bool NormalSpawner::CheckEntitiesWithinLimit()
{
	if (enemyList.size() <= 3)
		return true;
	else
		return false;
}