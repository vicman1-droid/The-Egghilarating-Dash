#pragma once
#include "Sprite.h"
class CollectibleInterface
{
public: 

	virtual void doEvent() = 0;
	virtual bool amIColliding(Sprite* otherSprite) = 0;
	virtual void Draw() = 0;
	virtual Vec2& Position() = 0;

};

