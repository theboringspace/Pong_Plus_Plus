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


void Paddle::Update(float deltaTime)
{
    // INPUT HANDLING
    if (IsKeyDown(upKey) && position.y >= 0)
    {
        position.y = std::max(0.0f, position.y - PADDLE_SPEED * deltaTime);
    }
    if (IsKeyDown(downKey) && position.y <= WINDOW_HEIGHT - dimensions.y)
    {
        position.y = std::min(position.y + PADDLE_SPEED * deltaTime, WINDOW_HEIGHT - dimensions.y);
    }
}


void Paddle::Draw()const
{
    DrawRectangle(position.x, position.y, dimensions.x, dimensions.y, WHITE);
}
