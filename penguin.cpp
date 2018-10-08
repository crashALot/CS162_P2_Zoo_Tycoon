/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/22/18
** Description: This file includes the associated method functions for
*               the derived penguin class. 
*********************************************************************/
#include "penguin.hpp"

/********************************************************************* 
** Description: penguin::penguin() : animal()
*               Default pengun class constructor. Inherits several
*               member variables from animal base class. Those 
*               attributes that need adjustment are changed here upon
*               being called.
*********************************************************************/
penguin::penguin() : animal()
{
    setCost(1000);
    setBabies(5);
    setPayoff(.1);
}

/********************************************************************* 
** Description: penguin::~penguin()
*               penguin class destructor
*********************************************************************/
penguin::~penguin()
{
}