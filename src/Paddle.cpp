#include "Paddle.hpp"
#include "Constants.hpp"

Paddle::Paddle(Vector2 position_, Vector2 dimensions_, KeyboardKey up, KeyboardKey down)
:   position(position_), dimensions(dimensions_), upKey(up), downKey(down)
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
        position.y -= PADDLE_SPEED * deltaTime;
    }
    if (IsKeyDown(downKey) && position.y <= WINDOW_HEIGHT - dimensions.y)
    {
        position.y += PADDLE_SPEED * deltaTime;
    }
}


void Paddle::Draw()
{
    DrawRectangle(position.x, position.y, dimensions.x, dimensions.y, WHITE);
}
