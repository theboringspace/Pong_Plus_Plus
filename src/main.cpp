// Dependencies
#include <raylib.h>

// Own includes
#include "World.hpp"
#include "Constants.hpp"
#include "Button.hpp"

/**
 * MAIN
 */
int main()
{
    /**
     * WINDOW INITIALIZATIONS
     */
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong++");
    SetTargetFPS(120);
    float deltaTime{};

    /**
     *  VARIABLE INITIALIZATIONS
     */
    World game;
    Button testButton(WINDOW_WIDTH / 4.0f, WINDOW_HEIGHT / 2.0f, 500, 100, "Single Player", 40);

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

        testButton.Draw();
        // DrawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT, WHITE);
        // game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
