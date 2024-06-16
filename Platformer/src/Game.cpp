#include "Game.h"
#include "Player.h"
#include "EntityManager.h"

Game::Game(int fps){
    SetTargetFPS(fps);
    SetRandomSeed(GetTime());
}

void Game::run(){
    Player p = Player({400, -1300, 25, 25});
    Camera2D cam = {0};
    cam.target = {p.rect.x, p.rect.y};
    cam.offset = {0.0f+GetScreenWidth()/2, 0.0f+GetScreenHeight()/2};
    cam.rotation = 0.0f;
    cam.zoom = 0.5f;
    EntityManager eM = EntityManager();
    while (!WindowShouldClose()){
        p.update(eM.quadTree);
        cam.target = {p.rect.x, p.rect.y};
        BeginDrawing();
        ClearBackground(WHITE);
        
        BeginMode2D(cam);
        // Camera Drawing goes here
        p.draw();
        eM.draw();
        EndMode2D();

        //non relative game drawing goes here
        DrawFPS(0, 0);
        EndDrawing();
    }
    CloseWindow();
}