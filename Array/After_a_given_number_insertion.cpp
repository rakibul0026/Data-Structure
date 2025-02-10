#include<iostream>
using namespace std;
void After_insert(int arr[],int n,int value,int num){
    cout<<"Before the insertion"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    n++;
    int pos=-1;
    for(int i=0;i<n;i++){
    if(arr[i]==num){
        pos=i;
        break;
      }
     }
     if(pos==-1){
        cout<<"the number is not found in this array"<<endl;
        return ;
     }
    for(int i=n-1;i>pos;i--){
        arr[i]=arr[i-1];

     }
     arr[pos+1]=value;


     cout<<"\nAfter the insertion"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
    int arr[]={2,3,4,5,7};
    int  n=5, value, num;
    cout<<"Enter the number which after insertion"<<endl;
    cin>>num;
    cout<<"Enter the insert value "<<endl;
    cin>>value;

    After_insert( arr, n, value, num);

}
