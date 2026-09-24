#pragma once

#include <raylib.h>
#include <array>

#include "Constants.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"

/**
 * NAMESPACE CollisionHandler
 * --
 * Handles collisions STRICTLY between a paddle and a ball in a game of Pong.
 *
 */
namespace CollisionHandler
{
    void ResolveCollisions(Ball& ball, const std::array<Paddle, PADDLE_COUNT>& paddles);
}
