#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *next;
    Node *previous;
};
Node *first, *last;
void init()
{
    first = NULL;
    last = NULL;
}
void add_First(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = first;
    p->previous = NULL;
    if (first != NULL)
    {
        first->previous = p;
    }
    else
        last = p;
    first = p;
    p = NULL;
    delete p;
}
void add_Last(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    p->previous = last;
    if (last != NULL)
    {
        last->next = p;
    }
    else
        first = p;
    last = p;
    p = NULL;
    delete p;
}
int rm_First()
{
    if (first != NULL)
    {
        Node *p = first;
        first = first->next;
        delete p;
        if (first != NULL)
        {
            first->previous = NULL;
        }
        else
            last = NULL;
        return 1;
    }
    return 0;
}
int rm_Last()
{
    if (last != NULL)
    {
        Node *p = last;
        last = last->previous;
        delete p;
        if (last != NULL)
        {
            last->next = NULL;
        }
        else
            first = NULL;
        return 1;
    }
    return 0;
}
void process_List()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
}
int main()
{
    init();
    for (int i = 0; i < 5; i++)
    {
        add_First(i);
    }
    process_List();
    rm_Last();
    cout << endl;
    process_List();

    return 0;
}
