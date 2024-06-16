#include "QuadTree.h"
#include <stdio.h>

QuadTree::QuadTree(float x, float y, float w, float h){
    area = (Rectangle){x, y, w, h};
}

void QuadTree::insert(Rectangle rect){
    if (CheckCollisionRecs(area, rect)){
        if (quad.size() < 4) quad.push_back(rect);
        else{
            if (tree.size() != 0){
                for (QuadTree &qt : tree){
                    qt.insert(rect);
                }
            }
            else{
                split();
                for (QuadTree &qt : tree){
                    qt.insert(rect);
                }
            }
        }
    }
}

Rectangle QuadTree::checkCollision(Rectangle rect){
    if (CheckCollisionRecs(area, rect)){
        if (tree.size() > 0){
            for (QuadTree qt : tree){
                Rectangle temp = qt.checkCollision(rect);
                if (temp.width > 0) return temp;
            }
            return {0.0f, 0.0f, -1.0f, -1.0f};
        }
        else{
            for (Rectangle &quadRect : quad){
                if (CheckCollisionRecs(quadRect, rect)) return quadRect;
            }
            return {0.0f, 0.0f, -1.0f, -1.0f};
        }
    }
    return {0.0f, 0.0f, -1.0f, -1.0f};
}

void QuadTree::split(){
    if (tree.size() == 0){
        QuadTree qt1 = QuadTree(area.x, area.y, area.width/2, area.height/2);
        QuadTree qt2 = QuadTree(area.x+(area.width/2), area.y, area.width/2, area.height/2);
        QuadTree qt3 = QuadTree(area.x, area.y+(area.height/2), area.width/2, area.height/2);
        QuadTree qt4 = QuadTree(area.x+(area.width/2), area.y+(area.height/2), area.width/2, area.height/2);

        tree.push_back(qt1);
        tree.push_back(qt2);
        tree.push_back(qt3);
        tree.push_back(qt4);

        for (QuadTree &qt : tree){
            for (Platform p : quad){
                qt.insert(p);
            }
        }
        quad.empty();
    }
}

void QuadTree::displayTree(){
    DrawRectangleLinesEx(area, 5, (Color){255, 0, 0, 100});
    if (tree.size() == 0){
        char str[1];
        sprintf(str, "%d", quad.size());
        DrawText(str, area.x, area.y, 32, BLACK);
    }
    for (QuadTree qt : tree){
        qt.displayTree();
    }
}