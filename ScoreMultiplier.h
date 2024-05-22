#pragma once
#include "CollectibleInterface.h"
class ScoreMultiplier :
    public CollectibleInterface
{
private:
	Sprite* m_pSprite;
	int multiplyFactor = 2;
	int* x;

public:

	ScoreMultiplier(const BackBuffer* pBackBuffer,int &x);

	Vec2& Position();

	virtual void doEvent();

	bool amIColliding(Sprite* otherSprite);

	void Draw();

	int getMultFactor() { return this->multiplyFactor; };
};

