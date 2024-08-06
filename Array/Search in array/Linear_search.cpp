#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int item) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            return i;  // Return the index of the found item
        }
    }
    return -1;  // Return -1 if the item is not found
}

int main() {
    int arr[] = {2, 4, 5, 6, 7, 8};
    int size = 6;
    int item = 5;

    int result = linearSearch(arr, size, item);
    if (result != -1) {
        cout << "The item index is: " << result << endl;
    } else {
        cout << "The item is not an element in this array" << endl;
    }

    return 0;
}
