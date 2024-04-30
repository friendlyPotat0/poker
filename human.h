#ifndef HUMAN_H
#define HUMAN_H

#include "competitor.h"

class Human : public Competitor {
  public:
    Human() { nature = "human"; }
    string get_identifier() { return nature; }
    void exchange_cards(vector<Card> &deck) override {
        int choice, cards_exchanged = 0;
        printf("Exchange card\n");
        printf("1. Yes\n");
        printf("2. No\n");
        do {
            printf("Enter option: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1: {
                    cards_exchanged++;
                    if (cards_exchanged < 3) {
                        int index;
                        printf("Enter index of card to exchange: ");
                        scanf("%d", &index);
                        cards.at(index) = deck.back();
                        deck.pop_back();
                    }
                    break;
                }
                default: {
                    return;
                }
            }
        } while (true);
    }
};

#endif
