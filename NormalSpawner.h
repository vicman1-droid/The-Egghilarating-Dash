#pragma once

#include <vector>

#include "../SpawnerControlInterface.h"
#include "Enemy.h"
#include "CPlayer.h"
#include <time.h>

#include <thread>
#include <chrono>

class NormalSpawner : public SpawnerControlInterface
{
private:
	std::vector<Enemy*> enemyList;
	std::vector<CollectibleInterface*> collectibleList;
	

	CPlayer* m_pPlayer;
	int *score;
	int *invulnerable;

public:

	NormalSpawner(CPlayer* m_pPlayer, int *score, int* invulnerable);

	void Spawn(const BackBuffer* pBackBuffer);
	virtual	void SpawnCollectible(const BackBuffer* pBackBuffer);

	
	bool Random();

	void Delete(std::vector<Enemy*>::iterator& it);
	void DeleteCollectible(std::vector<CollectibleInterface*>::iterator& it);
	void DeleteEverything();

	std::vector<Enemy*>& GetEnemyList() { return enemyList; };
	std::vector<CollectibleInterface*>& GetCollectibleList() { return collectibleList; };

	bool CheckEntitiesWithinLimit();
	virtual bool CheckCollectiblesWithinLimit();


};

