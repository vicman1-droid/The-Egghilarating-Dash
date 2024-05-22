#pragma once

#include "Vec2.h"
#include "Sprite.h"
#include "BackBuffer.h"

class Bullet
{
private:
	Sprite* m_pSprite;

public:
	Bullet(BackBuffer* pBackBuffer);
	~Bullet();

	void Draw();

	Vec2& Position();

	Sprite* Spr();

	Vec2& Velocity();
};

