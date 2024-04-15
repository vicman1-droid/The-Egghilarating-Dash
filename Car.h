#pragma once
#include "Enemy.h"


enum DIRECTION
{
    DIR_LEFT = 0,
    DIR_RIGHT = 1,
};

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


