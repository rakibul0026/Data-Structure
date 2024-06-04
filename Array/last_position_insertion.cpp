#include<iostream>
using namespace std;
void last_insertion(int arr[],int value ,int n,int pos){
    cout<<"Before the insertion:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    for(int i=n-1;i>=pos;i--){
        arr[i]=arr[i-1];

    }
    arr[pos-1]=value;

    cout<<"\nAfter the insertion:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
 int value,n=5,pos=5;
 int arr[100]={2,3,4,5,6};
 cout<<"Enter the which was insert"<<endl;
 cin>>value;
last_insertion( arr,value ,n,pos);
}
