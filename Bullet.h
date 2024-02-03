#pragma once
#include"Struct.h"
class Bullet {

public:
    Vector2 pos_;
    Vector2 speed_;
    float width;
    float height;
    bool isShot;
    Bullet();
    void Initalize();
    void Update();
    void Draw();
};
