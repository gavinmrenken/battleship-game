#ifndef LINE_OF_MINES
#define LINE_OF_MINES

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class LineOfMines {
    
private:
    
    size_t lineLength; // stores the number of locations in the game
    
    size_t numberOfMines; // stores the number of mines
    
    int score; // stores the game's score
    
    std::vector<std::string> locationDisplays; // stores how each location should be displayed if revealed
    std::vector<int> neighbouringMineCounts; // stores the number of neighbouring mines for each position
    std::vector<int> mineLocations; // stores the location of all mines in the game
    
    bool hitMine; // stores whether of not a mine has been hit
    
public:
    
    LineOfMines(size_t _lineLength, size_t _numberOfMines); // constructor for LineOfMines that accepts 2 size_t s
    
    void placeMines(); // member function to be called in thw constructor body - places number of mines in distinct locations from 1 to lineLength
    
    void setCounts(); // member function to be called in constructor body - set values of neighbouringMineCounts appropriately
    
    bool containsMine(int positionNumber); // member function that accepts an int for position number (from 1 to lineLength) / returns true if mine is present and else, false
    
    void display(); // member function that displays the board - outputs position on lineLength on 1 line and each value of locationDisplays on the following line
    
    void grandReveal(); // member function that modifies each locationDisplays value if there is a mine there
    
    bool hasHitMine(); // returns whether or not a mine has been hit
    
    int getScore(); // member function that returns the player's score if they have hit a mine and otherwsie the number of safe locations they have revealed
    
    void makeSelection(int revealPosition); // member function that accepts an int for the position a user wishes to reveal
    
};

#endif
