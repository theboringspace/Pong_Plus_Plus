#include "CollisionHandler.hpp"
#include <cstdlib>

CollisionHandler::CollisionHandler(Paddle* paddle1, Paddle* paddle2, Ball* ball_)
{
    ball = ball_;
    paddles.at(0) = paddle1;
    paddles.at(1) = paddle2;
}

void CollisionHandler::Update(float deltaTime)
{
    for (size_t index{0}; index < paddles.size(); ++index)
    {
        bool colliding = CheckCollisionCircleRec(ball->center, ball->radius,
                        Rectangle{  paddles.at(index)->GetPosition().x,
                                    paddles.at(index)->GetPosition().y,
                                    paddles.at(index)->GetDimensions().x,
                                    paddles.at(index)->GetDimensions().y,
                                    });

        ball->Update(deltaTime);
        paddles.at(0)->Update();
        paddles.at(1)->Update();


        if (colliding)
        {
            Ball temp{*ball};

            ball->velocity = Vector2{0, 0};

            // Right bound
            if (temp.velocity.x < 0 &&
                paddles.at(index)->GetPosition().x - paddles.at(index)->GetDimensions().x < temp.center.x - temp.radius)
            {
                temp.velocity.x *= -1;
            }
            // Left bound
            else if (temp.velocity.x > 0 &&
                paddles.at(index)->GetPosition().x + paddles.at(index)->GetDimensions().x > temp.center.x + temp.radius)
            {
                temp.velocity.x *= -1;
            }

            ball->velocity = temp.velocity;
        }
    }
}

void CollisionHandler::Draw()
{
    ball->Draw();
    paddles.at(0)->Draw();
    paddles.at(1)->Draw();
}
