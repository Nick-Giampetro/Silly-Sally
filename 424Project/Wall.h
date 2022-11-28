#pragma once
#include "Entity.h"
class Wall :
    public Entity
{
    static const int framesize = 100;
public:
    Wall();
    ~Wall();
    Wall(int,int);

    bool isLocatedAt(int, int);
    char spriteData(int, int);
    void setSprite();
    void defineShape();
private:
    char wallSprite[framesize];
    int imgPos[framesize][2];
};

