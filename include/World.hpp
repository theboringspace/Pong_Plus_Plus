#pragma once

#include <raylib.h>

#include <array>

#include "Ball.hpp"
#include "Paddle.hpp"
#include "CollisionHandler.hpp"

class World
{
private:
    std::array<Paddle*, 2> paddles;
    Ball* ball;
    CollisionHandler collisioner;

public:
    World(Paddle* leftPaddle, Paddle* rightPaddle, Ball* ball_);

    void Update(float deltaTime);

    void Draw();
};
