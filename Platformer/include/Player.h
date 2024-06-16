#pragma once
#include "raylib.h"
#include "EntityManager.h"
#include <vector>

class Player{
    bool onGround = false;
    bool canJump = true;
    bool falling = false;
    float yspeed = 0.0f;
    float xspeed = 5.0f;
    public:
    Rectangle rect;
    Player(Rectangle rectangle);
    void update(QuadTree quadTree);
    void checkKeyPressed();
    void draw();
};