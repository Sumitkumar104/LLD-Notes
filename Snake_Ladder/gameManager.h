// in simple language, this is the header file for the gameManager class
// behave as sekleton for the class
// .h is the extension for header file and we import it in the main file

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include<bits/stdc++.h>
// using namespace std;

class gameManager {
private:
    std::vector<int> ladderPosition, snakePosition;
    std::unordered_map<std::string, int> userPosition;

public:
    gameManager();  // Constructor
    void fillSnake(int s, int e);
    void fillLadder(int s, int e);
    void addNewUser(std::string user);
    int rollDice(int k);
    void handlePosition(std::string user, int diceNumber);
    int showCurrentPosition(std::string user);
};

#endif