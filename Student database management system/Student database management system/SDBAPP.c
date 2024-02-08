#include "SDBAPP.h"

struct Node *listhead=NULL;

void SDB_APP ()
{

    uint8 UserChoice = 0;

    uint8 text1[]= {"\n/  \\    /  \\ ____  |  |   ____  ____   _____   ____   \n"
                    "\\   \\/\\/   // __ \\ |  | _/ ___\\/  _ \\ /     \\_/ __ \\\n"
                    " \\        / \\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/  \n"
                    "  \\__/\\  /   \\___  >____/\\___  >____/|__|_|  /\\___  > \n"
                    "       \\/        \\/          \\/            \\/     \\/  \n"
                   };
    uint8 text2[]= {"To add student data                (1)\n"
                    "To get used size in database       (2)\n"
                    "To read student data               (3)\n"
                    "To get the list of all student IDs (4)\n"
                    "To check is ID is existed          (5)\n"
                    "To delete student data             (6)\n"
                    "To add student's Marks             (7)\n"
                    "To display student's Marks         (8)\n"
                    "About the app                      (9)\n"
                    "To exit                            (0)\n"
                   };

    disp_animation(text1);
    sleep(3);
    while(1)
    {
        system("cls");

        printf("Home Page\n");
        printf("===============================\n");
        disp_animation(text2);
        printf("===============================\n");


        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);
        SDB_action (UserChoice);
    }

}
/***********************************************/

void SDB_action (uint8 choice)
{
    bool status =false; /** to take the return value of the function  */

    switch(choice)
    {
    case 1:
        status=  SDB_AddEntry( &listhead);
        if (0==status)
        {
            printf("Operation error !!!!\n ");
            sleep(5);
        }
        else {/** Nothing */}

        break;

    case 2:

        SDB_GetUsedSize(listhead);
        break;

    case 3:
        status= SDB_ReadEntry(listhead);
        if (0==status)
        {
            printf("Operation error !!!!\n ");
            sleep(5);
        }
        else {/** Nothing */}
        break;

    case 4:
        status=SDB_GetList (listhead);
        if (0==status)
        {
            printf("Operation error !!!!\n ");
            sleep(5);
        }
        else {/** Nothing */}
        break;

    case 5:

        status= SDB_IsIdExist (listhead);
        if (0==status)
        {
            printf("Operation error !!!!\n ");
            sleep(5);
        }
        else {/** Nothing */}
        break;

    case 6:

        status=SDB_DeletEntry (&listhead);
        if (0==status)
        {
            printf("Operation error !!!!\n ");
            sleep(5);
        }
        else {/** Nothing */}

        break;
    case 7:
        status= EnterMarks(&listhead);
        if (0==status)
        {
            printf("Operation error !!!!\n ");
            sleep(5);
        }
        else {/** Nothing */}
        break;
    case 8:
        status= DisplayMarks(listhead);
        if (0==status)
        {
            printf("Operation error !!!!\n ");
            sleep(5);
        }
        else {/** Nothing */}
        break;

    case 9:

        system("cls");
        printf("About\n--------------------------------------\n");
        printf("The idea of the application is to enter student data (name, ID, etc.)\n"
               "and store it in a database. The user is allowed to modify this data,\n"
               "such as adding or deleting, and he can view this data.\n\n\n");
        uint8 text[]= {"By:\n"
                       "   Mariam Ahmed\n"
                       "   Farida Ahmed\n"
                       "   Reem Belal\n"
                       "   Yahia Mohammed\n"
                      };
        disp_animation(text);
        printf("--------------------------------------\n\n");
        printf("To return to the home page, enter(0)=> ");
        uint8 home=1;
        scanf("%i",&home);
        while(home!=0)
        {
            printf("Error in input!!!. Enter (0) to return to the home page => ");
            scanf("%i",&home);
        }
        break;


    case 0:
        system("cls");
        printf("Quit from application \n");
        exit(0);
        break;

    default:
        printf("User Choice out of range !!!\n");
        sleep(2);
        break;
    }
}



