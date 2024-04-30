#ifndef COMPETITOR_H
#define COMPETITOR_H

#include "card.h"

class Competitor {
  protected:
    string name;
    vector<Card> cards;
    int score{0};
    string nature;

  public:
    string get_nature() { return nature; }
    void add_card(Card &card) { cards.push_back(card); }
    virtual void exchange_cards(vector<Card> &deck) {}
    void set_name(string name) { this->name = name; }
    string get_name() { return name; }
    vector<Card> get_cards() { return cards; }
    void set_score(int score) { this->score = score; }
    int get_score() { return score; }
};

#endif
