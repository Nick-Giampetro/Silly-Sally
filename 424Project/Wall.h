#pragma once
#include "Entity.h"
class Wall :
    public Entity
{
public:
    Wall();
    Wall(int,int);

    char spriteData();
    void setSprite();
    void defineShape();
private:
    char wallSprite;
};

