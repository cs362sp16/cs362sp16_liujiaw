#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include "dominion.h"

int main() {
	int myCard[10] = {council_room, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState myTest;
	initializeGame(2, myCard, 1, &myTest);

	printf("\n");

	if (cardEffect(village, 0, 0, 0, &myTest, 0, 0) == 0 && numHandCards(&myTest) == numHandCards(&myTest) + 3 
		 && myTest.numBuys == myTest.numBuys + 1 && numHandCards(&myTest) == numHandCards(&myTest) + 1){
		printf("**************** Card Test Result *****************\n");
		printf("**             Card Test 2: council_room         **\n");
		printf("**                    Failed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	else{
		printf("**************** Card Test Result *****************\n");
		printf("**             Card Test 2: council_room         **\n");
		printf("**                    Passed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	return 0;
}