#ifndef _SDB_H
#define _SDB_H

#define max 20

#include <stdio.h>
#include "platform_types.h"

typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 English;
    uint32 Arabic;
    uint32 Maths;
    uint32 Total;
    uint8  Student_Name[max];
    struct student *NodeLink;

} student;

/****************************************/

/****************************************/

 /**
  * @brief get how many students in your database have added
  * @param (list) pointer to struct student
  */
void SDB_GetUsedSize( student *List );

/****************************************/

 /**
  * @brief user chooses to add entry data in the database
           to add one student which is his (Name,id, year,)
           and then add to your database
  * @param (list) pointer to struct student
  * @retval return 1 The function is working  return 0 If there is a warning
  */
  bool SDB_AddEntry(student **List);

/****************************************/

  /**
  * @brief delete the student data with the given id.
  * @param (list) pointer to struct student
  * @retval return 1 The function is working  return 0 If there is a warning
  */
bool SDB_DeletEntry (student **List);

  /****************************************/


 /**
  * @brief print the data of the user by searching on his data by the given id
  * @param (id) parameter to pass  student id
  * @param (list) pointer to struct student
  * @retval return 1 The function is working  return 0 If there is a warning
  */
  bool SDB_ReadEntry (student *List);

  /****************************************/

/**
  * @brief it gets the number of ids in the count and the list of all ids in list array
  * @param (list) pointer to struct student
  * @retval return 1 The function is working  return 0 If there is a warning
  */
  bool SDB_GetList ( student * List);

/****************************************/

 /**
  * @brief Checks if the given id the is Exist
  * @param (list) pointer to struct student
  * @retval return 1 The function is working  return 0 If there is a warning.
  */
  bool SDB_IsIdExist (student *List);

  /********************************************/
  /**
  * @brief To Display Student's Marks
  * @param (list) pointer to struct student
  * @retval return 1 The function is working  return 0 If there is a warning.
  */
  bool DisplayMarks (student *List);

  /****************************************/

  /**
  * @brief To Enter student's Marks
  * @param (list) pointer to struct student
  * @retval return 1 The function is working  return 0 If there is a warning
  */
  bool EnterMarks(student **List);

  /********************************************/

  /**
  * @brief To display text animatedly
  * @param (text[]) parameter to pass  text
  */
  void disp_animation(uint8 text[] );


#endif // _SDB_H


