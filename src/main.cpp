// Dependencies
#include <raylib.h>

// Own includes
#include "World.hpp"
#include "Constants.hpp"

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
     *  VARIABLE INITIALIZATIONS
     */
    World game;

    /**
     * MAIN GAME LOOP
     */
    while (!WindowShouldClose())
    {
        /**
         * PROCESS
         */
        deltaTime = GetFrameTime();
        game.Update(deltaTime);


        /**
         * DRAWING
         */
        BeginDrawing();
        ClearBackground(BLACK);

        DrawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, WHITE);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
