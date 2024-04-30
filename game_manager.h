#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "competitor.h"
#include "computer.h"
#include "evaluator.h"
#include "human.h"
#include <random>
#include <vector>

using std::cin;
using std::mt19937;
using std::random_device;
using std::shuffle;
using std::vector;

class GameManager {
  private:
    vector<Card> deck;
    vector<Competitor *> competitors;
    bool omniscient;

  public:
    GameManager() {
        deck.reserve(52);
        omniscient = false;
    }
    void configure_game() {
        int choice;
        printf("GAME SETTINGS\n");
        printf("1. Omniscient mode (false)\n");
        printf("2. Save\n");
        do {
            printf("Enter choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1: {
                    int omniscient;
                    printf("Enter 1 to enable, 0 to disable: ");
                    scanf("%d", &omniscient);
                    if (omniscient == 1)
                        this->omniscient = true;
                    break;
                }
                default: {
                    return;
                }
            }
        } while (true);
    }

    void add_competitors() {
        int choice;
        printf("ADD COMPETITORS\n");
        printf("1. Human\n");
        printf("2. Computer\n");
        printf("3. Stop adding\n");
        do {
            printf("Enter option: ");
            scanf("%d", &choice);
            bool can_add_players = competitors.size() < (52 - 2) / 5;
            switch (choice) {
                case 1: {
                    if (can_add_players) {
                        Human *human = new Human();
                        string name;
                        printf("Enter name: ");
                        cin >> name;
                        cin.ignore();
                        human->set_name(name);
                        competitors.push_back(human);
                    } else {
                        printf("You can't add more players! Maximum reached\n");
                    }
                    break;
                }
                case 2: {
                    if (can_add_players) {
                        Computer *computer = new Computer();
                        string name;
                        printf("Enter name: ");
                        cin >> name;
                        cin.ignore();
                        computer->set_name(name);
                        competitors.push_back(computer);
                    } else {
                        printf("You can't add more players! Maximum reached\n");
                    }
                    break;
                }
                case 99: {
                    printf("Secret case\n");
                    break;
                }
                default: {
                    if (competitors.size() >= 2) {
                        return;
                    } else {
                        printf("You must add at least two competitors\n");
                        break;
                    }
                }
            }
        } while (true);
    }

    void generate_and_shuffle_deck() {
        for (auto &suit : {"spades", "diamonds", "hearts", "clubs"}) {
            for (int rank = 2; rank <= 14; rank++) {
                Card card(suit, rank);
                deck.push_back(card);
            }
        }
        mt19937 rng(random_device{}());
        shuffle(deck.begin(), deck.end(), rng);
    }

    void deal_cards() {
        for (auto &competitor : competitors) {
            for (int i = 0; i < 5; i++) {
                competitor->add_card(deck.back());
                deck.pop_back();
            }
        }
    }

    void display_competitor_cards() {
        printf("COMPETITOR CARDS\n");
        bool visible = true; // First competitor
        for (auto &competitor : competitors) {
            if (!visible)
                competitor->hide_cards(true);
            if (!omniscient)
                visible = false;
            vector<string> ascii_cards = Card::construct_ascii_cards(competitor->get_cards());
            printf("#%s (%s)\n", competitor->get_name().c_str(), competitor->get_nature().c_str());
            for (const string &line : ascii_cards) {
                printf("%s\n", line.c_str());
            }
        }
    }

    void exchange_competitor_cards() {
        printf("EXCHANGE TIME\n");
        for (auto &competitor : competitors) {
            printf("#%s (%s) turn\n", competitor->get_name().c_str(), competitor->get_nature().c_str());
            competitor->exchange_cards(deck);
        }
    }

    void evaluate_hands() {
        for (auto &competitor : competitors) {
            vector<int> rank_count(14, 0);
            vector<int> suit_count(4, 0);
            // Count the number of each rank and suit
            for (auto &card : competitor->get_cards()) {
                rank_count.at(card.get_rank() - 2)++;
                suit_count.at(card.get_suit() == "spades" ? 0 : card.get_suit() == "diamonds" ? 1 : card.get_suit() == "hearts" ? 2 : 3)++;
            }
            // Perform hand evaluation
            Evaluator evaluator;
            int score = 0;
            if (evaluator.has_royal_flush(rank_count, suit_count)) {
                score = 9;
            } else if (evaluator.has_straight_flush(rank_count, suit_count)) {
                score = 8;
            } else if (evaluator.has_four_of_a_kind(rank_count)) {
                score = 7;
            } else if (evaluator.has_full_house(rank_count)) {
                score = 6;
            } else if (evaluator.has_flush(suit_count)) {
                score = 5;
            } else if (evaluator.has_straight(rank_count)) {
                score = 4;
            } else if (evaluator.has_three_of_a_kind(rank_count)) {
                score = 3;
            } else if (evaluator.has_two_pair(rank_count)) {
                score = 2;
            } else if (evaluator.has_pair(rank_count)) {
                score = 1;
            }
            competitor->set_score(score);
        }
    }

    void display_scores() {
        printf("SCORES\n");
        for (auto &competitor : competitors) {
            printf("#%s (%s) score: %d\n", competitor->get_name().c_str(), competitor->get_nature().c_str(), competitor->get_score());
        }
    }

    void announce_winner() {
        Competitor *winner = nullptr;
        int max_score = -1;
        int max_rank = -1;
        for (auto &competitor : competitors) {
            int competitor_score = competitor->get_score();
            int competitor_rank = competitor->get_highest_rank();
            if (competitor_score > max_score || (competitor_score == max_score && competitor_rank > max_rank)) {
                winner = competitor;
                max_score = competitor_score;
                max_rank = competitor_rank;
            }
        }
        printf("Winner: #%s (%s)\n", winner->get_name().c_str(), winner->get_nature().c_str());
    }
};

#endif
