#pragma once
#include <vector>
#include "Enemy.h"
#include "CollectibleInterface.h"

class SpawnerControlInterface
{

public:

	virtual bool CheckEntitiesWithinLimit() = 0;
	virtual bool CheckCollectiblesWithinLimit() = 0;

	virtual	void Spawn(const BackBuffer* pBackBuffer) = 0;
	virtual	void SpawnCollectible(const BackBuffer* pBackBuffer) = 0;
	virtual bool Random() = 0;
	
	virtual void Delete(std::vector<Enemy*>::iterator& it) = 0;
	virtual void DeleteCollectible(std::vector<CollectibleInterface*>::iterator& it) = 0;
	virtual void DeleteEverything() = 0;

	virtual std::vector<Enemy*>& GetEnemyList() = 0;
	virtual std::vector<CollectibleInterface*>& GetCollectibleList() = 0;
};
