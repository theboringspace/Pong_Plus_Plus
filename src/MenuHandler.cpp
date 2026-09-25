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
    settingsButton.Draw();

    if (singlePlayerButton.isClicked())
    {

    }
    else if (twoPlayerButton.isClicked())
    {
        game.Reset();
        state = TWO_PLAYER;
    }
    else if (settingsButton.isClicked())
    {

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
