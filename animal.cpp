/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/22/18
** Description: This file contains the methods to create an instance 
*               of the animal class. The animal class is a base class
*               used to create multiple different derived classes also.
*********************************************************************/
#include "animal.hpp"

/********************************************************************* 
** Description: animal::animal()
*               Default animal class constructor. Each member variable
*               initialized here is either used as a sentinel (such as
*               age and animalNumber) or set to a value that can be 
*               manipulated for derived classes.
*********************************************************************/
animal::animal()
{
    animalNumber=-1; // Allows easier indexing of indivdiual animal classes
    age=-1; // Animal classes are set to -1 initially to distinguish their existence in the game
    cost=100;
    babies=1;
    baseFoodCost=10;
    payoff=.05;
}

/********************************************************************* 
** Description: Get and Set functions
*               The included interfaces below allow the program to 
*               access an set important details of base and derived
*               animal classes.
*********************************************************************/
int animal::getAnimalNumber()
{
    return animalNumber;
}

int animal::getAge()
{
    return age;
}

int animal::getCost()
{
    return cost;
}

int animal::getBabies()
{
    return babies;
}

int animal::getBaseFoodCost()
{
    return baseFoodCost;
}

double animal::getPayoff()
{
    return payoff;
}

void animal::setAnimalNumber(int placeInPile)
{
    animalNumber=placeInPile;
}

// Used to specifically change an animal's age
// For example, when an animal dies its age is set to -1
void animal::setAge(int newAge)
{
    age=newAge;
}

// Normal day to day increment 
void animal::advanceAge()
{
    age+=1;
}

void animal::setCost(int newCost)
{
    cost=newCost;
}

void animal::animal::setBabies(int newBabies)
{
    babies=newBabies;
}

void animal::setBaseFoodCost(int newBaseFoodCost)
{
    baseFoodCost=newBaseFoodCost;
}

void animal::setPayoff(double newPayoff)
{
    payoff=newPayoff;
}

/********************************************************************* 
** Description: animal::~animal()
*               animal class destructor.
*********************************************************************/
animal::~animal()
{
}