//Singly linear LinkedList
//Write a program which return SECOND LARGEST element from singly linear linked list 
//not working
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

int SecMaximum(PPNODE Head)
{
    PNODE newn =NULL;
    PNODE temp =NULL;
    int iSum=0;
    int iSecond=0;

    newn = (PNODE)malloc(sizeof(NODE));  
    newn->next = NULL;
    if(*Head == NULL)   // LL is empty
    {
        *Head = newn;
    }
    else
    {
        temp = *Head;

        while(temp != NULL)
        {
            if(iSum < temp->data)
            {
                iSum= temp->data;
            }
            temp = temp->next;
        }
        iSum =iSecond ;
        iSum=0;
        while(temp != NULL )
        {
            if (iSecond!=temp->data  && iSum < temp->data)
            {
                iSum= temp->data;
            }
            temp = temp->next;
        }

      // temp->next = newn;

    }
return iSum;

}



int main()
{
    PNODE first = NULL;
    int iRet=0;

    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,50);
    InsertFirst(&first,10);
    
    iRet=SecMaximum(&first);
    printf("Second Maximum of linked list is %d\n",iRet);

    return 0;

}