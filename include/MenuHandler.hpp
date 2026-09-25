#pragma once
#include <raylib.h>
#include "Button.hpp"
#include "Constants.hpp"
#include "World.hpp"

namespace MenuHandler
{
enum GameState
{
    MENU,
    SINGLE_PLAYER,
    TWO_PLAYER,
    QUIT,
    GAME_OVER
};

inline constexpr float BUTTON_WIDTH{ 450 };
inline constexpr float BUTTON_HEIGHT{ 70 };
inline constexpr float SINGLE_PLAYER_BUTTON_X{ (WINDOW_WIDTH - BUTTON_WIDTH) / 2.0f };
inline constexpr float SINGLE_PLAYER_BUTTON_Y{ WINDOW_HEIGHT / 2.0f + 160 };
inline constexpr float BUTTON_SPACING{ BUTTON_HEIGHT * 1.1};
inline constexpr int TEXT_SIZE{ 55 };

inline Button singlePlayerButton(SINGLE_PLAYER_BUTTON_X, SINGLE_PLAYER_BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT, "Single Player", TEXT_SIZE);
inline Button twoPlayerButton(SINGLE_PLAYER_BUTTON_X, SINGLE_PLAYER_BUTTON_Y + BUTTON_SPACING * 1.5f, BUTTON_WIDTH, BUTTON_HEIGHT, "Two Player", TEXT_SIZE);
inline Button quitButton(SINGLE_PLAYER_BUTTON_X, SINGLE_PLAYER_BUTTON_Y + BUTTON_SPACING * 1.5f * 2.0f, BUTTON_WIDTH, BUTTON_HEIGHT, "Quit", TEXT_SIZE);

inline GameState state{MENU};

/**
 * START MENU
 */
void StartMenu(World& game);
/**
 * START MENU END
 */

/**
 * SETTINGS MENU
 */
void SettingsMenu();
/**
 * SETTINGS MENU END
 */

};
