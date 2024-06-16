#pragma once
#include "raylib.h"
#include <vector>
#include "Platform.h"
#include "QuadTree.h"
using namespace std;

class EntityManager{
    public:
    QuadTree quadTree = QuadTree(-1600, -1280, 3200, 2560);
    vector<Platform> platforms;
    EntityManager();
    void draw();
};