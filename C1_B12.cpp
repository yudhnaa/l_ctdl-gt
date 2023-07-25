#include <iostream>
using namespace std;
#define MAX 100
void init(int a[], int &front, int &rear);
int isEmpty(int a[], int front, int rear);
int isFull(int a[], int front, int rear);
int Push(int a[], int &front, int &rear, int x);
int Pop(int a[], int &front, int &rear, int &x);
int main()
{
    int a[MAX];
    int front, rear;
    init(a, front, rear);
    return 0;
}
void init(int a[], int &front, int &rear)
{
    front = -1;
    rear = -1;
}
int isEmpty(int a[], int front, int rear)
{
    if (front == -1)
        return 1;
    else
        return 0;
}
int isFull(int a[], int front, int rear)
{
    if ((rear - front) == MAX - 1)
        return 1;
    else
        return 0;
}
int Push(int a[], int &front, int &rear, int x)
{
    if ((rear - front) == MAX - 1)
        return 0;
    else
    {
        if (front == -1)
            front = 0;
        if (rear == MAX - 1)
        {
            for (int i = front; i < rear; i++)
            {
                a[i - front] = a[i];
            }
            rear = MAX - 1 - front;
            front = 0;
        }
        a[++rear] = x;
        return 1;
    }
}
int Pop(int a[], int &front, int &rear, int &x)
{
    if (front == -1)
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