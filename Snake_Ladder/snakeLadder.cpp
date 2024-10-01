
#include<bits/stdc++.h>
using namespace std;

// ladderArray is vector of pair of int,int
// first element of pair is the start of ladder
// second element of pair is the end of ladder

// snakeArray is vector of pair of int,int
// first element of pair is the start of snake

// Rool dice function will return a random number between 1 to 6

#include <vector>
using namespace std;

class gameManager {

private:
    vector<int> ladderPosition, snakePosition;
    unordered_map<string,int> userPosition;  // store with id as string

public:
    // Corrected constructor
    gameManager() {
        for (int i = 0; i < 101; i++) {
            ladderPosition.push_back(-1);
            snakePosition.push_back(-1);
        }
    }

    // handle the case that there is no snake and ladder on same postion
    void fillSnake(int s,int e)
    {
        this->snakePosition[s]=e;
        return ;
    }

    void fillLadder(int s,int e){
        this->ladderPosition[s]=e;
        return ;
    }

    void addNewUser(string user){
        this->userPosition[user]=1;
    }

    int rollDice(int k){
        // rand() funtion is used to generate a random number between 0 to INT_MAX
        int randomNumber=rand()%(6*k)+1;
        return randomNumber;
    }
    
   void handlePosition(string user,int diceNumber)
    {
        int curr=this->userPosition[user];
        int newPosition=-1;
       if(this->snakePosition[curr]!=-1)
       {
          newPosition=this->snakePosition[curr];
       }
      else if(this->ladderPosition[curr]!=-1)
         {
              newPosition=this->ladderPosition[curr];
         }
         else
         {
              newPosition=curr+diceNumber;
         }

         this->userPosition[user]=newPosition;
    }


    int showCurrentPostion(string user)
    {
        if(this->userPosition[user])
        return this->userPosition[user];
        else
        return -1;
    }
    
};

int main(){

    gameManager gm;
    return  0;
}


#include "gameManager.h"  // Import the gameManager class
#include <iostream>

int main() {
    gameManager gm;  // Create an object of the class

    gm.addNewUser("Player1");  // Add a new user
    int diceRoll = gm.rollDice(1);  // Roll the dice
    gm.handlePosition("Player1", diceRoll);  // Handle player's new position

    std::cout << "Player1's current position: " << gm.showCurrentPosition("Player1") << std::endl;

    return 0;
}
