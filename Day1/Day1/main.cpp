#include <iostream>

using namespace std;

class Node
{
public:
    int Data;
    Node *Next, *Prev;

    Node(int data)
    {
        Data = data;
        Next = Prev = NULL;
    }
};

class LinkedList
{
public:
    Node *Head, *Tail;


    LinkedList()               //constructor
    {
        Head = Tail = NULL;
    }

    void Add(int data)         //function add
    {
        Node *newNode = new Node(data);

        if(Head == NULL)
        {
            Head = Tail = newNode;
        }
        else
        {
            Tail->Next = newNode;
            newNode->Prev = Tail;
            Tail = newNode;
        }
    }

    void Display()             //function display
    {
        Node *current = Head;

        while(current != NULL)
        {
            cout << current->Data << "\t";
            current = current ->Next;
        }
    }

    void Delete(int data)       //function delete
    {
        Node *pDelete = Search(data);

        if(pDelete == NULL)
            return;

        if(pDelete == Head)
        {
            if(pDelete == Tail)
            {
                Head = Tail = NULL;
            }
            else
            {
                Head = Head->Next;
                Head->Prev = NULL;
            }
        }
        else if(pDelete == Tail)
        {
            Tail = Tail->Prev;
            Tail->Next = NULL;
        }
        else
        {
            pDelete->Prev->Next = pDelete->Next;
            pDelete->Next->Prev = pDelete->Prev;
        }

        delete pDelete;
    }

    int GetLength()    //1st ass.
    {
        int Count=0;
        Node *current= Head;
        while(current != NULL)
        {
            Count++;
            current = current->Next;
        }
        return Count;

    }

    int GetByIndex( int index)    //2nd ass.
    {
        Node *current= Head;
        int Count=0;
        while (current != NULL)
        {
            if (Count == index)
                return (current->Data);
            else
            Count++;
            current = current->Next;
        }
        return 0;
    }

  /*  void InsertAfter(int AfterThisData, int NewInsertData)
    {
         Node* Current= Search(AfterThisData);

         Node *newNode = new Node(NewInsertData);

        if(Head == NULL)
        {
            Head = Tail = newNode;
        }
        else
        {
            Tail->Next = newNode;
            newNode->Prev = Tail;
            Tail = newNode;
        }

        if(Current == Head)
        {
             if(Current == Tail)
             {
                  Tail->Next =newNode ;
                  newNode = Tail;
                  Tail = newNode;
             }

        }
           else if (Current != Head)
           {
               Current->Next->Prev = newNode->Prev;
               Current->Prev->Next = newNode->Next;
           }
        }
*/




private:                     // private access modifier
    Node* Search(int data)   // function search
    {
        Node *current = Head;

        while(current != NULL)
        {
            if(current-> == data)
            {
                return current;
            }

            current = current->Next;
        }

        return NULL;
    }

};


int main()
{
    LinkedList linkedList;

    linkedList.Add(3);
    linkedList.Add(5);
    linkedList.Add(7);
    linkedList.Add(9);
    linkedList.Add(11);
    linkedList.Add(13);


    linkedList.Display();

    cout << " " <<endl;

    cout<<"Your length of your list ="<<" "<<linkedList.GetLength() <<endl;


    cout << " ============================================= " <<endl;


    cout << "Your demanded Index Data = " << linkedList.GetByIndex(0)<<endl;

        cout << " ============================================= " <<endl;


   // linkedList.Delete(13);

/*   linkedList.InsertAfter(13,20);

   cout << " After InsertAfter Function: " <<endl;

   linkedList.Display();

   cout<<"Your length of your list AfterInsert Function ="<<" "<<linkedList.GetLength();

*/







   //cout<<"Element at demanded index = "<<" "<<linkedList.GetByIndex(linkedList.Head, 3);


    return 0;
}
