#include "World.hpp"

World::World(Paddle* leftPaddle, Paddle* rightPaddle, Ball* ball_)
:   ball(ball_), collisioner(&paddles, ball_)
{
    paddles.at(0) = leftPaddle;
    paddles.at(1) = rightPaddle;
}

void World::Update(float deltaTime)
{
    collisioner.Update(deltaTime);
    paddles.at(0)->Update();
    paddles.at(1)->Update();
    ball->Update(deltaTime);
}

void World::Draw()
{
    paddles.at(0)->Draw();
    paddles.at(1)->Draw();
    ball->Draw();
}
