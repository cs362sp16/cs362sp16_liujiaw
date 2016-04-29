#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
	//int number;
	int myCard[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState myTest;
	initializeGame(2, myCard, 1, &myTest);

	printf("\n");
	if (cardEffect(village, 0, 0, 0, &myTest, 0, 0) == 0 && numHandCards(&myTest) == numHandCards(&myTest) && myTest.numActions == myTest.numActions + 1){
		printf("**************** Card Test Result *****************\n");
		printf("**             Card Test 3: village              **\n");
		printf("**                    Passed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	else{
		printf("**************** Card Test Result *****************\n");
		printf("**             Card Test 3: village              **\n");
		printf("**                    Failed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	return 0;
}