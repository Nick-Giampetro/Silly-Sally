#pragma once
#include "Entity.h"
class Wall :
    public Entity
{
public:
    //default wall
    Wall();

    //here just because
    ~Wall();

    //allows for wall settings to be changed by user or game engine
    Wall(int,int, char);

    //
    bool isLocatedAt(int, int);
    char spriteData(int, int);
    void setSprite(char);
    void setSprite();
    void defineShape();
private:
    char wallSprite[frameSize];
    int imgPos[frameSize][2];
};

