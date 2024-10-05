//Time Complexity:
//Space complexity:
#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    int temp, flag;
    for (int i = 0; i < size - 1; i++) {
        flag = 0;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        
        if (flag == 0) {
            break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 5, 7, 2, 3, -9};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);
    bubbleSort(arr, size);

    cout << "After bubble sort, the array is: ";
    printArray(arr, size);

    return 0;
}

