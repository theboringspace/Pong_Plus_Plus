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

        // Left paddle: only bounce if the ball's center is still in front of the paddle's face
        if (index == LEFT && ball.center.x < currentPaddleRect.x + currentPaddleRect.width) { continue; }
        // Right paddle: same, mirrored
        if (index == RIGHT && ball.center.x > currentPaddleRect.x) { continue; }
        // No Collision, No problem.
       if (!CheckCollisionCircleRec(ball.center, ball.radius, currentPaddleRect)) { continue; }

        // Hits left paddle
        if (index == LEFT)
        {
            ball.velocity.x = std::abs(ball.velocity.x);
            ball.center.x   = currentPaddle.GetPosition().x + currentPaddle.GetDimensions().x + ball.radius;
        }
        // Hits right paddle
        else if (index == RIGHT)
        {
            ball.velocity.x = -std::abs(ball.velocity.x);
            ball.center.x   = currentPaddle.GetPosition().x - ball.radius;
        }
    }
}
