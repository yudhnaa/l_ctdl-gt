#include <iostream>
using namespace std;
int selection_Sort(int arr[], int n)
{
    for (int i = 0; i < 10; i++)
    {
        int min_pos = i;
        for (int j = i; j < 10; j++)
        {
            if (arr[min_pos] > arr[j])
            {
                min_pos = j;
            }
        }
        swap(arr[min_pos], arr[i]);
    }
    return 0;
}
int insertion_Sort(int arr[], int n)
{
    int j, x;
    for (int i = 1; i < n; i++)
    {
        x = arr[i];
        j = i - 1;
        while (j >= 0 && x < arr[j])
        {
            swap(arr[j+1],arr[j]);
            // arr[j + 1] = arr[j];
            j--;
        }
        // arr[j + 1] = x;
    }
    return 0;
}
int bubble_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
    return 0;
}
int interchange_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    return 0;
}
int merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int left_Arr[n1], right_Arr[n2];
    for (int i = 0; i < n1; i++)
    {
        left_Arr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right_Arr[i] = arr[mid + 1 + i];
    }
    int i = left, i1 = 0, i2 = 0;
    while (i1 < n1 && i2 < n2)
    {
        if (left_Arr[i1] <= right_Arr[i2])
        {
            arr[i] = left_Arr[i1];
            i1++;
        }
        else
        {
            arr[i] = right_Arr[i2];
            i2++;
        }
        i++;
    }
    while (i1 < n1)
    {
        arr[i] = left_Arr[i1];
        i1++;
        i++;
    }
    while (i2 < n2)
    {
        arr[i] = right_Arr[i2];
        i2++;
        i++;
    }
    return 0;
}
int merge_Sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_Sort(arr, left, mid);
        merge_Sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    return 0;
}

int print_Arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
int main()
{
    srand(time(0));
    int n = 6;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=rand()%100;
    }
    print_Arr(arr, n);
    cout << endl;
    // selection_Sort(arr,10);
    // bubble_Sort(arr, n);
    insertion_Sort(arr,n);
    // interchange_Sort(arr, 10);
    // merge_Sort(arr,0,(sizeof(arr)/sizeof(arr[0]))-1);
    print_Arr(arr, n);
    return 0;
}