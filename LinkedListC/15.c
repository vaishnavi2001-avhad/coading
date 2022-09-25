//Singly linear LinkedList
//Write a program which return LARGEST DIGIT of each element in singly linear linked list 
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

void DisplayLarge(PPNODE Head)
{
    PNODE newn =NULL;
    PNODE temp =NULL;

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
            if(temp->data >0  )
            {
                int n=temp->data;
                int large=0,small=9;
                int r;
                while (n > 0) {
                    r = n % 10;
                    if (large < r) {
                        large = r;
                    }
                   
                    n = n / 10;  
   }
                
                printf("Large digit is %d\n", large);
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

    InsertFirst(&first,67);
    InsertFirst(&first,49);
    InsertFirst(&first,32);
    InsertFirst(&first,20);
    InsertFirst(&first,18);
    
    DisplayLarge(&first);

    return 0;

}