#include "gameManager.h"  // Import the header file
#include <cstdlib>  // For rand()

gameManager::gameManager() {
    for (int i = 0; i < 101; i++) {
        ladderPosition.push_back(-1);
        snakePosition.push_back(-1);
    }
}

void gameManager::fillSnake(int s, int e) {
    snakePosition[s] = e;
}

void gameManager::fillLadder(int s, int e) {
    ladderPosition[s] = e;
}

void gameManager::addNewUser(std::string user) {
    userPosition[user] = 1;
}

int gameManager::rollDice(int k) {
    return rand() % (6 * k) + 1;
}

void gameManager::handlePosition(std::string user, int diceNumber) {
    int curr = userPosition[user];
    int newPosition = -1;

    if (snakePosition[curr] != -1) {
        newPosition = snakePosition[curr];
    } else if (ladderPosition[curr] != -1) {
        newPosition = ladderPosition[curr];
    } else {
        newPosition = curr + diceNumber;
    }

    userPosition[user] = newPosition;
}

int gameManager::showCurrentPosition(std::string user) {
    return userPosition[user] ? userPosition[user] : -1;
}
