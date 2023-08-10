#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *link;
};
// Initialize first Element
Node *first;
void init()
{
    first = NULL;
}
// A function makes the console stop to showing the result
void stopConsole()
{
    cin.ignore();
    string stop;
    getline(cin,stop);
}
// Add an Element to linked list
int addAnEle()
{
    cout << "Nhap gia tri muon them: ";
    int x;
    cin >> x;
    Node *p = new Node;
    p->info = x;
    p->link = NULL;
    Node *q;
    q = first;
    if (first == NULL)
    {
        first = p;
    }
    else
    {
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = p;
    }
    return 1;
}
// Print all elements from linked list
int printAllEle()
{
    Node *q;
    q = first;
    if (q == NULL)
    {
        cout << "Danh sach rong" << "\n";
        stopConsole();
        return 0;
    }
    else
    {
        while (q != NULL)
        {
            cout << q->info << " ";
            q = q->link;
        }
        stopConsole();
        return 1;
    }
}
// Find an element in linked list
int findAnEle()
{
    Node *q;
    q = first;
    cout << "Nhap gia tri can tim: ";
    int x;
    cin >> x;
    if (q == NULL)
    {
        cout << "Danh sach rong" << "\n";
    }
    else
    {
        while (q != NULL)
        {
            if (q->info == x)
            {
                cout << "Co phan tu " << x << "trong danh sach" << "\n";
                stopConsole();
                return 1;
            }
            else
            {
                q = q->link;
            }
        }
        cout << "Khong co phan tu trong danh sach" << "\n";
        stopConsole();
    }
    stopConsole();
    return 0;
}
// Find an Element and delete it
int findAndDelAnEle()
{
    Node *q;
    q = first;
    Node *p;
    p = NULL;
    cout << "Nhap gia tri can tim va xoa: ";
    int x;
    cin >> x;
    if (q == NULL)
    {
        cout << "Danh sach rong" << "\n";
    }
    else
    {
        while (q != NULL)
        {
            if (q->info == x)
            {
                if (p == NULL)
                {
                    first = q->link;
                }
                else
                {
                    p->link = q->link;
                }
                delete q;
                cout << "Danh sach sau khi xoa: ";
                printAllEle();
                return 1;
            }
            else
            {
                p = q;
                q = q->link;
            }
        }
        cout << "Khong co phan tu trong danh sach" << "\n";
    }
    stopConsole();
    return 0;
}
// Show the menu and let you choose the option
int menu()
{
    system("clear");
    cout << "1.Add an ele" << "\n";
    cout << "2.Print all elements" << "\n";
    cout << "3.Find ele" << "\n";
    cout << "4.Find and del an ele" << "\n";
    cout << "5.Exit" << "\n";
    int choose = 0;
    do
    {
        cout << "Chon: ";
        cin >> choose;
    } while (choose < 1 || choose > 5);
    switch (choose)
    {
    case 1:
        addAnEle();
        break;
    case 2:
        printAllEle();
        break;
    case 3:
        findAnEle();
        break;
    case 4:
        findAndDelAnEle();
        break;
    case 5:
    default:
        return 5;
        break;
    }
    return 1;
}
int main()
{
    system("clear");
    init();
    while (menu()!=5)
    {
    }
    return 0;
}