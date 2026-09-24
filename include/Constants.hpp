#pragma once
#include <cstdlib>

// WINDOW SIZE CONSTANTS
inline constexpr int WINDOW_WIDTH{1920};
inline constexpr int WINDOW_HEIGHT{1080};

// GLOBAL GAME CONSTANTS
inline constexpr size_t PADDLE_COUNT{2};
// for better indication with Paddles
enum Side : size_t {LEFT, RIGHT};
