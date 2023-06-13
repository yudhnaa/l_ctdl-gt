#include <iostream>
using namespace std;
#define MAX 100

//function
bool check_n(int n);
int input_list(int n, int a[]);
int output_list(int n, int a[]);
int menu(int &n, int a[]);
int Find_ele(int &n, int a[]);

int main()
{
    int a[MAX];
    int n = -1;
    while (check_n(n) == false)
    {
        cout << "Nhap so phan tu (toi da 100):";
        cin >> n;
    }
    input_list(n,a);
    while (menu(n,a) == 0)
    {
    }
    
    
    return 0;
}

bool check_n(int n)
{
    if (n >= 0) return true;
    else return false;
}
int input_list(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout <<"Nhap phan tu " << i << ":";
        cin >> a[i];
    }
    return 0;
}
int output_list(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout <<"Phan tu " << i << ": " << a[i] << "\n";
    }
    return 0;
}
int Find_ele(int &n, int a[])
{
    int x = -1;
    cout << "Nhap phan tu can tim:";
    cin >> x;  
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            cout << "Phan tu co danh sach nam o vi tri thu" << i << "\n";
            return 0;
        }
        else
        {
            cout << "Khong co phan tu trong danh sach\n";
            return 0;
        }
    }
    return -1;
}
int Find_ele_del(int &n, int a[])
{
    int x = -1;
    cout << "Nhap phan tu can tim va xoa:";
    cin >> x;  
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            cout << "Phan tu co danh sach nam o vi tri thu " << i << "\n";
            for (int j = i; j < n-1; j++)
            {
                a[j] = a[j+1];
            }
            n--;
            cout << "Danh sach sau khi xoa:\n";
            output_list(n,a);
            return 0;
        }
    }
    cout << "Khong co phan tu trong danh sach\n";
    return -1;
}






int menu(int &n, int a[])
{
    int choose = -1;
    cout << "0. Xuat danh sach ra man hinh\n";
    cout << "1. Tim 1 phan tu trong danh sach\n";
    cout << "2. Them mot phan tu vao cuoi danh sach\n";
    cout << "3. Xoa phan tu cuoi danh sach\n";
    cout << "4. Xoa phan tu tai i trong danh sach\n";
    cout << "5. Them phan tu tai i trong danh sach\n";
    cout << "6. Tim va xoa phan tu trong danh sach\n";
    cout << "7. Thoat\n";
    while (check_n(choose) == false || choose > 7)
    {
        cout << "Nhap lua chon:";
        cin >> choose;
    }
    switch (choose)
    {
    case 0:
        output_list(n,a);
        break;
    case 1:
        Find_ele(n,a);
        break;
    case 2:
        output_list(n,a);
        break;
    case 3:
        output_list(n,a);
        break;
    case 4:
        output_list(n,a);
        break;
    case 5:
        output_list(n,a);
        break;
    case 6:
        Find_ele_del(n,a);
        break;
    default:
        return -1;
        break;
    }
    return 0;
}