#include<iostream>
using namespace std;
void last_insertion(int arr[],int value,int n,int pos){

    cout<<"After the insertion:"<<endl;
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    for (int i = n - 1; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
     arr[pos - 1] = value;
     cout<<"\nAfter the insertion:";
     for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }

}
int main(){
    int value,n=5,pos;
    int arr[]={2,3,4,5,7};
    cout<<" Enter the value ";
    cin>>value;
    cout<<" choice  the position  ";
    cin>>pos;
    last_insertion(arr, value,n,pos);

}
