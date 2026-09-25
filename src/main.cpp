// Dependencies
#include <raylib.h>

// Own includes
#include "World.hpp"
#include "Constants.hpp"
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
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    /**
     *  VARIABLE INITIALIZATIONS
     */
    World game;

    /**
     * MAIN GAME LOOP
     */
    while (!WindowShouldClose() && MenuHandler::state != MenuHandler::QUIT)
    {
        switch(MenuHandler::state)
        {
        case MenuHandler::MENU :
            BeginDrawing();
            ClearBackground(BLACK);
            MenuHandler::StartMenu(game);
            EndDrawing();
            break;
        case MenuHandler::SINGLE_PLAYER :

            break;
        case MenuHandler::TWO_PLAYER :
        {
            const float deltaTime{ GetFrameTime() };
            // PROCESS
            game.Update(deltaTime);

            // DRAW
            BeginDrawing();
            ClearBackground(BLACK);
            game.Draw();
            EndDrawing();

            if (IsKeyPressed(KEY_ESCAPE))
            {
                MenuHandler::state = MenuHandler::MENU;
            }

            if (game.IsOver())
            {
                MenuHandler::state = MenuHandler::GAME_OVER;
            }

            break;
        }

        case MenuHandler::GAME_OVER :
        {
            BeginDrawing();
            ClearBackground(BLACK);
            game.Draw();
            if (game.GetWinner() == LEFT)
            {
                DrawText("PLAYER 1 WINS!", (WINDOW_WIDTH - MeasureText("PLAYER 1 WINS!", 150)) / 2, WINDOW_HEIGHT / 7.0f, 150, WHITE);
            }
            else
            {
                DrawText("PLAYER 2 WINS!", (WINDOW_WIDTH - MeasureText("PLAYER 2 WINS!", 150)) / 2, WINDOW_HEIGHT / 7.0f, 150, WHITE);
            }
            DrawText("Press Enter to Return to Menu...", (WINDOW_WIDTH - MeasureText("Press Enter to Return to Menu...", 50)) / 2, WINDOW_HEIGHT / 2.0f + 200, 50, WHITE);
            EndDrawing();

            if (IsKeyPressed(KEY_ENTER))
            {
                MenuHandler::state = MenuHandler::MENU;
            }
            break;
        }
        }
    }

    CloseWindow();

    return 0;
}
