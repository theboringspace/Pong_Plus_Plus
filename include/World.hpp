#pragma once

#include <raylib.h>

#include <array>

#include "Ball.hpp"
#include "Constants.hpp"
#include "Paddle.hpp"

/**
 * CLASS World
 * --
 * Handles all elements of the game.
 */
class World
{
private:
    /**
     * MEMBERS
     */
    Ball ball;
    std::array<Paddle, PADDLE_COUNT> paddles;

public:


    /**
     * CONSTRUCTOR World
     * --
     * Constructs a ball, and two paddles.
     * Positions them too.
     */
    World();

    // Update the whole world
    void Update(float deltaTime);
    // Draw the whole world
    void Draw()const;

};
