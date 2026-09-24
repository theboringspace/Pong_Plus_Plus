#pragma once

#include <raylib.h>

#include <array>

#include "Ball.hpp"
#include "Constants.hpp"
#include "Paddle.hpp"

class World
{
private:

    Ball ball;
    std::array<Paddle, MAX_PADDLES> paddles;

public:
    enum { LEFT, RIGHT };

    World();
    void Update(float deltaTime);
    void Draw();

};
