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
            if (arr[j] > arr[j + 1]) {
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


/* This function takes last element as pivot, places the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
int PartitionV2(int arr[], int l, int h)
{
    /*
        Trick to remember it,
        when pivot -> arr[low], start for loop from high.
        when pivot -> arr[high], start loop from low.
    */
    
	/*
    int i = l - 1;
	int pivot = arr[h];
	for (int j = l; j < h; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] < pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);	
	return (i + 1);
    */

    int i = h + 1;
	int pivot = arr[l];
	for (int j = h; j > l; j--)
	{
		if (arr[j] > pivot)
		{
			i--;
			swap(&arr[j], &arr[i]);
		}
	}
	swap(&arr[l], &arr[i - 1]);
	return i - 1;
}

/* The main function that implements QuickSort:
 arr[] --> Array to be sorted,
  l  --> Starting index,
  h  --> Ending index, not size */
void QuickSort(int arr[], int l, int h)
{
	int part;
	if (l < h)
	{
		//part = Partition(arr, l, h);      // This one is also works
		part = PartitionV2(arr, l, h);
		QuickSort(arr, l, part - 1);
		QuickSort(arr, part + 1, h);
	}
}


int main()
{
    int arr[] = { 11,44,56,87,2,3,90,24,59,11 }; int size = 10;
    
    BubbleSort(arr, size);
    
    print(arr, size);
    return 0;
}
