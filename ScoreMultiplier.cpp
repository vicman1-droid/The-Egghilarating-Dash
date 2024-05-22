#include "ScoreMultiplier.h"

ScoreMultiplier::ScoreMultiplier(const BackBuffer* pBackBuffer,int& x)
{
	m_pSprite = new Sprite("data/egg.bmp", RGB(184, 61, 186));
	m_pSprite->setBackBuffer(pBackBuffer);

	this->x = &x;
}

Vec2& ScoreMultiplier::Position()
{
	return m_pSprite->mPosition;
}

void ScoreMultiplier::doEvent()
{
	*x *= multiplyFactor;
}


bool ScoreMultiplier::amIColliding(Sprite* otherSprite)
{
	if (this->m_pSprite->mPosition.x + this->m_pSprite->width() >= otherSprite->mPosition.x &&
		this->m_pSprite->mPosition.x <= otherSprite->width() + otherSprite->mPosition.x &&
		this->m_pSprite->mPosition.y + this->m_pSprite->height() >= otherSprite->mPosition.y &&
		this->m_pSprite->mPosition.y <= otherSprite->height() + otherSprite->mPosition.y
		)
	{
		return true;
	}
	else return false;
}

void ScoreMultiplier::Draw()
{
	m_pSprite->draw();
}