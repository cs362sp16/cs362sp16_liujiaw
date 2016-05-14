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
	//int my_cardNumber[27]={curse,estate,duchy,province,copper,silver,gold,adventurer,council_room,feast,gardens,mine,remodel,smithy,village,baron,great_hall,minion,steward,tribute,ambassador,cutpurse,embargo,outpost,salvager,sea_hag,treasure_map};
	int my_return[27] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};
	int i,count=0;

	for (i = 0; i < 27; i++){
		if (getCost(i) != my_return[i]){
			count++;
<<<<<<< HEAD
		}
=======
		}	
>>>>>>> Jiawei-Liu
	}

	if (count==0){
		printf("**************** Unit Test Result *****************\n");
		printf("**             Unit Test 1: getCost()            **\n");
		printf("**                    Passed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	else{
		printf("**************** Unit Test Result *****************\n");
		printf("**             Unit Test 1: getCost()            **\n");
		printf("**                    Failed                     **\n");
		printf("********************** End ************************\n");
		printf("\n");
	}
	return 0;
}
