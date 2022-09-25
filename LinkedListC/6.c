//Singly linear LinkedList
//Write a program which return elements which are perfect from singly linear linked list 
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
int Perfect(int num)
{
    int sum = 0;
	int i = 1;
	while (i <= (num / 2))
	{
		if (num % i == 0)
		{
			// When number is divisible by number i
			sum += i;
		}
		i++;
	}
	return sum;

}
void DisplayPerfect(PPNODE Head)
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
            if(temp->data >0 && temp->data == Perfect(temp->data) )
            {
                iSum=temp-> data;
                printf("Perfect number is %d\n", iSum);
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
    
    DisplayPerfect(&first);

    return 0;

}