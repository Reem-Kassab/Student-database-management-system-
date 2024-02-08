#ifndef _SDBAPP_H
#define _SDBAPP_H

#include <stdlib.h>
#include "SDB.h"

/**
  * @brief it has a super loop it will make your project until
  *        the user chose to exit you will ask the user to choose
  *        between  options
  */
void SDB_APP ();

/****************************************/
/**
  * @brief it well takes the user choice and call the responding function for this choice.
  * @param (choice)  parameter to pass user choice
  */
void SDB_action (uint8 choice);

#endif // _SDBAPP_H
