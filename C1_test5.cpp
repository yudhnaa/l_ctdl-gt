#include <iostream>
#define MAX 100
struct Node
{
    int info;
    Node *link;
};
Node *front, *rear;
void init(int &front, int &rear)
{
    front = NULL;
    rear = NULL;
}
int push(int x)
{
    Node *p = new Node;
    p->link = NULL;
    p->info = x;
    if (rear == NULL) // near == null when list is empty
    {
        front = p;
    }
    else
    {
        rear->link=p; //when near != null?
    }
    rear = p;
        

}
int pop(int &x)
{
    if (front != NULL)
    {
        Node *p =front;
        x = p->info;
        front = front ->link;
        if(front == NULL) // if list has 1 element
            rear = NULL;
        delete p;
        return 1;
    }
    else
        return 0;
}
int isEmpty()
{
    if (front == NULL)
        return 1;
    else
    {
        return 0;
    }
    
}
using namespace std;
int main()
{
    int a[MAX];
    int front;
    int rear;

    return 0;
}