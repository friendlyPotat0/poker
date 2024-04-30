#ifndef COMPUTER_H
#define COMPUTER_H

#include "competitor.h"

class Computer : public Competitor {
  public:
    Computer() { nature = "computer"; }

    void exchange_cards(vector<Card> &deck) override {
        printf("I don't have a brain yet\n");
    }
};

#endif
