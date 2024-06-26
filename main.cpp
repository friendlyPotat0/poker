#include "game_manager.h"
#include <bits/stdc++.h>
#include <cstdio>

#define test_mode 0

using namespace std;

int main() {
    GameManager game_manager;
    game_manager.configure_game();
    game_manager.add_competitors();
    game_manager.generate_and_shuffle_deck();
    if (test_mode)
        game_manager.deal_cards_TEST();
    else
        game_manager.deal_cards();
    game_manager.display_competitor_cards();
    game_manager.exchange_competitor_cards();
    game_manager.display_competitor_cards();
    game_manager.evaluate_hands();
    game_manager.display_scores();
    game_manager.announce_winner();
    return 0;
}
