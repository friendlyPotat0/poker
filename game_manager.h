#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "competitor.h"
#include "computer.h"
#include "human.h"
#include <random>
#include <vector>

using std::cin;
using std::mt19937;
using std::random_device;
using std::shuffle;
using std::vector;

class GameManager {
  private:
    vector<Card> deck;
    vector<Card> community_cards;
    vector<Competitor *> competitors;

  public:
    void add_competitors() {
        int choice;
        printf("ADD COMPETITORS\n");
        printf("1. Human\n");
        printf("2. Computer\n");
        printf("3. Stop adding\n");
        do {
            printf("Enter option: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1: {
                    Human *human = new Human();
                    string name;
                    printf("Enter name: ");
                    cin >> name;
                    cin.ignore();
                    human->set_name(name);
                    competitors.push_back(human);
                    break;
                }
                case 2: {
                    Computer *computer = new Computer();
                    string name;
                    printf("Enter name: ");
                    cin >> name;
                    cin.ignore();
                    computer->set_name(name);
                    competitors.push_back(computer);
                    break;
                }
                case 99: {
                    printf("Secret case\n");
                    break;
                }
                default: {
                    if (competitors.size() >= 2) {
                        return;
                    } else {
                        printf("You must add at least two competitors\n");
                        break;
                    }
                }
            }
        } while (true);
    }

    void generate_and_shuffle_deck() {
        for (auto &suit : {"spades", "diamonds", "hearts", "clubs"}) {
            for (int rank = 2; rank <= 14; rank++) {
                Card card(suit, rank);
                deck.push_back(card);
            }
        }
        mt19937 rng(random_device{}());
        shuffle(deck.begin(), deck.end(), rng);
    }

    void deal_cards() {
        // Community cards
        for (int i = 0; i < 5; i++) {
            community_cards.push_back(deck.back());
            deck.pop_back();
        }
        // Competitor cards
        for (auto &competitor : competitors) {
            for (int i = 0; i < 2; i++) {
                competitor->add_card(deck.back());
                deck.pop_back();
            }
        }
    }

    void display_community_cards() {
        printf("COMMUNITY CARDS\n");
        vector<string> ascii_cards = Card::construct_ascii_cards(community_cards);
        for (const string &line : ascii_cards) {
            printf("%s\n", line.c_str());
        }
    }

    void display_competitor_cards() {
        printf("COMPETITOR CARDS\n");
        bool hidden = false;
        for (auto &competitor : competitors) {
            if (hidden)
                competitor->hide_cards(true);
            hidden = true;
            vector<string> ascii_cards = Card::construct_ascii_cards(competitor->get_cards());
            printf("#%s (%s)\n", competitor->get_name().c_str(), competitor->get_nature().c_str());
            for (const string &line : ascii_cards) {
                printf("%s\n", line.c_str());
            }
        }
    }

    void exchange_competitor_cards() {
        printf("EXCHANGE TIME\n");
        for (auto &competitor : competitors) {
            printf("#%s (%s) turn\n", competitor->get_name().c_str(), competitor->get_nature().c_str());
            competitor->exchange_cards(deck);
        }
    }

    void merge_community_cards(Competitor *competitor) {
        for (auto &card : community_cards) {
            competitor->add_card(card);
        }
    }

    void evaluate_hand(Competitor *competitor) {
        int score = 0;
        vector<int> rank_count(14, 0);
        vector<int> suit_count(4, 0);
        for (auto &card : competitor->get_cards()) {
            rank_count.at(card.get_rank() - 2)++;
            suit_count.at(card.get_suit() == "spades" ? 0 : card.get_suit() == "diamonds" ? 1 : card.get_suit() == "hearts" ? 2 : 3)++;
        }
        // Evaluate pair
        int pairs = 0;
        for (int i = 0; i < rank_count.size(); i++) {
            if (rank_count.at(i) == 2)
                pairs++;
        }
        if (pairs == 1) {
            score = 1;
        } else if (pairs == 2) {
            score = 2;
        }
        // Evaluate three of a kind
        for (int i = 0; i < rank_count.size(); i++) {
            if (rank_count.at(i) == 3)
                score = 3;
        }
        // Evaluate straight
        for (int i = 0; i < rank_count.size() - 4; i++) {
            if (rank_count.at(i) && rank_count.at(i + 1) && rank_count.at(i + 2) && rank_count.at(i + 3) && rank_count.at(i + 4))
                score = 4;
        }
        // Evaluate flush
        // Set score
        competitor->set_score(score);
    }

    void determine_winner() {}
};

#endif
