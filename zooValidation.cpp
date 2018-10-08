/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/22/18
** Description: 
*********************************************************************/
#include "zooValidation.hpp"
#include <iostream>
#include <string>
#include <cmath> // Used for pow function

/********************************************************************* 
** Description: int mainMenuValidate()
*               Validates input from main menu function
*********************************************************************/
int mainMenuValidate()
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]!='1' && userIn[0]!='2'))
        {
            std::cout << "Please re-enter your choice as an integer 1 (Play a game) or 2 (Quit the game): " << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;
}

/********************************************************************* 
** Description: int initialPurchaseValidate(int countIn)
*               Validates input for initial purchases at the zoo
*********************************************************************/
int initialPurchaseValidate(int countIn)
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]-'0')>countIn || (userIn[0]-'0')<1)
        {
            std::cout << "Please re-enter your choice as an integer less than " << countIn+1 <<" but greater than 0:" << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;
}

/********************************************************************* 
** Description: int endDayPurchaseValidate()
*               Validates purchase selection made after the end of the
*               day
*********************************************************************/
int endDayPurchaseValidate()
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]!='1' && userIn[0]!='2' && userIn[0]!='3'))
        {
            std::cout << "Please re-enter your choice as an integer 1, 2, or 3: " << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;
}

/********************************************************************* 
** Description: int endDayPurchaseValidate()
*               Validates game continuation selection after the end of
*               the day
*********************************************************************/
int endOfDayValidate()
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]!='1' && userIn[0]!='2'))
        {
            std::cout << "Please re-enter your choice as an integer 1 (Buy an animal) or 2 (Skip ahead): " << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;  
}

/********************************************************************* 
** Description: int endMenuValidate()
*               Validates whether player stays in game or exits
*********************************************************************/
int endMenuValidate()
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]!='1' && userIn[0]!='2'))
        {
            std::cout << "Please re-enter your choice as an integer 1 (Keep playing) or 2 (Exit the game): " << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;  
}
