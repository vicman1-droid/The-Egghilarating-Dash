#pragma once
#include "Enemy.h"


class Car : public Enemy
{
private:
    DIRECTION currentDirection;
    Sprite* m_pSprite;

public:
    Car(const BackBuffer* pBackBuffer, DIRECTION direction);
    Car(const BackBuffer* pBackBuffer, Vec2 location,DIRECTION direction);


    Vec2& Position();
    bool amIColliding(Sprite* otherSpriter);
    void Draw();
    void Move();

};


