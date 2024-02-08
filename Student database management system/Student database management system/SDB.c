#include"SDB.h"
/**
  * @brief To check if the identifier is not a duplicate
  * @param (id) parameter to pass  student id
  * @param (list) pointer to struct student
  * @retval return 1 if the id is existed and return 0 if the id not found.
  */
static bool ID_CHECK(uint32 id,student *List)
{

    bool status=true;
    student *TempNode=List;
    if(NULL==List)
    {
        status=false;
    }
    else
    {
        while( (NULL!=TempNode) && (id!=TempNode->Student_ID) )
        {
            TempNode=TempNode->NodeLink;
        }
        if(NULL == TempNode )
        {
            status=false;
        }
        else
        {
            printf("This ID already exists. Please enter the ID again\n");
        }
    }

    return status;
}
/**************************************************************************************/

bool SDB_AddEntry(student **List)
{
    system("cls");
    bool Status=false;
    uint32 selection=0;

    student *TempNode=NULL;
    student *LastNode=NULL;
    TempNode=(student *)malloc(sizeof (student));
    if(NULL!= TempNode)
    {
        printf("Addition \n");
        printf("--------------------------------------\n");
        while(1) /** To check if the identifier is not a duplicate */
        {
            printf("Enter  Student_ID : ");
            scanf("%i", &TempNode->Student_ID);
            if(0==ID_CHECK( TempNode->Student_ID,*List))
            {
                break;
            }
            else {/** Nothing*/}

        }


        printf("Enter  Student_Name : ");
        fflush(stdin);/** clear buffer */
        gets(TempNode->Student_Name);
        printf("Enter  Student_year : ");
        scanf("%i", &TempNode->Student_year);
        TempNode->English=0;
        TempNode->Arabic=0;
        TempNode->Maths=0;
        TempNode->Total=0;

        printf("--------------------------------------\n");
        TempNode->NodeLink= NULL;
        /** Check if database is empty */
        if (NULL==*List)
        {
            *List=TempNode;
        }
        else  /**  database is not empty */
        {
            LastNode=*List;
            while(NULL!=LastNode->NodeLink)
            {
                LastNode=LastNode->NodeLink;
            }
            LastNode->NodeLink=TempNode;
        }
        Status=true;
        printf("the data is added successfully\n\n");

    }
    else {/** Nothing */}

    printf("To add another student's data (1) "
           "\nTo return to the home page (0) \n=>> ");
    scanf("%i",&selection);
    while((selection!=0) && (selection!=1))
    {
        printf("Error in input!!!. Enter again => ");
        scanf("%i",&selection);
    }
    if(1==selection)
    {
        SDB_AddEntry (List);

    }
    else {/** Nothing */}


    return Status;
}
/*************************************************************************/

bool SDB_DeletEntry (student **List)
{
    system("cls");
    bool Status=false;
    uint32 selection=0;
    printf("Removal \n");
    /** Check if database is empty */
    if(NULL==*List)
    {
        printf("--------------------------------------\n");
        printf("the data is empty !!!\n");
        Status=true;
        printf("--------------------------------------\n");
    }
    else   /**  database is not empty */
    {
        uint32 id=0;
        student *TempNode=*List;
        student *NextNode=TempNode->NodeLink;
        printf("--------------------------------------\n");
        printf("enter the id to delete his data => ");
        scanf("%i",&id);
        printf("--------------------------------------\n\n");

        if (id==TempNode->Student_ID)
        {
            *List=TempNode->NodeLink;
            free(TempNode);
            printf("the data is delete successfully \n\n ");
            Status=true;
        }
        else
        {
            /** Search in database for the id*/
            while( (NULL!=NextNode) &&  (id!=NextNode->Student_ID) )
            {
                TempNode=TempNode->NodeLink;
                NextNode=NextNode->NodeLink;
            }
            if(NULL==NextNode)/** Check if id exists */
            {
                printf("not found this id [%i]\n",id);
                Status=true;
            }
            else
            {
                TempNode->NodeLink=NextNode->NodeLink;
                free(NextNode);
                printf("the data is delete successfully \n\n ");
                Status=true;

            }
        }

    }
    printf("To delete another student's data (1) "
           "\nTo return to the home page (0) \n=>> ");
    scanf("%i",&selection);
    while((selection!=0) && (selection!=1))
    {
        printf("Error in input. Enter again!!! => ");
        scanf("%i",&selection);
    }

    if(1==selection)
    {
        SDB_DeletEntry (List);

    }
    else {/** Nothing */}

    return Status;

}
/*****************************************************************/

bool SDB_GetList (student * List)
{
    system("cls");
    bool status=false;
    student *LastNode=NULL;
    uint32 id_count=1;
    printf("List of IDs\n");
    printf("--------------------------------------\n");
    /** Check if database is empty */
    if (NULL==List)
    {
        printf("\nThe database is empty\n");
        status=true;
    }
    /**  database is not empty */
    else
    {
        LastNode=List;
        while(NULL!=LastNode)
        {
            printf("ID number {%d} => %d\n",id_count++,LastNode->Student_ID);
            LastNode=LastNode->NodeLink;

        }
        status=true;
    }

    printf("--------------------------------------\n\n\n");
    printf("To return to the home page, enter(0)=> ");
    uint8 home=1;
    scanf("%i",&home);
    while(home!=0)
    {
        printf("Error in input!!!. Enter (0) to return to the home page => ");
        scanf("%i",&home);
    }
    return status;
}

/*****************************************************************/
bool SDB_ReadEntry (student *List)
{
    system("cls");
    bool status=false;
    uint32 id=0;
    uint32 selection=0;
    student * temp =List;
    uint32 student_number=1;
    printf("Data of student\n");
    printf("--------------------------------------\n");
    printf("Enter the ID you want to search => ");
    scanf("%d",&id);
    while( (NULL!=temp)&&(id!=temp->Student_ID)) /**to search for the ID*/
    {
        temp=temp->NodeLink;
        ++student_number;
    }
    if(temp==NULL)/**if the list is empty or the id doesn't exist*/
    {
        printf("\nthis id [%i]doesn't exist!!!\n",id);
        status=true;
    }
    else/**if the id is exist*/
    {
        status=true;
        printf("\nthe student number  : %d\n",student_number);
        printf("the student name    : %s\n",temp->Student_Name);
        printf("the student id      : %d\n",temp->Student_ID);
        printf("the student year    : %d\n",temp->Student_year);
    }
    printf("--------------------------------------\n\n\n");
    printf("To read another student's data (1) "
            "\nTo return to the home page (0) \n=>> ");
    scanf("%i",&selection);
    while((selection!=0) && (selection!=1))
    {
        printf("Error in input. Enter again!!! => ");
        scanf("%i",&selection);
    }

    if(1==selection)
    {
        SDB_ReadEntry (List);

    }
    else {/** Nothing */}
    return status;
}
/*****************************************************************/

bool SDB_IsIdExist (student *List)
{
    system("cls");
    bool status=false;
    uint32 selection=0;
    uint32 targetId=0;
    printf("check of ID\n");
    printf("--------------------------------------\n");
    printf("Enter student ID to check => ");
    scanf("%d", &targetId);
    student *TempNode = List;

    while (NULL != TempNode)
    {
        if (targetId == TempNode->Student_ID)
        {
            /** ID exists*/
            status = true;
            break;
        }
        TempNode = TempNode->NodeLink;
    }
    if (NULL!=TempNode )
    {
        printf("\nStudent ID  exists in the database.\n");
    }
    else
    {
        printf("\nStudent ID does not exist in the database.\n");
        status = true;
    }
    printf("--------------------------------------\n\n\n");
    printf("To check another student's ID (1) "
           "\nTo return to the home page (0) \n=>> ");
    scanf("%i",&selection);
    while((selection!=0) && (selection!=1))
    {
        printf("Error in input. Enter again!!! => ");
        scanf("%i",&selection);
    }

    if(1==selection)
    {
        SDB_IsIdExist (List);

    }
    else {/** Nothing */}

    return status;
}

/*****************************************************************/

void SDB_GetUsedSize(student *List )
{
    system("cls");
    uint32 Counter=0;
    student *TempNode=List;
    printf("Size \n");
    printf("--------------------------------------\n");
    while(NULL!=TempNode)
    {
        ++Counter;
        TempNode=TempNode->NodeLink;
    }
    printf("\n Number of students in the database : %i\n",Counter);
    printf("--------------------------------------\n\n\n");

    printf("To return to the home page, enter(0)=> ");
    uint8 home=1;
    scanf("%i",&home);
    while(home!=0)
    {
        printf("Error in input!!!. Enter (0) to return to the home page => ");
        scanf("%i",&home);
    }


}

/*****************************************************************/
bool EnterMarks(student **List){
    system("cls");
    bool status=false;
    uint32 id;
    uint32 selection=0;
    printf(" Enter marks of ID\n");
    printf("--------------------------------------\n");
    printf("Enter student ID => ");
    scanf("%d",&id);
    student *Temp=*List;
    while((NULL!=Temp)&&(id!=Temp->Student_ID)){
            Temp=Temp->NodeLink;}
    if(NULL==Temp){
        printf("\nthis id [%i]doesn't exist!!!\n",id);
        status=true;
        printf("--------------------------------------\n\n\n");
    }
    else{

       printf("\nEnglish => ");
       scanf("%d",&Temp->English);
       printf("Arabic  => ");
       scanf("%d",&Temp->Arabic);
       printf("Maths   => ");
       scanf("%d",&Temp->Maths);
       Temp->Total= (Temp->English)+(Temp->Arabic)+(Temp->Maths);
       status=true;
       printf("--------------------------------------\n");
       printf("the data is added successfully\n\n\n");
    }


     printf("To add another student's Marks (1) "
           "\nTo return to the home page (0) \n=>> ");
    scanf("%i",&selection);
    while((selection!=0) && (selection!=1))
    {
        printf("Error in input!!!. Enter again => ");
        scanf("%i",&selection);
    }
    if(1==selection)
    {
        EnterMarks(List);

    }
    else {/** Nothing */}

    return status;
}
/*****************************************************************/
bool DisplayMarks(student *list){
   system("cls");
    bool status=false;
    uint32 id;
    uint32 selection=0;
    printf(" Marks of ID\n");
    printf("--------------------------------------\n");
    printf("Enter student ID => ");
    scanf("%d",&id);
    student *Temp=list;


    while((NULL!=Temp)&&(id!=Temp->Student_ID)){
            Temp=Temp->NodeLink;}
    if(NULL==Temp){
        printf("\nthis id [%i]doesn't exist!!!\n",id);
        status=true;
    }
    else{
         printf("--------------------------------------\n");
         printf("Name: %s   age : %d",Temp->Student_Name,Temp->Student_year);
         printf("\n\n--------------------------------------\n");
         printf("Subject        |        Mark          \n");
         printf("--------------------------------------\n");
         printf("English        |        %d            \n",Temp->English);
         printf("--------------------------------------\n");
         printf("Arabic         |        %d          \n",Temp->Arabic);
         printf("--------------------------------------\n");
         printf("Maths          |        %d            \n",Temp->Maths);
         printf("======================================\n");
         printf("Total          |        %d         \n",Temp->Total);
         status=true;
    }

    printf("--------------------------------------\n\n\n");
    printf("To Display another student's Marks (1) "
           "\nTo return to the home page (0) \n=>> ");
    scanf("%i",&selection);
    while((selection!=0) && (selection!=1))
    {
        printf("Error in input!!!. Enter again => ");
        scanf("%i",&selection);
    }
    if(1==selection)
    {
        DisplayMarks(list);

    }
    else {/** Nothing */}

    return status;


}


/*****************************************************************/
void disp_animation(uint8 text[] )
{
    uint32 x;
    float64 y;
    for(x=0; text[x]!=NULL; x++)
    {
        printf("%c",text[x]);
        for(y=0; y<=8888888; y++)
        {
        }
    }
}
