#pragma once
#include "Entity.h"
class Wall :
    public Entity
{
public:
    Wall();
    ~Wall();
    Wall(int,int);

    char spriteData(int, int);
    void setSprite();
    void defineShape();

};

