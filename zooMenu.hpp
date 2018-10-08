/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/22/18
** Description: This file contains the associated prototypes and
*               data for the zooMenu class.
*********************************************************************/
#ifndef ZOOMENU_HPP
#define ZOOMENU_HPP
#include "zooValidation.hpp"
#include "zoo.hpp"

class zooMenu
{
private:

    zoo newZoo;

public:
    
    zooMenu();
    void mainMenu();
    void initialPurchaseMenu();
    void endOfDayPurchase();
    void gameDay();
    void endOfDayMenu();
    void endMenu();
    void quitMenu();
    ~zooMenu();
    
};


#endif