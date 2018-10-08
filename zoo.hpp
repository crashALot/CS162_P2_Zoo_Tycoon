/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/22/18
** Description: This file contains the associated prototypes and
*               data for the zoo class.
*********************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

// Enumerated data types help bridge the gap when managing the dynamic array
// The 2D array can use these values interchangeably to find specific animal elements.
enum AnimalType {Tiger, Penguin, Turtle};

class zoo
{
private:

    animal** cageArray;
    int bankBalance, animalPopulation, arrayLength[3], trackArray[3], day;

public:
    
    zoo();
    double randomNumber();
    void fillTheCage(AnimalType, zoo*);
    //void statusPrint();
    void resizeArray(int);
    void increaseAge();
    void incrementDay();
    void randomEvent();
    bool checkBalance();
    void calculatePayoff();
    void calculateFeedCost();
    int getDay();
    int getBankbalance();
    int getAnimalPopulation();
    int getArrayLength(AnimalType);
    void setDay(int);
    void setBankbalance(int);
    void setAnimalPopulation(int);
    void setArrayLength(AnimalType, int);
    ~zoo();
    
};

#endif