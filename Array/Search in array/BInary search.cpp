#include <iostream>
using namespace std;
void Binary_search(int arr[],int n,int item){
    int left, right, middle;
    left = 1;
    right = 7;
    while (left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] == item) {
         cout<<middle+1;
            return ;
        } else if (arr[middle] < item) {
            left = middle + 1;
        } else {
            right = middle - 1; 
        }
    }
    cout<<"Item not found\n";
    return ;
}
int main() {
    int arr[100] = {1, 2, 4, 5, 67, 89, 100}; 
    int n=7, item;
    cout<<"Enter the search item"<<endl;
    cin>>item;
    Binary_search( arr, n, item);
}
