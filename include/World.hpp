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

    static constexpr int WINNING_SCORE{5};

    int leftScore{0};
    int rightScore{0};

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

    void Score();

    // Put scores, ball, and paddles back to their starting state
    void Reset();

    bool IsOver()const;

    Side GetWinner()const;
};
