#include "card.h"
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

void add_competitors(vector<vector<Card>> competitors) {
    int choice;
    printf("Add competitors\n");
    printf("1. Human\n");
    printf("2. Computer\n");
    printf("3. Stop adding\n");
    while (true) {
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Human\n");
                break;
            case 2:
                printf("Computer\n");
                break;
            default:
                return;
        }
    }
}

int main() {
    vector<Card> deck;
    vector<vector<Card>> competitors;
    add_competitors(competitors);
    return 0;
}
