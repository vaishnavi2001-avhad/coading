//Singly linear LinkedList
//Write a program which return elements which DISPLAY ADDITION OF EVERY ELEMENT from singly linear linked list 
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

void SumDigit(PPNODE Head)
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
        iSum= temp-> data; 

        while(temp != NULL)
        {
            if(temp->data >0  )
            {
                int n = temp->data;
                int sum = 0;
                while (n != 0) {
                sum = sum + n % 10;
                n = n / 10;
            }
                iSum= sum;
              
                printf("Addition  is %d\n", iSum);
            }
            temp = temp->next;
        }
       //temp->next = newn;
    }


}


int main()
{
    PNODE first = NULL;
    int iRet=0;

    InsertFirst(&first,89);
    InsertFirst(&first,6);
    InsertFirst(&first,41);
    InsertFirst(&first,17);
    InsertFirst(&first,28);
    InsertFirst(&first,11);
    
    SumDigit(&first);

    return 0;

}