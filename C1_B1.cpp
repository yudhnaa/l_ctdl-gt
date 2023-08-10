#include <iostream>
using namespace std;
#define MAX 100
void input(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand()%100;
    }
}
void output(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int search(int a[], int n, int x, int &pos)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            pos = i;
            return 1;
        }
    }
    return 0;
    
}
int insertLast(int a[], int &n, int x)
{
    if (n == MAX -1) // Danh sach day
        return 0;
    else
    {
        a[n] = x;
        n++;
        return 1;
    }
}
int deleteLast(int a[], int &n)
{
    if (n==0) // Danh sach rong
        return 0;
    else
    {
        n--;
        return 1;
    }
}
int deletePos(int a[], int &n, int pos)
{
    if (n == 0) // Danh sach rong
        return 0;
    if (pos >= 0 && pos < n) // Vi tri ton tai
    {
        for (int i = pos; i < n; i++)
        {
            a[i] = a[i+1];
        }
        n--;
        return 1;
    }
    return 0; // Vi tri khong ton tai
}
int addPos(int a[], int &n, int x, int pos)
{
    if (pos >= 0 && pos < n) // Vi tri ton tai
    {
        for (int i = n; i > pos; i--)
        {
            a[i] = a[i-1];
        }
        a[pos] = x;
        n++;
        return 1;
    }
    return 0; // Vi tri khong ton tai
}
int findAndDel(int a[], int &n, int x)
{
    if (n == 0) // Danh sach rong
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            for (int j = i; j < n; j++)
            {
                a[j] = a[j+1]; 
            }
            n--;
            break;
        }
    }
    return 1;
}
using namespace std;
int main()
{
    int a[MAX];
    int n = -1;
    while (n < 0 || n >= 100)
    {
        cout << "Nhap so phan tu: ";
        cin >> n;
    }
    input(a,n);
    output(a,n);
    findAndDel(a,n,7);
    output(a,n);
    return 0;
}