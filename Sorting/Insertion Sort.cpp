/*  Time Complexity:
     Best case:O(n)
     Worst case: o(n^2)  
     Average case: o(n^2)  
   Space complexity:O(1) */

#include <iostream>
using namespace std;
void insertionsort(int arr[], int size)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    int arr[] = {6, 8, 9, 2, -9};
    int n;
    n = 5;
    cout << "Before the insertion the array is:  ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    insertionsort(arr, n);
    cout << "\nAfter the insertion the array is:  ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
