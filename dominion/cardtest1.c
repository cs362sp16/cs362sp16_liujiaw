#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include "dominion.h"
//#include "dominion_helpers.h"

int main() {
	int myCard[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState myTest;
	initializeGame(2, myCard, 1, &myTest);

	printf("\n");
	if (cardEffect(smithy, 0, 0, 0, &myTest, 0, 0) == 0 && numHandCards(&myTest) == numHandCards(&myTest) + 2){
		printf("**************** Card Test Result *****************\n");
		printf("**             Card Test 1: smithy               **\n");
		printf("**                    Passed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	else{
		printf("**************** Card Test Result *****************\n");
		printf("**             Card Test 1: smithy               **\n");
		printf("**                    Failed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	return 0;
}