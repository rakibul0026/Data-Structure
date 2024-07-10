
#include<iostream>
using namespace std;
int fib(int n){
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return (fib(n-1) + fib(n-2));
}

int main(){
    int N,i;
    cout<<"Enter the number of term:"<<endl;
    cin >> N;
    for(i=0;i<N;i++){
        cout<<fib(i)<<" ";
    }
    int result = fib(N);
    cout << result << endl;
}


