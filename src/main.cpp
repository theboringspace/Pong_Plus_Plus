// Dependencies
#include <raylib.h>

// Own includes
#include "World.hpp"
#include "Constants.hpp"
#include "Button.hpp"
#include "MenuHandler.hpp"

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

    /**
     *  VARIABLE INITIALIZATIONS
     */
    World game;

    /**
     * MAIN GAME LOOP
     */
    while (!WindowShouldClose())
    {
        switch(MenuHandler::state)
        {
        case MenuHandler::GameState::MENU :
            BeginDrawing();
            MenuHandler::StartMenu();
            EndDrawing();
            break;
        case MenuHandler::GameState::SINGLE_PLAYER :
            break;
        case MenuHandler::GameState::TWO_PLAYER :
            while (true)
            {
                const float deltaTime{ GetFrameTime() };
                // PROCESS
                game.Update(deltaTime);

                // DRAW
                BeginDrawing();
                ClearBackground(BLACK);
                game.Draw();
                EndDrawing();
            }
            break;
        case MenuHandler::GameState::SETTINGS :
            break;
        }
    }

    CloseWindow();

    return 0;
}
