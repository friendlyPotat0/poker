#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::array;
using std::distance;
using std::find_if;
using std::string;
using std::toupper;
using std::vector;
using std::transform;

class Card {
  private:
    string suit;
    string rank;
    bool hidden;

  public:
    Card(string suit, string rank) : suit(suit), rank(rank) {
        transform(this->suit.begin(), this->suit.end(), this->suit.begin(), ::tolower);
        hidden = false;
    }

    void set_hidden(const bool &hidden) { this->hidden = hidden; }

    static vector<string> ascii_version_of_card(const vector<Card> &cards) {
        array<string, 4> suits_name = {"spades", "diamonds", "hearts", "clubs"};
        array<string, 4> suits_symbols = {"♠", "♦", "♥", "♣"};

        vector<string> lines(9);

        for (const auto &card : cards) {
            string rank, space;
            if (card.rank == "10") {
                rank = card.rank;
                space = "";
            } else {
                rank = card.rank.substr(0, 1);
                space = " ";
            }

            string suit = suits_symbols[distance(suits_name.begin(), find(suits_name.begin(), suits_name.end(), card.suit))];

            if (!card.hidden) {
                lines[0] += "┌─────────┐";
                lines[1] += "│" + rank + space + "       │";
                lines[2] += "│         │";
                lines[3] += "│         │";
                lines[4] += "│    " + suit + "    │";
                lines[5] += "│         │";
                lines[6] += "│         │";
                lines[7] += "│       " + space + rank + "│";
                lines[8] += "└─────────┘";
            } else {
                lines[0] += "┌─────────┐";
                lines[1] += "│░░░░░░░░░│";
                lines[2] += "│░░░░░░░░░│";
                lines[3] += "│░░░░░░░░░│";
                lines[4] += "│░░░░░░░░░│";
                lines[5] += "│░░░░░░░░░│";
                lines[6] += "│░░░░░░░░░│";
                lines[7] += "│░░░░░░░░░│";
                lines[8] += "└─────────┘";
            }
        }

        return lines;
    }
};
