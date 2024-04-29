#include "card.h"

class Competitor {
  private:
    vector<Card> cards;
    bool is_human;

  public:
    Competitor(const bool &is_human) : is_human(is_human) {}
    void add_card(Card &card) { cards.push_back(card); }
    void exchange_card(Card &card, const int &index) { cards.at(index) = card; }
};
