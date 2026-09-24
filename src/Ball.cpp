#include "Ball.hpp"
#include "Constants.hpp"

Ball::Ball(Vector2 c)
:   center(c)
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
        // Bottom bound
        if (velocity.y > 0 && center.y + radius > WINDOW_HEIGHT)
        {
            velocity = Vector2{velocity.x, velocity.y * -1};

            center = Vector2{center.x, WINDOW_HEIGHT - radius};
        }
        // Top bound
        else if (velocity.y < 0 && center.y - radius < 0)
        {
            velocity = Vector2{velocity.x, velocity.y * -1};

            center = Vector2{center.x, radius};
        }
        // Right bound
        else if (velocity.x > 0 && center.x + radius > WINDOW_WIDTH)
        {
            velocity = Vector2{velocity.x * -1, velocity.y};

            center = Vector2{WINDOW_WIDTH - radius, center.y};
        }
        // Left bound
        else if (velocity.x < 0 && center.x - radius < 0)
        {
            velocity = Vector2{velocity.x * -1, velocity.y};

            center = Vector2{radius, center.y};
        }

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
