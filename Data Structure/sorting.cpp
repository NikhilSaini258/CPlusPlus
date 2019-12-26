#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int arr[], int size)
{
    bool flag = false;
    for (int i = 0; i < size - 1; i++)
    {
        flag = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j + 1] < arr[j]) {
                swap(&arr[j + 1], &arr[j]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

void InsertionSort(int arr[], int size)
{
    int temp;
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        temp = arr[i];
        while (j > -1 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void SelectionSort(int arr[], int size)
{
    int i, j, k;
    for (i = 0; i < size - 1; i++)
    {
        for (j = k = i; j < size; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(&arr[i], &arr[k]);
    }
}

int main()
{
    int arr[] = { 11,44,56,87,2,3,90,24,59,39 }; int size = 10;
    
    BubbleSort(arr, size);
    print(arr, size);

    InsertionSort(arr, size);
    print(arr, size);

    SelectionSort(arr, size);
    print(arr, size);
    
    return 0;
}
