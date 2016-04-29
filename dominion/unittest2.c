#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main() {
	int myCard[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState myTest;
	initializeGame(2, myCard, 1, &myTest);

	printf("\n");
	if (fullDeckCount(0, 0, &myTest) == 0){
		printf("**************** Unit Test Result *****************\n");
		printf("**             Unit Test 2: fullDeckCount()      **\n");
		printf("**                    Passed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	else{
		printf("**************** Unit Test Result *****************\n");
		printf("**             Unit Test 2: fullDeckCount()      **\n");
		printf("**                    Failed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	return 0;
}