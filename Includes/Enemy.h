#pragma once
#include "CPlayer.h"
#include "Vec2.h"
class Enemy
{
public:

	virtual bool amIColliding(Sprite* otherSprite) = 0;
	virtual void Draw() = 0;
	virtual Vec2& Position() = 0;
	virtual void Move() = 0;
};

