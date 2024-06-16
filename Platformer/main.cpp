#include "Game.h"

int main(){
    InitWindow(800, 640, "Platformer");
    Game game = Game(60);
    game.run();
}