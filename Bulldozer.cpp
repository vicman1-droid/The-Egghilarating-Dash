#include "Bulldozer.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

Bulldozer::Bulldozer(const BackBuffer* pBackBuffer, Vec2 location, DIRECTION direction)
{
	currentDirection = direction;


	if (currentDirection == DIR_LEFT)
	{
		m_pSprite = new Sprite("data/BulldozerLeft.bmp", RGB(184, 61, 186));
		m_pSprite->setBackBuffer(pBackBuffer);
	}
	else
	{
		m_pSprite = new Sprite("data/BulldozerRight.bmp", RGB(184, 61, 186));
		m_pSprite->setBackBuffer(pBackBuffer);
	}

	m_pSprite->mPosition = location;


	currentDirection = direction;
}

Bulldozer::Bulldozer(const BackBuffer* pBackBuffer, DIRECTION direction)
{

	currentDirection = direction;

	if (currentDirection == DIR_LEFT)
	{
		m_pSprite = new Sprite("data/BulldozerLeft.bmp", RGB(184, 61, 186));
		m_pSprite->setBackBuffer(pBackBuffer);

	}
	else
	{
		m_pSprite = new Sprite("data/BulldozerRight.bmp", RGB(184, 61, 186));
		m_pSprite->setBackBuffer(pBackBuffer);
	}

}

Vec2& Bulldozer::Position()
{
	return m_pSprite->mPosition;
}

bool Bulldozer::amIColliding(Sprite* otherSprite)
{
	
	if (this->m_pSprite->mPosition.x + this->m_pSprite->width()/2 >= otherSprite->mPosition.x &&
		this->m_pSprite->mPosition.x <= (otherSprite->width() * 4 - 10) + otherSprite->mPosition.x &&
		this->m_pSprite->mPosition.y + (this->m_pSprite->height() / 2 - 10) >= otherSprite->mPosition.y &&
		this->m_pSprite->mPosition.y <= otherSprite->height() + otherSprite->mPosition.y
		)
	{
		return true;
	}
	else return false;

	/*
	// collision x-axis?
	bool collisionX = this->m_pSprite->mPosition.x + this->m_pSprite->width() >= otherSprite->mPosition.x &&
		otherSprite->mPosition.x + otherSprite->width() >= this->m_pSprite->mPosition.x;
	// collision y-axis?
	bool collisionY = this->m_pSprite->mPosition.y + this->m_pSprite->height() >= otherSprite->mPosition.y &&
		otherSprite->mPosition.y + otherSprite->height() >= this->m_pSprite->mPosition.y;
	// collision only if on both axes
	return collisionX && collisionY;*/

	/*
	int aleft, aright, abottom, atop;
	int bleft, bright, bbottom, btop;
	int left, right, bottom, top;
	int columns, rows;

	aleft = m_pSprite->mPosition.x; aright = aleft + this->m_pSprite->width() - 1;
	abottom = m_pSprite->mPosition.y; atop = abottom + this->m_pSprite->height() - 1;

	bleft = otherSprite->mPosition.x; bright = bleft + otherSprite->width() - 1;
	bbottom =otherSprite->mPosition.y; btop = bbottom + otherSprite->height() - 1;

	if (aleft > bright || aright < bleft || abottom > btop || atop < bbottom)
		return false; // Collision box areas do not overlap

	// Bounding box of overlap of two masks
	left = MAX(aleft, bleft);
	right = MIN(aright, bright);
	bottom = MAX(abottom, bbottom);
	top = MIN(atop, btop);
	columns = right - left + 1;
	rows = top - bottom + 1;

	aleft = left - aleft;
	abottom = bottom - abottom;

	bleft = left - bleft;
	bbottom = bottom - bbottom;




	for (int y = 0; y < rows; ++y) {
		for (int x = 0; x < columns; ++x) {
			if (a.p[(aleft + x) + (abottom + y) * a.w] &&
				b.p[(bleft + x) + (bbottom + y) * b.w])
				return true;
		}
	}


	*/
	return false;
}


void Bulldozer::Draw()
{
	Bulldozer::Move();
	m_pSprite->draw();
}

void Bulldozer::Move()
{
	if (currentDirection == DIR_LEFT)
		m_pSprite->mPosition.x -= 0.1;
	if (currentDirection == DIR_RIGHT)
		m_pSprite->mPosition.x += 0.1;
}