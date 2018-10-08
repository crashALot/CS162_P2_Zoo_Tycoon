/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/22/18
** Description: This file includes the associated method functions for
*               the derived tiger class. 
*********************************************************************/
#include "tiger.hpp"

/********************************************************************* 
** Description: tiger::tiger() : animal()
*               Default tiger class constructor. Inherits several
*               member variables from animal base class. Those 
*               attributes that need adjustment are changed here upon
*               being called.
*********************************************************************/
tiger::tiger() : animal()
{
    setCost(10000);
    setBaseFoodCost(50);
    setPayoff(.2);
}
   
/********************************************************************* 
** Description: penguin::~penguin()
*               penguin class destructor
*********************************************************************/
tiger::~tiger()
{
}