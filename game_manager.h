#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "competitor.h"
#include "computer.h"
#include "human.h"
#include <cstdio>
#include <random>

using std::mt19937;
using std::random_device;
using std::shuffle;

class GameManager {
  private:
    vector<Card> deck;
    vector<Competitor> competitors;

  public:
    void add_competitors() {
        int choice;
        printf("Add competitors\n");
        printf("1. Human\n");
        printf("2. Computer\n");
        printf("3. Stop adding\n");
        do {
            printf("Enter option: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1: {
                    Human human;
                    competitors.push_back(human);
                    break;
                }
                case 2: {
                    Computer computer;
                    competitors.push_back(computer);
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
};

#endif
