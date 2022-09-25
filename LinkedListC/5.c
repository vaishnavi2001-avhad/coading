//Singly linear LinkedList
//Write a program which return smallest element from singly linear linked list 
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

int Minimum(PPNODE Head)
{
    PNODE newn =NULL;
    PNODE temp =NULL;
    int iSum;

    newn = (PNODE)malloc(sizeof(NODE));  
    newn->next = NULL;
    if(*Head == NULL)   // LL is empty
    {
        *Head = newn;
    }
    else
    {
        temp = *Head;
        iSum= temp-> data; 

        while(temp != NULL)
        {
            if(iSum > temp->data)
            {
                iSum= temp->data;
            }
            temp = temp->next;
        }
       //temp->next = newn;

    }
return iSum;

}


int main()
{
    PNODE first = NULL;
    int iRet=0;

    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);
    
    iRet=Minimum(&first);
    printf("Minimum of linked list is %d\n",iRet);

    return 0;

}