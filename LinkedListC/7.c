//Singly linear LinkedList
//Write a program which return elements which are PRIME from singly linear linked list 
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
int Prime(int a)
{
    int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return a;
}
void DisplayPrime(PPNODE Head)
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
            if(temp->data >0 && temp->data == Prime(temp->data) )
            {
                iSum= temp->data;
                printf("Prime number is %d\n", temp->data);
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
    
    DisplayPrime(&first);

    return 0;

}