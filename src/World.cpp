#include "World.hpp"
#include "CollisionHandler.hpp"
#include "Constants.hpp"

World::World()
:   ball{ Vector2{ WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f } },
    paddles{ Paddle{ Vector2{ WINDOW_WIDTH / 9.0f, (WINDOW_HEIGHT - Paddle::GetPaddleHeight()) / 2.0f }, KEY_W, KEY_S } ,
             Paddle{ Vector2{ WINDOW_WIDTH - WINDOW_WIDTH / 9.0f - Paddle::GetPaddleWidth(), (WINDOW_HEIGHT - Paddle::GetPaddleHeight()) / 2.0f }, KEY_UP, KEY_DOWN } }
{
}

void World::Update(float deltaTime)
{
    for (Paddle& paddle : paddles)
        { paddle.Update(deltaTime); }
    Score();
    ball.Update(deltaTime);
    CollisionHandler::ResolveCollisions(ball, paddles);

}

void World::Draw()const
{
    paddles[LEFT].Draw();
    paddles[RIGHT].Draw();
    ball.Draw();

    DrawText(TextFormat("%d", leftScore), WINDOW_WIDTH / 4, WINDOW_HEIGHT / 10, 50, WHITE);
    DrawText(TextFormat("%d", rightScore), WINDOW_WIDTH - WINDOW_WIDTH / 4, WINDOW_HEIGHT / 10, 50, WHITE);
}

void World::Score()
{
    // Right bound : Win Condition
    if (ball.velocity.x > 0 && ball.center.x + ball.radius > WINDOW_WIDTH)
    {
        ball.velocity.x = -std::abs(ball.velocity.x);
        ball.center = Vector2{ WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f };
        ++leftScore;
    }
    // Left bound : Win Condition
    else if (ball.velocity.x < 0 && ball.center.x - ball.radius < 0)
    {
        ball.velocity.x = std::abs(ball.velocity.x);
        ball.center = Vector2{ WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f };
        ++rightScore;
    }
}
