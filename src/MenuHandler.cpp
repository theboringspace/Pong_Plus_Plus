#include "MenuHandler.hpp"
#include "Constants.hpp"


/**
 * START MENU
 */
void MenuHandler::StartMenu(World& game)
{
    DrawText("PONG++", (WINDOW_WIDTH - MeasureText("PONG++", 300)) / 2, WINDOW_HEIGHT / 7.0f, 300, WHITE);
    singlePlayerButton.Draw();
    twoPlayerButton.Draw();
    quitButton.Draw();

    if (singlePlayerButton.isClicked())
    {
        game.Reset();
        state = SINGLE_PLAYER;
    }
    else if (twoPlayerButton.isClicked())
    {
        game.Reset();
        state = TWO_PLAYER;
    }
    else if (quitButton.isClicked())
    {
        state = QUIT;
    }
}
/**
 * START MENU END
 */

/**
 * SETTINGS MENU
 */
void MenuHandler::SettingsMenu()
{

}
/**
 * SETTINGS MENU END
 */
