#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>

using std::vector;

class Evaluator {
  private:
    vector<int> suit_count;
    vector<int> rank_count;

  public:
    Evaluator(const vector<int> &suit_count, const vector<int> &rank_count) : suit_count(suit_count), rank_count(rank_count) {}

    bool has_royal_flush() { return rank_count[8] == 1 && rank_count[9] == 1 && rank_count[10] == 1 && rank_count[11] == 1 && rank_count[12] == 1 && (suit_count[0] == 5 || suit_count[1] == 5 || suit_count[2] == 5 || suit_count[3] == 5); }

    bool has_straight_flush() {
        for (int i = 0; i <= 9; ++i) {
            if (rank_count[i] && rank_count[i + 1] && rank_count[i + 2] && rank_count[i + 3] && rank_count[i + 4]) {
                if (suit_count[0] == 5 || suit_count[1] == 5 || suit_count[2] == 5 || suit_count[3] == 5) {
                    return true;
                }
            }
        }
        return false;
    }

    bool has_four_of_a_kind() {
        for (size_t i = 0; i < rank_count.size(); i++) {
            if (rank_count.at(i) == 4) {
                return true;
            }
        }
        return false;
    }

    bool has_full_house() {
        bool three_of_kind = false;
        bool pair = false;
        for (size_t i = 0; i < rank_count.size(); i++) {
            if (rank_count.at(i) == 3) {
                three_of_kind = true;
            }
            if (rank_count.at(i) == 2) {
                pair = true;
            }
        }
        return three_of_kind && pair;
    }

    bool has_flush() {
        for (size_t i = 0; i < suit_count.size(); i++) {
            if (suit_count.at(i) == 5) {
                return true;
            }
        }
        return false;
    }

    bool has_straight() {
        for (int i = 0; i <= 9; ++i) {
            if (rank_count[i] && rank_count[i + 1] && rank_count[i + 2] && rank_count[i + 3] && rank_count[i + 4]) {
                return true;
            }
        }
        return false;
    }

    bool has_three_of_a_kind() {
        for (size_t i = 0; i < rank_count.size(); i++) {
            if (rank_count.at(i) == 3) {
                return true;
            }
        }
        return false;
    }

    bool has_two_pair() {
        int pairs = 0;
        for (size_t i = 0; i < rank_count.size(); i++) {
            if (rank_count.at(i) == 2) {
                pairs++;
            }
        }
        return pairs == 2;
    }

    bool has_pair() {
        for (size_t i = 0; i < rank_count.size(); i++) {
            if (rank_count.at(i) == 2) {
                return true;
            }
        }
        return false;
    }
};

#endif
