#include "Paddle.hpp"

Paddle::Paddle(Vector2 position_, Vector2 dimensions_)
:   position(position_), dimensions(dimensions_)
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


void Paddle::Update()
{
    // INPUT HANDLING
    if (IsKeyDown(KEY_UP))
    {
        position.y -= 5.0f;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        position.y += 5.0f;
    }
}   


void Paddle::Draw()
{
    DrawRectangle(position.x, position.y, dimensions.x, dimensions.y, WHITE);
}
