#include "Paddle.hpp"
#include "Constants.hpp"

#include <algorithm>

Paddle::Paddle(Vector2 position_, KeyboardKey up, KeyboardKey down)
:   position(position_), upKey(up), downKey(down)
{
}

Vector2 Paddle::GetPosition()const
{
    return position;
}

Vector2 Paddle::GetDimensions()const
{
    return dimensions;
}

float Paddle::GetVelocityY()const
{
    return velocityY;
}


void Paddle::Update(float deltaTime)
{
    const float oldY{ position.y };

    // INPUT HANDLING
    if (IsKeyDown(upKey) && position.y >= 0)
    {
        position.y = std::max(0.0f, position.y - PADDLE_SPEED * deltaTime);
    }
    if (IsKeyDown(downKey) && position.y <= WINDOW_HEIGHT - dimensions.y)
    {
        position.y = std::min(position.y + PADDLE_SPEED * deltaTime, WINDOW_HEIGHT - dimensions.y);
    }

    // Guard against a zero frame time (first frame)
    velocityY = (deltaTime > 0.0f) ? (position.y - oldY) / deltaTime : 0.0f;
}

void Paddle::UpdateAI(float deltaTime, const Ball& ball)
{
    const float oldY{ position.y };

    // Slow movement
    if (position.y + dimensions.y / 2 > ball.center.y)
    {
        position.y = std::max(0.0f, position.y - PADDLE_SPEED * deltaTime / 2);
    }
    else if (position.y + dimensions.y / 2 < ball.center.y)
    {
        position.y = std::min(position.y + PADDLE_SPEED * deltaTime / 2, WINDOW_HEIGHT - dimensions.y);
    }

    // Teleport
    if (ball.velocity.x > 0 && position.x - ball.center.x < 150)
    {
        position.y = ball.center.y - dimensions.y / 2;
    }

    // Teleports show up as huge speeds here, which means maximum spin
    velocityY = (deltaTime > 0.0f) ? (position.y - oldY) / deltaTime : 0.0f;
}

void Paddle::Draw()const
{
    DrawRectangle(position.x, position.y, dimensions.x, dimensions.y, WHITE);
}

float Paddle::GetPaddleHeight()
{
    return PADDLE_HEIGHT;
}
float Paddle::GetPaddleWidth()
{
    return PADDLE_WIDTH;
}
