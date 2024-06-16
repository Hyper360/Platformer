#include "Platform.h"

Platform::Platform(Rectangle rect){
    this->x = rect.x;
    this->y = rect.y;
    this->width = rect.width;
    this->height = rect.height;
}