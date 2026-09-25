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
    ToggleFullscreen();
    RenderTexture2D target{ LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT) };
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);
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
        SetMouseScale((float)WINDOW_WIDTH / GetScreenWidth(), (float)WINDOW_HEIGHT / GetScreenHeight());

        switch(MenuHandler::state)
        {
        case MenuHandler::MENU :
            BeginTextureMode(target);
            ClearBackground(BLACK);

            MenuHandler::StartMenu(game);
            EndTextureMode();
            break;
        // Both modes share the match; World handles who controls the right paddle
        case MenuHandler::SINGLE_PLAYER :
        case MenuHandler::TWO_PLAYER :
        {
            const float deltaTime{ GetFrameTime() };
            // PROCESS
            game.Update(deltaTime);

            // DRAW
            BeginTextureMode(target);
            ClearBackground(BLACK);

            game.Draw();
            EndTextureMode();

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
            BeginTextureMode(target);
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
            EndTextureMode();

            if (IsKeyPressed(KEY_ENTER))
            {
                MenuHandler::state = MenuHandler::MENU;
            }
            break;
        }
        case MenuHandler::QUIT :
            break;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(target.texture,
                       Rectangle{ 0, 0, (float)WINDOW_WIDTH, -(float)WINDOW_HEIGHT },
                       Rectangle{ 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() },
                       Vector2{ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }

    UnloadRenderTexture(target);
    CloseWindow();

    return 0;
}
