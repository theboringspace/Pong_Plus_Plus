#pragma once

#include <raylib.h>

#include "Ball.hpp"

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
    static constexpr float PADDLE_HEIGHT{200};
    static constexpr float PADDLE_WIDTH{25};

    Vector2 position;
    Vector2 dimensions{PADDLE_WIDTH, PADDLE_HEIGHT};

    // How fast the paddle moved vertically last frame (used for spin)
    float velocityY{0.0f};

    KeyboardKey upKey;
    KeyboardKey downKey;
public:
    /**
     * CONSTRUCTOR Paddle
     * --
     * Takes in x,y position and width, height dimensions.
     */
    Paddle(Vector2 position_, KeyboardKey up, KeyboardKey down);

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
     * FUNCTION GetVelocityY
     * --
     * Vertical speed from last frame. Positive is down.
     */
    float GetVelocityY()const;

    /**
     * FUNCTION Update
     * --
     * Updates paddle members depending on events.
     */
    void Update(float deltaTime);

    /**
     * FUNCTION UpdateAI
     * --
     * Computer-controlled movement. Watches the ball instead of the keyboard.
     */
    void UpdateAI(float deltaTime, const Ball& ball);

    /**
     * FUNCTION Draw
     * --
     * Draws the paddle on-screen.
     */
    void Draw()const;

    /**
     * FUNCTIONS GetPaddleHeight & GetPaddleWidth
     * --
     * Getters for paddle dimensions
     */
    static float GetPaddleHeight();
    static float GetPaddleWidth();
};
