#include <raylib.h>
#include <array>

#include "Paddle.hpp"
#include "Ball.hpp"

class CollisionHandler
{
private:
    std::array<Paddle*, 2> paddles;
    Ball* ball;
public:
    CollisionHandler(Paddle* paddle1, Paddle* paddle2, Ball* ball);

    void Update(float deltaTime);
    void Draw();
};