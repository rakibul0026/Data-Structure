//Time Complexity:O(n log n)
//Space complexity: 𝑂(𝑛)-->Need Extra Memory
#include <iostream>
using namespace std;

void merge(int arr[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int left_array[n1], right_array[n2];

    for (i = 0; i < n1; i++)
        left_array[i] = arr[beg + i];
    for (j = 0; j < n2; j++)
        right_array[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = beg;

    while (i < n1 && j < n2)
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int mid = beg + (end - beg) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, beg, mid, end);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
