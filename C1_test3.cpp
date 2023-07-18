#include <iostream>
#define MAX 100
struct Node
{
    int info;
    Node *link;
};
Node *sp;
void init()
{
    sp = NULL;
}
int Push(int x)
{
    Node *p = new Node;
    p->info = x;
    p->link = sp;
    sp = p;
}
int Pop(int &x)
{

    if (sp != NULL)
    {
        Node *p = sp;
        x = p->info;
        sp = p->link;
        delete p;
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if (sp == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
using namespace std;
int main()
{
    int a[MAX];
    int sp;
    init();

    return 0;
}