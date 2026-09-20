#pragma once

#include <raylib.h>
#include <array>

#include "Paddle.hpp"
#include "Ball.hpp"

/**
 * CLASS CollisionHandler
 * --
 * Handles collisions STRICTLY between a paddle and a ball in a game of Pong.
 *
 * This class does not inherently hold any ball or paddle objects, but it can
 * point to already existing paddle and ball objects.
 */
class CollisionHandler
{
private:
    /**
     * MEMBERS
     */
    std::array<Paddle*, 2>* paddles;
    Ball* ball;
public:
    /**
     * FUNCTIONS
     */

    /**
     * CONSTRUCTOR CollisionHandler
     * --
     * A collision handler handles 2 paddles' and 1 ball's collision events.
     */
    CollisionHandler(std::array<Paddle*, 2>* paddles_, Ball* ball);

    /**
     * FUNCTION Update
     * --
     * Updates collision events.
     */
    void Update(float deltaTime);

    /**
     * FUNCTION Draw
     * --
     * Draws updates on-screen.
     */
    void Draw();
};
