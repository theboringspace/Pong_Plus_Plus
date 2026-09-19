// Dependencies
#include <raylib.h>

// Own includes
#include "Ball.hpp"
#include "Paddle.hpp"
#include "CollisionHandler.hpp"

/**
 * MAIN
 */
int main()
{



    /**
     * WINDOW INITIALIZATIONS
     */
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong++");
    SetTargetFPS(60);
    float deltaTime{};

    /**
     * TESTING DECLARATIONS
     */
    const int PADDLE_WIDTH{20};
    const int PADDLE_HEIGHT{300};


    Ball ball(Vector2{WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0}, 25);
    Paddle paddle1(Vector2{WINDOW_WIDTH / 8.0, WINDOW_HEIGHT / 2.0}, Vector2{PADDLE_WIDTH, PADDLE_HEIGHT});
    Paddle paddle2(Vector2{WINDOW_WIDTH - WINDOW_WIDTH / 8.0, WINDOW_HEIGHT / 2.0}, Vector2{PADDLE_WIDTH, PADDLE_HEIGHT});


    CollisionHandler collisioner(&paddle1, &paddle2, &ball);
    /**
     * END TESTING
     */

    /**
     * MAIN GAME LOOP
     */
    while (!WindowShouldClose())
    {
        /**
         * PROCESS
         */
        deltaTime = GetFrameTime();

        collisioner.Update(deltaTime);

        /**
         * DRAWING
         */
        BeginDrawing();
        ClearBackground(BLACK);

        DrawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, WHITE);

        /**
         * TESTING STUFF
         */
        collisioner.Draw();
        /**
         * END TESTING
         */

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
