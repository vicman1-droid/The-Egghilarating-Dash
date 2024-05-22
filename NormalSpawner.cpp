#include "NormalSpawner.h"
#include "../Car.h"
#include "../Truck.h"
#include "../Bulldozer.h"
#include "../LifePack.h"
#include "../ScoreMultiplier.h"
#include "../Invulnerability.h"
#include "Math.h"
#include "CGameApp.h"

using namespace std;


NormalSpawner::NormalSpawner(CPlayer* m_pPlayer, int *score,int *invulnerable)
{
	this->score = score;
	this->m_pPlayer = m_pPlayer;
	this->invulnerable = invulnerable;
}

void NormalSpawner::Spawn(const BackBuffer* pBackBuffer)
{

	DIRECTION direction;

	if (Random())
		direction = DIR_LEFT;
	else
		direction = DIR_RIGHT;
	
	Enemy* enemy;


	if(Random())
		 enemy = new Car(pBackBuffer, direction);
	else
	{
		if(Random())
			 enemy = new Bulldozer(pBackBuffer, direction);
		else
			 enemy = new Truck(pBackBuffer, direction);
	}
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

void NormalSpawner::SpawnCollectible(const BackBuffer* pBackBuffer)
{
	CollectibleInterface* coll;

	int x = rand() % 800;
	int y = rand() % 600;

	if(Random())
	coll = new LifePack(pBackBuffer,m_pPlayer);
	else
	{
		if (Random())
			coll = new ScoreMultiplier(pBackBuffer, *score);
		else
		{
			coll = new Invulnerability(pBackBuffer, *invulnerable);
			x = rand() % 800;
			y = 450;
		}
	}
	coll->Position() = Vec2(x, y);

	collectibleList.push_back(coll);


	
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

void NormalSpawner::DeleteCollectible(std::vector<CollectibleInterface*>::iterator& it)
{
	it = collectibleList.erase(it);
}

void NormalSpawner::DeleteEverything()
{
	for (auto it = enemyList.begin(); it != enemyList.end();)
	{
		Delete(it);
	}

	for (auto it = collectibleList.begin(); it != collectibleList.end();)
	{
		DeleteCollectible(it);
	}
}

bool NormalSpawner::CheckEntitiesWithinLimit()
{
	if (enemyList.size() <= 3)
		return true;
	else
		return false;
}

bool NormalSpawner::CheckCollectiblesWithinLimit()
{
	if (collectibleList.size() <= 2)
		return true;
	else
		return false;
}