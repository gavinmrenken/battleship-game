#include "Player.h"


Player::Player(const std::string& _name) : name(_name), bestScore(0) {} // constructor

std::string Player::getName() const { // function returns player's name
    return name;
}

double Player::getMaxScore() {     // function returns the player's best score up to that point
    return bestScore;
}

bool Player::checkRecord(int recentScore) {    // function accepts an int and updates maximum score if this input is greater
    if (recentScore > bestScore) {    // returns true if new score is better
        bestScore = recentScore;
        return true;
    }
    else {    // otherwise is false
        return false;
    }
}
