#include "CollisionHandler.hpp"
#include <cstdlib>


void CollisionHandler::ResolveCollisions(Ball& ball, const std::array<Paddle, MAX_PADDLES>& paddles)
{
    Rectangle currentPaddleRect{};

    for (size_t index{0}; index < paddles.size(); ++index)
    {
        const Paddle& currentPaddle{paddles.at(index)};
        currentPaddleRect = Rectangle{ paddles.at(index).GetPosition().x, paddles.at(index).GetPosition().y,
                                       paddles.at(index).GetDimensions().x, paddles.at(index).GetDimensions().y, };

       if (!CheckCollisionCircleRec(ball.center, ball.radius, currentPaddleRect)) { continue; }

        // Hits left paddle
        if (index == LEFT)
        {
            ball.velocity.x = std::abs(ball.velocity.x);
            ball.center.x   = paddles.at(index).GetPosition().x + paddles.at(index).GetDimensions().x + ball.radius;
        }
        // Hits right paddle
        else
        {
            ball.velocity.x = -std::abs(ball.velocity.x);
            ball.center.x   = paddles.at(index).GetPosition().x - ball.radius;
        }
    }
}
