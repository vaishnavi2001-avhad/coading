//Singly linear LinkedList
//Write a program which search LAST occurance of particular element from singlylinear linked list. Function should return position at which element is found.
//not working (giving first occurance only)
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

int SearchLastOcc(PPNODE Head, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt=0;
    int i=0;
    int last=-1;

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
            if(temp->data == no )
            {
                iCnt=i;
            }
            temp = temp->next;
          }
          temp->next = newn;
    }
    
    return last;
    
    
}

int main()
{
    PNODE first = NULL;
    int iRet=0;

    InsertFirst(&first,50);
    InsertFirst(&first,70);
    InsertFirst(&first,30);
    InsertFirst(&first,50);
    InsertFirst(&first,20);
    InsertFirst(&first,30);
    //InsertFirst(&first,50);
    InsertFirst(&first,20);
    //InsertFirst(&first,50);

    iRet=SearchLastOcc(&first, 50);
    printf("Last Occurance at %d\n",iRet);


    return 0;

}