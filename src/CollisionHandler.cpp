#include "CollisionHandler.hpp"
#include <cstdlib>


void CollisionHandler::ResolveCollisions(Ball& ball, const std::array<Paddle, PADDLE_COUNT>& paddles)
{
    Rectangle currentPaddleRect{};

    for (size_t index{0}; index < paddles.size(); ++index)
    {
        const Paddle& currentPaddle{paddles.at(index)};
        currentPaddleRect = Rectangle{ currentPaddle.GetPosition().x, currentPaddle.GetPosition().y,
                                       currentPaddle.GetDimensions().x, currentPaddle.GetDimensions().y, };

       if (!CheckCollisionCircleRec(ball.center, ball.radius, currentPaddleRect)) { continue; }

        // Hits left paddle
        if (index == LEFT)
        {
            ball.velocity.x = std::abs(ball.velocity.x);
            ball.center.x   = currentPaddle.GetPosition().x + currentPaddle.GetDimensions().x + ball.radius;
        }
        // Hits right paddle
        else
        {
            ball.velocity.x = -std::abs(ball.velocity.x);
            ball.center.x   = currentPaddle.GetPosition().x - ball.radius;
        }
    }
}
