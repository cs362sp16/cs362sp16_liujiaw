#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TESTS 10     

void my_assert(int b, char* s) {
    if (!b) {
        printf ("assert failed: %s\n", s);
        if (0) {
            exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    struct gameState g;
	int i, j, player_num, theSeed, allcard;
    int k[10] = {smithy, adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, steward};
    
    printf("******* Adventurer Random Test *******\n");

    if(argc<2){
        printf("Insufficient arguments");
        return 0;
    }
    theSeed=atoi(argv[1]);

    for (i = 0; i < MAX_TESTS; i++){
        printf("Random Test %d:\n", i+1);

        player_num = rand()%3 + 2;
        j = initializeGame(player_num, k, theSeed, &g);
        my_assert(j == 0, "Initialize Failed");

        g.deckCount[player_num] = rand() % MAX_DECK;
        g.discardCount[player_num] = rand() % MAX_DECK;
        g.handCount[player_num] = rand() % MAX_HAND;

        allcard = g.handCount[player_num] + g.deckCount[player_num] + g.discardCount[player_num];
        printf("---- Before Use Card ----\n");
        printf ("Hand count: %d\n", g.handCount[player_num]);
        printf ("Deck count: %d\n", g.deckCount[player_num]);
        printf ("Card Number: %d\n\n", allcard);

        j = cardEffect(adventurer, 1, 1, 1, &g, 0, 0);
        my_assert(j == 0, "Use Card Failed"); 

        allcard = g.handCount[player_num] + g.deckCount[player_num] + g.discardCount[player_num];
        printf("---- After Use Card ----\n");
        printf ("Hand count: %d\n", g.handCount[player_num]);
        printf ("Deck count: %d\n", g.deckCount[player_num]);
        printf ("Card Number: %d\n\n", allcard);
        
    }
    
    printf ("******* Adventurer Test Finish *******\n\n");

    return 0;
}

