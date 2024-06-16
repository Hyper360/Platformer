#pragma once
#include "raylib.h"


struct Platform : public Rectangle{
    bool wall = false;
    bool ceiling = false;
    bool ground = false;
    Platform(Rectangle rect);
};