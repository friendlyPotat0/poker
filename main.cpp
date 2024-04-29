#include "game_manager.h"
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
    GameManager game_manager;
    game_manager.add_competitors();
    game_manager.generate_and_shuffle_deck();
    return 0;
}
