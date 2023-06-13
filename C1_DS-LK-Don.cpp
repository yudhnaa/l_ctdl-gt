#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *link;
};
Node *first = NULL;

void Insert_last(int n)
{
    for (int i = 0; i < n; i++)
    {
        Node *p = new Node;
        cout << "Nhap phan tu thu " << i << ":";
        cin >> p->info;
        p->link=NULL;
        if (first==NULL)
        {
            first=p;
        }
        else
        {
            Node *q =first;
            while (q->link!=NULL)
            {
                q=q->link;
            }
            q->link = p;
        }
    }   
}
void Insert_first()
{
    Node *p = new Node;
    cout << "\nNhap gia tri can them vao truoc: ";
    cin >> p->info;
    p->link=NULL;
    Node *q = first;
    if (q==NULL)
    {
        first = p;
    }
    else
    {
        p->link=q;
        first = p;
    }
}
void Ins_af_q(Node *q,int x)
{
    Node *p = first;
    if (p == NULL)
    {
        cout << "\nDanh sach trong";
    }
    else
    {
        while (p!=NULL && p->info!=x)
        {
            p=p->link;
        }
        Node *q1 = p->link;
        q->link= q1;
        p->link=q;
    }
}
void Output()
{
    if (first == NULL)
    {
        cout << "\nDanh sach trong\n";
    }
    else
    {
        Node *p = first;
        while (p!=NULL)
        {
            cout << p->info << " ";
            p=p->link;
        }
    cout << "\n";
    }
    
}
Node *Search(int x)
{
    Node *p=first;
    while (p!=NULL && p->info != x)
    {
        p=p->link;
    }
    return p;
}
void Del_firs()
{
    if(first==NULL)
        cout << "Danh sach rong";
    else
    {
        Node *q = first;
        first=first->link;
        delete q;
    }
}
void Del_last()
{
    if (first==NULL)
    {
        cout << "Danh sach rong";
    }
    else
    {
        Node *p = first, *q;
        while (p->link!=NULL)
        {
            q=p;
            p=p->link;
        }
        if (p!=first)
            q->link=NULL;
        else
            first=NULL;
        delete p;
    }
}
void Del_af_q(int x)
{
    Node *p = first,*q=NULL;
    if (p==NULL)
        cout << "Danh sach trong";
    else
    {
        if (p->link==NULL)
        {
            cout << "\nDanh sach chi co 1 phan tu";
        }
        while (p->link!=NULL && p->info!=x)
        {
            p=p->link;
        }
        if (p->link==NULL)
        {
            cout << "Khong co phan tu\n";
        }
        else
        {
        q=p->link;
        p->link=q->link;
        delete q;
        }
    }
}

int main()
{
    int x = -1;
    cout << "Nhap so phan tu: ";
    cin >> x;
    Insert_last(x);
    cout << "Danh sach cac phan tu\n";
    Output();
    cout << "\nNhap phan tu can tim: ";
    cin >> x;
    Node *p = Search(x);
    if (p==NULL)
        cout << "\n" << "Khong co trong danh sach";
    else 
        cout << "\nPhan tu co trong danh sach\n";
    Insert_first();
    Output();
    Node *q = new Node;
    cout << "Nhap gia tri can them: ";
    cin >> q->info;
    q->link=NULL;
    cout << "Them sau phan tu q:";
    cin >> x;
    Ins_af_q(q,x);
    Output();
    Del_firs();
    Output();
    Del_last();
    Output();
    Del_af_q(4);
    Output();
    return 0;
    
}