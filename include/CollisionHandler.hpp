#pragma once

#include <raylib.h>
#include <array>

#include "Constants.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"

/**
 * CLASS CollisionHandler
 * --
 * Handles collisions STRICTLY between a paddle and a ball in a game of Pong.
 *
 */
class CollisionHandler
{
public:
    /**
     * FUNCTION ResolveCollision
     * --
     * Resolves collision events.
     */
    static void ResolveCollision(Ball& ball, std::array<Paddle, MAX_PADDLES>& paddles);
};
