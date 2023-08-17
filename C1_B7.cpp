#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *link;
};
// Inittialize first element
Node *first;
void init()
{
    first = NULL;
}
// A function makes console stop
void stopConsole()
{
    cin.ignore();
    cin.get();
}
// Print all elements to console
int printAllEle()
{
    Node *p = first;
    if (p == NULL)
    {
        cout << "Linked list is empty\n";
        cout << "Enter to continue...";
        stopConsole();
        return 0;
    }
    else
    {
        do
        {
            cout << p->info << " ";
            p = p->link;
        } while (p != first); // Loop linked list (last element)->link == first
        stopConsole();
        return 1;
    }
}
// Add an element at first linked list
int addFirst()
{
    cout << "Enter value: ";
    Node *q = new Node;
    cin >> q->info;

    Node *p = first;
    q->link = p;
    if (p != NULL) // If this has > 1 element
    {
        do
        {
            p = p->link;
        } while (p->link != first);
        p->link = q;
    }
    else
    {
        q->link = q;
    }
    first = q;
    return 1;
}
// Add an element at last linked list
int addLast()
{
    cout << "Enter value: ";
    Node *q = new Node;
    cin >> q->info;

    Node *p = first;
    q->link = p;
    if (p != NULL) // If this has > 1 element
    {
        do
        {
            p = p->link;
        } while (p->link != first);
        p->link = q;
    }
    else
    {
        q->link = q;
        first = q;
    }
    return 1;
}
// Delete first element
int deleteFirst()
{
    Node *p = first;
    Node *q = first;
    if (p == NULL)
    {
        cout << "Linked list is empty\n";
        cout << "Enter to continue...";
        stopConsole();
        return 0;
    }
    else
    {
        if (p->link == first)
        {
            first = NULL;
        }
        else
        {
            do
            {
                p = p->link;
            } while (p->link != first);
            p->link = first->link;
            first = p->link;
        }
        cout << "Linked list: ";
        printAllEle();
        delete q;
        return 1;
    }
}
// Delete last element
int deleteLast()
{
    Node *p = first;
    if (p == NULL)
    {
        cout << "Linked list is empty\n";
        cout << "Enter to continue...";
        stopConsole();
        return 0;
    }
    else
    {
        if (p->link == first)
        {
            first = NULL;
            delete p;
        }
        else
        {
            do
            {
                p = p->link;
            } while (p->link->link != first);
            delete p->link;
            p->link = first;
        }
        cout << "Linked list: ";
        printAllEle();
        return 1;
    }
}
// Find and delete an element
int findAndDel()
{
    Node *p = first;
    Node *q = first;
    if (p == NULL)
    {
        cout << "Linked list is empty\n";
        cout << "Enter to continue...";
        stopConsole();
        return 0;
    }
    else
    {
        cout << "Enter value: ";
        int x = 0;
        cin >> x;
        do
        {
            if (p->info == x) // list exist x
            {
                if (p == first) // is first
                {
                    deleteFirst();
                }
                else if (p->link == first) // is last
                {
                    deleteLast();
                }
                else // in the middle of list
                {
                    cout << q->info << p->info << "\n";
                    q->link = p->link;
                    delete p;
                }
            }
            else if (p->link == first) // list does not exist x
            {
                cout << "List does not exist " << x;
                stopConsole();
                return 0;
            }
            q = p;
            p = p->link;
        } while (p != first);
        printAllEle();
        return 1;
    }
}
int menu()
{
    system("clear");
    cout << "1. Print all elements\n";
    cout << "2. Add an element at first\n";
    cout << "3. Add an element at last\n";
    cout << "4. Delete first element\n";
    cout << "5. Delete last element\n";
    cout << "6. Find an element and delete that\n";
    cout << "7. Quit\n";
    cout << "Chon: ";
    int choose = 0;
    cin >> choose;
    switch (choose)
    {
    case 1:
        printAllEle();
        break;
    case 2:
        addFirst();
        break;
    case 3:
        addLast();
        break;
    case 4:
        deleteFirst();
        break;
    case 5:
        deleteLast();
        break;
    case 6:
        findAndDel();
        break;
    case 7:
    default:
        return 7;
        break;
    }
    return 1;
}
int main()
{
    init();
    while (menu() != 7)
    {
    }
    return 0;
}