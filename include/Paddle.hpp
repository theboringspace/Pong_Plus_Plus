#pragma once

#include <raylib.h>

class Paddle
{
private:
    Vector2 position;
    Vector2 dimensions;

public:
    Paddle(Vector2 position_, Vector2 dimensions_);

    Vector2 GetPosition()const;

    Vector2 GetDimensions()const;

    void Update();

    void Draw();
};