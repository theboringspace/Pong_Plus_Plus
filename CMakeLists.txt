cmake_minimum_required(VERSION 3.10)

project(Pong_Plus_Plus)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

add_executable(PingPlusPlus
  src/main.cpp
  src/Ball.cpp
  src/Paddle.cpp
  src/CollisionHandler.cpp
  src/World.cpp
  src/Button.cpp
  src/MenuHandler.cpp)

target_include_directories(PingPlusPlus PRIVATE
  include)

target_link_libraries(PingPlusPlus PRIVATE raylib)
target_compile_options(PingPlusPlus PRIVATE -Wall -Wextra)
