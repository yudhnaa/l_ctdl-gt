#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100

void init(int a[], int &sp);
int isEmpty(int sp);
int isFull(int sp);
int push(int a[], int &sp, int x);
int pop(int a[], int &sp, int &x);
int Dec2Bi(int a[], int &sp, int x);
int Bi2Dec(int a[], int &sp, int &x);
int main()
{
    int a[MAX];
    int sp;
    init(a, sp);
    Dec2Bi(a, sp, 10);
    int x = -1;
    int sp1 = sp;
    while (pop(a, sp1, x) != 0)
    {
        cout << x;
    }
    Bi2Dec(a, sp, x);
    cout << "\n"
         << x;
    return 0;
}
void init(int a[], int &sp)
{
    sp = -1;
}
int isEmpty(int sp)
{
    if (sp == -1)
        return 1;
    else
        return 0;
}
int isFull(int sp)
{
    if (sp == MAX - 1)
        return 1;
    else
        return 0;
}
int push(int a[], int &sp, int x)
{
    if (sp < MAX - 1)
    {
        a[++sp] = x;
        return 1;
    }
    else
        return 0;
}
int pop(int a[], int &sp, int &x)
{
    if (sp != -1)
    {
        x = a[sp--];
        return 1;
    }
    else
        return 0;
}
int Dec2Bi(int a[], int &sp, int x)
{
    if (sp < MAX - 1)
    {
        while (x >= 2)
        {
            a[++sp] = x % 2;
            x = x / 2;
        }
        a[++sp] = x;
        return 1;
    }
    return 0;
}
int Bi2Dec(int a[], int &sp, int &x)
{
    int temp;
    while (sp > -1)
    {
        pop(a, sp, temp);
        if (temp == 1)
            x += pow(2, sp + 1);
        else
            x += 0;
    }
    return 1;

    return 0;
}