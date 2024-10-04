//Time complexity : O(N*logN)
//space complexity : O(1)
#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

  
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}

void BuildMaxHeap(int arr[], int n)
{
  
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, i, n);
    }
}

void sortArray(int arr[], int n)
{
   
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); 
        Heapify(arr, 0, i);    
    }
}

void printHeap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 3, 8, 9, 13, 18, 14, 11, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    BuildMaxHeap(arr, n);    
    sortArray(arr, n);      
    printHeap(arr, n);       

    return 0;
}
