#include "CollisionHandler.hpp"
#include <cstdlib>

CollisionHandler::CollisionHandler(std::array<Paddle*, 2>* paddles_, Ball* ball_)
:   paddles(paddles_), ball(ball_)
{
}

void CollisionHandler::ResolveCollision()
{
    for (size_t index{0}; index < paddles->size(); ++index)
    {
        bool colliding = CheckCollisionCircleRec(
                            ball->center, ball->radius,
                            Rectangle{  paddles->at(index)->GetPosition().x,
                                        paddles->at(index)->GetPosition().y,
                                        paddles->at(index)->GetDimensions().x,
                                        paddles->at(index)->GetDimensions().y,
                                                });

        if (colliding)
        {
            // Right bound
            if (ball->velocity.x < 0 && paddles->at(index)->GetPosition().x - paddles->at(index)->GetDimensions().x < ball->center.x - ball->radius)
            {
                ball->velocity.x = std::abs(ball->velocity.x);
            }
            // Left bound
            else if (ball->velocity.x > 0 && paddles->at(index)->GetPosition().x + paddles->at(index)->GetDimensions().x > ball->center.x + ball->radius)
            {
                ball->velocity.x = -std::abs(ball->velocity.x);
            }
            // Top bound
            else if (ball->velocity.y < 0 && paddles->at(index)->GetPosition().y < ball->center.y + ball->radius)
            {
                ball->velocity.y = -std::abs(ball->velocity.y);
            }
            // Bottom bound
            else
            {
                ball->velocity.y = std::abs(ball->velocity.y);
            }
        }
    }
}

void CollisionHandler::Draw()
{
    ball->Draw();
    paddles->at(0)->Draw();
    paddles->at(1)->Draw();
}
