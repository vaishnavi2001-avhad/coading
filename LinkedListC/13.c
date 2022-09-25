//Singly linear LinkedList
//Write a program which return MULTIPLICATION of each element in singly linear linked list 
//works partially(dosen't handle zero)
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

void DisplayProduct(PPNODE Head)
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
                int n = temp->data;
                int temp=n;
                int product=1;
                int r;
                while (n != 0) {
                r=n%10;    
                product *= r;
                n=n/10;  
            }
                if (product==0)
                {
                    printf("Multiplication of element is %d\n", temp);
                }
                else 
                printf("Product of element is %d\n", product);
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

    InsertFirst(&first,61);
    InsertFirst(&first,41);
    InsertFirst(&first,32);
    InsertFirst(&first,20);
    InsertFirst(&first,11);
    
    DisplayProduct(&first);

    return 0;

}