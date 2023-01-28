#include <iostream>
#include "game.h"

// продолжительность игры в годах
const int duration_of_the_game_in_years = 5;

int main()
{
    setlocale(LC_ALL, "Russian");
    Game Game1(2);
    std::cout << "Игра началась";
    for (int i = 0; i < duration_of_the_game_in_years; i++) {
        Game1.phase1();
        Game1.phase3();
        Game1.phase5();
        Game1.phase7();
        Game1.phase8();
    }
}
