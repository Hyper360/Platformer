#include "EntityManager.h"

EntityManager::EntityManager(){
    for (int i = 0; i < 700; i++){
        Platform temp = Platform({GetRandomValue(-1600, 1600), GetRandomValue(-1280, 1280), GetRandomValue(20, 50), GetRandomValue(20, 50)});
        platforms.push_back(temp);
    }
    for (Platform &p : platforms){
        quadTree.insert(p);
    }
}

void EntityManager::draw(){
    for (int i = 0; i < platforms.size(); ++i){
        DrawRectangleRec(platforms[i], PURPLE);
    }
    quadTree.displayTree();
}