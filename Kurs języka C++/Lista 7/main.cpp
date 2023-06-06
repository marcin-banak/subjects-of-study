#include <iostream>
#include "Game.h++"

int main() {
    /*GameState::Board board = GameState::Board();
    Player::Print(board);*/

    GameState::Game game = GameState::Game();
    game.Start();
    return 0;
}
