/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/22/18
** Description: This program runs a game of Zoo Tycoon! Zoo tycoon is
*               a game that allows players to run a zoo business. 
*               Different types of animals cost different prices, have 
*               different maintenance costs, and of course, return a 
*               different profit at the end of each day. For this game, 
*               the player will be the proud owner of a virtual zoo 
*               that has spaces to house tigers, penguins and turtles.
*********************************************************************/
#include "zooMenu.hpp"
#include "zooValidation.hpp"
#include <iostream>

int main()
{
    int go=1, userInput;
    while (go)
    {
        zooMenu newGame;
        std::cout << std::endl << "      Would you like to:" << std::endl;
        std::cout << "          1. Play another game" << std::endl;
        std::cout << "           2. Exit the game"<< std::endl << std::endl;
        userInput=endOfDayValidate();
        if (userInput==1)
        {
            go=1;
        }
        else
        {
            go=0;
        }
    }
 	return 0;
}
