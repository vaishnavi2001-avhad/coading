//Singly linear LinkedList
//Write a program which return addition of all even elements from singly linear linked list 
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

int AdditionEven(PPNODE Head)
{
    PNODE newn =NULL;
    PNODE temp =NULL;
    int iSum=0;

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
            if(temp->data % 2==0)
            {       
                iSum=iSum+ temp-> data;         
            }
             temp = temp->next;
        }
       //temp->next = newn;
    }
    return iSum;
//printf("Addition of even is : %d", iSum);

}


int main()
{
    PNODE first = NULL;
    int iRet=0;

    InsertFirst(&first,11);
    InsertFirst(&first,20);
    InsertFirst(&first,32);
    InsertFirst(&first,11);
    
    iRet=AdditionEven(&first);
    printf("Addition of even elemet is : %d",iRet);

    return 0;

}