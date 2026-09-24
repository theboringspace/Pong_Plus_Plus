#pragma once

#include <raylib.h>

/**
 * CLASS Paddle
 * --
 * Class implementation of a Paddle in the classic game of Pong.
 */
class Paddle
{
private:
    /**
     * MEMBERS
     */
    static constexpr float PADDLE_SPEED{500.0f};

    Vector2 position;
    Vector2 dimensions;

    KeyboardKey upKey;
    KeyboardKey downKey;
public:
    /**
     * CONSTRUCTOR Paddle
     * --
     * Takes in x,y position and width, height dimensions.
     */
    Paddle(Vector2 position_, Vector2 dimensions_, KeyboardKey up, KeyboardKey down);

    /**
     * FUNCTION GetPosition
     * --
     * x & y, respectively.
     */
    Vector2 GetPosition()const;

    /**
     * FUNCTION GetDimensions
     * --
     * Width & height, respectively.
     */
    Vector2 GetDimensions()const;

    /**
     * FUNCTION Update
     * --
     * Updates paddle members depending on events.
     */
    void Update(float deltaTime);

    /**
     * FUNCTION Draw
     * --
     * Draws the paddle on-screen.
     */
    void Draw();
};
