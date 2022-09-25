//Sample program 
//Singly Linear LinkedList in cpp
//All 8 functions 
//works

#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node 
{
    int Data;
    node *Next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class Singly_linkedlist 
{
private:
    PNODE Head;
public:
    Singly_linkedlist();
    ~Singly_linkedlist();
    BOOL InsertFirst(int);
    BOOL InsertLast(int);
    BOOL InsertAtPosition(int, int);
    inline void Display();
    inline int Count();
    BOOL DeleteFirst();
    BOOL DeleteLast();
    BOOL DeleteAtPosition(int);

};

Singly_linkedlist::Singly_linkedlist()
{
    Head = NULL;
}

Singly_linkedlist::~Singly_linkedlist()
{
    PNODE Temp, Navigate;

    if(Head!=NULL)
    {
        Navigate = Head;
            while(Navigate!=NULL)
            {
                Temp = Navigate ->Next;
                delete Navigate;
                Navigate = Temp;
            }
    }
}
BOOL Singly_linkedlist::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    if(newn == NULL)
    {
        return FALSE;
    }

    newn -> Next = NULL;
    newn -> Data = no;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> Next = Head;
        Head = newn;
    }
    return TRUE;
}

BOOL Singly_linkedlist::InsertLast(int no)
{
    PNODE newn = NULL, temp = Head;

    newn =  new NODE;

    if(newn == NULL)
    {
        return FALSE;
    }

    newn -> Next = NULL;
    newn -> Data = no;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp -> Next != NULL)
        {
            temp = temp-> Next;
        }
        temp -> Next = newn;
    }
    return TRUE;
}

BOOL Singly_linkedlist::InsertAtPosition(int pos, int no)
{
    if((Head == NULL) || (pos > Count()+1) || (pos <= 0))
    {
        return FALSE;
    }

    if( pos == 1)
    {
        return (InsertFirst(no));
    }
    else if( pos == (Count()+1))
    {
        return (InsertLast(no));
    }
    else
    {
        PNODE newn = NULL, temp = Head;

        newn = new NODE;

        if(newn == NULL)
        {
            return FALSE;
        }

        newn -> Data = no;
        newn -> Next = NULL;

        for(int i=1 ; i<=(pos-2); i++)
        {
            temp = temp -> Next;
        }

        newn -> Next = temp -> Next;
        temp -> Next = newn;
    }
    return TRUE;
}

BOOL Singly_linkedlist::DeleteFirst()
{
    PNODE temp = Head;

    if(Head == NULL)
    {
        return FALSE;
    }
    else
    {
        Head = Head -> Next;
        free(temp);
    }
    return TRUE;
}

BOOL Singly_linkedlist::DeleteLast()
{
    if(Head == NULL)
    {
        return FALSE;
    }
    else if (Head -> Next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE temp1 = Head , temp2 = NULL;

        while(temp1 -> Next -> Next!= NULL)
        {
            temp1 = temp1 -> Next;
        }

        temp2 = temp1 -> Next;
        temp1 -> Next = NULL;
        free(temp2);
    }
    return TRUE;
}

BOOL Singly_linkedlist::DeleteAtPosition(int pos)
{
    if((Head == NULL) || (pos > Count()+1) || (pos <= 0))
    {
        return FALSE;
    }

    if( pos == 1)
    {
        return (DeleteFirst());
    }
    else if( pos == (Count()+1))
    {
        return (DeleteLast());
    }
    else
    {
        PNODE temp1 = Head , temp2= NULL;

        for(int i=1 ; i<=(pos-2) ; i++)
        {
            temp1 = temp1 -> Next;
            ++i;
        }

        temp2 = temp1 -> Next;
        temp1 -> Next = temp2 -> Next;

        delete temp2;
    }
    return TRUE;
}

void Singly_linkedlist::Display()
{
    PNODE Temp = Head;

    while(Temp != NULL)
    {
        cout<< Temp -> Data << " -> ";
        Temp = Temp -> Next;
    }
    cout<<"NULL\n";
}

int Singly_linkedlist::Count()
{
    PNODE Temp = Head;
    int iCnt =0;

    while(Temp != NULL)
    {
        iCnt++;
        Temp = Temp -> Next;
    }
    return iCnt++;
}

int main() 
{
    Singly_linkedlist obj1;
    Singly_linkedlist *obj2 = new Singly_linkedlist();

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11); 

    obj1.Display();
    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

    obj1.InsertFirst(101);
    obj1.InsertFirst(111); 

    obj1.Display();
    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

    obj1.InsertAtPosition(75,4); 

    obj1.Display();
    cout<<"\nNumber of nodes : "<<obj1.Count()<<"\n";

    obj1.DeleteFirst();
    obj1.Display();

    obj1.DeleteLast();
    obj1.Display();

    obj2-> InsertFirst(501);
    obj2-> InsertFirst(511);
    obj2-> InsertFirst(521);

    obj2-> Display();

    obj2-> InsertLast(551);
    obj2-> InsertAtPosition(601,3);

    obj2-> Display();
    cout<<"\nNumber of nodes : "<<obj2->Count()<<"\n";

    delete obj2;

    return 0;
}