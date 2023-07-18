#include <iostream>
using namespace std;
#define MAX 100

int add_Ele(int &n, int arr[])
{
    int add_n = 0;
    cout << "Nhap so phan tu muon them: ";
    cin >> add_n;
    for (int i = n; i < n + add_n; i++)
    {
        cin >> arr[i];
    }
    n += add_n;
    return 0;
}
int print_All_Ele(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    system("read");
    return 0;
}
int find_Ele_Seq(int arr[], int n)
{
    int x = 0;
    cout << "Nhap gia tri muon tim kiem:";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << "Co phan tu tai i = " << i;
            system("read");
            return i;
        }
    }
    cout << "Khong co phan tu\n";
    system("read");
    return -1;
}
int mer_Sort(int arr[], int n, int add_Arr[], int n1, int mer_Arr[])
{
    int i = 0, i1 = 0, i2 = 0;
    while (i1 < n && i2 < n1)
    {
        if (arr[i1] > add_Arr[i2])
        {
            mer_Arr[i] = add_Arr[i2];
            i2++;
        }
        else
        {
            mer_Arr[i] = arr[i1];
            i1++;
        }
        i++;
    }
    while (i1 < n)
    {
        mer_Arr[i] = arr[i1];
        i1++;
        i++;
    }
    while (i2 < n1)
    {
        mer_Arr[i] = add_Arr[i2];
        i2++;
        i++;
    }
    return 0;
}
int print_Menu(int arr[], int &n, int add_Arr[], int &n1, int mer_Arr[])
{
    int choose = 0;
    system("clear");
    cout << "1.Them phan tu\n";
    cout << "2.In cac phan tu\n";
    cout << "3.Tim phan tu (phuong phap tuan tu)\n";
    cout << "4.Tim va xoa phan tu\n";
    cout << "5.Gop 2 danh sach co thu tu thanh 1\n";
    cout << "6. Thoat\n";
    cout << "Chon option: ";
    cin >> choose;

    switch (choose)
    {
    case 1:
        add_Ele(n, arr);
        return 0;
        break;

    case 2:
        print_All_Ele(arr, n);
        return 0;
        break;
    case 3:
        find_Ele_Seq(arr, n);
        return 0;
        break;
    case 4:
        cout << "Chua biet lam\n";
        return 0;
        break;
    case 5:
        add_Ele(n1, add_Arr);
        mer_Sort(arr, n, add_Arr, n1, mer_Arr);
        print_All_Ele(mer_Arr, n + n1);
        system("read");
        return 0;
        break;
    default:
        return -1;
        break;
    }
}
int main()
{
    int arr[MAX];
    int add_Arr[MAX];
    int mer_Arr[MAX];
    int n = 0, n1 = 0;
    system("clear");
    while (print_Menu(arr, n, add_Arr, n1, mer_Arr) == 0)
    {
    }
    return 0;
}
