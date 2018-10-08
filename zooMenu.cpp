/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/22/18
** Description: This file contains the necessary functions required to
*               prompt the user for game input and execute calls to 
*               necessary functions. 
*********************************************************************/
#include "zooMenu.hpp"
#include <iostream>
#include <string>

/********************************************************************* 
** Description: zooMenu::zooMenu()
*               zooMenu default constructor
*********************************************************************/
zooMenu::zooMenu()
{ 
    mainMenu();
}

/********************************************************************* 
** Description: void zooMenu::mainMenu()
*               Prompts user to play a new game or exit program.
*********************************************************************/
void zooMenu::mainMenu()
{
        int userChoice;
        std::cout << "****************** Welcome to Zoo Tycoon! ******************" << std::endl;
        std::cout << std::endl << "             Would you like to: " << std::endl;
        std::cout << "                  1. Play a game" << std::endl;
        std::cout << "                   2. Quit the game" << std::endl; 
        userChoice=mainMenuValidate();
        if (userChoice==1)
        {
            initialPurchaseMenu();
        }
        else
        {
            quitMenu();
        }
}

/********************************************************************* 
** Description: void zooMenu::initialPurchaseMenu() 
*               Prompts user to buy one type of animal from each
*               category and quantity of each. 
*********************************************************************/
void zooMenu::initialPurchaseMenu() 
{
    int count=3, purchaseSelection, purchaseQuantity, totalCost, remainingBalance;
    AnimalType animalList[]={Tiger, Penguin, Turtle}; // Used to identify output in for-loop
    int priceList[]={10000, 1000, 100}; // Used to print associated prices 
    // While-loop is used to decrement lines of output, starting with 3 lines, and removing one at a time
    while (count>0)
    {
        std::cout << std::endl << "     Please buy 1 or 2 of each animal listed below: " << std::endl;
        for (int i=0; i<count; i++)
        {
            if (animalList[i]==Tiger)
                std::cout << "         " << i+1 << ". Tiger: $" << priceList[i] << std::endl;
            if (animalList[i]==Penguin)
                std::cout << "          " << i+1 << ". Penguin: $" << priceList[i] << std::endl;
            if (animalList[i]==Turtle)
                std::cout << "           " << i+1 << ". Turtle: $" << priceList[i] << std::endl;
        }
        purchaseSelection=initialPurchaseValidate(count);
        std::cout << "Would you like to purchase 1 or 2?" << std::endl;
        purchaseQuantity=mainMenuValidate();
        // For-loop takes user selected quantity and iterates call to fill the cage array that many times
        for (int i=0; i<purchaseQuantity; i++)
        {
            newZoo.fillTheCage(animalList[purchaseSelection-1], &newZoo);
        }
        totalCost=purchaseQuantity*priceList[purchaseSelection-1];
        // Simple for-loop takes user selected animal type and moves it to end of array. Iterations through the animal list
        // are reduced by one during the next iteration, ensuring the last element won't be seen
        for (int i=(purchaseSelection-1); i<(count-1); i++)
        {
            animalList[i]=animalList[i+1];
            priceList[i]=priceList[i+1];
        }
        remainingBalance=newZoo.getBankbalance()-totalCost;
        newZoo.setBankbalance(remainingBalance);
        std::cout << "You're remaining balance is " << newZoo.getBankbalance() << std::endl;
        count--;
    }
    //newZoo.statusPrint();
    gameDay();
}

/********************************************************************* 
** Description: void zooMenu::endOfDayPurchase()
*               Allows user to choose one animal to purchase.
*********************************************************************/
void zooMenu::endOfDayPurchase()
{
    int purchaseSelection, totalCost, remainingBalance;
    AnimalType animalList[]={Tiger, Penguin, Turtle};
    int priceList[]={10000, 1000, 100};
    
    std::cout << std::endl << "You are able to buy one of the animals below: " << std::endl;
    for (int i=0; i<newZoo.getAnimalPopulation(); i++)
    {
        if (animalList[i]==Tiger && newZoo.getBankbalance()>priceList[i])
            std::cout << "        " << i+1 << ". Tiger: $" << priceList[i] << std::endl;
        if (animalList[i]==Penguin && newZoo.getBankbalance()>priceList[i])
            std::cout << "         " << i+1 << ". Penguin: $" << priceList[i] << std::endl;
        if (animalList[i]==Turtle && newZoo.getBankbalance()>priceList[i])
            std::cout << "          " << i+1 << ". Turtle: $" << priceList[i] << std::endl;
    }
    purchaseSelection=endDayPurchaseValidate();
    newZoo.resizeArray(purchaseSelection-1);
    newZoo.fillTheCage(animalList[purchaseSelection-1], &newZoo);
    totalCost=priceList[purchaseSelection-1];
    remainingBalance=newZoo.getBankbalance()-totalCost;
    newZoo.setBankbalance(remainingBalance);
    std::cout << "You're remaining balance is " << newZoo.getBankbalance() << std::endl;
    //newZoo.statusPrint();
    endMenu();
}

/********************************************************************* 
** Description: void zooMenu::gameDay()
*               Contains the necessary calls to functions for day to
*               day operations. Checks if game can continue due to
*               funds
*********************************************************************/
void zooMenu::gameDay()
{
        std::cout << std::endl << "         Congratulations! You've started day #" << newZoo.getDay()+1 << std::endl;
        newZoo.increaseAge();
        newZoo.calculateFeedCost();
        newZoo.calculatePayoff();
        newZoo.randomEvent();
        //newZoo.statusPrint();
        if (!newZoo.checkBalance())
        {
            quitMenu();
            return;
        }
        newZoo.setDay(1);
        endOfDayMenu();
}

/********************************************************************* 
** Description: void zooMenu::endOfDayMenu()
*               Menu function. Prompts user to buy a new animal or
*               skip ahead to next day.
*********************************************************************/
void zooMenu::endOfDayMenu()
{
    int userSelection;
    
    std::cout << "          You've reached the end of day #" <<newZoo.getDay() << std::endl << std::endl;
    std::cout << "Would you like to:" << std::endl;
    std::cout << "      1. Buy a new Adult animal" << std::endl;
    std::cout << "       2. Skip to the end of the day" << std::endl;
    userSelection=endOfDayValidate();
    if (userSelection==1)
        endOfDayPurchase();
    else
    {
        endMenu();
    }
}

/********************************************************************* 
** Description: void zooMenu::endMenu()
*               Enables user to choose whether to continue playing 
*               game or exit game
*********************************************************************/
void zooMenu::endMenu()
{
        std::cout << std::endl << "         Day #" << newZoo.getDay() << " is officially over!" << std::endl << std::endl;
        int userInput;
        std::cout << "Now that the day is over would you like to: " << std::endl;
        std::cout << "      1. Keep playing" << std::endl;
        std::cout << "       2. Exit the game" << std::endl;
        userInput=endMenuValidate();
        if (userInput==1)
            gameDay();
        else
            quitMenu();
        
}

/********************************************************************* 
** Description: int zooMenu::quitMenu()
*               Creates exit message when user leaves game
*********************************************************************/
void zooMenu::quitMenu()
{
    std::cout << std::endl << "************ Thank you for playing! See you again soon! ************" << std::endl;
}

/********************************************************************* 
** Description: zooMenu::~zooMenu()
*               zooMenu class destructor
*********************************************************************/
zooMenu::~zooMenu()
{
}