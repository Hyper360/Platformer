#include "Player.h"
#include <iostream>

Player::Player(Rectangle rectangle){
    rect = rectangle;
}

void Player::checkKeyPressed(){
    if (IsKeyDown(KEY_A)){
        xspeed = -5.0f;
    }
    else if (IsKeyDown(KEY_D)){
        xspeed = 5.0f;
    }
    else{
        xspeed = 0.0f;
    }
    if(IsKeyDown(KEY_W) and canJump){
        yspeed = -16.0f;
        canJump = false;
    }
    else if(IsKeyDown(KEY_S)){
        yspeed = 16.0f;
        canJump = false;
    }
}

void Player::update(QuadTree quad){
    checkKeyPressed();
    rect.y += yspeed;
    yspeed += 0.5;
    

    // Handling x and y collisions seperately
    Rectangle temp = quad.checkCollision(rect);
    if (temp.width > 0){
        if (yspeed < 0){
            rect.y = temp.y + temp.height;
        }
        if (yspeed > 0){
            rect.y = temp.y - rect.height;
            canJump = true;
        }
        yspeed = 0;
    }

    rect.x += xspeed;

    temp = quad.checkCollision(rect);
    if (temp.width > 0){
        if (xspeed > 0){
            rect.x = temp.x - rect.width;
        }
        else if (xspeed < 0){
            rect.x = temp.x + temp.width;
        }
        xspeed = 0;
    }
}

void Player::draw(){
    DrawRectangleRec(rect, RED);
}