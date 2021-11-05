#include <iostream>

using namespace std;

class Node
{
public:
    int Data;
    Node *Left, *Right;

    Node(int data)
    {
        Data = data;
        Left = Right = NULL;
    }
};

class Tree
{
    Node *root;
public:
    Tree()
    {
        root = NULL;
    }

    void Add(int data)
    {
        Node *newNode = new Node(data);

        if(root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node *current = root;
            Node *parent;

            while(current != NULL)
            {
                parent = current;
                if(data < current->Data)
                {
                    current = current->Left;
                }
                else
                {
                    current = current->Right;
                }
            }

            if(data < parent->Data)
                parent->Left = newNode;
            else
                parent->Right = newNode;
        }
    }

    void Delete(int data)
    {
        Node *pDelete = Search(data);
        Node *current;

        if(pDelete == root)
        {
            if(root->Left == NULL && root->Right == NULL)  // root has no children
            {
                root = NULL;
            }
            else if(root->Right == NULL)    // root has left child only
            {
                root = root->Left;
            }
            else if(root->Left == NULL)    // root has right child only
            {
                root = root->Right;
            }
            else
            {
                current = GetMaxLeft(root->Left);
                current->Left = root->Left;
                root = root->Right;
            }
        }
        else
        {
            Node *parent = GetParent(pDelete);
            Node *target;

            if(pDelete->Left == NULL && pDelete->Right == NULL)
            {
                target = NULL;
            }
            else if(pDelete->Right == NULL)
            {
                 target = pDelete->Left;
            }
            else if(pDelete->Left == NULL)
            {
                 target = pDelete->Right;
            }
            else
            {
                current = GetMaxLeft(pDelete->Right);
                current->Left = pDelete->Left;
                target = pDelete->Right;
            }

            if(parent->Left == pDelete)
                parent->Left = target;
            else
                parent->Right = target;
        }

        delete pDelete;
    }

    void Traverse()
    {
        Display(root);
    }

    void Traverse(int data)
    {
        Node *node = Search(data);
        Display(node);
    }

private:
    void Display(Node *pDisplay)
    {
        if(pDisplay == NULL)
            return;

        Display(pDisplay->Left);
        cout << pDisplay->Data << "\t";
        Display(pDisplay->Right);
    }

    Node* GetMaxLeft(Node *current)
    {
        while(current->Left != NULL)
        {
            current = current->Left;
        }

        return current;
    }

    Node* Search(int data)
    {
        Node *current = root;

        while(current != NULL)
        {
            if(data == current->Data)
                return current;

            if(data < current->Data)
            {
                current = current->Left;
            }
            else
            {
                current = current->Right;
            }
        }

        return NULL;
    }

    Node* GetParent(Node *child)
    {
        Node *parent = root;

        while(parent != NULL)
        {
            if(parent->Left == child || parent->Right == child)
            {
                return parent;
            }

            if(child->Data < parent->Data)
            {
                parent = parent->Left;
            }
            else
            {
                parent = parent->Right;
            }
        }

        return NULL;
    }
};

int main()
{
    Tree tree;

    tree.Add(50);
    tree.Add(40);
    tree.Add(35);
    tree.Add(30);
    tree.Add(45);
    tree.Add(47);
    tree.Add(65);
    tree.Add(60);
    tree.Add(55);
    tree.Add(70);
    tree.Add(80);
    tree.Add(90);
    tree.Add(100);




    tree.Traverse();

    return 0;
}
