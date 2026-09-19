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
    Vector2 position;
    Vector2 dimensions;

public:
    /**
     * CONSTRUCTOR Paddle
     * --
     * Takes in x,y position and width, height dimensions.
     */
    Paddle(Vector2 position_, Vector2 dimensions_);

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
    void Update();

    /**
     * FUNCTION Draw
     * --
     * Draws the paddle on-screen.
     */
    void Draw();
};
