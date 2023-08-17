#include <iostream>
using namespace std;
// Stop console
void stopConsole();
// A Node's data structure
struct Node;
Node *first;
// Init first Node
void init();
// Process stack
int printStack();
// Is stack full
bool isFull();
// Is stack empty
bool isEmpty();
// Insert an element
int insertEle(int x);
// Delete an elementx
int deleteEle();
// Convert a decimal number to binary base
int dec2Bin();
// Convert a decimal number to X base
int dec2XBase();
// Print menu to console
int menu();
// main() function
int main()
{
    init();
    while (menu() != 0)
    {
    }
    return 0;
}

/* others function */

// Stop console
void stopConsole()
{
    cout << "\nPress Enter To Continue...";
    cin.ignore();
    cin.get();
}
// A Node's data structure
struct Node
{
    int info;
    Node *link;
};
int printStack()
{
    if (isEmpty())
    {
        cout << "Stack is empty\n";
        stopConsole();
        return 0;
    }
    else
    {
        Node *p = first;
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->link;
        }
        stopConsole();
        return 1;
    }
}
// Init first Node
void init()
{
    first = NULL;
}
// Print menu to console
int menu()
{
    system("clear");
    cout << "1. Is stack empty ?\n";
    cout << "2. Is stack full ?\n";
    cout << "3. Insert an element\n";
    cout << "4. Delete an element\n";
    cout << "5. Convert a decimal number to binary base\n";
    cout << "6. Convert a decimal number to X base\n";
    cout << "7. Print all elements\n";
    cout << "8. Quit\n";
    cout << "Choose: ";
    int choose = 0;
    cin >> choose;
    switch (choose)
    {
    case 1:
        isFull();
        break;
    case 2:
        isEmpty();
        break;
    case 3:
    {
        cout << "Nhap gia tri: ";
        int x = 0;
        cin >> x;
        insertEle(x);
        break;
    }
    case 4:
        deleteEle();
        break;
    case 5:
        dec2Bin();
        break;
    case 6:
        dec2XBase();
        break;
    case 7:
        // printStack();
        break;
    case 8:
    default:
        return 0;
        break;
    }
    return 1;
}
// Is stack full
bool isFull()
{
    return !isEmpty();
    // using linked list so stack cannot be overflowed in a small program
}
// Is stack empty
bool isEmpty()
{
    if (first != NULL)
    {
        return false;
    }
    return true;
}
// Insert an element
int insertEle(int x)
{
    Node *p = first;
    Node *q = new Node;
    q->info = x;
    q->link = NULL;
    if (isEmpty())
    {
        first = q;
    }
    else
    {
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = q;
    }
    return 1;
}
// Delete last element
int deleteEle()
{
    if (isEmpty())
    {
        cout << "Stack is empty";
        stopConsole();
        return -1;
    }
    else
    {
        int x = -1;
        Node *p = first;
        if (p->link == NULL)
        {
            x = p->info;
            first = NULL;
        }
        else
        {
            Node *q;
            while (p->link != NULL)
            {
                q = p;
                p = p->link;
            }
            q->link = NULL;
            x = p->info;
        }
        delete p;
        return x;
    }
}
// Convert a decimal number to binary base
int dec2Bin()
{
    cout << "Nhap so muon chuyen sang he 2: ";
    int x;
    cin >> x;
    while (x >= 2)
    {
        insertEle(x % 2);
        x = x / 2;
    }
    insertEle(x);
    cout << "Sau khi chuyen doi: ";
    while (!isEmpty())
    {
        cout<< deleteEle();
    }
    stopConsole();
    return 1;
}
// Convert a decimal number to X base
int dec2XBase()
{
    cout << "Nhap he muon chuyen sang: ";
    int base;
    cin >> base;
    cout << "Nhap so muon chuyen sang he " << base << " : ";
    int x;
    cin >> x;
    while (x >= base)
    {
        insertEle(x % base);
        x = x / base;
    }
    insertEle(x);
    cout << "Sau khi chuyen doi: ";
    while (!isEmpty())
    {
        int n = 0;
        n = deleteEle();
        switch (n)
        {
        case 10:
            cout<<"A";
            break;
        case 11:
            cout<<"B";
            break;
        case 12:
            cout<<"C";
            break;
        case 13:
            cout<<"D";
            break;
        case 14:
            cout<<"E";
            break;
        case 15:
            cout<<"F";
            break;
        default:
            cout << n;
            break;
        }
    }
    stopConsole();
    return 1;
}