#define GAMEMANAGER_H
#include<bits/stdc++.h>
using namespace std;

class gameManager {
  int n;     // size of chess board
  int playerCount;
  vector<vector<int>> board;   // board of size n*n
  vector<char> playerSymbol;  // vector of pair of size playerCount which include symbol with every playercount.
  int totalFillCell;

  gameManager(int boardSize,int playerCount){

  }

  void setSymbolForPlayer(int playerId,char symbol){

  }

  int handleTurn(int playerId,int r,int c)
  {
     
  }

};