#include "card.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    Card test_card_1("DIAMONDS", "4");
    Card test_card_2("CLUBS", "Ace");
    Card test_card_3("SPADES", "Jack");
    Card test_card_4("hearts", "10");

    std::vector<Card> test_cards = {test_card_1, test_card_2, test_card_3, test_card_4};

    std::vector<std::string> card_ascii = Card::ascii_version_of_card(test_cards);
    for (const auto& line : card_ascii) {
        std::cout << line << std::endl;
    }

    test_cards.at(1).set_hidden(true);
    test_cards.at(3).set_hidden(true);
    // test_cards.at(1)=test_card_2;
    std::vector<std::string> hidden_card_ascii = Card::ascii_version_of_card(test_cards);
    for (const auto& line : hidden_card_ascii) {
        std::cout << line << std::endl;
    }

    return 0;
}
