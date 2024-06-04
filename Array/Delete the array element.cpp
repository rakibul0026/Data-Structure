#include <iostream>
using namespace std;
void deleteElement(int arr[], int& n, int pos) {
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 int main() {
    int a[5] = {5, 3, 8, 16, 3};
    int n = 5; 
    cout << "Original array: ";
    printArray(a, n);
    int pos;
    cout << "Enter the position to delete : "<<endl;
    cin >> pos;
    deleteElement(a, n, pos);
    cout << "Array after deletion: "<<endl;
    printArray(a, n);
    return 0;
}
