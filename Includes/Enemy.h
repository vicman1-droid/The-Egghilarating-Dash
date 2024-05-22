#pragma once
#include "CPlayer.h"
#include "Vec2.h"

enum DIRECTION
{
	DIR_LEFT = 0,
	DIR_RIGHT = 1,
};

class Enemy
{
public:

	virtual bool amIColliding(Sprite* otherSprite) = 0;
	virtual void Draw() = 0;
	virtual Vec2& Position() = 0;
	virtual void Move() = 0;
};

