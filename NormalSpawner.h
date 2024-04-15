#pragma once

#include <vector>

#include "../SpawnerControlInterface.h"
#include "Enemy.h"
#include <time.h>

class NormalSpawner : public SpawnerControlInterface
{
private:
	std::vector<Enemy*> enemyList;

public:

	NormalSpawner();

	void Spawn(const BackBuffer* pBackBuffer);
	
	bool Random();

	void Delete(std::vector<Enemy*>::iterator& it);

	std::vector<Enemy*>& GetEnemyList() { return enemyList; }

	bool CheckEntitiesWithinLimit();


};

