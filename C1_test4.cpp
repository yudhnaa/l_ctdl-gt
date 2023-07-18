#include <iostream>
#define MAX 100
void init(int a[], int &front, int &rear)
{
    front = -1;
    rear = -1;
}
int push(int a[], int &front, int &rear, int x)
{
    if (rear - front == MAX - 1)
        return 0;
    else
    {
        if (rear == MAX - 1)
        {
            for (int i = front; i < rear; i++)
            {
                a[i - front] = a[i];
            }
            rear = MAX - 1 - front;
            front = 0;
        }
        if (front == -1)
        {
            front = 0;
        }
        a[++rear] = x;
        return 1;
    }
}
int pushByLoop(int a[], int &front, int &rear, int x)
{
    if ((rear - front == MAX - 1) || rear - front == -1)
    {
        return 0;
    }
    else
    {
        if (front == -1)
            front = 0;
        if (rear == MAX - 1)
            rear = -1;
        a[++rear] = x;
        return 1;
    }
}
int pop(int a[], int &front, int &rear, int &x)
{
    if (rear == -1)
        return 0;
    else
    {
        x = a[front++];
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
        return 1;
    }
}
int popByLoop(int a[], int &front, int &rear, int &x)
{
    if (front == -1)
    {
        return 0;
    }
    else
    {
        x = a[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front ++;
            if (front > MAX-1)
            {
                front = 0;
            }
        }
        return 1;
    }
}
using namespace std;
int main()
{
    int a[MAX];
    int front;
    int rear;
    init(a,front,rear);

    return 0;
}