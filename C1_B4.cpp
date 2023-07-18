#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *link;
};
Node *first;
void init()
{
    first = NULL;
}
void process_List()
{
    Node *p = first;
    if (p != NULL)
    {
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->link;
        }
    }
    else
        cout << "Danh sach rong\n";
}
Node *find_Ele(int x)
{
    Node *p = first;
    Node *q;
    while (p != NULL)
    {
        if (p->info == x)
        {
            cout << "Phan tu co trong danh sach\n";
            return q;
        }
        else
            q = p;
        p = p->link;
    }
    cout << "Danh sach khong co phan tu\n";
    return p;
}
void insert_Ele(int x)
{
    Node *p = new Node;
    p->info = x;
    p->link = first;
    first = p;
}
void del_Ele()
{
    Node *p = first;
    if (p != NULL)
    {
        delete first;
        first = p->link;
    }
    else
        cout << "Danh sach rong";
}
void insert_Ele_Last(int x)
{
    Node *p;
    p = first;
    Node *q = new Node;
    q->info = x;
    q->link = NULL;
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = q;
}
void del_Ele_Last()
{
    Node *p, *q;
    p = first;
    if (p != NULL)
    {
        while (p->link != NULL)
        {
            q = p;
            p = p->link;
        }
        q->link = NULL;
        delete p;
    }
    else
        cout << "Danh sach rong";
}
int find_del_Ele(int x)
{
    Node *p = find_Ele(x);
    Node *q = p;
    if (first != NULL)
    {
        if (p != NULL)
        {
            q = q->link;
            q = q->link;
            p->link = q;
            delete q;
            return 1;
        }
        else
            cout << "Khong co phan tu trong danh sach\n";
        return 0;
    }
    else
    {
        cout << "Danh sach rong\n";
        return 0;
    }
}
void sort()

{
    Node *p;
    Node *q = NULL;
    bool swaped;
    do
    {
        swaped = false;
        p = first;
        while (p->link != q)
        {
            if (p->info > p->link->info)
            {
                swap(p->info, p->link->info);
                swaped = true;
            }
            p = p->link;
        }
        q = p;
    } while (swaped == true);
}
int main()
{
    init();
    int arr[4] = {3,2,5,1};
    for (int i = 0; i < 4; i++)
    {
        insert_Ele(arr[i]);
    }
    sort();
    cout << endl;
    process_List();

    return 0;
}