/*  Time Complexity:
      Best case:O(n^2)
      Worst case: o(n^2)  
      Average case: o(n^2)  
    Space complexity:O(1)  */

#include <iostream>
using namespace std;

void selectionSort(int a[], int n)
{
    int min_index, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
      
        temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {4, 2, 6, 3, 9, 1, 8};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Unsorted array: ";
    printArray(a, n);

    selectionSort(a, n);

    cout << "Sorted array: ";
    printArray(a, n);

    return 0;
}

