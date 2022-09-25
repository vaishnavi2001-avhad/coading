//Singly linear LinkedList
//Write a program which return elements PALINDROME in singly linear linked list 
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

void DisplayPalindrome(PPNODE Head)
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
                int sum=0;
                int r;
                while (n != 0) {
                r=n%10;    
                sum=(sum*10)+r;    
                n=n/10;   
            }
              if(temp==sum)
                {printf("Palindrome of element is %d\n", sum);}
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

    InsertFirst(&first,989);
    InsertFirst(&first,6);
    InsertFirst(&first,414);
    InsertFirst(&first,17);
    InsertFirst(&first,28);
    InsertFirst(&first,11);
    
    DisplayPalindrome(&first);

    return 0;

}