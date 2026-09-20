#include "Ball.hpp"

Ball::Ball(Vector2 c, float r)
:   center(c), radius(r)
{
}

void Ball::Update(float deltaTime)
{
    // Initializations
    bool hasHitWall{};

    // Regular Movement Update
    center.x += velocity.x * deltaTime;
    center.y += velocity.y * deltaTime;

    hasHitWall =    (velocity.y > 0 && center.y + radius > WINDOW_HEIGHT)   ||
                    (velocity.y < 0 && center.y - radius < 0)               ||
                    (velocity.x > 0 && center.x + radius > WINDOW_WIDTH)    ||
                    (velocity.x < 0 && center.x - radius < 0);

    if (hasHitWall)
    {
        Ball tempBall{*this};
        velocity = Vector2{0, 0};

        // Bottom bound
        if (tempBall.velocity.y > 0 && tempBall.center.y + radius > WINDOW_HEIGHT)
        {
            tempBall.velocity = Vector2{tempBall.velocity.x, tempBall.velocity.y * -1};

            center = Vector2{center.x, WINDOW_HEIGHT - radius};
        }
        // Top bound
        else if (tempBall.velocity.y < 0 && tempBall.center.y - radius < 0)
        {
            tempBall.velocity = Vector2{tempBall.velocity.x, tempBall.velocity.y * -1};

            center = Vector2{center.x, radius};
        }
        // Right bound
        else if (tempBall.velocity.x > 0 && tempBall.center.x + radius > WINDOW_WIDTH)
        {
            tempBall.velocity = Vector2{tempBall.velocity.x * -1, tempBall.velocity.y};

            center = Vector2{WINDOW_WIDTH - radius, center.y};
        }
        // Left bound
        else if (tempBall.velocity.x < 0 && tempBall.center.x - radius < 0)
        {
            tempBall.velocity = Vector2{tempBall.velocity.x * -1, tempBall.velocity.y};

            center = Vector2{radius, center.y};
        }

        velocity = tempBall.velocity;

        hasHitWall = false;
    }
}

void Ball::Draw()
{
    DrawCircle(center.x, center.y, radius, WHITE);
}

void Ball::AddToPosition(const Vector2& velocity_)
{
    center.x += velocity_.x;
    center.y += velocity_.y;
}
