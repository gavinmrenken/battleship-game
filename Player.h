#ifndef _PLAYER_
#define _PLAYER_

#include <iostream>
#include <string>

class Player {
    
private:
    
    int bestScore; // stores the player's best score achieved
    
    std::string name; // stores the player's name
    
public:
    
    Player(const std::string& _name); // constructor for Player that accepts a std::string input and assigns name to this input
    
    std::string getName() const;    // function returns player's name
    
    double getMaxScore();    // function returns the player's best score up to that point
    
    bool checkRecord(int recentScore);    // function accepts an int and updates maximum score if this input is greater / returns true if new score is better and otherwise false
    
};

#endif
