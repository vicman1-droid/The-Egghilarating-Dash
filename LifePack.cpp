#include "LifePack.h"

LifePack::LifePack(const BackBuffer* pBackBuffer,CPlayer* &m_pPlayer)
{
	m_pSprite = new Sprite("data/heart.bmp", RGB(184, 61, 186));
	m_pSprite->setBackBuffer(pBackBuffer);

	this->m_pPlayer = m_pPlayer;
}

void LifePack::doEvent()
{
	m_pPlayer->Heal();
}

Vec2& LifePack::Position()
{
	return m_pSprite->mPosition;
}

bool LifePack::amIColliding(Sprite* otherSprite)
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

void LifePack::Draw()
{
	m_pSprite->draw();
}