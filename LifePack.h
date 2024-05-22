#pragma once
#include "CollectibleInterface.h"
#include "CPlayer.h"
class LifePack : public CollectibleInterface
{
private:
	Sprite* m_pSprite;
	CPlayer* m_pPlayer;
	int* x;

public: 
	
	LifePack(const BackBuffer* pBackBuffer,CPlayer* &m_pPlayer);
	
	virtual void doEvent();

	Vec2& Position();
	
	bool amIColliding(Sprite* otherSprite);
	
	void Draw();
};

