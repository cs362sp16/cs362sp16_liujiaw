/*
CS 362 Assignment 4

05/24/2016
*/
#include "assert.h"
#include "math.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TEST_TIMES 50

//int i = 0, counter = 0, tempkc = 0, appear = 0, numplayer = 0, seed = 0, temp = -1, check = 0, money = 0;
//int p0card = -1, p1card = -1, p2card = -1, p3card = -1, tempcard0 = 0, tempcard1 = 0, tempcard2 = 0, tempcard3 = 0;
//int p0numcard = 0, p1numcard = 0, p2numcard = 0, p3numcard = 0;


const char* cardName(int cardVal){

    switch(cardVal){
    case curse: return "curse";
    case estate:return "estate";
    case duchy: return "duchy";
    case province: return "province";
    case copper: return "copper";
    case silver: return "silver";
    case gold: return "gold";
    case gardens: return "gardens";
    case adventurer: return "adventurer";
    case council_room: return "council room";
    case feast: return "feast";
    case mine: return "mine";
    case remodel: return "remodel";
    case smithy: return "smithy";
    case village: return "village";
    case baron: return "baron";
    case great_hall: return "great hall";
    case minion: return "minion";
    case steward: return "steward";
    case tribute: return "tribute";
    case ambassador: return "ambassador";
    case cutpurse: return "cutpurse";
    case embargo: return "embargo";
    case outpost: return "outpost";
    case salvager: return "salvager";
    case sea_hag: return "sea hag";
    case treasure_map: return "treasure map";
    }
    
    return "\n No good card\n ";
}

int main(int argc, char *argv[]){

  srand(time(NULL));
  int randSeed =1, randChoice;
  int totalPlayers = 0, totalMoney, roundCount =0;
  int smithyPosition, adventurerPosition, gardenPosition;
  int embargoPosition, villagePosition, minionPosition;
  int minePosition, cutpursePosition, seaHagPosition;
  int tribePosition;
  int i,j,gainCard;
  int players[5] = {-1,-1,-1,-1,-1};
  
  struct gameState state;
  
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
  

    randSeed = atoi(argv[2]);
    totalPlayers = atoi(argv[1]);
  printf("\n----------Game Info---------\n");
  printf ("Starting game with '%d' players.\n", totalPlayers);
    printf("The seed is %d\n", randSeed);
    printf("Kingdom Cards: \n");
  
  initializeGame(totalPlayers, k, randSeed, &state);
  printf("------------Game Begins----------\n");


  while (isGameOver(&state) == 0){

    printf("\n%d players turn\n", whoseTurn(&state)+1);
    randChoice = randSeed % 101;
    totalMoney = 0, smithyPosition = -1, adventurerPosition = -1;
    gardenPosition = -1, embargoPosition = -1, villagePosition= -1; 
    minionPosition = -1, minePosition = -1, cutpursePosition = -1; 
    seaHagPosition = -1, tribePosition = -1;
    


    while(numHandCards(&state) < 5){
      drawCard(whoseTurn(&state) , &state);
    }


   //   else if(card==feast){
   // *choice1 = rand()%27;
   // *choice2 = -1;
   // *choice3 = -1;    
  }
    printf("Hand is: ");
    printf("Player %d: played %d\n", g->whoseTurn+1, gainCard);
    for (i = 0; i < numHandCards(&state); i++){
      printf("%s   ", cardName(handCard(i, &state)));
    }
    for (j = 0; j < numHandCards(&state); j++) {
      if (handCard(j, &state) == copper){
  totalMoney += 1;

  playCard(j, -1, -1, -1, &state);
      }
      else if (handCard(j, &state) == silver){
  totalMoney += 2;

  playCard(j, -1, -1, -1, &state);
      }
      else if (handCard(j, &state) == gold){
  totalMoney += 3;

  playCard(j, -1, -1, -1, &state);
      }
      else if (handCard(j, &state) == smithy){
  smithyPosition = j;
      }
      else if (handCard(j, &state) == adventurer){
  adventurerPosition = j;
      }
      else if (handCard(j, &state) == gardens){
  gardenPosition = j;
      }
      else if (handCard(j, &state) == embargo){
  embargoPosition = j;
      }
      else if (handCard(j, &state) == village){
  villagePosition = j;
      }
      else if (handCard(j, &state) == minion){
  minionPosition = j;
      }
      else if (handCard(j, &state) == mine){
  minePosition = j;
      }
      else if (handCard(j, &state) == cutpurse){
  cutpursePosition = j;
      }
      else if (handCard(j, &state) == sea_hag){
  seaHagPosition = j;
      }
      else if (handCard(j, &state) == tribute){
  tribePosition = j;
      }
    } 
   // else if(card==steward){
   // *choice1 = rand()%3;
   // *choice2 = 0;
   // *choice3 = 0;
  //}
    
    if (adventurerPosition != -1){
      printf("Played adventurer Card\n");
      playCard(adventurerPosition, -1, -1, -1, &state);
    }
    if (smithyPosition != -1){
      printf("Played smithy Card\n");
      playCard(smithyPosition, -1, -1, -1, &state);
    }
    if (minePosition != -1){
      printf("Played mine Card\n");
      playCard(minePosition, -1,-1,-1, &state);
    }
    if (minionPosition != -1) {
      printf("Played minion Card\n");
      playCard(minionPosition,-1,-1,-1,&state);
    }
    if (tribePosition != -1) {
      printf("Played tribute Card\n");
      
    }
    if (cutpursePosition != -1) {
      printf("Played cutpurse\n");
      playCard(cutpursePosition,-1,-1,-1,&state);
    }
    if (gardenPosition != -1) {
      printf("Played gardens\n");
      playCard(gardenPosition,-1,-1,-1,&state);
    }
    if (seaHagPosition != -1) {
      printf("Played sea hag\n");
      playCard(seaHagPosition,-1,-1,-1,&state);
    }
    if (villagePosition != -1){
      printf("Played village Card\n");
      playCard(villagePosition,-1,-1,-1,&state);
    }
    if (embargoPosition != -1){
      printf("Played embargo Card\n");
      playCard(embargoPosition, -1,-1,-1,&state);
    }    
    printf("Current money: %d\n", totalMoney);
    if (totalMoney >= 8) {
      printf("Bought province\n"); 
      buyCard(province, &state);
    }
    else if (totalMoney >= 6) {
      if (randChoice <= 50){
  printf("Bought me some adventurer\n");
  buyCard(adventurer, &state);
      }
      else {
  printf("Bought gold\n"); 
  buyCard(gold, &state);
      }
    }
    else if (totalMoney >= 5){
      if (randChoice <= 33) {
  printf("Bought mine\n");
  buyCard(mine, &state);
      }
      else if (randChoice > 33 && randChoice <=66){
  printf("Bought minion\n");
  buyCard(minion, &state);
      }
      else if (randChoice > 66){
  printf("Bought tribute\n");
  buyCard(tribute, &state);
      }
    }
    else if (totalMoney >= 4) {
      if (randChoice <= 25){
  printf("Bought gardens\n"); 
  buyCard(gardens, &state);
      }
      else if (randChoice > 25 && randChoice <= 50) {
  printf("Bought smithy\n"); 
  buyCard(smithy, &state);
      }
      else if (randChoice > 50 && randChoice <= 75) {
  printf("Bought cutpurse\n"); 
  buyCard(cutpurse, &state);
      }
      else if (randChoice > 75){
  printf("Bought sea hag\n"); 
  buyCard(sea_hag, &state);
      }
    }
    else if (totalMoney >= 3) {
      if (randChoice <= 50){
  printf("Bought silver\n"); 
  buyCard(silver, &state);
      }
      else {
  printf("Bought village\n");
  buyCard(village, &state);
      }
    }
    else if (totalMoney >= 2){
      if(randChoice <=50){
  printf("Bought estate\n");
  buyCard(estate, &state);
      }
      else if(randChoice >50){
  printf("Bought embargo\n");
  buyCard(embargo, &state);
      }
    }
    endTurn(&state);
    roundCount++;
    if (roundCount >= 25000){
      break; 
    }
  } 
  printf("Player %d is the winner\n", i+1);
  printf ("Finished game with %d roundCounts.\n", roundCount);
  printf("\n--------Game Over---------\n");
  getWinners(players, &state);
  
  return 1;
}