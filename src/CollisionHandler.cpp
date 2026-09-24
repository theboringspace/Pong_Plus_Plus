#include "CollisionHandler.hpp"
#include <cstdlib>


void CollisionHandler::ResolveCollisions(Ball& ball, std::array<Paddle, MAX_PADDLES>& paddles)
{
    for (size_t index{0}; index < paddles.size(); ++index)
    {
        bool colliding = CheckCollisionCircleRec(
                            ball.center, ball.radius,
                            Rectangle{ paddles[index].GetPosition().x,
                                       paddles[index].GetPosition().y,
                                       paddles[index].GetDimensions().x,
                                       paddles[index].GetDimensions().y, });

        if (colliding)
        {
            // Right bound
            if (ball.velocity.x < 0 && paddles[index].GetPosition().x - paddles[index].GetDimensions().x < ball.center.x - ball.radius)
            {
                ball.velocity.x = std::abs(ball.velocity.x);
                ball.center.x   = paddles[index].GetPosition().x + paddles[index].GetDimensions().x + ball.radius;
            }
            // Left bound
            else if (ball.velocity.x > 0 && paddles[index].GetPosition().x + paddles[index].GetDimensions().x > ball.center.x + ball.radius)
            {
                ball.velocity.x = -std::abs(ball.velocity.x);
                ball.center.x   = paddles[index].GetPosition().x - ball.radius;
            }
        }
    }
}
