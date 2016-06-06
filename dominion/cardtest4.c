#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include "dominion.h"
//#include "dominion_helpers.h"

int main() {
	int number;
	int myCard[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState myTest;
	initializeGame(2, myCard, 1, &myTest);

	printf("\n");
	myTest.coins = 0;
	number = myTest.whoseTurn;
	myTest.hand[number][0] = silver;
	myTest.hand[number][1] = council_room;
	myTest.hand[number][2] = copper;
	myTest.hand[number][3] = copper;
	myTest.hand[number][4] = salvager;
	if (myTest.playedCardCount == 1 && myTest.playedCards[0] == salvager && myTest.handCount[number] == 3 && myTest.coins == 5){
		printf("**************** Card Test Result *****************\n");
		printf("**             Card Test 4: salvager             **\n");
		printf("**                    Failed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	else{
		printf("**************** Card Test Result *****************\n");
		printf("**             Card Test 4: salvager             **\n");
		printf("**                    Passed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	return 0;
}

