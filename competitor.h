#ifndef COMPETITOR_H
#define COMPETITOR_H

#include "card.h"

class Competitor {
  private:
    vector<Card> cards;

  public:
    void add_card(Card &card) { cards.push_back(card); }
    void exchange_card(Card &card, const int &index) { cards.at(index) = card; }
};

#endif
