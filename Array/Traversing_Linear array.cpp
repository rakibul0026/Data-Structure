#include<iostream>
using namespace std;

void Traversing(int arr[], int n) {
    cout << "The array is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 3, 4, 5, 7};
    int n = 5;
    Traversing(arr, n);
    return 0; 
}
