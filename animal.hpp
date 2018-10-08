/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/22/18
** Description: This file contains the associated prototypes and
*               data for the animal class. 
*********************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class animal
{
private:

    int age, cost, babies, baseFoodCost, animalNumber;
    double payoff;

public:

    animal();
    double foodCost();
    int getAnimalNumber();
    int getAge();
    int getCost();
    int getBabies();
    int getBaseFoodCost();
    double getPayoff();
    void setAnimalNumber(int);
    void setAge(int);
    void advanceAge();
    void setCost(int);
    void setBabies(int);
    void setBaseFoodCost(int);
    void setPayoff(double);
    ~animal();
    
};

#endif