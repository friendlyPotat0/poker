#ifndef CARD_H
#define CARD_H

#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using std::array;
using std::distance;
using std::find_if;
using std::string;
using std::to_string;
using std::toupper;
using std::transform;
using std::unordered_map;
using std::vector;

class Card {
  private:
    string suit;
    int rank;
    bool hidden;

  public:
    Card(string suit, int rank) : suit(suit), rank(rank) {
        if (rank < 2 || rank > 14)
            throw std::invalid_argument("Card rank must be in range [2, 14]");
        transform(this->suit.begin(), this->suit.end(), this->suit.begin(), ::tolower);
        hidden = false;
    }

    void set_hidden(const bool &hidden) { this->hidden = hidden; }

    vector<string> ascii_version_of_card(const vector<Card> &cards) {
        unordered_map<string, string> suits_map = {{"spades", "♠"}, {"diamonds", "♦"}, {"hearts", "♥"}, {"clubs", "♣"}};
        vector<string> fragments(9);
        for (const auto &card : cards) {
            // Suit icon representation
            string suit = suits_map.at(card.suit);
            // Rank string representation
            string rank, space{" "};
            switch (card.rank) {
                case 11: {
                    rank = 'J';
                    break;
                }
                case 12: {
                    rank = 'Q';
                    break;
                }
                case 13: {
                    rank = 'K';
                    break;
                }
                case 14: {
                    rank = 'A';
                    break;
                }
                case 10: {
                    space = "";
                }
                default: {
                    rank = to_string(card.rank);
                }
            }
            // Card building
            if (!card.hidden) {
                fragments[0] += "┌─────────┐";
                fragments[1] += "│" + rank + space + "       │";
                fragments[2] += "│         │";
                fragments[3] += "│         │";
                fragments[4] += "│    " + suit + "    │";
                fragments[5] += "│         │";
                fragments[6] += "│         │";
                fragments[7] += "│       " + space + rank + "│";
                fragments[8] += "└─────────┘";
            } else {
                fragments[0] += "┌─────────┐";
                fragments[1] += "│░░░░░░░░░│";
                fragments[2] += "│░░░░░░░░░│";
                fragments[3] += "│░░░░░░░░░│";
                fragments[4] += "│░░░░░░░░░│";
                fragments[5] += "│░░░░░░░░░│";
                fragments[6] += "│░░░░░░░░░│";
                fragments[7] += "│░░░░░░░░░│";
                fragments[8] += "└─────────┘";
            }
        }
        return fragments;
    }
};

#endif
