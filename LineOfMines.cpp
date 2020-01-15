#include "LineOfMines.h"

LineOfMines::LineOfMines(size_t _lineLength, size_t _numberOfMines) : lineLength(_lineLength), numberOfMines(_numberOfMines), score(0), locationDisplays(lineLength, "_____"), neighbouringMineCounts(lineLength, 0), mineLocations(numberOfMines, 0), hitMine(false) {
    
    placeMines(); // places mines in the game and sets the count...
    
    setCounts();
}

void LineOfMines::placeMines() {    // member function to be called in thw constructor body - places number of mines in distinct locations from 1 to lineLength
    int randNum = 0;
    int i = 0;
    while (i < numberOfMines) {
        double randNum = rand() % lineLength; // randomly generates numbers for up to numberOfMines desired
        if (mineLocations[i] == randNum) { // helps to prevent duplicates
            i++;
        }
        else {
            mineLocations[i] = randNum;    // if not duplicate, inserts value in
            i++;
        }
    }
}

void LineOfMines::setCounts() {    // member function to be called in constructor body - set values of neighbouringMineCounts appropriately
    for (int i = 0; i < lineLength; i++) {
        if (i == 0) {    // in the event a mine is location at the leftmost side of the line
            if (containsMine(i + 1) == true) {    // if mine is location one from left
                neighbouringMineCounts[i] = 1;    // if true, then increments mine count ...
            }
            else {
                neighbouringMineCounts[i] = 0;
            }
        }
        else if (i == lineLength - 1) {    // if mine is located at the rightmost side of the line
            if (containsMine(i - 1) == true) {
                neighbouringMineCounts[i] = 1;
            }
            else {
                neighbouringMineCounts[i] = 0;
            }
        }
        else {    // if mine is located in the middle
            if (containsMine(i + 1) == true) {    // if mine to the right side
                neighbouringMineCounts[i] = 1;
            }
            else if (containsMine(i - 1) == true) {    // if mine to the left side
                neighbouringMineCounts[i] = 1;
            }
            else if ((containsMine(i + 1) == true) && (containsMine(i - 1) == true)) {    // if 2 mines detected
                neighbouringMineCounts[i] = 2;
            }
            else {    // if no mines detected
                neighbouringMineCounts[i] = 0;
            }
        }
    }
}

bool LineOfMines::containsMine(int pos) {    // member function that accepts an int for position number (from 1 to lineLength) / returns true if mine is present and else, false
    for (int i = 0; i < numberOfMines; i++) {
        if (mineLocations[i] == pos) {
            return true;
        }
    }
    return false;
}

void LineOfMines::display() {    // member function that displays the board - outputs position on lineLength on 1 line and each value of locationDisplays on the following line
    for (int i = 1; i <= lineLength; i++) {
        std::cout << i << "     "; // properly spaces numbers in line
    }
    std::cout << "\n";
    for (int i = 0; i < lineLength; i++) {
        std::cout << locationDisplays[i] << " ";
    }
    std::cout << "\n";
}

void LineOfMines::grandReveal() {     // member function that modifies each locationDisplays value if there is a mine there
    for (int i = 0; i < lineLength; i++) {
        if (containsMine(i) == true) {
            locationDisplays[i] = "__*__";
        }
    }
    display();    // calls display function
}

bool LineOfMines::hasHitMine() {    // returns whether or not a mine has been hit
    if (hitMine == true) {
        return true;
    }
    else {
        return false;
    }
}

int LineOfMines::getScore() {    // member function that returns the player's score if they have hit a mine and otherwise the number of safe locations they have revealed
    if (hasHitMine() == true) {
        return 0;
    }
    else {
        return score; // number of safe locations
    }
}

void LineOfMines::makeSelection(int revealPosition) {    // member function that accepts an int for the position a user wishes to reveal and updates locationDisplays and otherwise, sets the value depending on how many adjacent mines there are
    if (containsMine(revealPosition - 1) == true) {
        locationDisplays[revealPosition - 1] = "__*__";
        hitMine = true;
    }
    else {
        score += 1;
        if(neighbouringMineCounts[revealPosition - 1] == 0) {
            locationDisplays[revealPosition - 1] = "__0__";
        } else if(neighbouringMineCounts[revealPosition - 1] == 1) {
            locationDisplays[revealPosition - 1] = "__1__";
        }else if(neighbouringMineCounts[revealPosition - 1] == 2) {
            locationDisplays[revealPosition - 1] = "__2__";
        }
    }
}
