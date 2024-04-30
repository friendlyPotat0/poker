#ifndef COMPUTER_H
#define COMPUTER_H

#include "competitor.h"

class Computer : public Competitor {
  public:
    Computer() { nature = "computer"; }

    /* void exchange_cards(vector<Card> &deck) override {
        int cards_exchanged = 0;
        do {
            int index;
            scanf("%d", &index);
            if (index == 5) { // Skip exchange
                cards_exchanged++;
            } else if (0 < index && index < 5) { // Exchange
                cards.at(index) = deck.back();
                deck.pop_back();
                cards_exchanged++;
            } else {
                throw std::runtime_error("Index out of range [0, 5]");
            }
        } while (cards_exchanged < 3);
    } */
};

#endif
