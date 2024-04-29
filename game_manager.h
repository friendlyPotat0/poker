#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "human.h"
#include "computer.h"
#include "competitor.h"
#include <cstdio>

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
                } case 2: {
                    Computer computer;
                    competitors.push_back(computer);
                    break;
                } case 99: {
                    printf("Secret case\n");
                    break;
                } default: {
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
};

#endif
