/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/22/18
** Description: This file includes the associated method functions for
*               the derived turtle class. 
*********************************************************************/
#include "turtle.hpp"

/********************************************************************* 
** Description: turtle::turtle() : animal()
*               Default turtle class constructor. Inherits several
*               member variables from animal base class. Those 
*               attributes that need adjustment are changed here upon
*               being called.
*********************************************************************/
turtle::turtle() : animal()
{
    setBabies(10);
    setBaseFoodCost(5);
}

/********************************************************************* 
** Description: turtle::~turtle()
*               penguin class destructor
*********************************************************************/
turtle::~turtle()
{
}