#pragma once
#include "Platform.h"
#include "raylib.h"
#include <vector>
using namespace std;

class QuadTree{
    vector<Platform> quad;
    vector<QuadTree> tree;
    Rectangle area;
    public:
    QuadTree(float x, float y, float w, float h);
    void insert(Rectangle rect);
    Rectangle checkCollision(Rectangle rect);
    void split();
    void displayTree();
};