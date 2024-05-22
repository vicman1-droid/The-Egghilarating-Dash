#pragma once
#include "Enemy.h"
class Truck : public Enemy
{
private:
    DIRECTION currentDirection;
    Sprite* m_pSprite;

public:
    Truck(const BackBuffer* pBackBuffer, DIRECTION direction);
    Truck(const BackBuffer* pBackBuffer, Vec2 location, DIRECTION direction);


    Vec2& Position();
    bool amIColliding(Sprite* otherSpriter);
    void Draw();
    void Move();

};

