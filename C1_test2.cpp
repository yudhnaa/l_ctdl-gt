#include <iostream>
#define MAX 100
void init(int a[], int &sp){
    sp = -1;
}
int Push(int a[], int &sp, int x){
    if (sp<MAX-1){
        a[++sp]=x;
        return 1;
    }
    return 0;
}
int Pop(int a[], int &sp, int &x){
    if (sp!=-1)
    {
        x = a[sp--];
        return 1; 
    }
    return 0;
}
int isFull(int a[], int &sp){
    if (sp == MAX-1){
        return 1;
    }
    return 0;
}
int isEmpty(int a[], int &sp){
    if (sp == -1){
        return 1;
    }
    return 0;
}
using namespace std;
int main()
{
    int a[MAX];
    int sp;
    init(a,sp);
    
    return 0;
}