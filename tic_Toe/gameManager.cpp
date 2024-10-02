#include "gameManager.h"
#include<bits/stdc++.h>
using namespace std;

gameManager::gameManager(int boardSize,int playerCount)
{
    this->n=boardSize;
    this->board.resize(boardSize,vector<int>(boardSize,-1));
    this->playerCount=playerCount;
    this->totalFillCell=0;
    this->playerSymbol.resize(playerCount);  // here playerId is 0 1 2 3 --- playerCount-1
}

void gameManager::setSymbolForPlayer(int playerId, char symbol){

    if(playerId<playerCount)
   this->playerSymbol[playerId]=symbol;

   return ;
}

int gameManager::handleTurn(int playerId,int r,int c)
{
   char symbol=playerSymbol[playerId];
   this->totalFillCell++;
   this->board[r][c]=playerId;
   
   int ans=0;
   // check for row 
   int symbolCount=0;
   for(int i=0;i<n;i++)
   {
       if(board[r][i]==playerId)
       symbolCount++;
   }
   if(symbolCount==n)
   return 1;  // win the game
   else
   symbolCount=0;

   // check for coloumn
    for(int i=0;i<n;i++)
   {
       if(board[i][c]==playerId)
       symbolCount++;
   }
   if(symbolCount==n)
   return 1;  // win the game
   else
   symbolCount=0;

   // check for both diagonal

   if(totalFillCell==n*n)
   {
    return -1;  
    // match draw;
   }

   return 0;  // next turn
}