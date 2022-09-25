//Singly linear LinkedList
//Write a program which search first occurance of particular element from singlylinear linked list. Function should return position at which element is found.
//works
#include<stdio.h>
#include<stdlib.h>

struct node{
    
    int data;
    struct node *next;

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn =NULL;
    newn=(PNODE)malloc(sizeof(NODE));

    newn-> data=no;
    newn-> next=NULL;

    if(Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        newn-> next=*Head;
        *Head=newn;
    }

}

int SearchFirstOcc(PPNODE Head, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt=0;
    int i=0;

    newn = (PNODE)malloc(sizeof(NODE));  
    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)   // LL is empty
    {
        *Head = newn;
    }
    else        // LL contains atleast one node
    {
            // travel till last node
            // store address of new node in the next pointer of last node
          temp = *Head;

          while(temp->next != NULL)
          {
            iCnt++;
            if(temp->data == no)
            {
                i=iCnt;
                break;
            }
            temp = temp->next;
          }
          temp->next = newn;
    }
    return i;
    
    
}

int main()
{
    PNODE first = NULL;
    int iRet=0;

    InsertFirst(&first,70);
    InsertFirst(&first,30);
    InsertFirst(&first,50);
    InsertFirst(&first,20);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);

    iRet=SearchFirstOcc(&first, 20);
    printf("First Occurance at %d",iRet);


    return 0;

}