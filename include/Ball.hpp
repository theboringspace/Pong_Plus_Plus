#pragma once

#include <raylib.h>
#include "Constants.hpp"

/**
 * STRUCT Ball
 * --
 * This struct's purpose is to be the ball in the classic game of Pong.
 */
struct Ball
{
    /**
     * MEMBERS
     */
    Vector2 center;
    float   radius;

    Vector2 velocity{ Vector2{-5, -5} };


    /**
     * FUNCTIONS
     */

    // Constructor
    Ball(Vector2 c, float r);

    // Object Update Function
    void Update(float deltaTime);

    // Object Main Function
    void Draw();

    // Helper Function
    void AddToPosition(const Vector2& velocity_);
};
