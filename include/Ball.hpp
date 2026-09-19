#pragma once

#include <raylib.h>
#include "Constants.hpp"

struct Ball
{
    // MEMBERS
    Vector2 center;
    float   radius;

    Vector2 velocity{ Vector2{-5, -5} };


    // FUNCTIONS
    Ball(Vector2 c, float r);

    void Update(float deltaTime);

    void AddToPosition(const Vector2& velocity_);

    void Draw();
};