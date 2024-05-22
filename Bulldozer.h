#pragma once
#include "Enemy.h"


class Bulldozer : public Enemy
{
private:
    DIRECTION currentDirection;
    Sprite* m_pSprite;

public:
    Bulldozer(const BackBuffer* pBackBuffer, DIRECTION direction);
    Bulldozer(const BackBuffer* pBackBuffer, Vec2 location, DIRECTION direction);


    Vec2& Position();
    bool amIColliding(Sprite* otherSpriter);
    void Draw();
    void Move();

};
