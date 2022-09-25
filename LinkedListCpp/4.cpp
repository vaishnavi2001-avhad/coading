//Singly Circular Linked List
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCLL
{
    private:        //characteristics
        PNODE Head;
        PNODE Tail;

    public:         //behaviors
       SinglyCLL();
       void InsertFirst(int no);
       void InsertLast(int no);
       void InsertAtPos(int no, int ipos);
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos( int ipos);
       void Display();
       int Count();


};
SinglyCLL::SinglyCLL() 
{
    Head = NULL;
    Tail= NULL;
}
void SinglyCLL::InsertFirst(int no)
{
    PNODE newn =NULL;

    newn = new NODE;

    newn-> data = no;
    newn-> next = NULL;

    if((Head==NULL) && (Tail==NULL)) //If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else  //If LL contains atleast one node
    {   
        newn-> next = Head;
        Head = newn;
    }

    Tail -> next = Head;

}
void SinglyCLL::InsertLast(int no)
{
    PNODE newn =NULL;

    newn = new NODE;

    newn-> data = no;
    newn-> next = NULL;

    if((Head==NULL) && (Tail==NULL)) //If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else  //If LL contains atleast one node
    {
        Tail -> next = newn;
        Tail = newn;
    }
    
    Tail -> next = Head;
}
void SinglyCLL::InsertAtPos(int no, int ipos)
{
    int iSize=Count();

    if((ipos<1) || (ipos>iSize+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == iSize+1)
    {
      InsertLast(no);  
    }
    else
    {
        PNODE newn =NULL;

        newn = new NODE;

        newn-> data = no;
        newn-> next = NULL;


        PNODE temp = Head ;
        int iCnt =0;

        for(iCnt =1;iCnt<ipos-1;iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
    }

}
void SinglyCLL::DeleteFirst()
{
    if((Head == NULL) && (Tail == NULL)) //If LL is empty
    {
        return;
    }
    else if(Head==Tail) //only one NODE
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;

        Tail->next=Head;
    }

}
void SinglyCLL::DeleteLast()
{
     if((Head == NULL) && (Tail == NULL)) //If LL is empty
    {
        return;
    }
    else if(Head==Tail) //only one NODE
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        PNODE temp = Head;

        while(temp -> next!= Tail)
        {
            temp=temp->next;
        }
        delete Tail;
        Tail = temp;

        Tail->next=Head;

    }
}
void SinglyCLL::DeleteAtPos( int ipos)
{
    int iSize=Count();

    if((ipos<1) || (ipos>iSize+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == iSize)
    {
      DeleteLast();  
    }
    else
    {
        PNODE temp = Head ;
        int iCnt =0;

        for(iCnt =1;iCnt<ipos-1;iCnt++)
        {
            temp = temp -> next;
        }
       
       PNODE temp2 = temp-> next;

       temp-> next = temp2-> next;
       delete temp2;
        
    }
}
void SinglyCLL::Display()
{
    PNODE temp = Head;
    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    do
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp -> next;
    }

    while(temp != Tail->next);
    cout<<"NULL"<<endl;
}
int SinglyCLL::Count()
{

int iCnt = 0;
    PNODE temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return 0;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp != Head);

    return iCnt;
}

int main()
{
    SinglyCLL obj;
    int iRet;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);


    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.InsertAtPos(75,4);
    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    obj.DeleteAtPos(4);
    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<endl;

    return 0;
} 