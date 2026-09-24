#include "World.hpp"
#include "CollisionHandler.hpp"
#include "Constants.hpp"

World::World()
:   ball{ Vector2{ WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f } },
    paddles{ Paddle{ Vector2{ WINDOW_WIDTH / 8.0f, (WINDOW_HEIGHT - Paddle::GetPaddleHeight()) / 2.0f }, KEY_W, KEY_S } ,
             Paddle{ Vector2{ WINDOW_WIDTH - WINDOW_WIDTH / 8.0f - Paddle::GetPaddleWidth(), (WINDOW_HEIGHT - Paddle::GetPaddleHeight()) / 2.0f }, KEY_UP, KEY_DOWN } }
{
}

void World::Update(float deltaTime)
{
    for (Paddle& paddle : paddles)
        { paddle.Update(deltaTime); }

    ball.Update(deltaTime);
    CollisionHandler::ResolveCollisions(ball, paddles);
}

void World::Draw()const
{
    paddles[LEFT].Draw();
    paddles[RIGHT].Draw();
    ball.Draw();
}
