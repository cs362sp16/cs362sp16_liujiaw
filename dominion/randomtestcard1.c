#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_TESTS 10     
#define MAX_COINS 20


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
    int i, j, player_num, allcard, choice, theSeed;
    int k[10] = {smithy, adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, steward};

    printf("******* Steward Random Test *******\n");
    
    if(argc<2){
        printf("Insufficient arguments");
        return 0;
    }
    theSeed=atoi(argv[1]);   
     
    for (i = 0; i < MAX_TESTS; i++){

        player_num = rand()%3 + 2;  
        choice = rand() % 3;
        printf("Random Test %d:\n", i+1);

        j = initializeGame(player_num, k, theSeed, &g);
        my_assert(j == 0, "Initialize Failed"); 

        g.deckCount[player_num] = rand() % MAX_DECK;
        g.discardCount[player_num] = rand() % MAX_DECK;
        g.handCount[player_num] = rand() % MAX_HAND;
        g.coins = rand() % MAX_COINS;

        allcard = g.handCount[player_num] + g.deckCount[player_num];
        printf("---- Before Use Card ----\n");
        printf ("Hand Count: %d\n", g.handCount[player_num]);
        printf ("Deck Count: %d\n", g.deckCount[player_num]);
        printf ("Card Number: %d\n", allcard);
        printf ("Coin Number: %d\n\n", g.coins);

        j = cardEffect(steward, choice, 3, 4, &g, 0, 0);
        my_assert(j == 0, "Use Card Failed");

        allcard = g.handCount[player_num] + g.deckCount[player_num];
        printf("---- After Use Card ----\n");
        printf ("Hand Count: %d\n", g.handCount[player_num]);
        printf ("Deck Count: %d\n", g.deckCount[player_num]);
        printf ("Card Number: %d\n", allcard);
        printf ("Coin Number: %d\n\n", g.coins);
        
    }

    printf ("******* Steward Test Finish *******\n\n");

    
    return 0;
}
