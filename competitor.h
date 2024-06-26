#ifndef COMPETITOR_H
#define COMPETITOR_H

#include "card.h"

class Competitor {
  protected:
    string name;
    vector<Card> cards;
    int score;
    string nature;

  public:
    Competitor() { score = 0; }
    string get_nature() { return nature; }
    void add_card(const Card &card) { cards.push_back(card); }
    virtual void exchange_cards(vector<Card> &deck) {
        printf("I don't have a brain yet :(\n");
    }
    void set_name(string name) { this->name = name; }
    string get_name() { return name; }
    vector<Card> get_cards() { return cards; }
    int get_highest_rank() {
        int max_rank = -1;
        for (auto &card : cards) {
            if (card.get_rank() > max_rank)
                max_rank = card.get_rank();
        }
        return max_rank;
    }
    void hide_cards(const bool &hidden) {
        for (auto &card : cards) {
            card.set_hidden(hidden);
        }
    }
    void set_score(int score) { this->score = score; }
    int get_score() { return score; }
};

#endif
