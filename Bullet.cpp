#include "Bullet.h"


Bullet::Bullet(BackBuffer* pBackBuffer)
{
	//m_pSprite = new Sprite("data/planeimg.bmp", "data/planemask.bmp");
	m_pSprite = new Sprite("data/bulletandmask.bmp", RGB(184, 61, 186));
	m_pSprite->setBackBuffer(pBackBuffer);
}

Bullet::~Bullet()
{
	delete m_pSprite;
}


void Bullet::Draw()
{
		m_pSprite->mPosition.y -= 3;
		m_pSprite->draw();
}

Vec2& Bullet::Position()
{
	return m_pSprite->mPosition;
}

Sprite* Bullet::Spr()
{
	return m_pSprite;
}

Vec2& Bullet::Velocity()
{
	return m_pSprite->mVelocity;
}