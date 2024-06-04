#include<iostream>
using namespace std;
void before_insert(int arr[],int n,int num,int value){
    cout<<"Before the insertion"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

     int pos=-1;
     for(int i=0;i<n;i++){
        if(arr[i]==num){
            pos=i;
            break;
        }

    }
    if(pos==-1){
        cout<<"\nthe num is not found in array"<<endl;
        return;
    }
    for(int i=n-1;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=value;
    n++;
     cout<<"\nAfter the insertion"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    int  n=5,num, value;
    cout<<"Enter the number which before insertion"<<endl;
    cin>>num;
    cout<<"Enter the value are insertion"<<endl;
    cin>>value;

    before_insert( arr, n, num,value);
}
