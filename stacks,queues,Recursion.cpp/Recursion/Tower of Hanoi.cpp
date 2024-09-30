#include<iostream>
using namespace std;

void tower(int n, char beg, char aux, char end);

int main(){
    int n;
    cout << "Enter the number of discs: ";
    cin >> n;
    cout << "Tower of Hanoi solution:\n" << endl;
    tower(n, 'a', 'b', 'c');
    return 0;
}

void tower(int n, char beg, char aux, char end){
    if(n <= 0){
        cout << "Illegal entry" << endl;
    } else if(n == 1){
        cout << "Move disc from " << beg << " to " << end << endl;
    } else {
        tower(n-1, beg, end, aux);
        tower(1, beg, aux, end);
        tower(n-1, aux, beg, end);
    }
}



