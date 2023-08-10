// Amen, cau 7 no kho vcl a
#include <iostream>
#include <time.h>
using namespace std;
struct Node
{
    int info;
    Node *previous;
    Node *next;
};
Node *first;
Node *last;
// Inittilize first and last elements
void init()
{
    first = NULL;
    last = NULL;
}
// A function makes the console stop to show the result
void stopConsole()
{
    cin.ignore();
    string stop;
    getline(cin, stop);
}
// A function checks is the linked list empty?
bool isEmpty()
{
    if (last == NULL || first == NULL)
    {
        cout << "Danh sach rong\n";
        stopConsole();
        return true;
    }
    return false;
}
// Print all Elements to console
int printAllEle()
{
    Node *p = first;
    if (p == NULL)
    {
        cout << "Danh sach rong"
             << "\n";
        stopConsole();
        return 0;
    }
    else
    {
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
        stopConsole();
        return 1;
    }
}
// Add an element at first
int addFirst()
{
    int x;
    cout << "Nhap gia tri muon them vao: ";
    cin >> x;
    Node *q = new Node;
    q->info = x;
    q->next = first;
    q->previous = NULL;
    if (first != NULL)
    {
        first->previous = q;
    }
    else
        last = q;
    first = q;
    return 1;
}
// Add an element at last
int addLast()
{
    for (int i = 0; i < 5; i++)
    {
        int x;
        // cout << "Nhap gia tri muon them vao: ";
        // cin >> x;

        x = i + rand() % 20;
        Node *q = new Node;
        q->info = x;
        q->next = NULL;
        q->previous = last;
        if (last != NULL)
        {
            last->next = q;
        }
        else
            first = q;
        last = q;
    }

    return 1;
}
// Delete an element at first
int deleteFirst()
{
    if (first == NULL)
    {
        cout << "Danh sach rong"
             << "\n";
        stopConsole();
        return 0;
    }
    else
    {
        Node *p = first;
        first = first->next;
        delete p;
        if (first == NULL)
        {
            first = NULL;
            last = NULL;
        }
        else
        {

            first->previous = NULL;
        }
        cout << "Danh sach sau khi xoa: ";
        printAllEle();
        return 1;
    }
}
// Delete an element at last
int deleteLast()
{
    if (last == NULL)
    {
        cout << "Danh sach rong\n";
        stopConsole();
        return 0;
    }
    else
    {
        Node *p = last;
        last = last->previous;
        delete p;
        if (last == NULL)
        {
            first = NULL;
            last = NULL;
        }
        else
        {
            last->next = NULL;
        }
        cout << "Danh sach sau khi xoa: ";
        printAllEle();
        return 1;
    }
}
// Find and delete an element
int findAnddel()
{
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        int x;
        cout << "Nhap gia tri muon tim: ";
        cin >> x;
        Node *p = first;
        while (p != NULL)
        {
            if (p->info == x)
            {
                Node *q = new Node;
                q = p;
                p = p->previous;
                if (p == NULL)
                {
                    last = NULL;
                    first = NULL;
                }
                else
                {
                    p->next = p->next->next;
                }
                delete q;
                cout << "Danh sach sau khi xoa: ";
                printAllEle();
                return 1;
            }
            else
            {
                p = p->next;
            }
        }
        return 0;
    }
}
// Find and add an element after that
int findAndAdd()
{
    if (isEmpty())
    {
        cout << "Danh sach rong";
        stopConsole();
        return 0;
    }
    else
    {
        int x;
        cout << "Nhap gia tri can tim: ";
        cin >> x;

        Node *p = first;
        Node *n = nullptr;

        while (p != NULL)
        {
            if ((p->info >= x && (n == nullptr || p->info - x < n->info - x)))
            {
                n = p;
            }
            p = p->next;
        }

        if (n == nullptr)
        {
            cout << "Khong co phan tu lon hon";
            stopConsole();
            return 0;
        }
        else
        {
            cout << "Gia tri bang hoac gan nhat lon hon " << x << " la " << n->info << endl;
            Node *q = new Node;
            cout << "Nhap gia tri muon them: ";
            cin >> q->info;

            q->previous = n;
            q->next = n->next;
            if (n->next != NULL)
            {
                n->next->previous = q;
            }
            n->next = q;
        }
        return 1;
    }
}
// Show the menu and options
int menu()
{
    system("clear");
    cout << "1.Print all elements"
         << "\n";
    cout << "2.Add an element at first"
         << "\n";
    cout << "3.Add an element at last"
         << "\n";
    cout << "4.Delete an element at first"
         << "\n";
    cout << "5.Delete an element at last"
         << "\n";
    cout << "6.Find and del an ele"
         << "\n";
    cout << "7.Find and del an element has extract or near value"
         << "\n";
    cout << "8.Exit"
         << "\n";
    int choose = 0;
    do
    {
        cout << "Chon: ";
        cin >> choose;
    } while (choose < 1 || choose > 8);
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
        findAnddel();
        break;
    case 7:
        findAndAdd();
        break;
    case 8:
    default:
        return 8;
        break;
    }
    return 1;
}
int main()
{
    srand(time(NULL));
    init();
    while (menu() != 8)
    {
    }

    return 0;
}