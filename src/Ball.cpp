#include "Ball.hpp"
#include "Constants.hpp"

Ball::Ball(Vector2 c)
:   center(c)
{
}

void Ball::Update(float deltaTime)
{
    // Regular Movement Update
    center.x += velocity.x * deltaTime;
    center.y += velocity.y * deltaTime;

    // Bottom bound
    if (velocity.y > 0 && center.y + radius > WINDOW_HEIGHT)
    {

        velocity.y = -std::abs(velocity.y);
    }
    // Top bound
    else if (velocity.y < 0 && center.y - radius < 0)
    {
        velocity.y = std::abs(velocity.y);

    }
}

void Ball::Draw()const
{
    DrawCircle(center.x, center.y, radius, WHITE);
}
